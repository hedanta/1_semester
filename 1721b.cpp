#include <iostream>
#include <vector>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i += 1) {
    int n, m, sx, sy, d;
    std::cin >> n >> m >> sx >> sy >> d;
    if ((std::min(n - sx, sy - 1) <= d) && (std::min(sx - 1, m - sy) <= d)) {
      std::cout << "-1\n";
    }
    else {
      std::cout << n + m - 2 << '\n';
    }
  }
  return 0;
} 
