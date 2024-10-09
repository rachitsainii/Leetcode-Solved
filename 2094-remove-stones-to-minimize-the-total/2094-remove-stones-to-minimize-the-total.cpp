class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());

        while(k > 0){
            int top = heap.top();
            top -= floor(top / 2.0);
            cout << top << endl;
            heap.pop();
            heap.push(top);
            k--;
        }

        int sum = 0;
        while(heap.size() > 0){
            sum += heap.top();
            heap.pop();
        }

        return sum;
    }
};