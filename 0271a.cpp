#include <iostream>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  int a = 0, b = 0, c = 0, d = 0;
  n += 1;
  a = n / 1000;
  b = (n % 1000) / 100;
  c = (n % 100) / 10;
  d = n % 10;
  while (a == b || a == c || a == d || b == c || b == d || c == d) {
      n += 1;
      a = n / 1000;
      b = (n % 1000) / 100;
      c = (n % 100) / 10;
      d = n % 10;
  }
  std::cout << n;
  return 0;
} 
