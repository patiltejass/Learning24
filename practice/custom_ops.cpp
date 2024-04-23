#include<iostream>
#include<vector>
#include<map>
#include<string>
//using namespace std;
class data{
    private:
    int n;
  std::string b;
    public:
        data(int x, std::string s) : n(x), b(s) {}
        bool operator<(const data &other) const
        {
            return this->n < other.n;
        }
};
int main(){
    std::map<int,data> da;
    data d1(2,"Tejas");
    data d2(3,"amar");
    da.insert(std::make_pair(1, d1));
    da.insert(std::make_pair(2, d2));

    return 0;

}