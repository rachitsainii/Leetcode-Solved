class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap(nums.begin(), nums.end());
        int largest = 0;;
        while(k != 0){
            largest = heap.top();
            heap.pop();
            k--;
        }

        return largest;
    }
};