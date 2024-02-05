#include "ClassDec.h"
using namespace std;
vector<Student> vec;
vector<Student *> vecpointer;

string GetClass1(int Rno)
{
    for(auto v:vec){
        if(v.getRoll()==Rno)
            return v.getClass();
    }
}