// class Solution {
// public:
//     long long countOfSubstrings(string word, int k) {
//         int p1 = 0;
//         int p2 = k + 5 - 1;
//         int ans = 0;
//         unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
//         //unordered_set<char> check;
//         while(p2 < word.size()){
//             unordered_set<char> check;
//             int consonants = k;
//             for(int i = p1; i <= p2; i++){
//                 if(s.find(word[i]) != s.end()){
//                     check.insert(word[i]);
//                 } else {
//                     consonants--;
//                 }
//             }

//             if(consonants == 0 && check != s){
//                 p1++;
//                 p2++;
//             }

//             if(check == s && consonants == 0){
//                 ans++;
//                 p1++;
//                 p2++;
//             } else {
//                 p1++;
//                 p2++;
//             }

//         }

//         return ans;
//     }
// };


class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int frequencies[2][128] = {};
        frequencies[0]['a'] = frequencies[0]['e'] = frequencies[0]['i'] = frequencies[0]['o'] = frequencies[0]['u'] = 1;

        long long response = 0;
        int currentK = 0, vowels = 0, extraLeft = 0, left = 0;

        for (int right = 0; right < word.length(); right++) {
            char rightChar = word[right];

            if (frequencies[0][rightChar]) {
                if (++frequencies[1][rightChar] == 1) vowels++;
            } else {
                currentK++;
            }

            while (currentK > k) {
                char leftChar = word[left++];
                if (frequencies[0][leftChar]) {
                    if (--frequencies[1][leftChar] == 0) vowels--;
                } else {
                    currentK--;
                }
                extraLeft = 0;
            }

            while (vowels == 5 && currentK == k && left < right && frequencies[0][word[left]] && frequencies[1][word[left]] > 1) {
                extraLeft++;
                frequencies[1][word[left++]]--;
            }

            if (currentK == k && vowels == 5) {
                response += (1 + extraLeft);
            }
        }

        return response;
    }
};