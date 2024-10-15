class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long one = 0;
        for(auto ch :s){
            if(ch == '1' ? one++ : ans+= one);
        }

        return ans;
    }
};