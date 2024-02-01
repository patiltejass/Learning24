#include <iostream>
#include <memory>
using namespace std;

class MyClass
{
public:
    MyClass(int value) : data(value)
    {
        cout << "Constructor called. Value: " << data << endl;
    }

    ~MyClass()
    {
        cout << "Destructor called. Value: " << data << endl;
    }

    void printData() const
    {
        cout << "Data: " << data << endl;
    }

private:
    int data;
};

int main()
{
    unique_ptr<MyClass> uniquePtr = make_unique<MyClass>(42);
    uniquePtr->printData();

    shared_ptr<MyClass> sharedPtr1 = make_shared<MyClass>(99);
    shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
    sharedPtr1->printData();
    sharedPtr2->printData();

    weak_ptr<MyClass> weakPtr = sharedPtr1;
    if (auto lockedPtr = weakPtr.lock())
    {
        cout << "Weak_ptr (locked): ";
        lockedPtr->printData();
    }
    else
    {
        cout << "The resource is no longer available." << endl;
    }

    return 0;
}
