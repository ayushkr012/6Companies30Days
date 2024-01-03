#include <bits/stdc++.h>
using namespace std;

// +++++++++++++++++++++++++++++++++  Method 1 ++++++++++++++++++++++++++++++++++++++++++++++++

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int index, int k, int n)
    {
        if (temp.size() == k && n == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (index > 9)
        {
            return;
        }

        for (int i = index; i <= 9; i++)
        {
            temp.push_back(i);
            solve(i + 1, k, n - i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        solve(1, k, n);
        return ans;
    }
};

// +++++++++++++++++++++++++++++++++++  Method 2 +++++++++++++++++++++++++++++++++++++++++++


class Solution
{
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;

    void solve(int index, int k, int target)
    {
        if (temp.size() == k && target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (index > 9)
            return;

        // Picked the current element
        temp.push_back(index);
        solve(index + 1, k, target - index);
        temp.pop_back();

        // Not picked the current element
        solve(index + 1, k, target);
    }

    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        solve(1, k, n);
        return ans;
    }
};
