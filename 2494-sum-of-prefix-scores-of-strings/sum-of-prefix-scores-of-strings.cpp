struct Node {
	Node* arr[26]; // NULL
	int countEnd = 0;
	int countPrefix = 0;
};
class Trie {
private:
	Node *root;
public:
	Trie() {
		root = new Node();
	}
	void insert(string &s) {
		int n = s.size();
		Node* node = root;  // creted dummpy root so that root doesnot alter
		for (int i = 0; i < n; i++) {
			if (node->arr[s[i] - 'a'] == NULL) {
				node->arr[s[i] - 'a'] = new Node();
			}
			node = node->arr[s[i] - 'a'];
			node->countPrefix++;
		}
		node->countEnd++;
	}
	int findNo_oFString(string &s) {
		int n = s.size();
		Node* node = root;
		for (int i = 0; i < n; i++) {
			if (node->arr[s[i] - 'a'] == NULL) {
				return 0;
			}
			node = node->arr[s[i] - 'a'];
		}
		return node->countEnd;
	}
	int No_oF_StringStartWith(string &s) {  // PREFIXES
		int n = s.size();
		Node* node = root;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (node->arr[s[i] - 'a'] == NULL) {
				return 0;
			}
			node = node->arr[s[i] - 'a'];
			count += (node->countPrefix);
		}
		return count;
	}
	void remove(string &s) {  // considering string exist
		int n = s.size();
		Node* node = root;
		for (int i = 0; i < n; i++) {
			node = node->arr[s[i] - 'a'];
			node->countPrefix--;
		}
		node->countEnd--;
	}
};
class Solution {
public:
	vector<int> sumPrefixScores(vector<string>& words) {
		Trie tr;
		for (auto x : words) {
			tr.insert(x);
		}
		vector<int>ans(words.size(), 0);
		for (int i = 0; i < words.size(); i++) {
			ans[i] = tr.No_oF_StringStartWith(words[i]);
		}
		return ans;
	}
};