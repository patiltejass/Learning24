#include<iostream>
using namespace std;
class data{
    private:
    int a;
    public:
    data(int a):a(a){}
   //pre_increment
    data operator++(){
        ++a;
        return *this;
    }
    data operator++(int){
        data temp=*this;
        ++(*this);
        return temp;
    }
};