class Solution {
public:
    int maximumSwap(int num) {
        
        string n = to_string(num);
        int size =  n.size();
        vector<int> m(size);
        m[size-1] = size-1;
        for(int i = size-2; i >= 0; i--){
            if(n[i] > n[m[i+1]]){
                m[i] = i;
            } else {
                m[i] = m[i+1];
            }
        }

        for(int i = 0; i < size; i++){
            if(n[i] < n[m[i]]){
                swap(n[i], n[m[i]]);
                break;
            }
        }

        return stoi(n);
    }
};