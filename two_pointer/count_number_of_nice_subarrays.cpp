#include<iostream>
using namespace std;
#include<vector>



class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        int oddCount = 0;
        int prefixCount = 0;

        for (int right = 0; right < nums.size(); ++right) {
    
            if (nums[right] % 2 != 0) {
                oddCount++;
                prefixCount = 0;  
            }

        
            while (oddCount == k) {
                prefixCount++;
                if (nums[left] % 2 != 0) {
                    oddCount--;  
                }
                left++;
            }

         
            count += prefixCount;
        }

        return count;
    }
};
int main() {
  Solution solution;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  int result = solution.numberOfSubarrays(nums, k);
  cout << "Number of nice subarrays: " << result << endl;
  return 0;
}