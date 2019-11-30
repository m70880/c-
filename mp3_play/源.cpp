#include <iostream>
#include <string>
#include<vector>
using namespace std;
void add_n(int& init, int begin, int end) {
	if (init + 1 <= end) {
		init++;
	}
	else {
		init = begin;
	}
}
void sub_n(int& init, int begin, int end) {
	if (init - 1 >= begin) {
		init--;
	}
	else {
		init = end;
	}
}
void set_pos(int& basepos, int& nowpos,int n,char comand) {
	if (comand == 'U') {
		if (nowpos == basepos) {
			sub_n(basepos, 1, n);
			nowpos = basepos;
			if (basepos == n) {
				basepos -= 3;
			}
		}
		else {
			sub_n(nowpos, 1, n);
		}
	}
	if (comand=='D') {
		if (nowpos - basepos == 3) {
			add_n(basepos, 1, n);
			add_n(nowpos, 1, n);
			if (nowpos == 1) {
				basepos = 1;
			}
		}
		else {
			add_n(nowpos, 1, n);
		}
	}

}
int main() {
	int n;
	int basepos = 1;
	int nowpos = 1;
	vector<int> song;
	string command;
	int int_comand = 1;
	while (cin >> n) {
		getchar();
		getline(cin, command);
		for (int i = 1;i <= n;i++) {
			song.push_back(i);
		}

		for (int i = 0;i < command.size();i++) {
			if (command[i] == 'U') {
				set_pos(basepos, nowpos, n, command[i]);
			}
			else if (command[i] == 'D') {
				set_pos(basepos, nowpos, n, command[i]);
			}
		}
		for (int i = basepos;i < basepos + 4;i++) {
			cout << song[i - 1] << ' ';
		}
		cout << endl << song[nowpos - 1] << endl;
	}

	return 0;
}