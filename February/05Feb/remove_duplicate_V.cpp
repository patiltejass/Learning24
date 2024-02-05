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
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i : vec)
    {
        cout << i << " -> ";
    }
}