#include<iostream>
using namespace std;

void increment(int y){
    int x =y;
    x++;
    x++;
    x++;
    //return x;
}
int main(){
    int a=10;
    increment(a);
    cout<<a<<endl;
    increment(a);
    cout<<a<<endl;
    increment(a);
    cout<<a<<endl;
    increment(a);
    cout<<a<<endl;

    return 0;
}

