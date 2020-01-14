#pragma once
#include <string>
#include <vector>
#include "HuffmanTree.hpp"
struct CharInfo {
	CharInfo(const int date = 0) {
		_count = date;
	}
	unsigned char _ch;
	size_t _count;
	std::string _strCode;
	CharInfo operator+(const CharInfo c) const{
		return CharInfo(_count + c._count);
	}
	bool operator>(const CharInfo ch)const{
		return _count > ch._count;
	}
	bool operator==(const CharInfo c)const {
		return _count == c._count;
	}
};
class FileCompressHuff {
public:
	FileCompressHuff();
	//----------------------------------------------------
	void CompressFile(const std::string& path);  
	void UNCompressFile(const std::string& path);
	//--------------------------------------------------
private:
	void GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* pRoot);
	void WriteHead(FILE* fout,const std::string& filePosFix);
	string GetFilePosFix(const string& fileName);
	void readLine(FILE* read,std::string &filePosFix);
private:
	std::vector<CharInfo> _fileInfo;
};
