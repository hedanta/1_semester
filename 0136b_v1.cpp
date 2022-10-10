//https://codeforces.com/problemset/problem/136/b
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <cmath>
#include <string>

//convert into ternary
std::string to_ternary(int n) 
{
    std::string res = "";
    while (n > 0) {
        //add digit modulo 3 as a char to the beginning of a string
        res.insert(res.begin(), (n % 3) + '0');
        //next digit
        n /= 3;
    }
    return res;
}

int to_decimal(std::string t) 
{
    int res = 0;
    int numsize = t.size();

    for (int i = 0; i < numsize; i += 1) {
        //muliplying a digit by 3^(current_position)
        res += (t[i] - '0') * pow(3, numsize - i - 1);
    }
    return res;
}

int main() {

    int a = 0;
    int c = 0;

    std::cin >> a >> c;

    std::string a_3 = to_ternary(a);
    std::string c_3 = to_ternary(c);
    std::string b = "";
    
    //make strings the same size
    if (a_3.size() < c_3.size()) {
        a_3.insert(a_3.begin(), c_3.size() - a_3.size(), '0');
    }
    else if (c_3.size() < a_3.size()) {
        c_3.insert(c_3.begin(), a_3.size() - c_3.size(), '0');
    }

    //count b by substracting from c_3-number a_3-number modulo 3
    for (int i = 0; i < a_3.size(); i += 1) {
        b += abs((c_3[i] - '0') - (a_3[i] - '0') + 3) % 3 + '0';
    }

    std::cout << to_decimal(b);

    return 0;
} 
