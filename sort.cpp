#include<iostream>;
#include<vector>;
using namespace std;

/*
All from large to small;
*/

/*
运算符重载:
若是类的成员函数 参数只要当前运算符之前的参数

若不是类的成员函数  参数需要前后两个
全局函数必须有一个是自定义类型
_Myiter& operator++();  
_Myiter& operator++(int);


对双目运算符而言，成员运算符重载函数参数列表中含有一个参数，而友元运算符重载函数参数列表含有两个参数；
对单目运算符而言，成员运算符重载函数参数列表中没有参数，而友元运算符重载函数参数列表含有一个参数。

*/
ostream& operator<<(ostream & os, vector<int>& array){
	for (int i = 0; i < array.size(); i++){
		cout << array[i] << " ";
	}
	cout << endl;
	return os;
}

// Bubble sort
// 时间 n^2  空间 1
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
// 时间 n^2  空间 1

// Insertion sort
// 时间 n^2  空间 1





int main(){
	vector<int> array = { 4, 5, 2, 1, 3 };
	cout << bubble_sort(array);
}