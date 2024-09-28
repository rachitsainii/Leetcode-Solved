class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> list;
        int ans = -1;
        list.push_back(1);
        for(int i = 2; i <= n; i++){
            if(n % i == 0){
                list.push_back(i);
            } 
        }

        if(k > list.size()){
            return ans;
        } else {
            for(int i = 0; i < k; i++){
               ans = list[i];
            }
        } 
        return ans;
    }
};