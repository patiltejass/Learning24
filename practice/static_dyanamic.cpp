#include<iostream>
using namespace std;
//static cast
// int main(){
//     double d =12.53;
//     int n;
//     n=static_cast<int>(d);
// }

// dynamic_cast
class base{
    private:
    int a,b;
    public:
    base(int a,int b):a(a),b(b){}
    int getter1(){
        return a;
    }
    int getter2(){  
        return b;
    }
    virtual int add(){
        return a+b;
    }
};
class dereived:public base{
    public:
    dereived(int a,int b):base(a,b){}
    int add(int a,int b){
        return a-b;
    }
    void print(){
        cout<<getter1()<<" "<<getter2();
    }
};
int main(){
    base *b1= new dereived(2,3); 
    b1->add();
    dereived *d1;
    d1= dynamic_cast<dereived*>(b1);
    d1->print();
}