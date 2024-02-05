#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
    vector<int> vec = {11, 23, 11, 23, 24, 25, 380, 450, 350, 450, 11};
    vector<int> ans;
    sort(vec.begin(), vec.end());
    for(int i=0;i<vec.size()-1;i++){
        if(vec[i]!=vec[i+1]){
            ans.push_back(vec[i]);
        }
    }
    for(int i:ans){
        cout<<i<<" -> ";
    }
return 0;
}