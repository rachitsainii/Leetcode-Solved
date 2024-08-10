class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int left = 0;
        int right = 0;
        string small = "";

        // Fixed size window
        for( right = 0; right < k; right++){
            small += s[right];
            if(small[right] == 'a' || small[right] == 'e' || small[right] == 'i' || small[right] == 'o' || small[right] == 'u'){
                count++;
            }
        }

        int ans = count;
        for(int right = k; right < s.length(); right++){
            small += s[right];
            if(small[left] == 'a' || small[left] == 'e' || small[left] == 'i' || small[left] == 'o' || small[left] == 'u'){
                count--;
            }
            small.erase(left, 0);
            left++;
            if(small[right] == 'a' || small[right] == 'e' || small[right] == 'i' || small[right] == 'o' || small[right] == 'u'){
                count++;
            }

            ans = max(ans, count);

        }

        return ans;
    }
};