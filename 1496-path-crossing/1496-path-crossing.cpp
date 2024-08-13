class Solution {
public:
    bool isPathCrossing(string path) {
        set<vector<int>> coordinates;
        coordinates.insert({0,0});
         int sum_n_s = 0;
         int sum_e_w = 0;
        for(int i = 0; i < path.size(); i++){
            if(path[i] == 'N'){
                sum_n_s++;
            } else if(path[i] == 'S'){
                sum_n_s--;;
            } else if(path[i] == 'E'){
               sum_e_w++;
            }else if(path[i] == 'W'){
               sum_e_w--;
            }

            if(coordinates.find({sum_n_s, sum_e_w}) != coordinates.end()){
                return true;
            } else {
                coordinates.insert({sum_n_s, sum_e_w});
            }
        }

        return false;
    }
};