#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Tejas{
    public:
    int a;
    int b;
    int c;
    Tejas(int a,int b,int c):a(a),b(b),c(c){}

};
class compare{
  public:
  bool operator()(Tejas &obj1,Tejas &obj2){
        return obj1.a > obj2.a;
  }  
};

int main(){

    Tejas t1(1,2,3);
    Tejas t2(4,5,6);
    Tejas t3(7,8,9);
    vector<Tejas> vec;
    vec.push_back(t1);
    vec.push_back(t2);
    vec.push_back(t3);
    compare c;
    sort(vec.begin(),vec.end(),c);


return 0;
}

