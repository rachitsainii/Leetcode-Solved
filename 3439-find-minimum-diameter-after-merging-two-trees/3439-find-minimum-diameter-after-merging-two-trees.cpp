class Solution {
public:

    pair<int, int> BFS(unordered_map<int, vector<int>> &adj, int source){
        queue<int> q;
        q.push(source);

        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthestNode = source;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();

                farthestNode = curr;

                for(auto &ngbr : adj[curr]){
                    if(visited[ngbr] == false){
                        visited[ngbr] = true;
                        q.push(ngbr);
                    }
                }
            }

            if(!q.empty()){
                distance++;
            }
        }

        return {farthestNode, distance};
    }

    int findDiameter(unordered_map<int, vector<int>> &adj){
        // Step 1 - Find the farthest node from a random node - 0

        auto [farthestNode, dist] = BFS(adj, 0);

        // Step 2 - The farthestNode we get from above is nothing but one end of the diameter of adj


        // Step 3 - Find the farthest node from the node we got from above. That will be the other end of the diameter
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }
    
    unordered_map<int, vector<int>> buildAdj(vector<vector<int>> &edges){
        unordered_map<int, vector<int>> adj;

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }


    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1+1) / 2 + (d2 + 1) / 2 + 1;

        return max({d1, d2, combined});
    }
};