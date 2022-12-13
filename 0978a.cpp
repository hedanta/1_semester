#include <iostream>
#include <vector>
#include <array>

int main() {
  int n(0);
  std::cin >> n;
  std::vector<int> numbers(n);
  int cnt(0);
  std::array<int, 1001> count = {0};
  for (int i = 0; i < n; i += 1) {
    std::cin >> numbers[i];
    if (count[numbers[i]] == 0) {
      cnt += 1;
    }
    count[numbers[i]] += 1;
  }
  std::cout << cnt << '\n';
  for (int i = 0; i < n; i += 1) {
    if (count[numbers[i]] == 1) {
      std::cout << numbers[i] << " ";
    }
    else if (count[numbers[i]] > 1) {
      count[numbers[i]] -= 1;
    }
  }
  return 0;
}
