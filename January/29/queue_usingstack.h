//implement queue using stack
#include <stack>

class Queue {
private:
    std::stack<int> enqueueStack;
    std::stack<int> dequeueStack;

public:
    void enqueue(int value) {
        enqueueStack.push(value);
    }

    int dequeue() {
        if (dequeueStack.empty()) {
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        int front = dequeueStack.top();
        dequeueStack.pop();
        return front;
    }

    bool isEmpty() {
        return enqueueStack.empty() && dequeueStack.empty();
    }
};