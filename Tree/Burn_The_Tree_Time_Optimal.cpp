#include <bits/stdc++.h>
#include "TreeCreation.cpp"
/// Tree has unique values if not parent will also be node

/*
Time Complexity = O(n) 

Space Complexity = O(n)
*/


int result = INT_MIN;

int solve(TreeNode* root,int start)
{
    if(!root) return 0;
    
    int lh = solve(root->left,start);
    int rh = solve(root->right,start);

    if(root->data == start)
    {
        result = max(lh,rh);
        return -1;
    }
    else if(lh >= 0 && rh >= 0)
    {
        return max(lh,rh) + 1;
    }
    else  //anyone is negative
    {
       int dist = abs(lh) + abs(rh);
       result = max(result,dist);
       return min(lh,rh) - 1;
    }
    return 0;

}
int amountOfTime(TreeNode *root, int start)
{
    solve(root,start);
    return result;

}

/*
🔎 The situation

You wrote:

int amountOfTime(TreeNode* root, int start) {
    solve(root, start);   // return value is ignored
    return result;
}


solve has return type int.

But inside amountOfTime, you call solve(root, start); without storing its return value.

So you’re asking:
👉 “Why doesn’t this give a compile error since I’m not using the returned value?”

✅ The answer

In C++, it is perfectly valid to call a function and ignore its return value.
There is no requirement that you must use or store the return value of a function.

For example:

int foo() { return 42; }

int main() {
    foo(); // ✅ valid, return value is ignored
    return 0;
}


This compiles fine.
*/