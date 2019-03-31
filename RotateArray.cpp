/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/
#include "vector"
#include "iostream"
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
	int left = 0;
	int right = rotateArray.size() - 1;
	int mid = 0;
	while (left < right){
		mid = (left + right) / 2;
		if (rotateArray[mid] < rotateArray[left]){
			right = mid;
		}
		else{
			if (rotateArray[left] < rotateArray[right]){
				return rotateArray[left];
			}
			else{
				left = mid + 1;
			}
		}
	}
	return rotateArray[left];


}


void rotate_array_main(){
	vector<int> array = {1,2,3,4,5};
	cout<<minNumberInRotateArray(array);
}
