#include <iostream>
#include <queue>

int main() {
  long long n = 0;
  long long k = 0;
  std::cin >> n >> k;
  k = std::min(k, n * n);
  std::queue<int> q;
  for (int i = 0; i < n; i += 1) {
    int x = 0;
    std::cin >> x;
    q.push(x);
  }
  int cur_max = q.front();
  q.pop();
  int second = 0;
  for (long long i = 0; i < k; i += 1) {
    second = q.front();
    q.pop();
    if (cur_max < second) {
      q.push(cur_max);
      cur_max = second;
      i = 0;
    }
    else {
      q.push(second);
    }
  }
  std::cout << cur_max;
  return 0;
}
