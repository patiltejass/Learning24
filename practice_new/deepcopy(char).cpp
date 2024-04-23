#include<iostream>
using namespace std;

class deepcopy{
    private:
    int rollno;
    char* name;
    public:
    deepcopy(int rollno,char* name):rollno(rollno),name(new char[10]){};
    deepcopy(deepcopy &obj):rollno(obj.rollno){
        name=new char[strlen(obj.name)+1];
        strcpy(name,obj.name);
    }
    deepcopy &operator= (deepcopy &obj){
        if (&obj!=this)
        {
            rollno= obj.rollno;
            delete name;
            name=new char[strlen(obj.name)+1];
            strcpy(name,obj.name);
        }
        return *this;
    }
};