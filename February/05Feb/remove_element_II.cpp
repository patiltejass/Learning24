#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
    int ele_toremove = 11;
    vector<int> vec = {11, 23, 11, 23, 24, 25, 380, 450, 350, 450, 11};
    vector<int> ans;
    for (int i : vec)
    {
        if (i != ele_toremove)
        {
            ans.push_back(i);
        }
    }
    return 0;
}