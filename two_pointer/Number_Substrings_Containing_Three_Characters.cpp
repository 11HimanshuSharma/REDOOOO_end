#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    int count = 0;
    vector<int> hash(3, -1);

    for (int i = 0; i < s.size(); i++) {
      hash[s[i] - 'a'] = i;
      if ((hash[0] >= 0 && hash[1] >= 0 && hash[2] >= 0)) {
        int mini = *min_element(hash.begin(), hash.end());
        count += mini + 1;
      }
    }
    return count;
  }
};

int main() {
  Solution solution;
  string s = "abcabc";
  int result = solution.numberOfSubstrings(s);
  cout << "Number of substrings containing all three characters: " << result << endl;
  return 0;
}