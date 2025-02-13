class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        int ops = 0;

       while(!pq.empty()){

        long long x = pq.top();
        if(x >= k){
            break;
        }
        pq.pop();
        long long y = pq.top();
        pq.pop();

        long long new_ele = (2 * x + y);
        pq.push(new_ele);
        ops++;
       }

       return ops;

    }
};