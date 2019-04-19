#include "queue"
#include "iostream"
#include "string"
using namespace std;

int queue_main(){
	queue<string> q;
	q.push("Hello world");
	q.push("China");
	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop();
	cout << q.front() << endl;

	

}