#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
  public:
    int totalFruits(vector<int>& arr) {
        unordered_map<int, int> basket;
        int left = 0, max_len = 0;

        for (int right = 0; right < arr.size(); ++right) {
            basket[arr[right]]++;

            // If more than 2 types are in the basket, move `left` pointer
            while (basket.size() > 2) {
                if (--basket[arr[left]] == 0) {
                    basket.erase(arr[left]);
                }
                left++;
            }

            max_len = max(max_len, right - left + 1);  // Update max length if current window is larger
        }

        return max_len;
    }
};
int main() {
  Solution solution;
  vector<int> fruits = {1, 2, 1, 2, 3, 2, 2, 2};
  int result = solution.totalFruits(fruits);
  cout << "Maximum number of fruits: " << result << endl;
  return 0;
}
