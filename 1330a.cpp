#include <iostream>
#include <vector>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i += 1) {
    int n = 0, x = 0;
    std::cin >> n >> x;
    std::vector<int> a(202, 0);
    for (int j = 0; j < n; j += 1) {
      int rank = 0;
      std::cin >> rank;
      a[rank] = 1;
    }
    int ans = 0;
    for (int j = 1; j < a.size() && (x || a[j]); j += 1) {
      if (a[j] == 0) {
        x -= 1;
        a[j] = 1;
      }
      ans = j;
    }
    std::cout << ans << '\n';
  }
  return 0;
} 
