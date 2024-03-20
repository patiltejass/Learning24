#include<iostream>
using namespace std;
class Tejas{
    private:
    public:

    virtual void dosomething()=0;
    virtual ~Tejas()=0;
};
Tejas::~Tejas(){
   cout<<"Destructor Called";
}
class Patil : public Tejas{
    public:

    void dosomething(){};
    ~Patil(){
        cout<<"Destruc Called";
    }
};


int main(){
    Patil p1;

return 0;
}

