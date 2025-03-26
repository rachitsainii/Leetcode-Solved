class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> dim;
        for(auto i : grid){
            for(auto j : i){
                dim.push_back(j);
            }
        }


        sort(dim.begin(), dim.end());

        int median = dim[dim.size() / 2];
        int ops = 0;
        for(int i = 0; i < dim.size(); i++){
            int absDiff = abs(median - dim[i]);

            if(absDiff % x != 0){
                return -1;
            }

            ops += abs(dim[i] - median) / x;
        }

        return ops;
    }
};