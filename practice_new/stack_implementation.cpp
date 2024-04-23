#include<iostream>
#include<vector>

using namespace std;
template<typename T>

class stack{
private:
    int *data;
    int capacity;
    int topp;
public:
    stack(){
        capacity=10;
        this->data=new T[10];
        topp=-1;
    }
    void push(T value){
        if(topp==capacity-1){
            resize();
        }
        data[topp++]=value;
    }
    T pop(){
        if(topp==-1){
            //stack is empty
            throw out_of_range("Stack is empty");
        }
        return data[topp--];
    }
    T top(){
        if (topp == -1)
        {
            // stack is empty
            throw out_of_range("Stack is empty");
        }
        return data[topp];
    }
    bool isEmpty(){
        return topp==-1;
    }
    void resize(){
        int newcap = capacity*2;
        T *newdata= new T[newcap];
        for(int i=0;i<capacity;i++){
            newdata[i]=data[i];
        }
        capacity=newcap;
        delete data;
        data= newdata;
    }
    void print(){
        int i=topp+1;
        while(i--){
            cout<<data[i]<<" ";
        }
    }
};
