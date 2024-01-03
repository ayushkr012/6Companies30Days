/*
Question : You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

Trim each number in nums to its rightmost trimi digits.
Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
Reset each number in nums to its original length.
Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

Note:

To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
Strings in nums may contain leading zeros.


Question Link : https://leetcode.com/problems/kth-smallest-number-after-trimming/


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the Kth smallest number after trimming digits
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int numQueries = queries.size();
        vector<int> result;

        for (int i = 0; i < numQueries; ++i)
        {
            // Extracting values from the query
            int k = queries[i][0]; // k is the KthSmallest number
            int t = queries[i][1]; // no of digits to trim from last

            // Creating a vector of pairs to store trimmed numbers and their original indices
            vector<pair<string, int>> trimmedNumbers;
            int index = 0;

            // Extracting last 't' digits from each number and storing in the vector
            for (auto &num : nums)
            {
                string trimmed = num.substr(num.size() - t, t);
                trimmedNumbers.push_back({trimmed, index++});
            }

            // Sorting the vector based on trimmed numbers
            sort(trimmedNumbers.begin(), trimmedNumbers.end());

            // Storing the index of Kth smallest trimmed number
            result.push_back(trimmedNumbers[k - 1].second);
        }

        return result;
    }
};