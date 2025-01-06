class Solution {
public:
    vector<int> minOperations(string boxes) {

        // Brute Force - O(n^2), O(1)
        // int n = boxes.size();
        // vector<int> ans;

        // for(int i = 0; i < n; i++){
        //     int total = 0;
        //     for(int j = 0; j < n; j++){
        //         if(boxes[j] == '1'){
        //             total += abs(i-j);
        //         }
        //     }

        //     ans.push_back(total);
        // }

        // return ans;

        // Optimal Solution
        // Reducing the complexity to O(n)
        
        vector<int> ans;
        int n = boxes.size();
        vector<int> leftToRight(n);
        vector<int> rightToLeft(n);

        int sum = boxes[0] - '0';
        leftToRight[0] = sum;
        for(int i = 1 ; i  < n; i++){
            sum += (boxes[i] - '0');
            leftToRight[i] = sum;
        }

        int sum_2 = boxes[n-1] - '0';
        rightToLeft[n-1] = sum_2;

        for(int i = n-2; i >= 0; i--){
            sum_2 += (boxes[i] - '0');
            rightToLeft[i] = sum_2; 
        }

        vector<int> left(n);
        vector<int> right(n);

        left[0] = 0;
        int sum_3 = 0;
        for(int i = 0; i < n-1; i++){
            sum_3 += leftToRight[i];
            left[i+1] = sum_3;
        }

        for(auto i : left){
            cout << i << " ";
        }

        cout << endl;

        int sum_4 = 0;
        for(int i = 0; i < n; i++){
            sum_4 += rightToLeft[i];
        }

        for(int i = 0; i < n; i++){
            right[i] = sum_4 - rightToLeft[i];
            sum_4 -= rightToLeft[i];
        }

        for(int i = 0 ; i < n; i ++){
            ans.push_back(left[i] + right[i]);
        }

        return ans;

    }
};