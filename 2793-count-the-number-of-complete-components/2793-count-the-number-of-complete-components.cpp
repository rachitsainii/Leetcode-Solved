class Solution {
public:

    void bfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int source, int &v, int &e){
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            v++;
            e += adj[curr].size();

            for(int &ngbr : adj[curr]){
                if(!visited[ngbr]){
                    visited[ngbr] = true;
                    q.push(ngbr);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        int result = 0;


        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == true){
                continue;
            } else {
                int v = 0;
                int e = 0;
                bfs(adj, visited, i, v, e);

                if(v * (v-1) == e){
                    result++;
                }
            }
        }

        return result;

    }
};