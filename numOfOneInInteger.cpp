#include<iostream>
using namespace std;

/*
 * 求一个二进制整数中1的个数
 */
class NumOfOneInInteger {
    public:
        int numOfOneInInteger1(int num) {
            int sum = 0;
            //while(num != 0) {
            //对负数不管用,因为负数右移时左边添加的是1,所以!=0永远成立
            for(int i = 0;i < 32; i++) {
                sum += (num & 1);   //简短精炼
                num >>= 1;
            }
            return sum;
        }

        //效率高一点
        int numOfOneInInteger2(int num) {
            int sum = 0;
            while(num != 0) {
                sum++;
                num = (num -1)&num;
                //num-1会把最右边的1变成0，但是他右边其他位又可能多出来1
                //和num做与运算，num和num-1右边对应位不可能同时为1
                //求&之后就为0,这样num最右边的1就没了
            }
            return sum;
        }
};

int main(void) {
    NumOfOneInInteger obj;
    //int num = obj.numOfOneInInteger1(-1);
    int num = obj.numOfOneInInteger2(-1);
    printf("%d\n", num);
    return 0;
}
