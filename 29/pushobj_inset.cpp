#include <iostream>
#include <set>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(const std::string &n, int a) : name(n), age(a) {}
};

struct PersonComparator
{
    bool operator()(const Person &a, const Person &b) const
    {
        if (a.name == b.name)
        {
            return a.name < b.name;
        }
        return a.age < b.age;
    }
};

int main()
{
    std::set<Person, PersonComparator> personSet;

    personSet.insert(Person("Alice", 30));
    personSet.insert(Person("Bob", 25));
    personSet.insert(Person("Alice", 20));
    personSet.insert(Person("Charlie", 20));

    // Display the sorted set
    std::cout << "Sorted set of persons:\n";
    for (const auto &person : personSet)
    {
        std::cout << "Name: " << person.name << ", Age: " << person.age << "\n";
    }

    return 0;
}
