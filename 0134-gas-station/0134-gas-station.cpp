class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas = 0;
        int sum_cost = 0;
        for(int i = 0; i < gas.size(); i++){
            sum_gas += gas[i];
            sum_cost += cost[i];
        }

        if(sum_gas < sum_cost ){
            return -1;
        } 

        int starting_index = 0;
        int net_gas = 0;
        for(int i = 0; i < gas.size(); i++){
            net_gas += gas[i] - cost[i];
            if(net_gas < 0){
                starting_index = i + 1;
                net_gas = 0;
            } 

            
        }

        return starting_index;

    }
};