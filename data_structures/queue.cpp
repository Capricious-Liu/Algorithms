#include "queue"
#include "iostream"
#include "string"
using namespace std;

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()){
			TreeNode* tmp = q.front();
			if (tmp->left != NULL) { q.push(tmp->left); }
			if (tmp->right != NULL) { q.push(tmp->right); }
			int tmp1 = tmp->val;
			res.push_back(tmp1);
			q.pop();
		}
		return res;
	}
};

int queue_main(){
	struct TreeNode s1(0);
	struct TreeNode s2(1);
	struct TreeNode s3(2);
	s1.left = &s2;
	s1.right = &s3;

	Solution s;
	vector<int> res = s.PrintFromTopToBottom(&s1);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;






	/*queue<string> q;
	q.push("Hello world");
	q.push("China");
	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop();
	cout << q.front() << endl;
*/
	
	return 1;
}