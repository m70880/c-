#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char addchar(char a, char b,int& flag) {
	char c = a + b -  2*'0' + flag;
	if (c > 9) {
		flag = 1;
	}
	else {
		flag = 0;
	}
	return c % 10 + '0';
}
string addBigNumber() {
	string s1;
	string s2;
	string ret;
	getline(cin, s1);
	getline(cin, s2);
	int pos1 = s1.size() - 1;
	int pos2 = s2.size() - 1;
	int pret = max(s1.size(), s2.size());
	ret.resize(pret + 1,0);
	int flag = 0;
	while (pos1>=0&&pos2>=0) {//计算相等长度的位置
		ret[pret] = addchar(s1[pos1], s2[pos2], flag);
		pos1--;
		pos2--;pret--;
	}
	//后续位计算的部分
	while(pos1 >= 0) {
		
		ret[pret] += addchar(s1[pos1], '0', flag);
		pos1--;
		pret--;
	}
	while(pos2 >= 0) {
		ret[pret] += addchar(s2[pos2], '0', flag);
		pos2--;
		pret--;
	}
	if (flag == 0) {
		for (int i = 1;i < ret.size();i++) {
			cout << ret[i];
		}
		cout << endl;
		return string(&ret[0]);
	}
	else {
		ret[0] = '1';
		for (int i = 0;i < ret.size();i++) {
			cout << ret[i];
		}
		cout << endl;
		return string(&ret[1]);
	}
}
int main() {
	addBigNumber();
	return 0;
}