#include<queue>
#include<vector>
using namespace std;

#include<iostream>
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        // for (auto it : prerequisites){
        //     inDegree[it[1]]+
        // }
        vector<int> adj[numCourses];
        for (auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0 ; i < numCourses;i++){
            for (auto it : adj[i]){
                inDegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses ; i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()){
            int node  = q.front();
            q.pop();
            count++;
            for (auto adjNode : adj[node]){
                inDegree[adjNode]--;
                if (inDegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        if (count == numCourses){
            return true;
        }
        return false;
    }
};