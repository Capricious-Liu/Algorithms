/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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
