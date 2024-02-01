#include<bits/stdc++.h>
using namespace std;
template <typename T>

class temp{
    private:
    T first,second;
    public:
    temp(T x,T y){
        first =  x;
        second = y;
    }
    void getvalue(){
        cout<<first<<endl;
        cout<<second<<endl;
    }
};

int main(){

    temp<int> t1(2,4);
    temp <double> t2(2.4 , 5.3);
    temp<string> t3("Tejas","Patil");
    t1.getvalue();
    t2.getvalue();
    t3.getvalue(); 
    return 0;
}

