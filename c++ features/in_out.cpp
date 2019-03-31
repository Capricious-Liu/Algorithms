#include"iostream";
#include"iomanip";

using namespace std;

int in_out_main(){
	//在用cin输入时,系统也会根据变量的类型从输入流中提取相应长度的字节
	char c1, c2;
	int x;
	double y;
	cin >> c1 >> c2 >> x >> y;
	cout << c1 << " " << c2 << " " << x << " " << y << endl;
	//input:  1234 43.3
	//output: 1 2 34 43.3

	// cin 不读取空格 回车 换行符
	return 0;
}