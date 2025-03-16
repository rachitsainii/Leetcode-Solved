class Solution {
public:

    bool isPossible(vector<int> &ranks, int cars, long long min_given){
        long long cars_done = 0;
        for(auto r : ranks){
            long long c2 = min_given/r;
            long long c = floor(sqrt(c2));

            cars_done += c;
        }

        return cars_done >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0;
        long long r = pow(10, 14);
        long long mid = l + (r - l) / 2;
        long long ans = 0;

        while(l < r){
            mid = l + (r - l) / 2;
            if(isPossible(ranks, cars, mid)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};