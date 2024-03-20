#include<iostream>
using namespace std;

class Tejas{
    public:
    virtual void dosomething()=0;
    virtual ~Tejas()=0;
};
Tejas::~Tejas(){
    cout<<"Tejas Destructor Called"<<endl;
}
class Patil : public Tejas{
    public:
    void dosomething(){
        cout<<"Patil class called"<<endl;
    }
    void printsomething(){
        cout<<"Print Something Called"<<endl;
    }
    ~Patil(){
        cout<<"Patil Destructor Callled"<<endl;
    }
};
int main(){

    Tejas *t1 = new Patil;
    t1->dosomething();
    Patil *p1 = dynamic_cast<Patil*>(t1);
    p1->printsomething();
    delete t1;
    delete p1;
return 0;
}

