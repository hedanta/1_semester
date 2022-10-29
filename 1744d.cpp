#include <iostream>
#include <vector>
#include <cmath>

int Pow_2(int x) {
  int cnt = 0;
  while (x % 2 == 0) {
    cnt += 1;
    x /= 2;
  }
  return cnt;
}

int main() {
  int test = 0;
  std::cin >> test;
  for (int iTest = 0; iTest < test; iTest += 1) {
    int n;
    std::cin >> n;
    int v = 0;
    int count_power = 0;
    for (int i = 0; i < n; i += 1) {
      std::cin >> v;
      count_power += Pow_2(v);
    }
    int ans = 0;
    for (int power = (int)std::log2(n + 1); power >= 0; power -= 1) {
      int k = 1 << power;
      for (int i = k; i <= n; i += k) {
        if (count_power >= n) {
          break;
        }
        if (power == Pow_2(i)) {
          ans += 1;
          count_power += power;	
        }
      }
    }
    if (count_power >= n) {
      std::cout << ans << '\n';
    }
    else {
      std::cout << "-1\n";
    }
  }
  return 0;
} 
