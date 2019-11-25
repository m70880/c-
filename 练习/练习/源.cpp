#include <iostream>
#include <vector>
using namespace std;
int getTheNumber(vector<vector<int>>& v, int row, int col) {
	int ret = 0;
	row--;
	for (int i = col;(i >= 0)&&(i>=col-2);i--) {
		ret += v[row][i];
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v;
	v.resize(n);
	for (int i = 0;i < n;i++) {
		v[i].resize(2*n,0);
		v[i][0] = 1;
	}
	for (int i = 1;i < n;i++) {
		for (int j = 1;j < 2 * i + 1;j++) {
			v[i][j]=getTheNumber(v, i, j);
		}
	}
	for (int i = 0;i < 2 * i + 1;i++) {
		if (v[n - 1][i] % 2 == 0) {
			cout << i;
			break;
		}
	}

	return 0;
}