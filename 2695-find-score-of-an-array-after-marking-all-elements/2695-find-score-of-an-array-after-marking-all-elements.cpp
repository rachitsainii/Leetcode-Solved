class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;

        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> marked(nums.size(), false);


        for(int i = 0 ; i < nums.size(); i++){
            pq.push({nums[i], i});
        }

        while(!pq.empty()){
            int val = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if(marked[index] == true){
                continue;
            } else {
                score += val;
                marked[index] = true;
                if(index > 0){
                    marked[index-1] = true;
                }

                if(index + 1 < nums.size()){
                    marked[index + 1] = true;
                }
            }
           
        }


        return score;


    }
};