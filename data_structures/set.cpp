// Set
/*
set就是数学上的集合——每个元素最多出现一次，其中的元素自动排序，
自定义类型构造set时，必须定义"小于"运算符。
一个集合通过一个链表来组织，在插入操作和删除操作上比向量(vector)快，但查找或添加末尾的元素时会有些慢。
具体实现采用了红黑树的平衡二叉树的数据结构。
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
	set<int> s1; //默认升序

	set<int, comp> s2; //降序

	set<Node> s3;

	// Insert
	s1.insert(5);
	s1.insert(5);
	s1.insert(3);
	s3.insert(Node{ 8, 5 });
	cout << *s1.begin() << endl;//第一个元素
	cout << *(--s1.end()) << endl;//最后一个元素

	// Iteration
	//只能通过迭代器遍历
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