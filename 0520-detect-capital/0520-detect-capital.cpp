class Solution {
public:
    bool detectCapitalUse(string word) {
        string copy = word;
        string option1 = "";
        string option2 = "";
        string option3 = "";

       for(auto i : word){
         option1 += toupper(i);
         option2 += tolower(i);
       }

        option3 += toupper(word[0]);
       for(int i = 1; i < word.size(); i++){
        option3 += tolower(word[i]);
       }

       //cout << option1 << " " << option2 << " " << option3 << endl;

       if(copy == option1 || copy == option2 || copy == option3){
        return true;
       }

        return false;

    }
};