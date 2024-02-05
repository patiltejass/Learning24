#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
    vector<int> vec = {11, 23, 11, 23, 24, 25, 380, 450, 350, 450, 11};
    sort(vec.begin(), vec.end());
    int k ,j;
    for (int i = 0; i < vec.size()-1 ; i++){
        if (vec[i] == vec[i + 1]){
            j = i + 1;
            while (j < vec.size() - 1 && vec [j] == vec[i])     j++;
            vec.erase(vec.begin() + i+1, vec.begin() + j);
            }
    }
    for(int i:vec){
        cout<<i<<" -> ";
    }

}