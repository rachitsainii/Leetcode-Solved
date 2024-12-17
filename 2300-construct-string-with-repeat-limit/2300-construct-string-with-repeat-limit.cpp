class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> counts;
        priority_queue<pair<char, int>> pq;
        for(auto i : s){
            counts[i]++;
        }

        for(auto [key , val] : counts){
            pq.push({key, val});
        }

        
        string ans = "";

        while(!pq.empty()){
            if(pq.top().second <= repeatLimit){
                auto topEle = pq.top();
                pq.pop();
                for(int i = 1 ; i <= topEle.second; i++){
                    ans += topEle.first;
                }
            
            } else {
                auto topEle = pq.top();
                pq.pop();

                char topChar = topEle.first;
                int topCount = topEle.second;

                for(int i = 1; i <= repeatLimit; i++){
                    ans += topChar;
                }

                int new_val = topCount - repeatLimit;
                if(pq.empty()){
                    // No Smaller Element available
                    return ans;
                } else {
                    auto nextEle = pq.top();
                    pq.pop();
                    char nextChar = nextEle.first;
                    int nextCount = nextEle.second;

                    ans += nextChar;
                    int new_val2 = nextCount - 1;

                    if(new_val > 0){
                        pq.push({topChar, new_val});
                    }

                    if(new_val2 > 0){
                        pq.push({nextChar, new_val2});
                    }
                }
            }
        }


        return ans;
    } 
};