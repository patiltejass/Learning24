#include<iostream>
using namespace std;
class base{
    private:
    int a,b;
    public:
    base(int x,int y){
        a=x;
        b=y;
    }
    virtual int ADD(int x,int y){
        return x+y;
    }
};
class dereived:public base{
    private:
    int a;
    int b;
    public:
        // dereived(int x, int y)
        // {
        //     a = x;
        //     b = y;
        // }
    dereived(int a,int b):base(a,b){};
     int  ADD(int a,int{
        return a-b;
    }

};
int main(){
    base * p = new dereived(2,4);
    cout<<p->ADD(7,6);
}