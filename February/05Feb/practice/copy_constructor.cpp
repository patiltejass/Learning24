#include <iostream>
using namespace std;

class Tejas
{
private:
    int a;
    int b;
    int *c;

public:
    Tejas() {}
    Tejas(int x, int y, int *z) : a(x), b(y), c(z) {}
    Tejas(Tejas &temp)
    {
        a = temp.a;
        b = temp.b;
        c = new int(*(temp.c));
        cout<<"copy constructor called";
    }
};
int main()
{
    int *z = new int(3);

    Tejas t1(1, 2, z);
    Tejas t2(t1);
    return 0;
}
