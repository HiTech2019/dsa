/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * 也可以开一个数组，第一遍历进行格式化
 * 第二次遍历进行判断,只不过要遍历两次
 */
class ValidPalindrome {
    public:
        bool isPalindrome(string s) {
            int len = s.length();
            for(int pre = 0, tail = len - 1; tail - pre != 0 && tail - pre != -1;) {
                if(!(s[pre] >= '0' && s[pre] <= '9') && !(s[pre] >= 'a' && s[pre] <= 'z') && !(s[pre] >= 'A' && s[pre] <= 'Z')) {
                    pre++;
                    continue;
                }
                if(!(s[tail] >= '0' && s[tail] <= '9') && !(s[tail] >= 'a' && s[tail] <= 'z') && !(s[tail] >= 'A' && s[tail] <= 'Z')) {
                    tail--;
                    continue;
                }
                if(s[pre] >= 'a' && s[pre] <= 'z') {
                    s[pre] = s[pre] - 32;
                }
                if(s[tail] >= 'a' && s[tail] <= 'z') {
                    s[tail] = s[tail] - 32;
                }
                if(s[pre++] != s[tail--]) {
                    return false;
                }
            }
            return true;
        }
};
