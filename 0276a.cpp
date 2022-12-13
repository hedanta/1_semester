#include <iostream>


int main() {
  int n(0), k(0);
  std::cin >> n >> k;
  int maxud(-1000000000);
  for (int i = 0; i < n; i += 1) {
    int a(0), b(0);
    std::cin >> a >> b;
    if (b > k) {
      a -= (b - k);
    }
    maxud = std::max(maxud, a);
  }
  std::cout << maxud;
  return 0;
}
