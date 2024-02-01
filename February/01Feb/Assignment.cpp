#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;

typedef pair<string,string> NameClass;
typedef pair<string,list<string>> AddressContact;
typedef pair<list<string>, pair<string, list<string>>> GradeSports;
typedef pair<NameClass,pair<AddressContact,GradeSports>> Student;

map <int,Student> mp;

int main(){
    //AddressContact a1 = ;
    //GradeSports g1 = ;
    mp[1] = {{"Manoj", "2"}, {{"101, Future Tower, Pune", {"99xxxxxxxx", "11xxxxxxxx"}}, {{"Maths", "English"}, {"A", {"Cricket"}}}}};
    //mp[1] = s1;
    return 0;
}
