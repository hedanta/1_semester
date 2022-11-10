#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::pair<int, int>> results;
  for (int i = 1; i <= n; i += 1) {
    int eng = 0;
    int dch = 0;
    int math = 0;
    int hist = 0;
    std::cin >> eng >> dch >> math >> hist;
    int sum = eng + dch + math + hist;
    results.push_back({sum, i});
  }
  int i = 1;
  std::stable_sort(results.begin(), results.end(), [](auto &left, auto &right) {
    return right.first < left.first;
  });
  for (std::pair<int, int> st : results) {
    if (st.second == 1) {
      std::cout << i;
      break;
    }
    i += 1;
  }
  return 0;
}
