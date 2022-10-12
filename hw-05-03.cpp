//hw-05-03
//BPM-22-2 Lebkova Marina

#include <iostream>
#include <cmath>
#include <iomanip>

int factorial(int number) 
{
    if (number == 0) {
        return 1;
    }

    int sum = 1;

    for (int i = 2; i <= number; i += 1) {
        sum *= i;
    }

    return sum;
}

int main() {
    double a = 0, b = 1, step = 0.1;
    double x = a;
    double y = 0;
    double element = 0;
    double eps = 0.0001;

    //column names
    std::cout << "   x   " << "|" << " s(x)  " << "|" << " f(x)\n";

    for (a; a <= b; a += step) {
        //x belongs to [a, b]
        x = a;
        //sum variable
        double s = 0;
        //control function
        double y = exp(2 * x);

        //sum of elements
        for (int i = 0; i < 1000; i += 1) {
            element = pow(2 * x, i) / factorial(i);
            
            if (std::abs(element) < eps) {
                break;
            }
            s += element;
        }
        std::cout << std::setw(6) << std::fixed << std::setprecision(3) << x << " | " << s << " | " << y << '\n';
    }
    return 0;
} 
