#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Person
{
    string name;
    int age;
};

struct SortByAge
{
    bool operator()(const Person &a, const Person &b) const
    {
        return a.age < b.age;
    }
};

int main()
{
    vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

    sort(people.begin(), people.end(), SortByAge());

    for (const auto &person : people)
    {
        cout << person.name << " (" << person.age << " years)\n";
    }

    return 0;
}
