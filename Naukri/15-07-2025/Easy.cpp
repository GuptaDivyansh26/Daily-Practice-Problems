// Problem 
/*Ninja opened a shikanji’s stall to earn a living for him. In his stall, each shikanji drinks cost ‘5$’. Customers are standing in the form queue and each customer either pays ‘5$, 10$, 20$ ‘ so now Ninja has to give them change so that each customer exactly pays ‘5$’.

So now help the ninja to find out whether he is able to charge exactly ‘5$’ from each customer by providing them the change.

So your task is to write a code to check whether ninja can provide change to the customer if they paid extra to him. You will be provided with the ‘BILL_ARR’ array denoting the amount paid by each customer you have to return ‘True’ if it is possible else you have to return ‘False’.
*/

// Code

#include <bits/stdc++.h> 
bool ninjaShikanji(vector<int> bill, int n) {
	
	int fives = 0, tens = 0;
	for(auto it: bill) {

		if(it == 5)	fives ++;
		else if(it == 10) {
			
			if(fives < 1)	return false;

			fives --;
			tens ++;
		}
		else {

			if(fives >= 1 && tens > 0) {

				fives --;
				tens --;
			}
			else if(fives >= 3) {

				fives -= 3;
			}
			else	return false;
		}
	}

	return true;
}
