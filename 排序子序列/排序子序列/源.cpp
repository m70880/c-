#include<iostream>
#include<vector>
using namespace std;
int judgeHighOrLow(vector<int>& v) {
	if (v.size() < 3) {
		return 1;
	}
	int count = 1;
	for (int i = 1;i < v.size() - 1;i++) {
		if ((v[i] > v[i - 1] && v[i] > v[i + 1]) || v[i] < v[i - 1] && v[i] < v[i + 1]) {
			count++;
			if (i != v.size() - 3) {
				i = i + 2;
				break;
			}
		}
	}
	return count;
}
int main() {
	vector<int> v;
	int n = 0;
	int t = 0;
	cin >> n;
	while (n--) {
		cin >> t;
		v.push_back(t);
	}
	cout << judgeHighOrLow(v);

	return 0;
}