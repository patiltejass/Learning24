#include <iostream>
using namespace std;

class Tejas
{
private:
    int a;
    int b;

public:
    Tejas(){};
    Tejas(int x, int y) : a(x), b(y){};
    Tejas& operator+(Tejas &temp)
    {
        Tejas *newTemp = new Tejas();
        newTemp->a = temp.a + this->a;
        newTemp->b = temp.b + this->b;
        return *newTemp;
    }
    void print()
    {
        cout << a << endl;
        cout << b << endl;
    }
};
int main()
{
    Tejas t1(2, 4);
    Tejas t2(3, 4);
    Tejas t3(t1 + t2);
    t3.print();
    return 0;
}
