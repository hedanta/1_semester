#include <iostream>

int main() {
  int a;
  int m;
  std::cin >> a >> m;
  bool stop = 0;
  long long cur_num = a;
  for (int i = 0; i < 30; i += 1) {
    cur_num += (cur_num % m);
    if (cur_num % m == 0) {
      stop = 1;
      break;
    }
  }
  std::cout << (stop ? "Yes" : "No");
  return 0;
}
