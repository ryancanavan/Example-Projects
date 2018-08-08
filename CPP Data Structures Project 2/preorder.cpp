#include <iostream>
#include <stack>
using namespace std;

int preorderEval(stack<int> operands, stack<string> operators){
	int a, b, result;
	string c;
	while (operators.empty() != true){
		a = operands.top(); //first number
		operands.pop();
		b = operands.top(); //second number
		operands.pop();
		c = operators.top(); //first operator
		operators.pop();
		if (c == "+"){ //check for operand and perform that operation
			result = a + b;
			operands.push(result);
		}
		if (c == "-"){
			result = a - b;
			operands.push(result);
		}
		if (c == "*"){
			result = a * b;
			operands.push(result);
		}
		if (c == "/"){
			result = a / b;
			operands.push(result);
		}
	}
	return result;
}

int main(){
	stack<int> operands;
	stack<string> operators;
	int result;
	cout << "My example arithmetic expression is 3 + 4 * 2 / 4" << endl;
	cout << "My preorder expression is + 3 * 4 / 2 4" << endl;
	operands.push(3);
	operands.push(4);
	operands.push(2);
	operands.push(4);
	operators.push("+");
	operators.push("*");
	operators.push("/");
	cout << "I created a stack of the operands which is 3, 4, 2, 4 and a stack of operators which is +, *, /" << endl;
	result = preorderEval(operands, operators);
	cout << "My result is " << result << endl;

	return 0;
}
