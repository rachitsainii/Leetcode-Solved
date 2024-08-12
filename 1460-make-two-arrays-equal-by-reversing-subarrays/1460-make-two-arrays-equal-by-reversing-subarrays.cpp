class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        /* 
        // Approach 1: Sort both arrays and compare.
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        if(arr == target){
            return true;
        } else{
            return false;
        }

        */

        // Approach 2: Hashmap

        unordered_map<int, int> targetMap, arrMap;
        for(int i = 0; i < target.size(); i++){
            targetMap[target[i]]++;
            arrMap[arr[i]]++;
        }

        if(arrMap == targetMap){
            return true;
        } else {
            return false;
        }
     }
};