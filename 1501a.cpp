#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n = 0;
    std::cin >> n;
    std::vector<int> ar(1 + n); 
    std::vector<int> dep(1 + n);
    std::vector<int> tm(1 + n);
    for (int i = 1; i <= n; i += 1) {
      std::cin >> ar[i] >> dep[i];
      tm[i] = (dep[i] - ar[i] + 1) >> 1;
    }
    int delay = 0;
    for (int i = 1; i <= n; i += 1) {
      std::cin >> delay;
      ar[i] += delay;
    }
    for (int i = 1; i < n; i += 1) {
      if (ar[i] + tm[i] > dep[i]) {
        ar[i + 1] += ar[i] + tm[i] - dep[i];
      }
    }
    std::cout << ar.back();
    std::cout << "\n";
  }
  return 0;
}
