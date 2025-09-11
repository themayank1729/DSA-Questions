// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0; // before starting
        vector<vector<string>> ans;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            // erase all the words that has been used in the previous levels to transform
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear(); // new level new guys gets stored
            }
            string word = vec.back(); // last word in the vec will be the guy

            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size()) // to store different sequence of same length
                {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.length(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word) > 0) // if it is present
                    {
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        usedOnLevel.push_back(word);
                        // why popping back , read notes
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};