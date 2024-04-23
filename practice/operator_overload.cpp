#include<iostream>
using namespace std;
class values{
    private:
    int a,b;
    public:
    values(){}
    values(int x,int y){
        a=x;
        b=y;
    }
    void print (){
        cout<<a<<endl;
        cout<<b<<endl;
    }
    values operator+(values &temp){
        values temp1;
        temp1.a=a+temp.a;
        temp1.b=b+temp.b;
        return temp1;
    }
};
int main(){
    values v1(10,20);
    values v2 (20,30);
    values v3;
    v3=v2+v1;
    v3.print();
    return 0;
}
