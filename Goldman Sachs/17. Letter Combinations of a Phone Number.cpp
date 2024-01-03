/*

Question: Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Question Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> ans;
    string temp;
    string map[11] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(int i, std::string digits)
    {
        if (i == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        int currDigit = digits[i] - '0';
        std::string s = map[currDigit];
        for (auto &it : s)
        {
            temp.push_back(it);
            solve(i + 1, digits);
            temp.pop_back();
        }
    }

    std::vector<std::string> letterCombinations(std::string digits)
    {
        // base case when
        if (digits.size() == 0)
            return ans;

        solve(0, digits);
        return ans;
    }
};
