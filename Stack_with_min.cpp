/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
*/

#include "iostream"
#include "stack"

using namespace std;

class Solution{
	stack<int> s1, s2;

	void push(int value){
		s1.push(value);
		if (s2.empty() || value <= s2.top()){
			s2.push(value);
		}
	}

	void pop(){
		if (s1.top() == this->min()){
			s1.pop();
			s2.pop();
		}
		else{
			s1.pop();
		}
	}

	int top(){
		return s1.top();
	}

	int min(){
		return s2.top();
	}

};

int s_w_m_main(){
	Solution s;
	return 1;
}