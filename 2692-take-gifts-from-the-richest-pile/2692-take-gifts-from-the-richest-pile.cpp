class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        while(k > 0){
            int x = pq.top();
            //cout << x << endl;
            pq.pop();
            k--;
            x = floor(sqrt(x));
            //cout << x << endl;
            pq.push(x);
        }

        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};