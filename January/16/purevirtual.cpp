#include <bits/stdc++.h>
using namespace std;
class Animal
{

public:
    int age;
    int *ptr;

    Animal() = 0;
    virtual ~Animal() = 0;
};

Animal ::~Animal()
{
    cout << "Animal destroyed" << endl;
};

class Dog : public Animal
{
public:
    Dog(int age)
    {
        cout << "Dog created" << endl;
    }
    void sound()
    {
        cout << "Bark" << endl;
    }
    ~Dog()
    {
        cout << "Dog destroyed" << endl;
            
    }
};
int main()
{

    return 0;
}
