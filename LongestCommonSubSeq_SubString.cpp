/*
Longest Common Subsequence
Longest Common Substring
*/
#include "vector"
#include "iostream"
using namespace std;

int LCS_Seq(vector<char> x, vector<char> y){
	int y_size = y.size();
	int** c = new int*[x.size()+1];
	for (int i = 0; i < x.size()+1; i++){
		c[i] = new int[y_size+1]();
	}

	for (int i = 0; i <= x.size(); i++){
		for (int j = 0; j <= y.size(); j++){
			if (i == 0 || j == 0){
				c[i][j] = 0;
			}
			else if (x[i-1] == y[j-1]){
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else{
				c[i][j] = c[i - 1][j]>c[i][j - 1] ? c[i - 1][j] : c[i][j - 1];
			}
		}
	}
	return c[x.size()][y.size()];

}

int LCS_Str(vector<char> x, vector<char> y){
	int y_size = y.size();
	int** c = new int*[x.size() + 1];
	for (int i = 0; i < x.size() + 1; i++){
		c[i] = new int[y_size + 1]();
	}

	int max = 0;

	for (int i = 0; i <= x.size(); i++){
		for (int j = 0; j <= y.size(); j++){
			if (i == 0 || j == 0){
				c[i][j] = 0;
			}
			else if (x[i - 1] == y[j - 1]){
				c[i][j] = c[i - 1][j - 1] + 1;
				max = c[i][j]>max ? c[i][j] : max;
			}
			else{
				c[i][j] = 0;
			}
		}
	}
	return max;
}


void LCS_SS_main(){
	vector<char> X = { 'A', 'B', 'C', 'B', 'D', 'A', 'B' };
	vector<char> Y = { 'B', 'D', 'C', 'A', 'B', 'A' };

	cout << LCS_Str(X, Y);
}