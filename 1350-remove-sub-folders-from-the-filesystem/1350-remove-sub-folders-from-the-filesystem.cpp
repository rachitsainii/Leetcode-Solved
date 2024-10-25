class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result = {folder[0]};

        for(int i = 1; i < folder.size(); i++){
            if(folder[i].find(result.back() + "/")!= 0){
                result.push_back(folder[i]);
            }
        }


        return result;
    }
};