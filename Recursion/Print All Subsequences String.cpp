#include <bits/stdc++.h>
using namespace std;

void helper(int index, string &s, string current) {
    // Base case: when we’ve considered all characters
    if (index == s.size()) {
        cout << current << "\n";
        return;
    }

    // Choice 1: Exclude current character
    helper(index + 1, s, current);

    // Choice 2: Include current character
    helper(index + 1, s, current + s[index]);
}

int main() {
    string s;
    cin >> s;
    helper(0, s, "");
}
