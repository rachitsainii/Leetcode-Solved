class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int count_negative = 0;
        int smallest = INT_MAX;
        for(auto i : matrix){
            for(auto j : i){
                if(j < 0){
                    count_negative++;
                }
            }
        }

        //cout << count_negative << endl;

        for(auto i : matrix){
            for(auto j : i){
                ans += abs(j);
            }
        }

        if(count_negative % 2 == 0){
           return ans;
        } else {
            for(auto i : matrix){
                for(auto j : i){
                    if(abs(j) < smallest){
                        smallest = min(smallest, abs(j));
                    }
                }
            }
            cout << smallest << endl;
            ans -= 2*abs(smallest);
            return ans;
        }
    }
};