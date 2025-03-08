class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int start = 0;
        int end = k-1;
        int recolor = 0;
        int ans = INT_MAX;
        while(end < blocks.size()){
            for(int i = start; i <= end; i++){
                if(blocks[i] == 'W'){
                    recolor++;
                }
            }

            ans = min(ans, recolor);
            recolor = 0;
            start++;
            end++;
        }

        return ans;
    }
};