// Problem
/*
You have been given an integer 'N'. Your task is to generate and return all binary strings of length 'N' such that there are no consecutive 1's in the string.
*/

// Code

void generate(int N, string curr, vector<string>& result, char c) {

    if(curr.length() >= N) {

        result.push_back(curr);
        return;
    }

    generate(N, curr + "0", result, '0');

    if(c != '1') {

        generate(N, curr + "1", result, '1');
    }
}
vector<string> generateString(int N) {
    
    vector<string> result;
    generate(N, "", result, '0');
    return result;
}