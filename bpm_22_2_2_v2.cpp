#include <cmath>
#include <iostream>
#include <iomanip>

int main() {
  double x, y;
  int cnt = 0;
  int n = 0;
  while (x = std::cin.get()) {
    std::cin >> y;
    cnt += 1;
    if (y >= abs(x)) {
      n += 1;
    }
    else if (y <= 2 - x * x) {
      n += 1;
    }
    if (y == abs(x)) {
      n -= 1;
    }
    if (y == 2 - x * x) {
      n -= 1;
    }
  }
  std::cout << n / cnt;
  return 0;
}