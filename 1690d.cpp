#include <iostream>
#include <algorithm>
#include <string>

int main() {
  int test = 0;
  std::cin >> test;

  for (int iTest = 0; iTest < test; iTest += 1) {
    int n;
    int k;
    std::string str = "";

    std::cin >> n >> k >> str;

    int seq_b_count = 0;
    int b_count = 0;
    int max_seq_b = 0;

    for (int iSt = 0; iSt < n; iSt += 1) {
      if (str[iSt] == str[iSt + 1] && str[iSt] == 'B'
        && iSt != n - 1) {
        seq_b_count += 1;
        b_count += 1;
      }

      else if (str[iSt] == 'B') {
        b_count += 1;
        seq_b_count += 1;
      }

      else {
        if (seq_b_count > max_seq_b) {
          max_seq_b = seq_b_count;
          seq_b_count = 0;
        }
      }
    }

    if (k == n) {
      std::cout << k - b_count << '\n';
    }

    else if (max_seq_b >= k) {
      std::cout << "0\n";
    }

    else {
      std::cout << k - max_seq_b << '\n';
    }
  }
  return 0;
}
