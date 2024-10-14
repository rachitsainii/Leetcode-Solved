class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> heap(nums.begin(), nums.end());

        unsigned long score = 0;
        while(k > 0){
            int max = heap.top();
            heap.pop();
            score += max;
            heap.push(ceil(max / 3.0));
            k--;
        }

        return score;
    }
};