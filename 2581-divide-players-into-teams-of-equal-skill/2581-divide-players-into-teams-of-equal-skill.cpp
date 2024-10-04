class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        // Initialize the answer variable.
        long long chemistry = 0;
    
        // Find the size of the skill array
        int size = skill.size();
        
        // Sort the array
        sort(skill.begin(), skill.end());

        if(size == 2){
            return skill[0] * skill[size-1];
        } else {
            int i = 1;
            int j = size - 2;
            long sum = skill[0] + skill[size-1];
            long product = skill[0] * skill[size-1];
            chemistry = product;
            while(i < j){
                if(skill[i] + skill[j] != sum){
                    return -1;
                } else {
                    product = skill[i] * skill[j];
                    chemistry += product;
                    i++;
                    j--;
                }
            }

            return chemistry;
        }

    }
};