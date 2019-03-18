// Map

/*
����Ԫ�ػ����keyֵ����Ĭ�����������ֵΪ�ַ��������ֵ��򣩣�
map�е�����Ԫ�ض���pair��ͬʱӵ��ʵֵ�ͼ�ֵ��pair��firstΪ��ֵ��secondΪʵֵ���ײ㽫����first��Ϊ�����������key��
map��������������ͬ��ֵ��Ԫ�ء�map�ĵ����������޸ļ�ֵ���������޸�ʵֵ����Ҫ���ڴ�����м�ֵ�ļ�¼��Ԫ�����ݵĿ��ٲ��롢ɾ���ͼ�����
*/

#include"iostream"
#include"string"
#include"map"

using namespace std;

void test_map(){
	// Initialization
	map<string, double> m;
	m["Jack"] = 98.5;
	cout << m["Jack"] << endl;
	if (m["Apple"] == NULL) cout << "yes"<<endl;

	map<string, string> m2;
	if (m2["Apple"] == "") cout << "yes"<<endl;

	// Iteration
	map<string, double> ::iterator it = m.begin();
	for (; it != m.end(); it++){
		cout << (*it).first << ": " << (*it).second << endl;;
	}

	// Deletion
	m2.erase("Apple");
	m2.clear();
	m.erase("Apple");

	// Find
	it = m.find("Apple");
	if (it == m.end()) cout << "yes" << endl;
	it = m.find("Apple");
	if (it == m.end()) cout << "yes" << endl;
	it = m.begin();
	for (; it != m.end(); it++){
		cout << (*it).first << ": " << (*it).second << endl;;
	}
	// find will not insert


	if (m["Jack1"])
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;
	if (m["Jack1"])
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;
	it = m.begin();
	for (; it != m.end(); it++){
		cout << (*it).first << ": " << (*it).second << endl;;
	}
	// m[] will insert

	if (m.count("Jack2"))
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;
	it = m.begin();
	for (; it != m.end(); it++){
		cout << (*it).first << ": " << (*it).second << endl;;
	}
	// m.count will not insert
}



// Maya Calendar

void t_main(){
	//test_map();

	char m1[][10] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
		"yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };

	char m2[][10] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
		"muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
	
	map<string, int> habb;
	map<int, string> tzo;

	for (int i = 0; i < 19; i++){
		habb[m1[i]] = i;
	}
	for (int i = 0; i < 20; i++){
		tzo[i] = m2[i];
	}

	int num;
	cin >> num;
	cout << num << endl;
	for (int i = 0; i < num; i++){
		int day;
		string month;
		int year;
		scanf("%d.", &day);
		cin >>  month >> year;

		int cur_days = day + habb[month] * 20 + year * 365+1;
		//cout << cur_days;
		int tzo_year = cur_days / 260;
		int cur_days_in_tzo_year = cur_days % 260;
		int number = cur_days_in_tzo_year % 13;
		if (number == 0) number = 13;
		string name_of_day = tzo[cur_days_in_tzo_year % 20-1];

		cout << number << ' ' << name_of_day << ' ' << tzo_year << endl;
	}
}