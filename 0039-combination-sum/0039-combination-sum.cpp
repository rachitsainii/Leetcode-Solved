class Solution {
public:

    vector<vector<int>> result;

    void solve(int start, int n , int target, int sum, vector<int> &candidates, vector<int> &temp){
        if(sum == target){
            result.push_back(temp);
            return;
        }

        if(start > n){
            return;
        }

        if(sum > target){
            return;
        }

        // Take the first element
        temp.push_back(candidates[start]);
        solve(start, n, target, sum + candidates[start], candidates, temp);

        // Don't take first element
        temp.pop_back();
        solve(start+1, n, target, sum, candidates, temp);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int n = candidates.size()-1;
        solve(0, n, target, 0, candidates, temp);

        return result;
    }
};