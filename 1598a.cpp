#include <iostream>

int main() {
  int t(0);
  std::cin >> t;
  while (t > 0) {
    int n(0);
    std::cin >> n;
    std::string s1, s2;
    std::cin >> s1 >> s2;
    bool flag = 1;
    for (int i = 0; i < n; i += 1) {
      if (s1[i] == '1' && s2[i] == '1') {
        flag = false;
      }
    }
    if (flag) {
      std::cout << "YES\n";
    }
    else {
      std::cout << "NO\n";
    }
    t -= 1;
  }
  return 0;
}
