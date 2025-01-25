class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // brute force -  > O(n^2) : TLE
        // int n = nums.size();

        // for(int i = 0; i < n; i++){ // O(n)
        //     while(true) {
        //         int smallValue = nums[i];
        //         int idx = -1;

        //         for(int j = i + 1; j < n; j++){ // O(n)
        //             if(abs(nums[i] - nums[j]) <= limit){
        //                 if(nums[j] < smallValue){
        //                     smallValue = nums[j];
        //                     idx = j;
        //                 }
        //             }
        //         }

        //         if(idx != -1){
        //             swap(nums[i], nums[idx]);
        //         } else {
        //             break;
        //         }
        //     }
        // }

        // return nums;

        // optimal 

        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());


        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupNum].push_back(vec[0]);

        for(int i = 1; i < n; i++){
            if(abs(vec[i] - vec[i-1]) > limit){
                groupNum+= 1;
            }

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);

        }

        // Build the answer - Merge the groups
        vector<int> result(n);
        for(int i =  0; i < n; i++){
            int num = nums[i];
            int group = numToGroup[num];
            // Smallest available number in the group
            result[i] = *(groupToList[group].begin());
            groupToList[group].pop_front(); // O(n) Operation

        }

        return result;
    }
};