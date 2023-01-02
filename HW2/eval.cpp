#include <stdio.h>
#include "Map.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;

bool isOperators(char ch) {
    string arr = "+-*/";
    if (arr.find(ch) == -1)
        return false;
    return true;
}

bool Valid(string infix) {
    string infixNoSpace = "";
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] != ' ') {
            infixNoSpace += infix[i];
        }
    }
    int x = 0; // number of operands
    int y = 0; // number of operator
    int Parentheses = 0;
    
    stack<char>par;
    char curr;
    
    for (int i = 0; i < infixNoSpace.length(); i++) {
        curr = infixNoSpace[i];
        
        if (curr == '(') {
            if (infixNoSpace[i + 1] != '(' && !isalpha(infixNoSpace[i + 1])) {
                return false;;
            }
            par.push(curr);
            Parentheses++;
        }
        else if (curr == ')') {
            if (infixNoSpace[i - 1] != ')' && !isalpha(infixNoSpace[i - 1])) {
                return false;;
            }
            if (par.empty()) {
                return false;
            }
            else {
                if (par.top() != '(') {
                    return false;
                }
            }
            par.pop();
            Parentheses++;
        }
        else if (isalpha(curr) && islower(curr)) {
            x++;
        }
        else if (isOperators(curr)) {
            y++;
        }
        else {
            return false;
        }
    }
    if (Parentheses % 2 != 0 || y + 1 != x || (y == 0 && x > 1)) {
        return false;
    }
    return true;
}

bool validOperands(string infix, const Map& values) {
    for (int i = 0; i < infix.length(); i++) {
        if (isalpha(infix[i])) {
            if (values.contains(infix[i]) == false) {
                return false;
            }
        }
    }
    return true;
}


bool lessPrec(char op1, char op2) {
    if ((op2 == '*' || op2 == '/') && (op1 == '+' || op1 == '-')) {
        return true;
    }
    return false;
}

string InfixToPostfix(string infix) {
    string infixNoSpace = "";
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] != ' ') {
            infixNoSpace += infix[i];
        }
    }
    string postfix = "";
    stack<char> o;

    char curr;

    for (int i = 0; i < infixNoSpace.length(); i++) {
        curr = infixNoSpace[i];

        //case operand
        if (isalpha(curr)) {
            postfix += curr;
            continue;
        }

        switch (curr) {
        case '(':
            o.push(curr);
            break;
        case ')':
            // pop stack until matching '('
            while (o.top() != '(') {
                postfix += o.top();
                o.pop();
            }
            //pop the '('
            o.pop();
            break;
            //case operators
        case '+':
        case '-':
        case '*':
        case '/':
            //While the stack is not empty and the stack top is not '('
             //and precedence of ch <= precedence of stack top
            while (!o.empty() && o.top() != '(' && lessPrec(curr, o.top())) {
                postfix += o.top();
                o.pop();
            }
            o.push(curr);
            break;
        }
    }
    while (!o.empty()) {
        postfix += o.top();
        o.pop();
    }
    return postfix;
}

int evaluate(string infix, const Map& values, string& postfix, int& result) {

    postfix = InfixToPostfix(infix);
    if (Valid(infix) == false)
        return 1;

    if (validOperands(infix, values) == false)
        return 2;

    //Initialize the operator stack to empty
    stack<int> EvalResult;
    char curr;
    int pfvalue;
    for (int i = 0; i < postfix.length(); i++) {
        curr = postfix[i];
        if (isalpha(curr)) {
            //push the value that curr represents onto the operand stack
            values.get(curr, pfvalue);
            EvalResult.push(pfvalue);
        }
        else {//curr is a binary operands
            int op2 = EvalResult.top();
            EvalResult.pop();
            int op1 = EvalResult.top();
            EvalResult.pop();
            //apply the operation that ch represents to operand1 and
            //operand2, and push the result onto the stack
            switch (curr) {
            case '+':
                EvalResult.push(op1 + op2);
                break;
            case '-':
                EvalResult.push(op1 - op2);
                break;
            case '*':
                EvalResult.push(op1 * op2);
                break;
            case '/':
                //if evaluating the expression
                //   attempts to divide by zero, then result
                //   is unchanged and the function returns 3;
                if (op2 == 0) {
                    return 3;
                }
                EvalResult.push(op1 / op2);
                break;
            }
        }
    }
    // otherwise, result is set to the value of the expression and the function returns 0.
    result = EvalResult.top();
    return 0;

}

int main()
{
    char vars[] = { 'a', 'e', 'i', 'o', 'u', 'y', '#' };
    int  vals[] = { 3,  -9,   6,   2,   4,   1 };
    Map m;
    for (int k = 0; vars[k] != '#'; k++)
        m.insert(vars[k], vals[k]);
    string pf;
    int answer;
    assert(evaluate("a+ e", m, pf, answer) == 0 &&
        pf == "ae+" && answer == -6);
    answer = 999;
    assert(evaluate("", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("a+", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("a i", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("ai", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("()", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("()o", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("y(o+u)", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("y(*o)", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("a+E", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("(a+(i-o)", m, pf, answer) == 1 && answer == 999);
    // unary operators not allowed:
    assert(evaluate("-a", m, pf, answer) == 1 && answer == 999);
    assert(evaluate("a*b", m, pf, answer) == 2 &&
        pf == "ab*" && answer == 999);
    assert(evaluate("y +o *(   a-u)  ", m, pf, answer) == 0 &&
        pf == "yoau-*+" && answer == -1);
    answer = 999;
    assert(evaluate("o/(y-y)", m, pf, answer) == 3 &&
        pf == "oyy-/" && answer == 999);
    assert(evaluate(" a  ", m, pf, answer) == 0 &&
        pf == "a" && answer == 3);
    assert(evaluate("((a))", m, pf, answer) == 0 &&
        pf == "a" && answer == 3);
    cout << "Passed all tests" << endl;
}