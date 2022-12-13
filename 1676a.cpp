#include <iostream>
#include <string>

int main() {
  int t(0);
  std::cin >> t;
  for (int i = 0; i < t; i += 1) {
    std::string s = "";
    std::cin >> s;
    int lsum = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    int rsum = (s[3] - '0') + (s[4] - '0') + (s[5] - '0'); 
    std::cout << ((lsum == rsum) ? "YES" : "NO") << '\n';
  }
  return 0;
}
