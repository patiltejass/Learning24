#include<iostream>
#include<stdlib.h>
using namespace std;

void *operator new(size_t val){
    void *ptr = malloc(val);
    if(ptr){
        return ptr;
    }
    else{
        throw bad_alloc();
    }
}
void operator delete(void *ptr) noexcept{
    free(ptr);
}
int main(){

return 0;
}

void *operator new[](size_t val)
{
    void *ptr = malloc(val);
    if (ptr)
    {
        return ptr;
    }
    else
    {
        throw bad_alloc();
    }
}
