#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    int max_len = 0;
    int countZeros = 0;
    
    while (right < nums.size()) {
      if (nums[right] == 0) {
        countZeros++;
      }
      
      while (countZeros > k) {
        if (nums[left] == 0) {
          countZeros--;
        }
        left++;
      }
      
      max_len = max(max_len, right - left + 1);
      right++;
    }
    
    return max_len;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;
  cout << "The longest sequence of 1s with at most " << k << " zeros is: " << solution.longestOnes(nums, k) << endl;
  return 0;
}