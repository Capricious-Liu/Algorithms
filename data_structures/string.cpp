#include "string"
#include "iostream"
#include "vector"
#include "sstream"

using namespace std;

// 3种方法实现字符串分隔

// 1.利用find & substr
// size_t find (const string& str, size_t pos = 0) const;
// pos：初始查找位置
// 返回第一次出现位置
// string substr (size_t pos = 0, size_t len = npos) const;
// pos：初始查找位置
// len：截取字符串长度
vector<string> split_with_find(const string& str, const string& pattern){
	vector<string> res;
	if (str == "")
		return res;
	string strs = str + pattern;
	size_t pos = strs.find(pattern);
	while (pos != strs.npos){
		string tmp = strs.substr(0, pos);
		res.push_back(tmp);
		strs = strs.substr(pos + 1);
		pos = strs.find(pattern);
	}
	return res;
}


// 2.利用strtok
// char * strtok ( char * str, const char * delimiters );
// 分割字符串str，delimiters为指定的分割符，可以有多个。

// strtok只能接受C风格的字符串，如果是string类型，可以使用c_str函数进行转换。
// strtok()用来将字符串分割成一个个片段。
// 参数str指向欲分割的字符串，参数delim则为分割字符串，当strtok()在参数s的字符串中发现到参数delim的分割字符时 则会将该字符改为\0 字符。
// 在第一次调用时，strtok()必需给予参数s字符串，往后的调用则将参数s设置成NULL。每次调用成功则返回被分割出片段的指针。

vector<string> split_with_strtok(const string& str, const string& pattern){
	char* strc = new char[strlen(str.c_str()) + 1];
	strcpy(strc, str.c_str());

	vector<string> res;
	char* tmp = strtok(strc, pattern.c_str());
	while (tmp != NULL){
		res.push_back(string(tmp));
		tmp = strtok(NULL, pattern.c_str());
	}
	delete[] strc;
	return res;
}

// 3.通过stringstream实现
// stringstream为字符串输入输出流，继承自iostream，灵活地使用stringstream流可以完成很多字符串处理功能，例如字符串和其他类型的转换，字符串分割等。
// 在这里，我们使用其实现字符串分割功能。注意stingstream的使用需要包含sstream头文件。

vector<string> split_with_stringstream(const string& str, const string& pattern){ // pattern is char!
	vector<string> res;
	stringstream input(str);
	string tmp;
	const char* c_pattern = pattern.c_str();
	while (getline(input, tmp, c_pattern[0])){ //getline(stream, string, char);
		res.push_back(tmp);
	}
	return res;
}


ostream& operator <<(ostream& os, vector<string>& res){
	for (int i = 0; i < res.size(); i++){
		os << res[i] <<endl;
	}
	//os << endl;
	return os;
}

int string_main(){
	string x;
	getline(cin,x);
	string pattern;
	getline(cin, pattern);



	// vector<string> res = split_with_find(x, pattern);
	// vector<string> res = split_with_strtok(x, pattern);
	vector<string> res = split_with_stringstream(x, pattern);
	cout << res;
	return 1;
}