#include<bits/stdc++.h>
using namespace std;

void strrev(string &x){
    int i= 0;
    int j= x.size()-1;
    while(i<=j){
        swap(x[i],x[j]);
        i++;
        j--;
    }
}
int intrev(int y){
    int rev=0;
    while (y>0){
        int temp=y%10;
        rev=(rev*10)+temp;
        y/=10;
    }
    return rev;
}
int main(){
    string str = "litap sajet";
    strrev(str);
    cout<<str<<endl;
    int a=intrev(1234);
    cout<<a;
return 0;
}

