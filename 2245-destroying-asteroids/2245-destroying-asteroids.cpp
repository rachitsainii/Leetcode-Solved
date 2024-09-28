class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        bool ans = true;
        long long total = mass;
        for(auto i : asteroids){
            if(i > total){
                return false;
            } else {
                total += i;
            }
        }

        return ans;
    }
};