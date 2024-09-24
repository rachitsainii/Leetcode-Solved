class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<string, int> counts;
        for(auto num: arr1){
            string strNum = to_string(num);
            string prefix = "";
            for(char ch : strNum){
                prefix += ch;
                counts[prefix]++;
            }
        }

        // for(auto [key, val] : counts){
        //     cout << key << ":" << val ;
        //     cout << endl;
        // }

        for(int num : arr2){
            string strNum = to_string(num);
            string prefix = "";
            for(char ch : strNum){
                prefix += ch;
                if(counts.find(prefix) != counts.end()){
                    ans = max(ans, int(prefix.length()));
                }
            }
        }

        return ans;
    }
};