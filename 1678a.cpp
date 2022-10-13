//https://codeforces.com/problemset/problem/1678/A
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
        std::vector<int> v(n, 0);
        int zero = 0;

        for (int iNum = 0; iNum < n; iNum += 1) {
            std::cin >> v[iNum];
            if (v[iNum] == 0) {
                zero += 1;
            }
        }

        std::sort(v.begin(), v.end());

        int operations = 0;

        if (zero != 0) {
            operations = n - zero;
        }

        else {
            int para = 0;

            for (int iNum = 0; iNum < n - 1; iNum += 1) {
                if (v[iNum] == v[iNum + 1]) {
                    para = 1;
                    operations = n;
                    break;
                }
            }

            if (para == 0) {
                operations = n + 1;
            }
        }

        std::cout << operations << '\n';
    }
    return 0;
} 