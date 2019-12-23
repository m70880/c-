#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) {
			return "";
		}
		if (strs.size() == 1) {
			return strs[0];
		}
		//"a"
		//"abc","ab","a"
		//"abcd","abc","a","b"
		int commond = 0;
		int minCommond;
		int size = strs.size();
		for (int i = 0;i < size - 1;i++) {
			if (strs[i].size() == 0 || strs[i + 1].size() == 0) {
				return "";
			}
			for (int j = 0;j < strs[i].size() && j < strs[i + 1].size(); j++) {
				if (strs[i][j] == strs[i + 1][j]) {
					commond++;
				}
				if (strs[i][j] != strs[i + 1][j] || strs[i].size() == commond || strs[i + 1].size()==commond)
				{//�˳�ʱ����¼��󹫹�ǰ׺�Ĵ�С��
					if (i == 0) {//��¼��һ�ι���ǰ׺�ĵĴ�С
						minCommond = commond;
					}
					if (commond < minCommond) {//�洢ÿ�αȽϵ���С����ǰ׺
						minCommond = commond;
					}
					commond = 0;
					break;
				}

			}
		}
		string result(strs[0]);
		result.resize(minCommond);
		return result;
	}

};
int main()
{
	Solution s;
	vector<string> vs;
	vs.push_back("flower");
	vs.push_back("flow");
	vs.push_back("flight");
	s.longestCommonPrefix(vs);
	return 0;
}
