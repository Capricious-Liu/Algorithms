// Set
/*
set������ѧ�ϵļ��ϡ���ÿ��Ԫ��������һ�Σ����е�Ԫ���Զ�����
�Զ������͹���setʱ�����붨��"С��"�������
һ������ͨ��һ����������֯���ڲ��������ɾ�������ϱ�����(vector)�죬�����һ����ĩβ��Ԫ��ʱ����Щ����
����ʵ�ֲ����˺������ƽ������������ݽṹ��
*/



#include"set"
#include "iostream"
using namespace std;

struct comp{
	bool operator()(const int& lhs, const int& rhs){
		return lhs > rhs;
	}
};

struct Node
{
	int x;
	int y;
	friend bool operator<(Node a, Node b){
		return a.x < b.x;
	}
};

void test_set(){
	set<int> s1; //Ĭ������

	set<int, comp> s2; //����

	set<Node> s3;

	// Insert
	s1.insert(5);
	s1.insert(5);
	s1.insert(3);
	s3.insert(Node{ 8, 5 });
	cout << *s1.begin() << endl;//��һ��Ԫ��
	cout << *(--s1.end()) << endl;//���һ��Ԫ��

	// Iteration
	//ֻ��ͨ������������
	set<int>::iterator it;
	for (it = s1.begin(); it != s1.end(); it++)
		cout << *it << endl;

	// Deletion
	cout << s1.erase(5) << endl;
	s1.erase(s1.begin());

	for (it = s1.begin(); it != s1.end(); it++)
		cout << *it << endl;

	s1.clear();

	if (s1.find(5) != s1.end())
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;
}

void set_main(){
	test_set();
}