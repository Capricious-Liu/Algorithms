#include<iostream>;
#include<vector>;
using namespace std;

/*
All from large to small;
*/

/*
���������:
������ĳ�Ա���� ����ֻҪ��ǰ�����֮ǰ�Ĳ���

��������ĳ�Ա����  ������Ҫǰ������
ȫ�ֺ���������һ�����Զ�������
_Myiter& operator++();  
_Myiter& operator++(int);


��˫Ŀ��������ԣ���Ա��������غ��������б��к���һ������������Ԫ��������غ��������б�������������
�Ե�Ŀ��������ԣ���Ա��������غ��������б���û�в���������Ԫ��������غ��������б���һ��������

*/
ostream& operator<<(ostream & os, vector<int>& array){
	for (int i = 0; i < array.size(); i++){
		cout << array[i] << " ";
	}
	cout << endl;
	return os;
}

// Bubble sort
// ʱ�� n^2  �ռ� 1
void swap(vector<int>& array, int i, int j){
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	return;
}

vector<int> bubble_sort(vector<int>& array){
	for (int j = array.size()-1; j > 0; j--){
		for (int i = 0; i < j; i++){
			if (array[i] < array[i + 1]){
				swap(array, i, i + 1);
			}
		}
	}
	return array;
	
}


// Selection sort
// ʱ�� n^2  �ռ� 1

// Insertion sort
// ʱ�� n^2  �ռ� 1





int main(){
	vector<int> array = { 4, 5, 2, 1, 3 };
	cout << bubble_sort(array);
}