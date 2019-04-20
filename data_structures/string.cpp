#include "string"
#include "iostream"
#include "vector"
#include "sstream"

using namespace std;

// 3�ַ���ʵ���ַ����ָ�

// 1.����find & substr
// size_t find (const string& str, size_t pos = 0) const;
// pos����ʼ����λ��
// ���ص�һ�γ���λ��
// string substr (size_t pos = 0, size_t len = npos) const;
// pos����ʼ����λ��
// len����ȡ�ַ�������
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


// 2.����strtok
// char * strtok ( char * str, const char * delimiters );
// �ָ��ַ���str��delimitersΪָ���ķָ���������ж����

// strtokֻ�ܽ���C�����ַ����������string���ͣ�����ʹ��c_str��������ת����
// strtok()�������ַ����ָ��һ����Ƭ�Ρ�
// ����strָ�����ָ���ַ���������delim��Ϊ�ָ��ַ�������strtok()�ڲ���s���ַ����з��ֵ�����delim�ķָ��ַ�ʱ ��Ὣ���ַ���Ϊ\0 �ַ���
// �ڵ�һ�ε���ʱ��strtok()����������s�ַ���������ĵ����򽫲���s���ó�NULL��ÿ�ε��óɹ��򷵻ر��ָ��Ƭ�ε�ָ�롣

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

// 3.ͨ��stringstreamʵ��
// stringstreamΪ�ַ���������������̳���iostream������ʹ��stringstream��������ɺܶ��ַ��������ܣ������ַ������������͵�ת�����ַ����ָ�ȡ�
// ���������ʹ����ʵ���ַ����ָ�ܡ�ע��stingstream��ʹ����Ҫ����sstreamͷ�ļ���

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