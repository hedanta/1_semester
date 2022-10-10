//v2
//https://codeforces.com/problemset/problem/136/b
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <cmath>
#include <string>

int main() {

    int a = 0;
    int c = 0;
    int b = 0;

    std::cin >> a >> c;

    int numsize = std::max(std::to_string(a).size(), std::to_string(c).size());
    int mupltiply = 1;

    //count b by substracting from c_3-number a_3-number modulo 3 
    //and converting to decimal by multiplying by 3^(current_pos)
    for (int i = 0; (a || c); i += 1) {
        b += (((c % 3) - (a % 3) + 3) % 3) * mupltiply;
        a /= 3;
        c /= 3;
        mupltiply *= 3;
    }

    std::cout << b;

    return 0;
} 