#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <utility>
using namespace std;

typedef int roll_no;
typedef string Name;
typedef string className;
typedef string Addresstype;
int main(){
    int n;
    cout << "Enter the number of students:" << endl;
    cin >> n;
    map<roll_no,pair<Name,pair<className,pair<Addresstype,list<string>>>>> mp;
    for (int i = 0; i < n; i++)
    {
        roll_no Roll_no;
        Name Name;
        className className;
        Addresstype Addresstype;
        list<string> l;
        cout << "Enter the roll no:" << endl;
        cin>>Roll_no;
        cout << "Enter the Name:" << endl;
        cin.ignore();   
        getline(cin,Name);
        cout << "Enter the class:" << endl;
        getline(cin,className);
        cout << "Enter the Addresstype:" << endl;
        getline(cin,Addresstype);
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
        mp[Roll_no] = make_pair(Name, make_pair(className, make_pair(Addresstype, l)));
    }
    cout<<"Displaying the data:" << endl;
    cout<<"_____________________________________________________________________________________________________________" << endl;
    for(auto i:mp){
        cout << "Roll no: " << i.first << "----";
        cout << "Name: " << i.second.first << "----";
        cout << "Class: " << i.second.second.first << "----";
        cout << "Addresstype: " << i.second.second.second.first << "----";
        cout << "Numbers: ( ";
        for(auto j:i.second.second.second.second){
            cout << j << ", ";
        }
        cout <<" )"<<endl;
        cout<<"__________________________________________________________________________________________________________" << endl;
    }
    return 0;
}