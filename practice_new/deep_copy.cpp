#include<iostream>
using namespace std;
class deepcopy{
    int a;
    int *b;
    deepcopy(int a,int *b):a(a),b(b){}
    deepcopy(deepcopy &temp){
        this->a=temp.a;
        if(temp.b!=nullptr){
            this->b=new int(*temp.b);
        }
    }
};
class assignment{
    int a;
    int *b;
    assignment(int a, int *b) : a(a), b(b) {}
    assignment operator=(assignment &temp){
        this->a = temp.a;
        if (temp.b != nullptr){
            this->b = new int(*temp.b);
        }
        return *this;
    }
};