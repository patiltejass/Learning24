#include <iostream>
#include <string>
using namespace std;

/*int Sum(int x, int y)
{
    return x + y;
}

double Sum(double x, double y)
{
    return x + y;
} */

template <class T>
T Sum(T x, T y)
{
    return x + y;
}

int main()
{
    std::cout << Sum(2, 3) << endl;
    std::cout << Sum(2.12, 3.21) << endl;
    string st = "Delta";
    string st1 = "India";
    std::cout << Sum<string>(st, st1) << endl;
}