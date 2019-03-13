// STL containers
#include"iostream"
using namespace std;

#include <algorithm>
#include <functional>
//vector
#include"vector"

bool cmp(int x, int y) {
	return x > y;
}

void test_vector(){
	//intialization
	vector<int> v1;
	vector<int> v2(10);
	vector<double> v3(10, 8.6);

	//get item
	cout << v2[2]<<endl;
	cout << *(v2.begin() + 2) << endl;
	
	//iteration
	vector<int>::iterator it;
	for (it = v2.begin(); it != v2.end()-8; it++) {
		cout << *it << ' ';
	}
	cout << endl;

	//insert
	v1.push_back(9);
	v1.insert(v1.begin() + 1, 1);
	v1.insert(v1.end(), 3);

	//delete
	v1.erase(v1.begin() + 1);
	v2.erase(v2.begin() + 2, v2.begin() + 5);
	v1.clear();

	//find
	v2.push_back(3);
	it = find(v2.begin(), v2.end(), 3);
	if (it != v2.end()) {
		int pos = distance(v2.begin(), it);
		cout << "position:	" << pos << endl;
	}

	//sort
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(100);
	sort(v2.begin(), v2.end());
	sort(v2.begin(), v2.end(), cmp);
	sort(v2.begin(), v2.end(), greater<int>());
	for (it = v2.begin(); it != v2.end() - 8; it++) {
		cout << *it << ' ';
	}
	cout << endl;

	//reverse
	reverse(v2.begin(), v2.end());
	v2.size();
	v2.empty();

}

//HDU: Round table question

void t_main() {
	int n, m;
	while (cin >> n >> m) {
		// Algorithm 1
		// Naive solution
		//vector<char> res(n*2,'G');
		//vector<char> ::iterator it = res.begin();
		//
		//for (int i = 0; i < n; i++){
		//	for (int j = 0; j < m; j++){
		//		if (it == res.end()) it = res.begin();
		//		if ((*it) == 'B') j--;
		//		it++;
		//	}
		//	*(--it) = 'B';
		//}
		//for (it = res.begin(); it != res.end(); it++){
		//	cout << *it;
		//}
		//cout << endl;

		//Algorithm 2
		// store the B position
		vector<int> res(n * 2);
		vector<int> b_pos;
		for (int i = 0; i < n * 2; i++){
			res[i] = i;
		}
		int cur_index = 0;
		for (int i = 0; i < n; i++){
			cur_index = (cur_index + m - 1) % res.size();
			b_pos.push_back(res[cur_index]);
			res.erase(res.begin() + cur_index);
		}
		cur_index = 0;
		for (int i = 0; i < n * 2; i++){
			if (i < b_pos[cur_index]) cout << 'G';
			if (i == b_pos[cur_index]){
				cout << 'B';
				cur_index++;
			}
		}
		cout << endl;

	}


}