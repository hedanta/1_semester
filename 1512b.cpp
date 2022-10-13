//https://codeforces.com/problemset/problem/1512/A
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int test = 0;
    std::cin >> test;

    for (int iTest = 0; iTest < test; iTest += 1) {
        int n = 0;
        std::cin >> n;
        std::vector<std::vector<char>> table;

        int x1 = 0, y1 = 0;
        int x2 = 0, y2 = 0;
        bool first = 0;

        for (int iRow = 0; iRow < n; iRow += 1) {
            for (int iCol = 0; iCol < n; iCol += 1) {
                char c;
                std::cin >> c;
                table[iRow].push_back(c);
                std::cin >> table[iRow][iCol];
                if (c == '*') {
                    if (first) {
                        x2 = iRow;
                        y2 = iCol;
                    }
                    else {
                        x1 = iRow;
                        y1 = iCol;
                    }
                }
            }
        }

        table[x2][y1] = '*';
        table[x1][y2] = '*';

        for (int iRow = 0; iRow < n; iRow += 1) {
            for (int iCol = 0; iCol < n; iCol += 1) {
                std::cout << table[iRow][iCol];
            }
            std::cout << '\n';
        }

    }
    return 0;
} 