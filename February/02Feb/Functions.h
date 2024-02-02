#include "ClassDec.h"
using namespace std;
vector<Student> vec;
vector<Student *> vecpointer;


//Fuction 1: Implementation of GetClass Function return Class of Student from Roll No
string GetClass1(int Rno, Student *obj)
{
    if (obj->Rollpresent(Rno))
        return obj->getClass();
    return "";
}

//Function 2: Implementation of GetContacts Function returns Contact of Students by Names
list<string> GetContacts(int Rno, Student *obj)
{
    if (obj->Rollpresent(Rno))
        return obj->getContact();
    return {};
}

//Function 3: Implementation of GetSubjects Function returns Subjects of students by roll no
list<string> GetSubjects(int Rno, Student *obj)
{
    if (obj->Rollpresent(Rno))
        return obj->getSubjects();
    return {};
}
// Function 4: Implementation of GetSubjectsWiseStudentNames which returns Students Name by Subject

list<string> GetSubjectsWiseStudentNames(string subjctnme, Student *obj)
{
    list<string> SubjectsWiseStudentName;
    if (obj->Subspresent(subjctnme))
        for (auto i : obj->getSubjects())
        {
            if (i == subjctnme)
                SubjectsWiseStudentName.push_back(obj->getName());
        }
    return SubjectsWiseStudentName;
}

// Function 5: Implementation of GetGradeWiseStudentNames which returns Students Name by Grades
list<string> GetGradeWiseStudentNames(string grade, Student *obj)
{
    list<string> GradeWiseStudentNames;
    if (obj->Gradepresent(grade))
        GradeWiseStudentNames.push_back(obj->getName());
    return GradeWiseStudentNames;
};

// Function 6: Implementation of GetSportName which returns Sports Name by Student Name
list<string> GetSportName(string student, Student *obj)
{
    if (obj->Namepresent(student))
    {
        return obj->getSports();
    }
    return {};
}
// Function 7: Implemenation of NamePresent Function returns whether student is present or not
bool Namepresent(string Names)
{
    for (auto student : vec)
    {
        if (student.getName() == Names)
            return true;
    }
    return false;
}
//Function 8: Converts Vector to List
list<Student> vectortoList(vector<Student> &vec)
{
    list<Student> ans;
    for (auto i : vec)
    {
        ans.push_back(i);
    }
    return ans;
}

void print_list(list<string> &l)
{
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}