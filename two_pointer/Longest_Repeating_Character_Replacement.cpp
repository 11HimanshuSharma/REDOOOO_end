#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int left = 0;
    int right = 0;
    unordered_map<char, int> mp;
    int maxFreq = 0;
    int maxi = 0;

    // Iterate through the string with the right pointer
    while (right < s.length()) {
      mp[s[right]]++;
      maxFreq = max(maxFreq, mp[s[right]]);

      // If the current window size minus the frequency of the most common character is greater than k, shrink the window from the left
      while ((right - left + 1) - maxFreq > k) {
        mp[s[left]]--;
        if (mp[s[left]] == 0) {
          mp.erase(s[left]);
        }
        left++;
      }

      // Update the maximum length of the window
      maxi = max(maxi, right - left + 1);
      right++;
    }
    return maxi;
  }
};

int main() {
  Solution solution;
  string s = "AABABBA";
  int k = 1;
  int result = solution.characterReplacement(s, k);
  cout << "The length of the longest substring with at most " << k << " replacements is: " << result << endl;
  return 0;
}