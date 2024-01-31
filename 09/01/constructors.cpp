#include <bits/stdc++.h>
using namespace std;
class Student
{
    int age;
    const int birthYear;
    char *name;

public:
    Student(int age, int birthYear, char *name) : birthYear(birthYear), age(age), name(new char[strlen(name) + 1])
    {
        strcpy(this->name, name);
    }

    // copy constructor TODO
    Student(const Student &obj) : birthYear(obj.birthYear)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->name = new char[strlen(obj.name) + 1];
            strcpy(this->name, obj.name);
        }
    }

    Student& operator=(const Student &obj) : birthYear(obj.birthYear)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->name = new char[strlen(obj.name) + 1];
            strcpy(this->name, obj.name);
        }
    }

    void print()
    {
        cout << "my name is " << this->name << " and age is " << this->age << " " << this->birthYear << endl;
    }
};
class Student
{
    int age;
    const int birthYear;
    char *name;

public:
    Student(int age, int birthYear, char *name) : birthYear(birthYear), age(age), name(new char[strlen(name) + 1])
    {
        strcpy(this->name, name);
    }

    // copy constructor TODO
    Student(const Student &obj) : birthYear(obj.birthYear)
    {
        if (this != &obj)
        {
            this->age = obj.age;
            this->name = new char[strlen(obj.name) + 1];
            strcpy(this->name, obj.name);
        }
    }

    Student &operator=(const Student &obj) : birthYear(obj.birthYear)
    {
        if (this)
        {
            delete this->name;
        }
        if (this != &obj)
        {
            this->age = obj.age;
            this->name = new char[strlen(obj.name) + 1];
            strcpy(this->name, obj.name);
        }
        return *this;
    }

    void print()
    {
        cout << "my name is " << this->name << " and age is " << this->age << " " << this->birthYear << endl;
    }
};
int main()
{
    Student s1(22, 2001, "Tejas");
    Student s2;
    s2 = s1;
    s2 = s2;
    return 0;
}
