#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

int main() {
  int length = 0;
  std::string s = "";
  std::cin >> length >> s;
  std::string res = s;
  int np = length / 2 + (length % 2 == 0 ? -1 : 0);
  int vp = length / 2 + (length % 2 == 0 ? 0 : 1);
  for (int i = 0; i < length; i += 2) {
    res[i] = s[vp];
    vp += 1;
  }
  for (int i = 1; i < length; i += 2) {
    res[i] = s[np];
    vp += 1;
  }
  std::cout << res;
  return 0;
}