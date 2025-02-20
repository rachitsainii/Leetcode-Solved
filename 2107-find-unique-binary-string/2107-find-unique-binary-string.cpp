class Solution {
public:

    bool found = false;

    void solve(unordered_set<string> &s, string &st, int n){
        if(st.size() == n){
            if(s.find(st) == s.end()){
                found = true;
                return;
            }

            return;
        }
        
        for(char ch = '0'; ch <= '1'; ch++){
            st.push_back(ch);
            solve(s, st, n);
            if(found) return ;
            st.pop_back();
        }
        
        
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> s(nums.begin(), nums.end());
        string st = "";
        solve(s, st, n);

        return st;
    }
};