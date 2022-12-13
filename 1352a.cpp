#include <iostream>


int main() {
  int t(0);
  std::cin >> t;
  for (int i = 0; i < t; i += 1) {
    int n(0);
    std::cin >> n;
    int d = 1, cnt(0), ind(0);
    int ans[5];
    for (int i = 0; i < 5; i += 1) {
      ans[i] = 0;
    }
    while (n > 0) {
      int slag = n % 10;
      if (slag != 0) {
	      if (d != 1) {
	        slag *= d;
	      }
        cnt += 1;
      }
      ans[ind] = slag;
      ind += 1;
      d *= 10;
      n /= 10;
    }
    std::cout << cnt << '\n';
    for (int i = 0; i < 5; i += 1) {
      if (ans[i] != 0) {
        std::cout << ans[i] << " ";
      }
    }
    std::cout << '\n';
  }
  return 0;
}
