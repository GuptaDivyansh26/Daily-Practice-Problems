// Problem
/*
Given n pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. That is, you need to generate all possible valid set of parenthesis that can be formed with given number of pairs.
*/

// Code

void print(string& s, int& lc, int& rc, int& n) {

    if(lc + rc == 2*n)    cout << s << "\n";

    if(lc < n) {

        s.push_back('(');
        lc ++;
        print(s, lc, rc, n);
        lc --;
        s.pop_back();
    }

    if(rc < lc) {

        s.push_back(')');
        rc ++;
        print(s, lc, rc, n);
        rc --;
        s.pop_back();
    }
}
void printWellFormedParanthesis(int n){

    int lc= 0, rc= 0;
    string s = ""; 
    print(s, lc, rc, n);
}
