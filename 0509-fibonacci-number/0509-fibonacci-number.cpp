class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1){
            return n;
        }

        int onePrev = fib(n-1);
        int twoPrev = fib(n-2);
        return onePrev + twoPrev;
    }
};