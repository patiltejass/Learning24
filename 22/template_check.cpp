#include <bits/stdc++.h>
using namespace std;
template <typename T>

T func(T x, T y)
{
    double pi = 3;
    if (is_same<T, double>::value)
    {
        //cout << "tejas " << endl;
        pi= 3.14;
    }
    return x * y * pi;
}

int main()
{
    cout << "if int:" << func(2, 3) << endl;
    cout << "if double" << func(2.5, 3.5) << endl;
    // cout << "if string" << func<string>("Tejas ", "Patil ") << endl;

    return 0;
}
