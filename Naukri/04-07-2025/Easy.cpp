// Problem
/*
Ninja was feeling bored during the lockdown. So, he decided to watch the Ninja World Tournament. The tournament consists of several matches, where the scores of past matches may affect future matches’ scores.

At the beginning of the match, every player starts with an empty track record. Ninja wants to calculate the final score for a player. So, given a list of strings, ‘MATCHRESULT’, where ‘MATCHRESULT[ i ]’ is the ‘i’th operation Ninja must apply to the track record and is one of the following:

1) An integer “A”: Introduce a new score of ‘A’ on the track record.
2) "+": Introduce a new score on the track record that is the sum of the previous two scores.
3) "C": Nullify the previous score, removing it from the track record.
4) "D": Introduce a new score on the track record that is double the previous score.
Ninja deduced that this could be easily solved using programming. So, he needs your help to calculate the sum of all the scores present in the track record.

Note:

It is guaranteed there will always be a previous score before the “C” and “D” operations and two previous scores before the “+” operation.
*/

// Code

#include <bits/stdc++.h> 
int calculateScore(vector<string> &matchResult, int n)
{
    stack<int> st;
    for(auto it: matchResult) {

        if(it == "+") {

            int a = st.top();
            st.pop();

            int b = st.top();

            st.push(a);
            st.push(a + b);
        }
        else if(it == "C") {

            st.pop();
        }
        else if(it == "D") {

            st.push(2*st.top());
        }
        else {

            int temp = stoi(it);
            st.push(temp);
        }
    }

    int res = 0;
    while(!st.empty()) {

        res += st.top();
        st.pop();
    }

    return res;
}