//hw-05-02
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

    double a = 0, b = 1, step = 0.05;
    double x = a;
    double y = 0;
    double element = 0;
    double eps = 0.001;
    double pi = std::asin(1) * 2;

    //column names
    std::cout << "   x   " << "|" << " s(x)  " << "|" << " f(x)\n";

    for (a; a <= b; a += step) {

        //x belongs to [a, b]
        x = a;
        //sum variable
        double s = 0;
        //control function
        double y = (x * sin(pi/4)) / (1 - 2 * x * cos(pi/4));

        //sum of elements
        for (int i = 1; i < 1000; i += 1) {
            element = pow(x, i) * sin(i * pi/4);
            if (std::abs(element) < eps) {
                break;
            }
            s += element;
        }

        std::cout << std::setw(6) << std::fixed << std::setprecision(3) << x << " | " << s << " | " << y << '\n';
    }
    return 0;
} 