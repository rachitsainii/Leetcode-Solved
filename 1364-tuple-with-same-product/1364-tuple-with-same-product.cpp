class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // int num_pairs = 0;
        // vector<pair<pair<int, int>, int>> p;
        // unordered_set<int> pro;
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         int product = nums[i] * nums[j];
        //         if(pro.find(product) != pro.end()){
        //             num_pairs += 2;
        //             pro.erase(product);
        //         } else {
        //            pro.insert(product);
        //         }
        //         p.push_back({{nums[i], nums[j]}, product});
        //     }
        // }

        // // for(auto i : p){
        // //     cout << i.first.first << "," << i.first.second << " " << i.second << endl;
        // // }

        // // for(int i = 0; i < p.size(); i++){
        // //     for(int j = i+1 ; j < p.size(); j++){
        // //         if(p[i].second == p[j].second){
        // //             num_pairs += 2;
        // //         }
        // //     }
        // // }

        // return 4 * num_pairs;

        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int product = nums[i] * nums[j];
                freq[product]++;
            }
        }
        int ans = 0;
        for(auto i : freq){
            if(i.second > 1){
                ans += 4 * (i.second) * (i.second - 1);
            }
        }

        return ans;
    }
};