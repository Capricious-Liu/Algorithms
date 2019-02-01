/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 
队列中的元素为int类型。
*/


#include<stack>;
#include<iostream>;
using namespace std;


class Solution5
{
public:
	void push(int node) {
		while (!stack2.empty()){
			int tmp = stack2.top();
			stack1.push(tmp);
			stack2.pop();
		}
		stack1.push(node);
	}

	int pop() {
		while (!stack1.empty()){
			int tmp = stack1.top();
			stack2.push(tmp);
			stack1.pop();
		}
		int ans = stack2.top();
		stack2.pop();
		return ans;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

//int main(){
//	Solution5 x1;
//	x1.push(2);
//	x1.push(3);
//	x1.push(1);
//	cout << x1.pop();
//	cout << x1.pop();
//	x1.push(4);
//	cout << x1.pop();
//
//}