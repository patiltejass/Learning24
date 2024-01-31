#include <bits/stdc++.h>
using namespace std;
int main()
{
    int *ptr = new int(10);
    delete ptr;

    ptr = new int(20);
    delete ptr;

    ptr = nullptr;

    cout << *ptr << endl;
    return 0;
}