/*
Given an array,
find the subarray which have the greatest sum
*/


#include"vector"
#include"iostream"
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	int cur_max = INT_MIN;
	int cur_sum = INT_MIN;
	for (int i = 0; i<array.size(); i++){
		if (cur_sum <= 0){
			cur_sum = array[i];
		}
		else{
			cur_sum += array[i];
		}
		if (cur_sum >= cur_max){
			cur_max = cur_sum;
		}
	}
	return cur_max;
}

/*
Another solution:
 Dynamic Programming
 F£¨i£©=max£¨F£¨i-1£©+array[i] £¬ array[i]£©

the same as the first solution
*/



//int main(){
//	vector<int> a = { -1, 2, 3 };
//	cout << FindGreatestSumOfSubArray(a);
//}