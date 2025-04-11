class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            string s = to_string(i);
            if(s.size() % 2 != 0){
                continue;
            } else {
                int mid = s.size() / 2;
                int left_sum = 0;
                for(int j = 0; j < mid; j++){
                    left_sum += s[j] - '0';
                }

                int right_sum = 0;
                for(int k = mid; k < s.size(); k++){
                    right_sum += s[k] - '0';
                }

                if(right_sum == left_sum){
                    ans++;
                }
            }
        }

        return ans;
    }
};