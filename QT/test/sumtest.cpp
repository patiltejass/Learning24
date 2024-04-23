#include<sum.h>
#include<gtest/gtest.h>

using namespace testing;
TEST(SumTest, WhenGetValueisCalledThenitShouldReturnCorrectValue){
    sum obj;
    const int value=obj.getsum(4,6);
    EXPECT_EQ(10,value);
}
TEST(SumTest, GivenZeroValuesToGetSumThenShouldReturnZero){
    sum obj;
    const int x = obj.getsum(0,0);

    EXPECT_EQ(0, x);

}
TEST (SumTest,GivenFirstParamAsZeroWhenGetValueCalledThenitShouldReturnCorrectValue){
    sum obj;
    int arg1=0;
    int arg2=10;
    const int x=obj.getsum(arg1,arg2);
    EXPECT_EQ(arg2,x);
}
TEST (SumTest,GivenSecondParamAsZeroWhenGetValueCalledThenitShouldReturnCorrectValue){
    sum obj;
    int arg1=10;
    int arg2=0;
    const int x=obj.getsum(arg1,arg2);
    EXPECT_EQ(arg1,x);
}
TEST(SumTest,WhenGetStatusisCalledThenitShouldReturnCorrectValue){
    sum obj;
    const bool value = obj.getstatus();
    EXPECT_FALSE(value);
}
