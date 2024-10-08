#include <string>
#include<iostream>
using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    int n = s.size();
    if (n % 2 != 0) {
      // If the length of the string is odd, it's impossible to balance
      return -1;
    }

    int balance = 0;
    int swap = 0;
    for (auto c : s) {
      if (c == '[') {
        balance++;
      } else {
        balance--;
      }
      // If balance goes negative, we need a swap
      if (balance < 0) {
        swap++;
        balance = 1; // Reset balance to 1 after a swap
      }
    }
    return swap;
  }
};

int main() {
  Solution solution;
  string s = "[]][][";
  int result = solution.minSwaps(s);
  cout << "Minimum swaps to balance: " << result << endl;
  return 0;
}