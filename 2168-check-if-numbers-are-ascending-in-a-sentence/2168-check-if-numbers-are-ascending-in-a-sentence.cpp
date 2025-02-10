class Solution {
public:

    vector<string> stringToVector(string s){
        vector<string> ans;
        string k = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                ans.push_back(k);
                k = "";
            } else {
                k += s[i];
            }
        }

        ans.push_back(k);
        return ans;
    }

    bool isInteger(string s){
        for(auto i : s){
            if(!isdigit(i)){
                return false;
            }
        }

        return true;
    }

    bool areNumbersAscending(string s) {
        vector<string> x;
        vector<int> nums;
        x = stringToVector(s);
       for(auto i : x){
            if(isInteger(i)){
                nums.push_back(stoi(i));
            }
       }

       for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] >= nums[i+1]){
            return false;
        }
       }

       return true;
    }
};