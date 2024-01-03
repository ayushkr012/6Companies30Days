/*
Question : You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

Question Link: https://leetcode.com/problems/map-of-highest-peak/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the highest peak using BFS algorithm
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        // Using simple BFS algorithm
        queue<pair<int, int>> q;

        // Calculate the number of rows and columns
        int n = isWater.size();
        int m = isWater[0].size();

        // Initialize the queue with water cells and distances
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (isWater[i][j] == 1)
                {
                    isWater[i][j] = 0; // Initialize distance to 0 for water cell
                    q.push({i, j});
                }
                else
                {
                    isWater[i][j] = -1; // Initialize distance to -1 for land cell
                }
            }
        }

        // Perform BFS
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int currDis = isWater[r][c];

            // Define possible moves (up, down, right, left)
            int v1[4] = {-1, 1, 0, 0};
            int v2[4] = {0, 0, 1, -1};

            // Explore neighbors
            for (int i = 0; i < 4; ++i)
            {
                int nr = r + v1[i];
                int nc = c + v2[i];
                // Check if the neighbor is within bounds and unvisited
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && isWater[nr][nc] == -1)
                {
                    // Update distance and add to the queue
                    isWater[nr][nc] = currDis + 1;
                    q.push({nr, nc});
                }
            }
        }

        return isWater;
    }
};
