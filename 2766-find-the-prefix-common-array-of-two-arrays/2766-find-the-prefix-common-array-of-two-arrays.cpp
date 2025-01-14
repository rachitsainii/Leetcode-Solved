class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;

        vector<int> c;

        for(int i = 0; i < A.size(); i++){
            freq[A[i]]++;
            freq[B[i]]++;
            int count = 0;
            for(auto i : freq){
                if(i.second == 2){
                    count++;
                }
            }

            c.push_back(count);
        }

        return c;
    }
};