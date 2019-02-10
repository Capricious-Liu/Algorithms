/*
���ص�����k���ڵ�
*/

/*
˼·��
��һ���ڵ�������k-1����
�ڶ����ڵ�ӵ�һ����ʼ�������ڵ�һ����
*/


/*
NULL �� nullptr ������

#ifndef NULL
	#ifdef __cplusplus
		#define NULL 0
	#else
		#define NULL ((void *)0)
	#endif
#endif

C++ �� NULL ���� 0
C �� NULL ��(void*) 0
ԭ������c++�ĺ�������
����
void Func(char *);
void Func(int);
Func(NULL);
��ʱ�������᲻֪�������ĸ���


��ʽת��������
* ����ת��
* ������ת��Ϊָ�����һ��Ԫ�ص�ָ��
	int ia[10]; // array of 10 ints
	int *ip = ia; // convert ia to pointer to first element
���⣬�����������͵�ָ�붼��ת��Ϊvoid *��������ֵ����0����ת��Ϊ��������ָ�롣

* ָ��ֵ��ת��Ϊbool
* ����������bool��ת��
* ö�����Ͷ����ö�ٳ�Ա���Զ�ת��Ϊ����

nullptr ��Ϊc++ 11�ؼ���
��ָ�������ָ��
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