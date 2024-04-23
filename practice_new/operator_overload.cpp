#include<iostream>
using namespace std;

class overload{
    private:
    int a,b;
    public:
    overload(){}
    overload(int a,int b):a(a),b(b){}
    overload operator+(overload &temp){
        temp.a=a+temp.a;
        temp.b=b+temp.b;
        return temp;
    }
    void print(){
        cout<<a<<b<<endl;
    }
};
int main(){
    overload obj1(2,4);
    overload obj2(3,5);
    overload obj3;
    
    obj3=obj1+obj2;
    obj3.print();
    return 0;
}