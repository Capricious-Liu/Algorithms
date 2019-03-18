// Õ»

#include "stack"
#include "iostream"
#include "string"
#include "vector"

using namespace std;

void test_stack(){
	stack<int> s;
	//cout << s.top();
	s.push(89);

	cout << s.top();
	s.pop();	
	

}

//HDU 1022£ºTrain Problem I
void train_problem(){
	string s1, s2;
	int n;
	stack<char> s;
	vector<bool> seq;
	bool flag;
	while (cin >> n >> s1 >> s2){
		flag = true;
		while (!s.empty()){
			s.pop();
		}
		if (!seq.empty()){
			seq.clear();
		}
		int j = 0;
		for (int i = 0; i < s2.size(); i++){
			while (s.empty() || s.top() != s2[i]){
				s.push(s1[j++]);
				seq.push_back(true);
				if (j > s1.size()){
					cout << "No." << endl;
					flag = false;
					break;
				}
			}
			if (!s.empty() && s.top() == s2[i]){
				s.pop();
				seq.push_back(false);
			}
			if (flag == false) break;

		}
		if (flag){
			cout << "Yes" << endl;
			for (int k = 0; k < seq.size(); k++){
				seq[k] ? cout << "in" << endl : cout << "out" << endl;
			}
		}
		cout << "FINISH" << endl;
	}

}

void stack_main(){
	//test_stack();
	train_problem();
}