#include <iostream>

int main() {
  int t;
  std::cin >> t;
    while (t--) {
      std::string s;
      std::cin >> s;
      int streak = 1;
      for (int i(1); i < s.size(); i += 1) {
        if (s[i] != s[i - 1]) {
          if (streak == 1) {
            std::cout << "no\n";
            break;
          }
          streak = 0;
        }
        streak += 1;
      }
    if (s.size() > 1 && streak > 1) {
      std::cout << "yes\n";
    }
    else {
      std::cout << "no\n";
    }
  }
  return 0;
}
