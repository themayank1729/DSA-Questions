#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int maxRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        int element = -1;
        int NSE, PSE;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                element = st.top();
                st.pop();
                NSE = i;
                PSE = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element] * (NSE - PSE - 1));
            }
            st.push(i);
        }
        while (!st.empty())
        {
            NSE = n;
            element = st.top();
            st.pop();
            PSE = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (NSE - PSE - 1));
        }
        return maxArea;
    }

public:
    int maxArea(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int maxArea = 0;
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            maxArea = max(maxArea, maxRectangleArea(height));
        }
        return maxArea;
    }
};