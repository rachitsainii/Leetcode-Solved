class Solution {
public:
    
    void reverseArr(vector<int> &v, int start, int end){
        int i = start;
        int j = end;
        while(i <= j){
            swap(v[i], v[j]);
            i++;
            j--;
        }   
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for(int i = 0;  i < n-1; i++){
            if(nums[i+1] < nums[i]){
                pivot = i;
            }
        }

        reverseArr(nums, 0, pivot);
        reverseArr(nums, pivot+1, n-1);
        reverseArr(nums, 0, n-1);

        for(int i = 0 ; i < n-1; i++){
            if(nums[i+1] < nums[i]){
                return false;
            }
        }

        return true;
    }
};