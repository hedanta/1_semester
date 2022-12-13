#include <iostream>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  int ans = 0;
  if (n % 5 == 0) {
    ans = n / 5;
  }
  else {
    ans = n / 5 + 1;
  }
  std::cout << ans;
  return 0;
} 
