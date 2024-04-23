#include<iostream>
using namespace std;
class preinc{
    private:
    int a;
    preinc(){}
    preinc(int a):a(a){}
    preinc operator++() {
        ++a;
        return *this;
    }
    preinc operator++(int)
    {
        preinc temp = *this;
        ++(*this);
        return temp;
    }
};
