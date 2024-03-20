#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string str ="AABCCCDEEEFF";
    vector<int> vec(26,0);
    for(int i=0;i<str.size();i++){
        vec[str[i]-'A']++;
    }
    for(auto i:vec){
        cout<<i<<" ";
    }
return 0;
}

