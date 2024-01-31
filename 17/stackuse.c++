#include <iostream>
using namespace std;
#include "stack1.h"
int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    Stack<int> s;
    s.push(n1);
    s.push(n2);
    cout << "Data at top is " << s.top() << endl;
    cout << "Data popped is " << s.pop() << endl;
    s.push(n3);
    cout << "Data at top is " << s.top() << endl;
    if (s.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
    cout << "Data popped is " << s.pop() << endl;
    cout << "Data popped is " << s.pop() << endl;
    if (s.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}
