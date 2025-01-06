class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            int total = 0;
            for(int j = 0; j < n; j++){
                if(boxes[j] == '1'){
                    total += abs(i-j);
                }
            }

            ans.push_back(total);
        }

        return ans;
    }
};