#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

// using typedef to avoid Confusion
typedef pair<string, string> NameClass;
typedef pair<string, list<string>> AddressContact;
typedef pair<list<string>, pair<string, list<string>>> GradeSports;
typedef pair<NameClass, pair<AddressContact, GradeSports>> Student;
//creating map in global scope
map<int, Student> mp;

//GetClass Function Declaration
string GetClass(int rollNum){
    return mp[rollNum].first.second;
}
//GetContacts Function Declaration
list<string> GetContacts(int rollNum){
    list<string> l;
    for(auto x : mp[rollNum].second.first.second){
        l.push_back(x);
    }
    l.sort();
    return l;
}
//GetSubjects Function Declaration
list<string> GetSubjects(int rollNum){
    list<string> l;
    for(auto x : mp[rollNum].second.second.first){
        l.push_back(x);
    }
    l.sort();
    return l;
}
//GetSubjectsWiseStudenNames Function Declaration
list<string> GetSubjectsWiseStudenNames(string subjectName){
    list<string> l;
    for(auto x : mp){
        for(auto y : x.second.second.second.first){
            if(y==subjectName){
                l.push_back(x.second.first.first);
            }
        }
    }
    return l;
}

//GetGradeWiseStudenNames Function Declaration
list<string> GetGradeWiseStudenNames(string grade){
    list<string> l;
    for (auto x : mp){
        if (x.second.second.second.second.first == grade)
        {
            l.push_back(x.second.first.first);
        }
    }
    return l;
}
//GetSportName Function Declaration
list<string> GetSportName(string student){
    list<string> l;
    for (auto x : mp){
        if (x.second.first.first == student)
        {   
            for(auto y : x.second.second.second.second.second){
                l.push_back(y);
            }
        }
    }
    return l;
}

int main()
{
    //inserting details of Student 1
    NameClass n1 = {"Manoj", "2"};
    AddressContact a1 = {"101, Future Tower, Pune", {"99xxxxxxxx", "11xxxxxxxx"}};
    GradeSports g1 = {{"Maths", "English"}, {"A", {"Cricket"}}};
    Student s1 ;//= {n1, {a1, g1}};
    mp[1]=s1;

    // inserting details of Student 2
    NameClass n2 = {"Dinesh", "3"};
    AddressContact a2 = {"104, Future Tower, Pune", {"88xxxxxxxx", "22xxxxxxxx"}};
    GradeSports g2 = {{"Maths", "English","Marathi","Hindi"}, {"A+", {"Football"}}};
    Student s2 = {n2, {a2, g2}};
    mp[2] = s2;

    // inserting details of Student 3
    NameClass n3 = {"Sunil", "4"};
    AddressContact a3 = {"1011, Future Tower, Pune", {"55xxxxxxxx", "44xxxxxxxx", "11xxxxxxxx"}};
    GradeSports g3 = {{"Maths", "English", "Marathi", "Hindi"}, {"B", {"Basketball","Cricket"}}};
    Student s3 = {n3, {a3, g3}};
    mp[3] = s3;

    // inserting details of Student 4
    NameClass n4 = {"Vivek", "6"};
    AddressContact a4 = {"1012, Future Tower, Pune", {"77xxxxxxxx", "87xxxxxxxx"}};
    GradeSports g4 = {{"Maths", "English", "Marathi", "Hindi","Computer"}, {"B", {"Hockey","Cricket"}}};
    Student s4 = {n4, {a4, g4}};
    mp[4] = s4;

    // inserting details of Student 5
    NameClass n5 = {"Sameer", "10"};
    AddressContact a5 = {"1014, Future Tower, Pune", {"66xxxxxxxx", "98xxxxxxxx"}};
    GradeSports g5 = {{"Maths", "English","Marathi","Hindi","Bio","Physics"},{"A++", {"Carrom","Baseball"}}};
    Student s5 = {n5, {a5, g5}};
    mp[5] = s5;
    int i;
    do
    {
    cout << "\n"
         << "1. Print All Details"
         << "\n"
         << "2. Print Class by Roll No"
         << "\n"
         << "3. Print Contact by Roll No"
         << "\n"
         << "4. Print Subjects by Roll No"
         << "\n"
         << "5. Print Subject wise Student Name"
         << "\n"
         << "6. Print Grade wise Student Name"
         << "\n"
         << "7. Print Sport Name by Roll No"
         << "Enter Your Choice :" << endl;
    cout<<"_______________________________________________________________________________________________________________"<<endl;
    cin>>i;
    switch(i){
        case 1:{
            //printing all details
            cout<<"All Details of Students"<<endl;
            cout<<"________________________________________________________________________________________________________"<<endl;
            for(auto i:mp){
                cout<<"Roll No: "<<i.first<<endl;
                cout<<"Name : "<<i.second.first.first<<endl;
                cout<<"Class : "<<i.second.first.second<<endl;
                cout<<"Address: "<<i.second.second.first.first<<endl;
                cout<<"Contact: ( ";
                for(auto j:i.second.second.first.second){
                    cout<<j<<" ";
                }
                cout<<")"<<endl;
                cout << "Subject: ( ";
                for (auto j : i.second.second.second.first)
                {
                    cout << j << " ";
                }
                cout << ")" << endl;
                cout << "Grade: "<<i.second.second.second.second.first<<endl;
                cout << "Sports: ( ";
                for (auto j : i.second.second.second.second.second)
                {
                    cout << j << " ";
                }
                cout << ")" << endl;
                cout<<"________________________________________________________________________________________________________"<<endl;
            }
        //break;
        }
        //Using GetClass function
        case 2:{
            int roll;
            cout<<"Enter Roll No: ";
            cin>>roll;
            cout<<"Class: "<<GetClass(roll)<<endl;
        //break;
        }
        //Using GetContacts function
        case 3:{
            int roll;
            cout<<"Enter Roll No: ";
            cin>>roll;
            cout<<"Contact: ";
            for(auto i:GetContacts(roll)){
                cout<<i<<" ";
            }
            cout<<endl;
        //break;
        }
        //Using GetSubjects function
        case 4:{
            int roll;
            cout<<"Enter Roll No: ";
            cin>>roll;
            cout<<"Subjects: ";
            for(auto i:GetSubjects(roll)){
                cout<<i<<"  ";
            }
        //break;
        }
        // Using SubjectsWiseStudentNames function
        case 5:{
            string Subject1;
            cout<<"Enter Subject: ";
            cin>>Subject1;
            cout<<"Students: (";
            for(auto i:GetSubjectsWiseStudenNames(Subject1)){
                cout<<i<<"  ";
            }
            cout<<")"<<endl;
        //break;
        }
        //UsingGetGradeWiseStudenNames function
        case 6:{
            string Grade;
            cout<<"Enter Grade: ";
            cin>>Grade;
            cout<<"Students: ";
            for(auto i:GetGradeWiseStudenNames(Grade)){
                cout<<i<<"  ";
            }
        //break;
        }
        //Using GetSportName function
        case 7:{
              string Student;
              cout<<"Enter Student: ";
              cin>>Student;
              cout<<"Sports: ";
              for(auto i:GetSportName(Student)){
                  cout<<i<<"  ";
              }
        //break;
        }
        default:
            cout<<"Invalid Choice"<<endl;
            break;
    }
    } while (i!=-1);
    cout<<"Thank You"<<endl;

}