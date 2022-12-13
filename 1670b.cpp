#include <iostream>
#include <set>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int t = 0;
  std::cin >> t;
  int max = 0;
  while (t--) {
    int a = 0;
    std::string s = "";
    int n;
    std::cin >> a >> s >> n;
    std::set<char> str;
    int k = 0;
    max = 0;
    char tmp;
    for (int i = 0; i < n; i += 1) {
      std::cin >> tmp;
      str.insert(tmp);
    }
    for (int i = 0; i < s.size(); i += 1) {
      if (str.count(s[i])) {
        k = i - k;
        if (max < k) {
          max = k;
        }
        k = i;
      }
    }
    std::cout << max << '\n';
  }
  return 0;
}
