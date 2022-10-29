#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  int ans = 0;
  while (n > 0) {
    if (n & 1) {
      ans += 1;
    }
    n = n >> 1;
  }
  std::cout << ans;
  return 0;
} 
