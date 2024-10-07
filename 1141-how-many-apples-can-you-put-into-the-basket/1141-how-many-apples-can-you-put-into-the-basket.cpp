class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int ans = 0;
        int sum = 0;
        int it = 0;
        while(sum <= 5000 && it < weight.size()){
            if(sum + weight[it] <= 5000){
                sum += weight[it];
                it++;
                ans++;
            } else {
                break;
            }  
        }

        return ans;
    }
};