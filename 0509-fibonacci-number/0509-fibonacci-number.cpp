class Solution {
public:
    int fib(int n) {
        // Base Case (Mandatory)
        if(n == 0 || n == 1){
            return n;
        }

        // Processing (Optional)

        // Recursive Relation (Mandatory)
        int ans = fib(n-1) + fib(n-2);

        return ans;
        
    }
};