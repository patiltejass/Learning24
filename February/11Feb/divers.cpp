#include<iostream>
#include<vector>
#include<string>
using namespace std;

void rec(int i, int j, int n, string path, vector<string> &ans, vector<vector<long long int>> &grid, vector<vector<bool>> &vis)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;

    if ((i == 0 && j == n - 1) || (i == n - 1 && j == n - 1))
    {
        ans.push_back(path);
        return;
    }

    if (vis[i][j] == true)
        return;

    vis[i][j] = true;
    if (grid[i][j] == 0)
        return;

    // recursion
    rec(i, j + 1, n, path + "R", ans, grid, vis);
    rec(i + 1, j, n, path + "D", ans, grid, vis);
    rec(i - 1, j, n, path + "U", ans, grid, vis);
    rec(i, j - 1, n, path + "L", ans, grid, vis);
    vis[i][j] = false;
}
int feasible(int n, int m, string path, vector<vector<long long int>> &grid)
{
    int i = 0, j = 0;
    int cap = m;

    for (char p : path)
    {
        int prev = grid[i][j];
        if (p == 'U')
            i--;
        if (p == 'D')
            i++;
        if (p == 'R')
            j++;
        if (p == 'L')
            j--;
        int curr = grid[i][j];

        cap -= (curr + prev);
        if (cap < 0)
            return -1;
        if (grid[i][j] == 9)
            cap = m;
    }
    return cap;
}
int main(){

    int n;
    cin >> n;

    vector<vector<long long int>> grid(n, vector<long long int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int m;
    cin >> m;

    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    rec(0, 0, n, "", ans, grid, vis);
    if(ans.size()==0){   
        cout<<"No Available paths";
        return 0;
    }
    else{
    cout<<"The Available Paths are :"<<endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
    }
    vector<pair<string, int>> res;

    for (auto i : ans)
    {
        cout << i << endl;

        int x = feasible(n, m, i, grid);
        if (x != -1)
        {
            res.push_back({i, x});
        }
    }
    if(res.size()==0)   cout<<"No Feasible Paths";
    else{
        cout << "The Feasible Paths are :" << endl;
        for(auto i:res){
            cout << i.first<<" "<<i.second << endl;
        }
    }
return 0;
}




