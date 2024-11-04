class Solution {
public:
    string compressedString(string word) {
        // string comp = "";
        // unordered_map<char, int> counts;
        // vector<char> order;

        // for(int i = 0; i < word.size(); i++){
        //     if(counts.find(word[i]) == counts.end()){
        //         order.push_back(word[i]);
        //     }
        //     counts[word[i]]++;

        // }

        // for(int i = 0; i < order.size(); i++){
        //     if(counts[order[i]] > 9){
        //         int rem = counts[order[i]] % 9;
        //         int times = counts[order[i]] / 9;
        //         while(times > 0){
        //             comp += '9';
        //             comp += order[i];
        //             times--;
        //         }

        //         comp += rem + '0';
        //         comp += order[i];
        //     } else {
        //         comp += counts[order[i]] + '0';
        //         comp += order[i];
        //     }
        // }

        // return comp;

        string comp = "";
        int pos = 0;
        while(pos < word.size()){
            int consecutiveCount = 0;
            char currentChar = word[pos];

            while(pos < word.size() && consecutiveCount < 9 && word[pos] == currentChar){
                consecutiveCount++;
                pos++;
            }

            comp += to_string(consecutiveCount) + currentChar;
        }

        return comp;

    }
};