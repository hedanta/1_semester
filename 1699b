#include <iostream>
#include <algorithm>
#include <string>

int main() {
  int test = 0;
  std::cin >> test;
  for (int iTest = 0; iTest < test; iTest += 1) {
    int n;
    int m;
    std::cin >> n >> m;
    std::string first = "";
    // создание универсальной первой строки
    char cur = '0';
    first += '1';
    for (int i = 1; i < m; i += 2) {
      first += cur;
      first += cur;
      cur = (cur == '1' ? '0' : '1');
    }
    // инвертирование строки
    std::string inverted = first;
    for (int i = 0; i < m; i += 1) {
      inverted[i] = (inverted[i] == '1' ? '0' : '1');
    }
    // таблица состоит только из обычной 
    // и инвертированной строк
    if (n == 2) {
      for (int i = 0; i < m; i += 1) {
        std::cout << first[i] << " ";
      }
      std::cout << '\n';
      for (int i = 0; i < m; i += 1) {
        std::cout << inverted[i] << " ";
      }
    }
    // матрица большего размера
    else {
      // вывод первой строки
      for (int i = 0; i < m; i += 1) {
        std::cout << first[i] << " ";
      }
      std::cout << '\n';
      int cnt = 0;
      bool inv = 1;
      bool last = 0;
      // вывод пар строк обычных/инвертированных
      for (int iRow = 0; iRow < n - 2; iRow += 1) {
        if (inv == 1) {
          for (int i = 0; i < m; i += 1) {
            std::cout << inverted[i] << " ";
          }
          cnt += 1;
          if (cnt == 2) {
            inv = 0;
            cnt = 0;
          }
          last = 0;
        }
        else {
          for (int i = 0; i < m; i += 1) {
            std::cout << first[i] << " ";
          }
          cnt += 1;
          if (cnt == 2) {
            cnt = 0;
            inv = 1;
          }
          last = 1;
        }
        std::cout << '\n';
      }
      // вывод последней строки в зависимости от предпоследней
      for (int i = 0; i < m; i += 1) {
        std::cout << (last == 1 ? inverted[i] : first[i]) << " ";
      }
    }
    std::cout << '\n';
  }
  return 0;
}
