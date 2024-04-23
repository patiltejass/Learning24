#include<iostream>
using namespace std;
class copies{
    private:
    int a;
    int *b;
    public:
    copies(){}
    copies(int a,int *b):a(a),b(b){}
    void print(){
        cout<<a<<*b;
    }
    copies (copies &temp){
        a=temp.a;
        b=new int(*temp.b);
    }

};
int main(){
    int n=6;
    copies c1(2,&n);
    copies c2;
    c2= c1;
    c2.print();
}
