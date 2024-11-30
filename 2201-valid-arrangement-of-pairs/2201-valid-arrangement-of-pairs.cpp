class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        // Step 1: Build adjacency list - Graph
        unordered_map<int, vector<int>> adj;

        // Build indegree and outdegree
        unordered_map<int, int> indegree, outdegree;
        // Key : Node, Value: indegree


        for(auto edge: pairs){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); // U -> V
            outdegree[u]++;
            indegree[v]++;
        }

        // Find the start Node of the Euler Path
        int startNode = pairs[0][0];
        for(auto &it : adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }

        // Simply do DFS
        vector<int> EulerPath;  // To Store my Euler Path
        stack<int> st; // To Perform DFS

        st.push(startNode);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }

        // Build your result

        reverse(EulerPath.begin(), EulerPath.end());
        vector<vector<int>> result;
        for(int i = 0; i < EulerPath.size() - 1; i++){
            result.push_back({EulerPath[i], EulerPath[i+1]});
        }


        return result;

    }
};