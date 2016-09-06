/*
 * 如何不适用'+' '- '*' '/'实现加法运算
 */
class AddWithoutPlus{
    public:
        int getSum(int a, int b) {
            if(b == 0) {
                return a;
            }
            int cxor = a^b;
            int cand = (a&b)<<1;
            return getSum(cxor, cand);
        }
};

/*
 * 1.用亦或先做不进位加法
 * 2.用与计算需要进位的并左移1位
 * 对这个两个结果求和即可,但是求和又出现进位问题
 * 所以继续递归1、2步,这样直到b==0时所有的值都被加到了a中,此时返回a.
 */

