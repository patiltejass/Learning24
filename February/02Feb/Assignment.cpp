#include "Functions.h"
using namespace std;
int main()
{

    Student s1(1, "Manoj", "2", "101, Future Tower, Pune", {"99xxxxxxxx", "11xxxxxxxx"}, {"Maths", "English"}, "A", {"Cricket", "Football", "Hockey"});
    Student s2(2, "Dinesh", "3", "104, Future Tower, Pune", {"88xxxxxxxx", "22xxxxxxxx"}, {"Maths", "English", "Marathi", "Hindi"}, "A+", {"Football", "Cricket", "Hockey"});
    Student s3(3, "Sunil", "4", "1011, Future Tower, Pune", {"55xxxxxxxx", "44xxxxxxxx", "11xxxxxxxx"}, {"Maths", "English", "Marathi", "Hindi"}, "B", {"Basketball", "Cricket", "Football"});
    Student s4(4, "Vivek", "6", "1012, Future Tower, Pune", {"77xxxxxxxx", "87xxxxxxxx"}, {"Maths", "English", "Marathi", "Hindi", "Computer"}, "B", {"Cricket", "Football", "Hockey"});
    Student s5(5, "Vishal", "7", "1013, Future Tower, Pune", {"66xxxxxxxx", "77xxxxxxxx"}, {"Maths", "English", "Marathi", "Hindi", "Computer"}, "A", {"Cricket", "Football", "Hockey"});

    Student *s1pointer = &s1;
    Student *s2pointer = &s2;
    Student *s3pointer = &s3;
    Student *s4pointer = &s4;
    Student *s5pointer = &s5;
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);
    vec.push_back(s4);
    vec.push_back(s5);
    vecpointer.push_back(s1pointer);
    vecpointer.push_back(s2pointer);
    vecpointer.push_back(s3pointer);
    vecpointer.push_back(s4pointer);
    vecpointer.push_back(s5pointer);

    cout << "_________________________________________________________________________________" << endl;
    for (auto i:vecpointer)
    {
        string classss = GetClass1(1, i);
        cout << classss ;
    }
    cout<<endl;
    cout << "_________________________________________________________________________________" << endl;
    for (auto i : vecpointer)
    {
        list<string> cont = GetContacts(1, i);
        if (!cont.empty())
            print_list(cont);
    }
    cout << "_________________________________________________________________________________" << endl;
    for (auto i:vecpointer)
    {
        list<string> subs = GetSubjects(1, i);
        if (!subs.empty())
            print_list(subs);
    }
    cout << "_________________________________________________________________________________" << endl;
    for (auto i:vecpointer)
    {
        list<string> stusubs = GetSubjectsWiseStudentNames("Maths", i);
        if (!stusubs.empty())
            print_list(stusubs);
    }
    cout<<"_________________________________________________________________________________"<<endl;
    for (auto i:vecpointer)
    {
        list<string> grdsubs = GetGradeWiseStudentNames("A+", i);
        if (!grdsubs.empty())
            print_list(grdsubs);
    }
    cout << "_________________________________________________________________________________" << endl;

    for (auto i:vecpointer)
    {
        list<string> sprts = GetSportName("Manoj", i);
        if (!sprts.empty())
            print_list(sprts);
    }
    cout << "_________________________________________________________________________________" << endl;
    string ans;
    if (s1.Namepresent("Manoj"))
        ans = "True";
    ans = "False";
    cout<<ans<<endl;
    cout << "_________________________________________________________________________________" << endl;

    return 0;
}
