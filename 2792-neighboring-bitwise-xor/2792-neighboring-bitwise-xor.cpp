class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = derived[0];
        for(int i = 1; i < derived.size(); i++){
            x ^= derived[i];
        }

        if(x == 0){
            return true;
        } else {
            return false;
        }
    }
};