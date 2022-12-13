#include <iostream>
#include <string>

int main() {
  int test = 0;
  std::cin >> test;
  for (int iTest = 0; iTest < test; iTest += 1) {
    std::string str;
    std::cin >> str;
    int left_zero = str.size() - 1;
    int right_one = 0;
    for (int i = str.size() - 1; i > 0; i -= 1) {
      if (left_zero < 0 || str[left_zero] == '1') {
        break;
      }
      left_zero -= 1;
    }
    for (int i = 0; i < str.size(); i += 1) {
      if (right_one >= left_zero || str[right_one] == '0') {
        break;
      }
      right_one += 1;
    }
    std::cout << right_one - left_zero + 1 << '\n';
  }
  return 0;
}
