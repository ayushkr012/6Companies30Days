/*

Question : You are given a 2D 0-indexed array of strings, access_times, with size n. For each i where 0 <= i <= n - 1, access_times[i][0] represents the name of an employee, and access_times[i][1] represents the access time of that employee. All entries in access_times are within the same day.

The access time is represented as four digits using a 24-hour time format, for example, "0800" or "2250".

An employee is said to be high-access if he has accessed the system three or more times within a one-hour period.

Times with exactly one hour of difference are not considered part of the same one-hour period. For example, "0815" and "0915" are not part of the same one-hour period.

Access times at the start and end of the day are not counted within the same one-hour period. For example, "0005" and "2350" are not part of the same one-hour period.

Return a list that contains the names of high-access employees with any order you want.


Question Link : https://leetcode.com/discuss/interview-question/398031/

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &nums)
    {
        // Create an unordered map to store employee IDs and their access times in a priority queue
        unordered_map<string, priority_queue<int, vector<int>, greater<int>>> um;

        // Populate the unordered map with employee IDs and corresponding access times
        for (auto &it : nums)
        {
            um[it[0]].push(stoi(it[1]));
        }

        // Vector to store the final result of high-access employees
        vector<string> ans;

        // Iterate over each employee in the unordered map
        for (auto &it : um)
        {
            int minAccessTime = numeric_limits<int>::max();    // Initialize minimum access time
            int count = 1;                                     // Initialize access count
            priority_queue<int, vector<int>, greater<int>> pq; // Priority queue to track the latest access times

            // Process each access time for the current employee
            while (!it.second.empty())
            {
                // Check conditions for updating minimum access time and count
                if (minAccessTime == numeric_limits<int>::max())
                {
                    minAccessTime = it.second.top();
                }
                else if (it.second.top() - minAccessTime < 100)
                {
                    count++;
                }
                else if (it.second.top() - minAccessTime >= 100)
                {
                    pq.pop();
                    if (pq.empty())
                        minAccessTime = it.second.top();
                    else
                        minAccessTime = pq.top();
                    count = 1;
                    if (it.second.top() - minAccessTime < 100 && !pq.empty())
                    {
                        count++;
                    }
                }

                // Push the current access time to the priority queue and pop from the original queue
                pq.push(it.second.top());
                it.second.pop();

                // Check if the access count is 3, and if so, add the employee ID to the result vector
                if (count == 3)
                {
                    ans.push_back(it.first);
                    break;
                }
            }
        }

        // Return the final result vector
        return ans;
    }
};