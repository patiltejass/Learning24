#include<iostream>
using namespace std;

class base{
    protected:
    int a,b;
    public:
    base(int a,int b):a(a),b(b){}
    virtual int sum(int a,int b){
        return a+b;
    } 
    void print(){
        cout << a << " " << b << endl;
    }
};
class dereived: public base{
    public:
    dereived(int a,int b):base(a,b){}
    int sum(int a,int b){
        return a-b;
    }
    void print(){
        cout<<a<<" "<<b<<endl;
    }
    int mul(int a,int b){
        return a*b;
    }
};
int main(){
    base *ptr = new dereived(3,4);
    ptr->sum(3,4);
    dereived *ptr1= dynamic_cast<dereived*>(ptr);
    ptr1->mul(3,5);
}