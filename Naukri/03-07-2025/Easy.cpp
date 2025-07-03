// Problem
/*
You are given a string 'exp' which is a valid infix expression.



Convert the given infix expression to postfix expression.



Note:
Infix notation is a method of writing mathematical expressions in which operators are placed between operands. 

For example, "3 + 4" represents the addition of 3 and 4.

Postfix notation is a method of writing mathematical expressions in which operators are placed after the operands. 

For example, "3 4 +" represents the addition of 3 and 4.

Expression contains digits, lower case English letters, ‘(’, ‘)’, ‘+’, ‘-’, ‘*’, ‘/’, ‘^’. 
*/

// Code

#include <stack>
string infixToPostfix(string exp){

	exp = exp + ')';
	
	stack<char> st;
	st.push('(');

	string res;

	for(auto it: exp){

		if((it >= '0' && it <= '9') || (it >= 'a' && it <= 'z'))	res += it;
		else if(it == '(')	st.push(it);
		else if(it == ')'){

			while(st.top() != '('){

				char c = st.top();
				res += c;
				st.pop();
			}
			st.pop();
		}
		else if(it == '+' || it == '-'){

			while(st.top() == '*' || st.top() == '/' || st.top() == '^' || st.top() == '+' || st.top() == '-'){

				res += st.top();
				st.pop();
			}
			st.push(it);
		}
		else if(it == '^'){

			while(st.top() == '^'){

				char c = st.top();
				res += c;
				st.pop();
			}
			st.push(it);
		}
		else{

			while(st.top() == '/' || st.top() == '*' || st.top() == '^'){

				char c = st.top();
				res += c;
				st.pop();
			}
			st.push(it);
		}
	}

	return res;
}