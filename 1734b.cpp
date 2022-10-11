//https://codeforces.com/problemset/problem/1734/B
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <string>

int main() {

    int t = 0;
    std::cin >> t;

    for (int iTest = 0; iTest < t; iTest += 1) {
        int n = 0;
        std::cin >> n;
        for (int iFloor = 0; iFloor < n; iFloor += 1) {
            for (int iRoom = 0; iRoom <= iFloor; iRoom += 1) {
                std::cout << (iRoom == 0 || iRoom == iFloor ? 1 : 0) << " ";
            }
            std::cout << '\n';
        }
    }

    return 0;
} 