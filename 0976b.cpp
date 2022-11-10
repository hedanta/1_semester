#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int a = 0;
  int b = 0;
  std::cin >> n >> a >> b;
  std::vector<int> tube(n);
  int s = 0;
  int first = 0;
  std::cin >> first;
  s += first;
  for (int i = 1; i < n; i += 1) {
    int x = 0;
    std::cin >> x;
    tube[i] = x;
    s += x;
  }
  std::sort(tube.begin(), tube.end());
  std::reverse(tube.begin(), tube.end());
  int ans = 0;
  for (int i = 0; i < n; i += 1) {
    if (first * a / s >= b) {
      break;
    }
    ans += 1;
    s -= tube[i];
  }
  std::cout << ans;
  return 0;
}
