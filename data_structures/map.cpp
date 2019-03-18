// Map

/*
所有元素会根据key值排序（默认升序，如果键值为字符串就是字典序），
map中的所有元素都是pair，同时拥有实值和键值，pair的first为键值，second为实值，底层将它的first作为红黑树的排序key。
map不允许有两个相同键值的元素。map的迭代器不能修改键值，但可以修改实值。主要用于处理带有键值的记录性元素数据的快速插入、删除和检索。
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