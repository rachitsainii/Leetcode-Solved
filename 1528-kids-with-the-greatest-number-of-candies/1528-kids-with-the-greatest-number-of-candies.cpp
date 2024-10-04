class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int> copy(candies);
        vector<bool> ans(candies.size(), false);
        sort(copy.begin(), copy.end());
        int largest = copy[copy.size() - 1];
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= largest){
                ans[i] = true;
            }
        }
        return ans;
    }
};