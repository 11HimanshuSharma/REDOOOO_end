#include<iostream>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if (n % 2 != 0){
            return -1;
        }
        stack<char> st;
        int swap = 0;

        for (auto c : s){
            if (c == '['){
                st.push('[');
            }
            else{
                if (!st.empty()){
                    st.pop();
                }
                else{
                    swap++;
                }
            }
        }
        return (swap + 1) / 2;
    }
};
int main() {
  Solution solution;
  string s = "[]][][";
  int result = solution.minSwaps(s);
  cout << "Minimum swaps needed: " << result << endl;
  return 0;
}