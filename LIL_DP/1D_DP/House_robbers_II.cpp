#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int Solve(int index,vector<int>&cost, vector<int> &dp){
        if (index == 0){
            return cost[index];
        }
        if (index < 0){
            return 0;

        }
        if (dp[index] != -1){
            return dp[index];
        }
        int pick = cost[index];
        if (index - 2 >= 0){
            pick += Solve(index - 2, cost , dp);
        }
        int notpick = 0 + Solve(index - 1, cost, dp);

        return dp[index] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        vector<int> cost1, cost2;
        vector<int> dp1(n,-1),dp2(n,-1);
        
        for (int i = 1; i < n ; i++){
            cost1.push_back(nums[i]);
        }
        for (int i = 0 ; i < n-1 ; i++){
            cost2.push_back(nums[i]);
        }
        int Loot1 = Solve(n-1-1,cost1,dp1);
        int Loot2 = Solve(n-1-1,cost2,dp2);
        return max(Loot1,Loot2);
    }
};