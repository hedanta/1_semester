#include <cmath>
#include <iostream>
#include <iomanip>

int main() {
  int num_of_dots = 0;
  std::cin >> num_of_dots;
  int n = 0;
  int t = num_of_dots;
  while (t--) {
    double x = 0.0;
    double y = 0.0;
    std::cin >> x >> y;
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
  std::cout << n / num_of_dots;
  return 0;
}