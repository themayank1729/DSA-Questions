#include <bits/stdc++.h>
using namespace std;
class Solution
{ // using Recursion
    int maxi = INT_MIN;
    int countPoints(vector<vector<int>> &arr, int currentDay, int lastDay)
    {

        if (currentDay > arr.size())
            return 0;

        int maxi = INT_MIN;
        for (int activity = 0; activity < 3; activity++)
        {
            if (activity != lastDay)
            {
                int points = arr[currentDay][activity] + countPoints(arr, currentDay + 1, activity);
                maxi = max(maxi, points);
            }
        }
        return maxi;
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();    // total n days
        int m = arr[0].size(); // total trainings

        return countPoints(arr, 0, -1); // Starting from day 0 and no day is visited now so lastDay  = -1
    }
};

class Solution
{ // Using Memoization
    int maxi = INT_MIN;
    int countPoints(vector<vector<int>> &arr, int day, int last, vector<vector<int>> &dp)
    {

        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                  if (task != last) 
                maxi = max(maxi, arr[day][task]);
            }
            return maxi;
        }
        if (dp[day][last] != -1)
            return dp[day][last];
        int maxi = 0; // since points are positive
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int points = arr[day][task] + countPoints(arr, day - 1, task, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();    // total n days
        int m = arr[0].size(); // total trainings

        vector<vector<int>> dp(n, vector<int>(m + 1, -1));

        return countPoints(arr, n - 1, -1, dp); // Starting from day 0
    }
};

class Solution
{  //Using Tabulation of dp.size() =  n * 3
public:
    int maximumPoints(vector<vector<int>> arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        for (int task = 0; task < 3; task++)
        {
            dp[n - 1][task] = arr[n - 1][task];
        }

        for (int day = n - 2; day >= 0; day--)
        {
            dp[day][0] = arr[day][0] + max(dp[day + 1][1], dp[day + 1][2]);
            dp[day][1] = arr[day][1] + max(dp[day + 1][0], dp[day + 1][2]);
            dp[day][2] = arr[day][2] + max(dp[day + 1][0], dp[day + 1][1]);
        }
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            maxi = max(maxi, dp[0][task]);
        }
        return maxi;
    }
};
class Solution
 {  //using tabulation of dp.size() = 3 * 2
public:
    int maximumPoints(vector<vector<int>> arr)
    {
        int n = arr.size();

        if (arr.size() == 1)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                maxi = max(maxi, arr[0][task]);
            }
            return maxi;
        }
        vector<int> dp_cur(3, 0), dp_prev(3, 0); // initializing with last row of arr in below loop
        for (int task = 0; task < 3; task++)
        {
            dp_prev[task] = arr[n - 1][task];
        }

        int maxi = 0;
        for (int day = n - 2; day >= 0; day--)
        {
            for (int task = 0; task < 3; task++)
            {
                dp_cur[0] = arr[day][0] + max(dp_prev[1], dp_prev[2]);
                dp_cur[1] = arr[day][1] + max(dp_prev[0], dp_prev[2]);
                dp_cur[2] = arr[day][2] + max(dp_prev[0], dp_prev[1]);
            }
            for (int i = 0; i < 3; i++)
            {
                dp_prev[i] = dp_cur[i];
                maxi = max(maxi, dp_prev[i]);
            }
        }

        return maxi;
    }
};
