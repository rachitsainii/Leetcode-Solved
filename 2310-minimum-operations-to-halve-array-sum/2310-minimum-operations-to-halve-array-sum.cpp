class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap(nums.begin(), nums.end());
        double sum = 0;
        int ans = 0;
        for(double i : nums){
            sum += i;
        }

        sum /= 2;

        while( sum > 0){
            ans++;
            double max = heap.top();
            heap.pop();
            sum -= max / 2;
            heap.push(max / 2);
        }

        return ans;
    }
};