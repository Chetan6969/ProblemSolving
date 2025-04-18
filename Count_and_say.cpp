/*
Leetcode Problem 38: Count and Say

Problem Description:
The "count-and-say" sequence is a sequence of digit strings defined by the recursive formula:

- countAndSay(1) = "1"
- countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":
- Two '3's → "23"
- Three '2's → "32"
- One '5' → "15"
- One '1' → "11"
Resulting in "23321511"

Given a positive integer n, return the nth term of the count-and-say sequence.

Constraints:
- 1 ≤ n ≤ 30
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 1; i < n; ++i) {
            string temp = "";
            int len = result.length();

            for (int j = 0; j < len;) {
                char currentChar = result[j];
                int count = 0;

                while (j < len && result[j] == currentChar) {
                    ++count;
                    ++j;
                }

                temp += to_string(count) + currentChar;
            }

            result = temp;
        }

        return result;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the value of n (1 ≤ n ≤ 30): ";
    cin >> n;

    if (n < 1 || n > 30) {
        cout << "Please enter a value between 1 and 30." << endl;
        return 1;
    }

    string output = solution.countAndSay(n);
    cout << "countAndSay(" << n << ") = " << output << endl;

    return 0;
}
