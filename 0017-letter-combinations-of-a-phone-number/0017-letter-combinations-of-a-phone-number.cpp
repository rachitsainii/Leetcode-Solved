class Solution {
public:

    vector<string> result;

    unordered_map<char, string> m = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

    void backtrack(int index, string &digits, string &temp){
        if(index >= digits.size()){
            result.push_back(temp);
            return;
        }

        char ch = digits[index];
        string str = m[ch];

        for(int i = 0; i < str.size(); i++){
            temp.push_back(str[i]);
            backtrack(index+1, digits, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        string temp = "";
        backtrack(0, digits, temp);

        return result;

    }
};