#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<bool>& arr, int low, int high) {
    int idx = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == 1) {
            idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return idx;
}

int rowWithMax1s(vector<vector<bool>>& mat) {
    //Better Approach 
    //Time Complexity - O ( n * log(m))
    int max_row_index = -1, max = -1;
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++) {
        int index = lowerBound(mat[i], 0, m - 1);
        if (index != -1 && m - index > max) {
            max = m - index;
            max_row_index = i;
        }
    }

    return max_row_index;
}

int rowWithMax1s(vector<vector<bool>>& mat) {
    //Optimal Approach 
    // Time Complexity -  O (m  + n )
    int maxRow = -1, row = 0;
    int R = mat.size();
    int C = mat[0].size();
    int col = C - 1;

    // Move till we are inside the matrix
    while (row < R && col >= 0) {
        // If the current value is 0, move down to the next row
        if (mat[row][col] == 0) {
            row += 1;
        }
        // Else if the current value is 1, update ans and
        // move to the left column
        else {
            maxRow = row;
            col -= 1;
        }
    }
    return maxRow;
}

// Driver Code
int main() {
    vector<vector<bool>> mat = { { 0, 0, 0, 1 },
                                 { 0, 1, 1, 1 },
                                 { 1, 1, 1, 1 },
                                 { 0, 0, 0, 0 } };

    cout << "Index of row with maximum 1s is "
         << rowWithMax1s(mat);

    return 0;
}

