/*
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/
/*
����������ģ������½��������������ֵݼ����������ֵ�����
��˴����½ǿ�ʼ���ң���Ҫ�������ֱ����½����ִ�ʱ������
Ҫ�������ֱ����½�����Сʱ������
*/

#include<vector>;
#include<iostream>;
using namespace std;

class Solution1 {
public:
	bool Find(int target, vector<vector<int> > array) {
		int i = array.size() - 1;
		int j = 0;
		while ((i >= 0) && (j <= array[0].size() - 1)){
			if (target == array[i][j]){
				return true;
			}
			else if (target<array[i][j]){
				i--;
			}
			else{
				j++;
			}
		}
		return false;
	}
};


//int main(){
//	Solution1 x1;
//	cout<<x1.Find(7, { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } });
//}