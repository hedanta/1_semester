//https://codeforces.com/problemset/problem/1140/A
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <vector>

int main() {
    int pages = 0;
    std::cin >> pages;
    std::vector<int> secret(pages + 2, 0);
    int maxpage = 0;
    int days = 0;

    for (int iPage = 1; iPage <= pages; iPage += 1) {
        std::cin >> secret[iPage];
    }

    maxpage = 1;

    for (int iPage = 1; iPage <= pages; iPage += 1) {
        if (maxpage < secret[iPage]) {
            //found new secret
            maxpage = secret[iPage];
        }

        if (maxpage < iPage + 1) {
            //stop reading if every current secret is known
            days += 1;
        }
    }

    std::cout << days;
    return 0;
} 