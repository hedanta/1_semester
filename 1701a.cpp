#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;
    if (a1 && a2 && b1 && b2) {
      std::cout << 2;
    }
    else if (!(a1 || a2 || b1 || b2)) {
      std::cout << 0;
    }
    else {
      std::cout << 1;
    }
    std::cout << '\n';
  }
  return 0;
}
