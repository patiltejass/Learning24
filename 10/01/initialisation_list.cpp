#include <iostream>
using namespace std;
class Name
{
    int x;

public:
    Name() { 
        cout << "Tejas" << endl; 
    }
    Name(int a) {
        cout << "patil" << endl; 
    }
    Name(const Name &obj) { 
        cout << "tejas patil" << endl; 
    }
    Name &operator=(const Name &obj) { 
        cout << "assginment" << endl; 
        }
};
class named
{
    Name _b;

public:
    named() { cout << "derrrivig" << endl; }
    named(Name &b)
    {
        _b = b;
        cout << "derived ";
    }
};

int main()
{

    Name b(10);
    named mc(b);
    return 0;
    // Write C++ code here

    return 0;
}