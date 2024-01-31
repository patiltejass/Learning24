#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of students:"<<endl;
    cin>>n;
    vector<pair<int,pair<vector<string>,set<string>>>> ans;
    for(int i=0;i<n;i++){
        int roll_no;
        vector<string> vec;
        set<string> number;
        string name,classs,Address;
        cout<<"Enter the roll no:"<<endl;
        cin>>roll_no;
        cout<<"Enter the name:"<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the class:"<<endl;
        //cin.ignore();
        getline(cin,classs);
        cout<<"Enter the Address:"<<endl;
        //cin.ignore();
        getline(cin,Address);
        vec.push_back(name);
        vec.push_back(classs);
        vec.push_back(Address);
        int no;
        cout<<"Enter the no. of Numbers:"<<endl;
        cin>>no;
        for(int i=0;i<no;i++){
            string numb;
            cout<<"Enter the "<<i+1<< " Number:"<<endl;
            cin>>numb;
            number.insert(numb);
        }
        ans.push_back({roll_no,{vec,number}});
    }
    cout << "Student Details are as Follows" << endl;
    for(int i=0;i<ans.size();i++){
        cout<<"__________________________________________________________________________________________________"<<endl;
        cout<<"Roll No. : "<<ans[i].first<<endl;
        cout<<"Name : "<<ans[i].second.first[0]<<endl;
        cout<<"Class : "<<ans[i].second.first[1]<<endl;
        cout<<"Address : "<<ans[i].second.first[2]<<endl;
        cout<<"Numbers : ";
        cout<<"( ";
        for(auto i:ans[i].second.second){
            cout<<i<<" ,";
        }
        cout<<")"<<endl;
    }
    cout<<"________________________________________________________________________________________________________"<<endl;

    return 0;
}
