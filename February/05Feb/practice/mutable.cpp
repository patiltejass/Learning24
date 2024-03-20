#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Tejas{
    public:
    int a;
    mutable int d;
    Tejas(int a,int b,int c):a(a),d(0){}
    void mut() const{
        d=10;
    }
};
int main(){

return 0;
}

