#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of students:" << endl;
    cin >> n;
    map<int,pair<string,pair<string,pair<string,list<string>>>>> mp;
    for (int i = 0; i < n; i++)
    {
        int roll_no;
        list<string> l;
        string name, classs, Address;
        cout << "Enter the roll no:" << endl;
        cin>>roll_no;
        cout << "Enter the name:" << endl;
        cin.ignore();   
        getline(cin, name);
        cout << "Enter the class:" << endl;
        //cin.ignore();
        getline(cin, classs);
        cout << "Enter the Address:" << endl;
        //cin.ignore();
        getline(cin, Address);
        int no;
        cout << "Enter the no. of Numbers:" << endl;
        cin >> no;
        for (int i = 0; i < no; i++)
        {
            string numb;
            cout << "Enter the " << i + 1 << " Number:" << endl;
            cin >> numb;
            l.push_back(numb);
        }
        mp[roll_no] = make_pair(name, make_pair(classs, make_pair(Address, l)));
    }
    for(auto i:mp){
        cout << "Roll no: " << i.first << endl;
        cout << "Name: " << i.second.first << endl;
        cout << "Class: " << i.second.second.first << endl;
        cout << "Address: " << i.second.second.second.first << endl;
        cout << "Numbers: ";
        for(auto j:i.second.second.second.second){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}