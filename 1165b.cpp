#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> problems(n);
  for (int i = 0; i < n; i += 1) {
    std::cin >> problems[i];
  }
  int day = 1;
  std::sort(problems.begin(), problems.end());
  for (int i = 0; i < n; i += 1) {
    if (problems[i] >= day) {
      day += 1;
    }
  }
  std::cout << day - 1;
  return 0;
}
