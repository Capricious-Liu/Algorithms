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
vector<int> insert_sort(vector<int> & array){
	for (int i = 1; i < array.size(); i++){
		int pre_index = i - 1;
		int cur_num = array[i];
		while (pre_index >= 0 && cur_num > array[pre_index]){
			array[pre_index + 1] = array[pre_index];
			pre_index--;
		}
		array[pre_index+1] = cur_num;
	}
	return array;
}

// Shell Sort
vector<int> shell_sort(vector<int>& array){
	int gap = array.size()/3+1;
	bool flag = false; // ��֤gapΪ1ʱ ��ִ�в���ִֻ��һ�Σ������·�while������ѭ����
	while (gap > 0){
		for (int i = gap; i < array.size(); i++){
			int tmp = array[i];
			int j = i - gap;
			for (; j>=0 && tmp>array[j]; j-=gap){
				array[j + gap] = array[j];
			}
			array[j + gap] = tmp;
		}
		gap = gap / 3 + 1;
		if (gap == 1 && !flag){
			flag = true;
		}
		else if (gap == 1 && flag){
			break;
		}
	}
	return array;
}

// Merge Sort
vector<int> merge(vector<int> left, vector<int> right){
	vector<int> res;
	int i=0, j = 0;
	while (i < left.size() && j < right.size()){
		if (left[i] > right[j]){
			res.push_back(left[i]);
			i++;
		}
		else{
			res.push_back(right[j]);
			j++;
		}
	}
	while (i < left.size()){
		res.push_back(left[i]);
		i++;
	}
	while (j < right.size()){
		res.push_back(right[j]);
		j++;
	}
	return res;
}

vector<int> merge_sort(vector<int>& array){
	if (array.size() == 1) return array;
	int middle = array.size() / 2;
	vector<int> left(array.begin(),array.begin()+middle);
	vector<int> right(array.begin() + middle, array.end());
	return merge(merge_sort(left), merge_sort(right));
}


int main(){
	vector<int> array = { 4, 5, 2, 1, 3 };
	cout << merge_sort(array);
}