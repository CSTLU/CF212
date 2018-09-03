#include <iostream>
#include <cctype>
#include <string>
#include <math.h>
#include <stack>
#include <list>
using namespace std;

// get weight of operators as per precedence
// higher weight given to operators with higher precedence
// for non operators, return 0 
int getWeight(char ch) {
   switch (ch) {
      case '^': return 3;
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}

// convert infix expression to postfix using a stack
string infix2postfix(const string & infix) {
   stack<char> s;
   string postfix = "";
   int weight;
   int i = 0;
   int k = 0;
   char ch;
   // iterate over the infix expression   
   while (i < infix.length()) {
      ch = infix[i];
      if (ch == '(') {
         // simply push the opening parenthesis
         // ====================== YOUR CODE HERE ======================
            
         // ============================================================
      }
      if (ch == ')') {
         // if we see a closing parenthesis,
         // pop of all the elements and append it to
         // the postfix expression till we encounter
         // a opening parenthesis
         while (!s.empty() && s.top() != '(') {
            // ====================== YOUR CODE HERE ======================
            
            // ============================================================
         }
         // pop off the opening parenthesis also
         if (!s.empty()) {
            // ====================== YOUR CODE HERE ======================
            
            // ============================================================
         }
         i++;
         continue;
      }
      weight = getWeight(ch);
      if (weight == 0) {
         // we saw an operand
         // simply append it to postfix expression
         // ====================== YOUR CODE HERE ======================
            
         // ============================================================
      }
      else {
         // we saw an operator
         if (s.empty()) {
            // simply push the operator onto stack if
            // stack is empty
            // ====================== YOUR CODE HERE ======================
            
            // ============================================================
         }
         else {
            // pop of all the operators from the stack and
            // append it to the postfix expression till we
            // see an operator with a lower precedence that
            // the current operator
            while (!s.empty() && s.top() != '(' && weight <= getWeight(s.top())) {
               // ====================== YOUR CODE HERE ======================
            
               // ============================================================
            }
            // push the current operator onto stack
            // ====================== YOUR CODE HERE ======================
            
            // ============================================================
         }
      }
      i++;
   }
   // pop of the remaining operators present in the stack
   // and append it to postfix expression 
   while (!s.empty()) {
      // ====================== YOUR CODE HERE ======================
            
      // ============================================================
   }

   return postfix;
}


// returns the value when a specific operator
// operates on two operands
int eval(int op1, int op2, char operate) {
   switch (operate) {
      case '*': return op2 * op1;
      case '^': return pow(op2,op1);
      case '/': return op2 / op1;
      case '%': return op2 % op1;
      case '+': return op2 + op1;
      case '-': return op2 - op1;
      default : return 0;
   }
}

// evaluates the postfix operation
// this module neither supports multiple digit integers
// nor looks for valid expression
// However it can be easily modified and some additional
// code can be added to overcome the above mentioned limitations
// it's a simple function which implements the basic logic to
// evaluate postfix operations using stack
int evalPostfix(const string & postfix) {
   stack<int> s;
   int i = 0;
   char ch;
   int val;

   while (i < postfix.length()) {
      ch = postfix[i];

      if (isdigit(ch)) {
         // we saw an operand
         // push the digit onto stack
         // ====================== YOUR CODE HERE ======================
            
         // ============================================================
      }
      else {
         // we saw an operator
         // pop off the top two operands from the
         // stack and evalute them using the current
         // operator
         // ====================== YOUR CODE HERE ======================
            
         // ============================================================

         // push the value obtained after evaluating
         // onto the stack
         // ====================== YOUR CODE HERE ======================
            
         // ============================================================
      }
      i++;
   }
   return val;
}

// main
int main() {
   string infix;
   cin>>infix;
   string postfix = infix2postfix(infix);
   cout<<postfix<<endl;
   cout<<evalPostfix(postfix);
   return 0;
}
