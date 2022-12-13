#include <iostream>

int main() {
  int indx = 0, indy = 0;
  for (int i = 0; i < 5; i += 1) {
    for (int j = 0; j < 5; j += 1) {
      int x(0);
      std::cin >> x;
      if (x == 1) {
        indx = i;
        indy = j;
      }
    }
  }
  std::cout << abs(2 - indx) + abs(2 - indy);
  return 0;
}
