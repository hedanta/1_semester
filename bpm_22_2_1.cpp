#include <cmath>
#include <iostream>
#include <iomanip>

const double eps = 0.0001;

int main() {
  for (double x = 0.1; x <= 1; x += 0.05) {
    double sum = 0.0;
    for (int i = 1; i < 10000; i += 1) {
      double cur = pow(-1, i) * (pow(x, 2 * i + 1))/(2 * i + 1);
      if ((cur < eps) && (cur > 0)) {
        break;
	  }
	  if ((cur > eps) && (cur < 0)) {
        break;
	  }
      sum += cur;
    }
    std::cout << std::fixed << std::setprecision(4) << x << " | " << sum << '\n';
  }
  return 0;
}