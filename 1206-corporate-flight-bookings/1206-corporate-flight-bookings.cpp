class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> total(n);
        for(auto i : bookings){
            int start = i[0];
            int end = i[1];
            int x = i[2];

            total[start-1] += x;
            if(end < n){
                total[end] -= x;
            }
           
        }

        vector<int> ans;
        long sum = 0;
        for(int i = 0; i < total.size(); i++){
            sum += total[i];
            ans.push_back(sum);
        }

        return ans;
    }
};