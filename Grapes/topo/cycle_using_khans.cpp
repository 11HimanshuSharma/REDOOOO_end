//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> inDegree(V,0);
        for (int i = 0; i < V;i++){
            for (auto adjNode : adj[i]){
                inDegree[adjNode]++;
            }
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0 ; i < V ; i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for (auto adjNode : adj[node]){
                inDegree[adjNode]--;
                if (inDegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        if (count == V){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends