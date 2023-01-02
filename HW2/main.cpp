//#include <stack>
//#include <queue>
//#include <string>
//#include <iostream>
//#include "map.h"
//using namespace std;
//
//
//#include <cassert>
//int evaluate(string infix, const Map& values, string& postfix, int& result) {
//	string inf = "";
//	// remove spaces
//	for (int i = 0; i < infix.length(); i++) {
//		if (infix[i] != ' ')
//			inf += infix[i];
//	}
//	// Initialize postfix to empty
//	string pos = "";
//
//	// Initialize the operator stack to empty
//	stack<char> operators;
//
//	// initialize operand array
//
//	// initialize operator array
//	char oparr[4] = { '+','-','*','/' };
//
//	//For each character ch in the infix string
//	for (int i = 0; i < inf.length(); i++) {
//		char ch = infix[i];
//		//switch (ch) {
//		if (values.contains('ch')) { // operand case
//			//append ch to end of postfix
//			pos += ch;
//		}
//		else if (ch == '(') { // case '(':
//			//push ch onto the operator stack
//			operators.push(ch);
//		}
//		else if (ch == ')') {//case ')':
//			// pop stack until matching '('
//			//While stack top is not '('
//			while (operators.top() != '(') {
//				//append the stack top to postfix
//				pos += operators.top();
//				//pop the stack
//				operators.pop();
//			}
//			//pop the stack  // remove the '('
//			operators.pop();
//		}
//
//		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){//case operator:
//			//While the stack is not empty and the stack top is not '('
//			//char t = operators.top();
//			while (!operators.empty() && operators.top() != '('&& 
//				((ch == '+' || ch == '-') && (operators.top() == '*' || operators.top() == '/'))) {
//				//append the stack top to postfix
//				postfix += operators.top();
//				//pop the stack
//				operators.pop();
//			}
//			//push ch onto the stack
//			operators.push(ch);
//		}
//		else {
//			return false;
//		}
//		// While the stack is not empty
//		while (!operators.empty()) {
//			//append the stack top to postfix
//			pos = operators.top();
//			//pop the stack
//			operators.pop();
//		}
//
//	}
//}
//
//
//// If infix valid, infix integer expression & operands are lower case letters \
//// (whether or not in map), then postfix = postfix form
//
//// otherwise postfix may or may not be
//// changed, result is unchanged, and returns 1.  
//
////   If infix valid but contains operand not in map, then
////   result is unchanged and returns 2.  
//
////   If infix valid and all operand in map, then if divide by zero, \
////   then result unchanged and returns 3
//
////   otherwise, result is
////   set to the value of the expression and the function returns 0.
//
//
//
//// infix to postfix
//bool inTopo(string in, string& po, const Map& values) {
//	
//
//	
//		
//}
//
//int main()
//{
//
//}