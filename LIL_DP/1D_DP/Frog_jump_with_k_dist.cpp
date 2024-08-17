#include<iostream>
using namespace std;
#include<vector>


int Solve(int index,int maxSteps,vector<int> &cost,vector<int> &dp){
        if (index == 0){
            return 0;
        }
        if (dp[index] != -1){
            return dp[index];
        }
        int minLocalCost = INT_MAX;
        for (int i = 1 ; i <= maxSteps ; i++){
            if (index - i >= 0){
            int localCost = abs(cost[index] - cost[index - i]) + Solve(index - i, maxSteps, cost,dp);
            minLocalCost = min(localCost, minLocalCost);
            }
        }
        return dp[index] = minLocalCost;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        
        // there is not any mean to further optmise the code 
        dp[0] = 0;
        for (int i = 1 ; i < n ; i++){
            int minLocalCost = INT_MAX;
            for (int j = 1 ; j <= k ; j++){
                if (i - j >= 0){
                int LocalCost = abs(arr[i] - arr[i-j]) + dp[i - j];
                minLocalCost = min(LocalCost, minLocalCost);
                }
                
            }
            dp[i] = minLocalCost;
        }
        return dp[n-1];
        
    }