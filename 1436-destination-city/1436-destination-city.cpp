class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> cityCount;
        string ans = "";
        for(int i = 0; i < paths.size(); i++){
            for(int j = 0; j < paths[i].size(); j++){
                cityCount[paths[i][j]]++;
            }
                
                // This is the most important part of this question. If the city at the 1st index(destination) exists in the table
                // then reduce it's count by one. In the end, the destination city will have a count of zero.
                if(cityCount.find(paths[i][1])!= cityCount.end()){
                cityCount[paths[i][1]]--;  
            } 
        }

        for(auto [key,val] : cityCount){
            cout << key << " " << val << endl;
        }

        for(auto [key, val] : cityCount) {
           if(val == 0){
                ans =  key;
           }
        }

        

        return ans;
    }
};