#include<bits/stdc++.h>
using namespace std;

void strcpy1(string &s,string &t){ 
    t.resize(s.size()+1);
    for(int i=0;i<s.length();i++)
        t[i]=s[i];
}
int main(){
    string str = "Tejas Patil";
    string str2;
    strcpy1(str,str2);
    
    cout<<str2<<endl;
}

