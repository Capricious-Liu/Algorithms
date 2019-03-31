/*
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
���磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include "vector"
#include "iostream"

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	int i = 0, j = 0, k = 0;

	int h = matrix.size();
	int w = matrix[0].size();

	int direction = 0;

	vector<int> res;
	
	int left = 0;
	int right = w - 1;
	int up = 0;
	int down = h - 1;

	while (j>=left && j<=right && i>= up && i<= down){
		switch (direction)
		{
		case 0:{
			while (j <= right){
				res.push_back(matrix[i][j]);
				j++;
			}
			j--;
			up++;
			i++;
			break;
		}
		case 1:{
			while (i <= down){
				res.push_back(matrix[i][j]);
				i++;
			}
			i--;
			right--;
			j--;
			break;
		}
		case 2:{
			while (j >= left){
				res.push_back(matrix[i][j]); 
				j--;
			}
			j++;
			down--;
			i--;
			break;
		}
		case 3:{
			while (i >= up){
				res.push_back(matrix[i][j]);
				i--;
			}
			i++;
			left++;
			j++;
			break;
		}
		default:
			break;
		}
		direction++;
		if (direction == 4){
			direction = 0;
		}
	}
	return res;

}

ostream& operator<< (ostream& out, vector<int> res){
	for (int i = 0; i < res.size(); i++){
		out << res[i] << " ";
	}
	out << endl;
	return out;
}


void main(){
	vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	cout << printMatrix(matrix);
}