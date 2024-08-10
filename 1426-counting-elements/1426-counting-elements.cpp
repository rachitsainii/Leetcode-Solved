class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        unordered_map<int, int> dic;
        for(int i = 0; i <arr.size(); i++){
            dic[arr[i]]++;
        }
        
        for(int j = 0; j < arr.size(); j++){
            if(dic.find(arr[j]) != dic.end() && dic.find(arr[j]+1) != dic.end()){
                count += 1;
            }
        
        }

        return count;
    }
};