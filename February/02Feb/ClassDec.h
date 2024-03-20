#include <iostream>
#include <string>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
class Student
{
private:
    int rollno;
    string name;
    string classs;
    string address;
    list<string> numbers;
    list<string> subjects;  
    string grade;
    list<string> sports;

public:
    Student(int rno, string Name, string Classs, string Address, list<string> Numbers, list<string> Subjects, string Grade, list<string> Sports) : rollno(rno), name(Name), classs(Classs), address(Address), numbers(Numbers), subjects(Subjects), grade(Grade), sports(Sports) {}

    int getRoll()
    {
        return this->rollno;
    }
    bool Rollpresent(int RNo)
    {
        if (this->rollno == RNo)
            return true;
        return false;
    }
    string getName()
    {
        return this->name;
    }

    bool Namepresent(string Nme)
    {
        if (this->name == Nme)
            return true;
        return false;
    }
    string getClass()
    {
        return this->classs;
    }
    string getAddress()
    {
        return this->address;
    }
    list<string> getContact()
    {
        return this->numbers;
    }
    list<string> getSubjects()
    {
        return this->subjects;
    }
    bool Subspresent(string Sub)
    {
        for (auto i : this->subjects)
            if (i == Sub)
                return true;
        return false;
    }
    string getGrades()
    {
        return this->grade;
    }

    bool Gradepresent(string Grd)
    {
        if (this->grade == Grd)
            return true;
        return false;
    }
    list<string> getSports()
    {
        return this->sports;
    }

};