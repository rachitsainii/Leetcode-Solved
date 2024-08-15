class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dic{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        vector<int> num;

       for(auto i : s){
        if(dic.find(i) != dic.end()){
            num.push_back(dic[i]);
        }
       }

       for(auto i : num){
            cout << i << " ";
        }
        int sum = 0;
        for(int j = 0; j < num.size(); j++){
            if(j < num.size() - 1 && num[j] < num[j+1]){
                sum += (num[j+1] - num[j]);
                j++;
            } else {
                sum += num[j];
            }
        }

        
        return sum;
    }
};