#include<iostream>
class tejas{
    private:
    int a;
    int *b;
    public:
    tejas(int a,int *b):a(a),b(b){}
    tejas(tejas&temp){
        this->a=temp.a;
        if(temp.b!= nullptr){
            this->b=new int(*temp.b);
        }
    }
    tejas operator=(tejas &other){
        if(this!=&other){
            this->a=other.a;
            if(this->b!=nullptr){
                this->b=new int(*other.b);
            }
        }
        return *this;
    }
};