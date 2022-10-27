//https://codeforces.com/problemset/problem/935/B
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <string>
#include <array>

int main() {
    int n = 0;
    std::cin >> n;

    std::string way = "";
    std::cin >> way;

    int curx = 0;
    int cury = 0;


    int money = 0;

    for (int iSt = 0; iSt < way.size() - 1; iSt += 1) {
        if (way[iSt] == 'U') {
            curx += 1;
        }

        else {
            cury += 1;
        }
        if (curx - cury == 0) {
            if (way[iSt] == way[iSt + 1]) {
                money += 1;
            }
        }
    }

    std::cout << money;
    return 0;
} 
