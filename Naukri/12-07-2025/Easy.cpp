// Problem
/*
ou are given a string, 'MESSAGE'. The receiver of this ‘MESSAGE’ has a set of instructions on how to decrypt the message. In order to decrypt the message, we need to perform some rotation operations on the string.

These rotations can either be left rotations or right rotations. The set of instructions contains information about which type of rotation is to be performed and how many times. Your task is to determine the decrypted message.

Note:

Performing a 'left rotation' means deleting the first character of the string and appending it to the end of the string.

Performing a 'right rotation' means deleting the last character of the string and appending it to the beginning of the string.

For example, if we perform a left rotation on the string “coding”, it will become “odingc”. If we perform a right rotation on the string “ninja”, it will become “aninj”.
*/

// Code

#include <bits/stdc++.h> 
string decrypt(string& message, vector<vector<int>>& operations) {
	
	int total = 0;
	for(auto it: operations) {

		total += it[0]*it[1];
	}

	int n = message.size();
	total %= n;

	int times = abs(total);
	while(times --) {

		if(total < 0) {

			char c = message[0];
			message.erase(message.begin());
			message = message + c;
		}
		else {

			char c = message.back();
			message.pop_back();
			message = c + message;
		}
	}

	return message;
}