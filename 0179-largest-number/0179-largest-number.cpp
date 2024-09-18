class Solution {
public:
    string largestNumber(vector<int>& nums) {

        // Convert each integer to a string.
        vector<string> strNums;
        for(auto i : nums){
            strNums.push_back(to_string(i));
        }

        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b){
            return a+b > b+a;
        });

        if(strNums[0] == "0"){
            return "0";
        }

        string ans;
        for(auto i : strNums){
            ans += i;
        }

        return ans;
    }
};