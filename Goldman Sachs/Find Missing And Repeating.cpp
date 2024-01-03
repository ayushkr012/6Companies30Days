/*
Question: Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing 
and one number 'B' occurs twice in array. Find these two numbers.

Question Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // calculate the sum of all elements from 1 to n
        long long sum = (n * (n + 1)) / 2;

        // calculate the sum of all elements in the array
        long long arrSum = accumulate(arr.begin(), arr.end(), 0);

        int RepeatingNo, missingNo;
        unordered_map<int, int> um;

        // find the repeating number
        for (auto &it : arr)
        {
            um[it]++;
            if (um[it] > 1)
            {
                RepeatingNo = it; // here we get the repeating number
            }
        }

        // calculate the missing number
        for (int i = 1; i <= n; i++)
        {
            if (um[i] == 0)
            {
                missingNo = i;
                break;
            }
        }

        return {RepeatingNo, missingNo};
    }
};