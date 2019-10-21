#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>	
#include<string>
using namespace std;
class Solution {
public:
	void plus(char &ret, int &carry , const char left = '0', const char right = '0') {
		int temp = left + right + carry - 2 * '0';
		ret = temp % 10 + '0';
		if (temp > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
	};
	string addStrings(string num1, string num2) {
		int big = num1.size();
		int small = num2.size();
		if (big < small) {
			swap(big, small);
		}
		string ret;
		ret.resize(big + 1, 0);
		int retpos = big;

		int leftpos = num1.size() - 1;
		int rightpos = num2.size() - 1;

		int temp = 0;
		int carry = 0;

		for (int i = small - 1;i >= 0;i--, leftpos--, rightpos--, retpos--) {
			plus(ret[retpos], carry, num1[leftpos], num2[rightpos]);
			/*temp = carry + num1[leftpos] + num2[rightpos] - 2 * '0';
			ret[retpos] = temp % 10 + '0';
			if (temp > 9) {
				carry = 1;
			}
			else {
				carry = 0;
			}*/
		}
		//拷贝大的字符串剩下的部分到ret中
		if (leftpos >= rightpos) { //num1>num2时
			for (;leftpos >= 0;retpos--, leftpos--) {
				plus(ret[retpos], carry, num1[leftpos]);
			}
			if (1 == carry) {
				ret[retpos] = '1';
				return ret;
			}
			else {
				return ret.substr(1);
			}
			//if (carry == 0) {    //当进位为0时
			//	for (int i = leftpos;leftpos >= 0;leftpos--, retpos--) {
			//		ret[retpos] = num1[leftpos];
			//	}
			//	return ret.substr(1);
			//}
			//else { //当进位为1时   
			//	for (int i = leftpos;leftpos >= 0;leftpos--, retpos--) {
			//		temp = carry + num1[leftpos] - '0';
			//		ret[retpos] = temp % 10 + '0';
			//		if (temp > 9) {
			//			carry = 1;
			//		}
			//		else {
			//			carry = 0;
			//		}
			//	}
			//	if (carry == 1) {
			//		ret[retpos] = '1';
			//		return ret;
			//	}
			//	return ret.substr(1);
			//}

		}
		else { //num2>num1时
			for (;rightpos >= 0;retpos--, rightpos--) {
				plus(ret[retpos], carry, num2[rightpos]);
			}
			if (1 == carry) {
				ret[retpos] = '1';
				return ret;
			}
			else {
				return ret.substr(1);
			}
			//if (carry == 0) {    //当进位为0时
			//	for (int i = rightpos;rightpos >= 0;rightpos--, retpos--) {
			//		ret[retpos] = num2[rightpos];
			//	}
			//	return ret.substr(1);
			//}
			//else { //当进位为1时   
			//	for (int i = rightpos;rightpos >= 0;rightpos--, retpos--) {
			//		temp = carry + num2[rightpos] - '0';
			//		ret[retpos] = temp % 10 + '0';
			//		if (temp > 9) {
			//			carry = 1;
			//		}
			//		else {
			//			carry = 0;
			//		}
			//	}
			//	if (carry == 1) {
			//		ret[retpos] = '1';
			//		return ret;
			//	}
			//	return ret.substr(1);
			//}

		}

	}
};
int main() {
	//"96423702883453279"
	//"72156405165936898"
	string s1 = "1";
	string s2 = "9";
	string ret;
	Solution a;
	ret = a.addStrings(s1, s2);
	cout << ret << endl;
	system("pause");
	return 0;
}