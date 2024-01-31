template <typename T>

class Stack
{
private:
    int capacity;
    int topp;
    T *data;
    
    public:
    Stack()
    {
        capacity = 10;
        topp = -1;
        this->data = new T[10];
    }
    void push(T value)
    {
        if (topp == capacity - 1)   resize();
        
        data[++topp] = value;
        cout << "data inserted sucessfully"<<endl;
    }
    T pop(){
        if(topp == -1){
            cout<<"stack is empty"<<endl;
            return T();
        }
        else{
            return data[topp--];
        }
    
    }
    T top(){
        return data[topp];
    }

    bool isEmpty(){
        return (topp == -1 );
    }
    void resize(){
        int newcap = capacity*2;
        T *newdata= new T[newcap];
        for (int i = 0; i < capacity; i++)
        {
            newdata[i]=data[i];
        }
        delete data;
        capacity = newcap;
        data=newdata;
    }


};