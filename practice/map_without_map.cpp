#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str= "adkjskdljdvba";
    vector<int> v(26,0);
    for(auto it:str){
        v[it-'a']++;
    }

    for (int i=0;i<v.size();i++){
        char c = 'a'+i;
        if(v[i]==0) continue;
        cout<<c<<" "<<v[i]<<endl;
    }
    
}