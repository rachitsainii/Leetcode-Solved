class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_set<string> available(supplies.begin(), supplies.end());
    vector<string> result;

    bool check = true;

    while(check){
        check = false;

        for(int i = 0; i < recipes.size(); i++){
            if(available.count(recipes[i])){
                continue;
            }

            bool flag = true;
            for(auto i : ingredients[i]){
                if(!available.count(i)){
                    flag = false;
                    break;
                }
            }

            if(flag){
                available.insert(recipes[i]);
                result.push_back(recipes[i]);
                check = true;
            }
        }
    }

    return result;
    }
};