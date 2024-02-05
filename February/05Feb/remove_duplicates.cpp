#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
int main(){
    

vector<int> vec = {11, 23, 11, 23, 24, 25, 380, 450, 350, 450, 11};
vector<int>ans;
bool flag = false;
ans.push_back(vec[0]);
for(int i=1;i<vec.size();i++){
    flag=false;
    for(int j=0;j<ans.size();j++){
        if(vec[i]==ans[j]){
            flag=false;
            break;
        }
        else{
            flag=true;
        }
    }
    if(flag){
        ans.push_back(vec[i]);
    }
}
for(int i:ans){
    cout<<i<<" ";
}
return 0;
}