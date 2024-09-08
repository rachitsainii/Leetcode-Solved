class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int new_num = 0;
        if(n == 1){
            return true;
        }
        while(n != 1){
            if(seen.find(n) != seen.end()){
            return false;
        } else {
            seen.insert(n);
            while(n > 0){
                int digit = n % 10;
                n = n / 10;
                new_num += digit * digit;
            }

            n = new_num;
            new_num = 0;
            for(auto i : seen){
                cout << i << " ";
                }
                cout << endl;
            }
        }
        
        return true;
    }
};