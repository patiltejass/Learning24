#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main(){
    int ele_toremove=11;
    vector<int> vec = {11, 23, 11, 23, 24, 25, 380, 450, 350, 450, 11};

    for(int i=0;i<vec.size();i++){
        vec.erase(remove(vec.begin(),vec.end(),ele_toremove),vec.end());
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" -> ";
    }
    return 0;
}