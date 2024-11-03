class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        int window = goal.size()-1;
        string x = s + s;

        int left = 0;
        for(int right = window; right < x.size(); right++){
            int start = left;
            string curr = "";
            while(start <= right){
                curr += x[start];
                start++;
            }
            
            cout << curr << endl;

            if(curr == goal){
                return true;
            }

            left++;
        }


        return false;
    }
};