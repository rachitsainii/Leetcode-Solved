class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor == -1){
            return 2147483647;
        }

        if(divisor < 0 && dividend < 0){
            int ans = abs(dividend) / abs(divisor);
            return ans;
        } else if(divisor < 0 || dividend < 0){
            int ans = abs(dividend) / abs(divisor);
            return -1 * ans;
        } else {
             return dividend / divisor;
        }
    }
};