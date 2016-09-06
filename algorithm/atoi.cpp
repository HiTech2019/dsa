/*
 * String to Integer (atoi)
 * 时间复杂度O(n)，空间复杂度O(1)
 */
class Solution {
    public:
        int myAtoi(string str) {
            const int len = str.length();
            int sign = 1;
            int sum = 0;
            int n = 0;
            while(n < len && str[n] == ' ') {
                n++;
            }
            if(str[n] == '+') {
                n++;
            }
            if(str[n] == '-') {
                sign = -1;
                n++;
            }
            for(int i = n; i < len; i++) {
                if(str[i] < '0' || str[i] > '9') {
                    break;
                }
                if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
                    return sign == -1 ? INT_MIN : INT_MAX;
                }
                sum = sum * 10 + str[i] - '0';
            }
            return sum * sign;
        }
};

