#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  int max_size = 200001;
  std::vector<int> cafe(max_size, -1);
  for (int i = 0; i < n; i += 1) {
    int x = 0;
    std::cin >> x;
    cafe[x] = n - i - 1;
  }
  std::cout << std::distance(cafe.begin(), std::max_element(cafe.begin(), cafe.end()));
  return 0;
}
