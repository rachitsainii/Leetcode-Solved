class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int size = strs.size() - 1;
        string smallest = strs[0];
        string largest = strs[size];
        string ans = "";

        for(int i = 0 ; i < smallest.size(); i++){
            if(smallest[i] == largest[i]){
                ans += smallest[i];
            } else {
                return ans;
            }
        }

        for(auto i : strs){
            cout << i << " ";
        }

        return ans;
    }
};