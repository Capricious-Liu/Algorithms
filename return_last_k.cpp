/*
返回倒数第k个节点
*/

/*
思路：
第一个节点往后走k-1步，
第二个节点从第一个开始，两个节点一起走
*/


/*
NULL 和 nullptr 的区别：

#ifndef NULL
	#ifdef __cplusplus
		#define NULL 0
	#else
		#define NULL ((void *)0)
	#endif
#endif

C++ 中 NULL 就是 0
C 中 NULL 是(void*) 0
原因在于c++的函数重载
例：
void Func(char *);
void Func(int);
Func(NULL);
此时编译器会不知道调用哪个。


隐式转换条件：
* 算术转换
* 数组名转换为指向其第一个元素的指针
	int ia[10]; // array of 10 ints
	int *ip = ia; // convert ia to pointer to first element
另外，任意数据类型的指针都可转换为void *，整形数值常量0可以转换为任意类型指针。

* 指针值可转换为bool
* 算术类型与bool的转换
* 枚举类型对象或枚举成员将自动转换为整形

nullptr 作为c++ 11关键字
可指代任意空指针
Func(nullptr) -> func(char*)
*/


void func(void *){
	return;
}

//int main(){
//	int* p = 0;
//	func(p);
//}


#include"stdio.h";
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k <= 0){
			return NULL;
		}
		ListNode* first = pListHead;
		ListNode* second = pListHead;
		for (int i = 0; i<k - 1; i++){
			first = first->next;
			if (first == NULL) return NULL;
		}
		while (first->next != NULL){
			first = first->next;
			second = second->next;
		}
		return second;
	}
};