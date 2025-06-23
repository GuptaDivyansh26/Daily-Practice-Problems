// Problem
/*
Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. Return the minimum possible sum as a string with no leading zeroes.
*/

// Code

class Solution {
  public:
    string addStrings(string num1, string num2) {
        
        string result = "";
        int carry = 0;
    
        int i = num1.length() - 1;
        int j = num2.length() - 1;
    
        while (i >= 0 || j >= 0 || carry) {
            
            int digit1 = (i >= 0 ? num1[i--] - '0' : 0);
            int digit2 = (j >= 0 ? num2[j--] - '0' : 0);
    
            int sum = digit1 + digit2 + carry;
            
            carry = sum / 10;
            result += (sum % 10) + '0';
        }
    
        while(result.back() == '0')
        {
            result.pop_back();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    string minSum(vector<int> &arr) {
        
        sort(arr.begin(), arr.end());
        
        string num1 = "", num2 = "";
        
        for(int i = 0; i < arr.size(); i ++) {
            
            if(i % 2 == 0) {
                
                num1 = num1 + to_string(arr[i]);
            }
            else {
                
                num2 = num2 + to_string(arr[i]);
            }
        }
        
        return addStrings(num1, num2);
    }
};