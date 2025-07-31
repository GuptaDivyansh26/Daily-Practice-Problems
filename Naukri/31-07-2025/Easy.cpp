// Problem
/*
Shrey has just arrived in the city. When he entered the city, he was given two strings. Now, after arriving at his college, his professor gave him an extra string. To check his intelligence, his professor told him to check if the third string given to him has all the characters of the first and second strings in any order. Help Shrey before his professor scolds him. He has to answer “YES” if all characters are present else “NO”.

Example: ‘HELLO’ and ‘SHREY’ are two initial strings, and his professor gave him ’HLOHEELSRY’. So, here all the characters are present, so he has to say “YES”.

Note: The strings contain only uppercase Latin characters.
*/

// Code

#include <unordered_map>
string amazingStrings(string first, string second,string third) {
    
    unordered_map<char, int> mpp;
    for(auto it: first) mpp[it] ++;
    for(auto it: second)    mpp[it] ++;

    unordered_map<char, int> mpp2;
    for(auto it: third) mpp2[it] ++;

    if(mpp == mpp2)   return "YES";
    else    return "NO";
}
