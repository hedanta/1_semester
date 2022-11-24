#define _USE_MATH_DEFINES
#include "geometry.h"

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  Rdec2D v1 = { 0.0, 5.0 };
  Rpol2D v2 = { 5.0, M_PI / 2};
  std::cout << ToDec(v2);
}
