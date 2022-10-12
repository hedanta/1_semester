//https://codeforces.com/problemset/problem/1559/A
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;

    for (int iTest = 0; iTest < t; iTest += 1) {
        int arrsize = 0;
        std::cin >> arrsize;
        std::vector<int> array(arrsize, 0);
        int ans = 0;

        for (int iNum = 0; iNum < arrsize; iNum += 1) {
            std::cin >> array[iNum];
        }

        //after some iterations, the answer will be ans & array[i]
        //so we can start from ans = array[0] and iterate it with array[i],
        //where i is in [1, arrsize)
        ans = array[0];

        for (int iNum = 1; iNum < arrsize; iNum += 1) {
            ans = ans & array[iNum];
        }
        std::cout << ans << '\n';
    }
    return 0;
} 