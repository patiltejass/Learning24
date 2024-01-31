#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
using namespace std;
int main()
{

    map<int, pair<vector<string>, list<string>>> mp;
    int n;
    cout << "Enter the number of students:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int roll_no;
        list<string> st;
        string name, classs, Address;
        cout << "Enter the roll no:" << endl;
        cin >> roll_no;
        cout << "Enter the name:" << endl;
        cin.ignore(256, '\n');
        getline(cin, name); 
        cout << "Enter the class:" << endl;
        //cin.ignore(256, '\n');
        getline(cin, classs);
        cout << "Enter the Address:" << endl;
        //cin.ignore(256, '\n');
        getline(cin, Address);
        int no;
        cout << "Enter the no. of Numbers:" << endl;
        cin >> no;
        for (int i = 0; i < no; i++)
        {
            string numb;
            cout << "Enter the Numbers:" << endl;
            cin >> numb;
            st.push_back(numb);
        }
        mp[roll_no] = {{name, classs, Address}, st};
    }
    for (auto i : mp)
    {
        cout << "Roll No: " << i.first << " || ";
        cout << "Name : " << i.second.first[0] << " || ";
        cout << "Class : " << i.second.first[1] << " || ";
        cout << "Address :" << i.second.first[2] << " || ";
        cout << "Phone Numbers: (";
        for (auto j : i.second.second)
        {
            cout << j << " ,";
        }
        cout << ")" << endl;
    }
    return 0;
}
