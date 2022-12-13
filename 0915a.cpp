#include <iostream>

const int N = 1e5;

int main() {
  int b = 0;
  int length = 0;
  std::cin >> b >> length;
  int t = N;
  for (int i = 0; i < b; i += 1) {
    int s = 0;
    std::cin >> s;
    if (length % s == 0) {
      t = std::min(t, length / s);
    }
  }
  std::cout << t;
  return 0;
}
