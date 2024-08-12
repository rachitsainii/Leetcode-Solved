class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        int age = 0;
        for(int i = 0; i < details.size(); i++){
            char age1 = details[i][11]; 
            char age2 = details[i][12];
            int age = (age1 - '0') * 10 + (age2 - '0');
            // cout << age;
           if(age > 60){
            ans++;
           }

        }

        
        return ans;
    }
};