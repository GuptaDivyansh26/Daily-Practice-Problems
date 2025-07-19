// Problem
/*
Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
*/

// Code

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        unordered_set<string> st;

        sort(folder.begin(), folder.end());

        for(auto it: folder) {

            string copy = it;
            bool flag = true;

            while(copy.length() > 0) {
                
                while(copy.back() != '/')   copy.pop_back();
                copy.pop_back();

                if(copy.length() > 0 && st.count(copy) == 1) {

                    flag = false;
                    break;
                }
            }

            if(flag)    st.insert(it);
        }

        return vector<string>(st.begin(), st.end());
    }
};