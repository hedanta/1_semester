//https://codeforces.com/problemset/problem/1512/B
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
  int test_num = 0;
  std::cin >> test_num;

  for (int iTest = 0; iTest < test_num; iTest += 1) {
    int table_size = 0;
    std::vector<std::vector<char>> table;
    
    std::cin >> table_size;

    //координаты двух углов
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    
    bool first_cell = true; //клетка с '*' встретилась впервые

    for (int iRow = 0; iRow < table_size; iRow += 1) {
      std::vector<char> cur_row;
      for (int iCol = 0; iCol < table_size; iCol += 1) {
        char element = ' ';

        std::cin >> element;
        cur_row.push_back(element);

        if (element == '*') {
          if (first_cell) {
            x1 = iRow;
            y1 = iCol;
            first_cell = false;
          }

          else {
            x2 = iRow;
            y2 = iCol;
          }
        }

      }

      table.push_back(cur_row);
    }

    //'*' в одной строке
    if (x1 == x2) {
      //положение двух других клеток в противоположной строке
      int ind_x = 0; //строка с двумя другими клетками

      if (x1 != 0 && x1 != table_size - 1) {
        ind_x = x1 + 1;
      }

      else {
        ind_x = table_size - 1 - x1;
      }

      table[ind_x][y1] = '*';
      table[ind_x][y2] = '*';
    }

    //'*' в одном столбце
    else if (y1 == y2) {
      //положение двух других клеток в противоположном столбце
      int ind_y = 0; //столбец с двумя другими клетками

      if (y1 != 0 && y1 != table_size - 1) {
        ind_y = y1 + 1;
      }

      else {
        ind_y = table_size - 1 - y1;
      }

      table[x1][ind_y] = '*';
      table[x2][ind_y] = '*';
    }

    //'*' в двух разных углах
    else {
      //клетки противоположны имеющимся
      table[x1][y2] = '*';
      table[x2][y1] = '*';
    }

    for (int iRow = 0; iRow < table_size; iRow += 1) {
      for (int iCol = 0; iCol < table_size; iCol += 1) {
        std::cout << table[iRow][iCol];
      }
      std::cout << '\n';
    }
  }
  return 0;
}
