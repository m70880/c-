#include "FileCompressHuff.h"
#include "HuffmanTree.hpp"
#include <assert.h>
FileCompressHuff::FileCompressHuff() {
	_fileInfo.resize(256);
	for (int i = 0;i < 256;++i) {
		_fileInfo[i]._ch = (char)i;
		_fileInfo[i]._count = 0;
	}
}
void FileCompressHuff::CompressFile(const std::string& path) {
	//1.统计员文件中每个字符出现的次数
	FILE* fIn = fopen(path.c_str(), "rb");
	if (fIn == nullptr) {
		assert(false);
		return;
	}
	unsigned char* pReadBufff = new unsigned char[1024];
	size_t rdSize = 0;
	while (true) {
		rdSize=fread(pReadBufff, 1, 1024, fIn);//返回值为所读字节数
		if (rdSize == 0) break;

		for (size_t i = 0;i < rdSize;++i) {
			_fileInfo[pReadBufff[i]]._count++;
		}
	}
	//2.以这些字符出现的次数为权值创建Huffman树p
	HuffmanTree<CharInfo> t(_fileInfo,CharInfo(0));
	//3.获取每个字符的编码
	GenerateHuffmanCode(t.getRoot());
	//4.用获取的字符编码源文件
	string fileName = "2.txt";
	FILE* fout = fopen(fileName.c_str(), "wb");
	WriteHead(fout, GetFilePosFix(fileName));
	fseek(fIn, 0, SEEK_SET);
	if (fout == nullptr) {
		assert(false);
	}
	char ch = 0;
	while (true) {
		rdSize = fread(pReadBufff, 1, 1024, fIn);
		int count = 0;
		if (0 == rdSize)
			break;
		//根据字节的编码读取的内容进行重写
		for (size_t i = 0;i < rdSize;++i) {
			string strCode = _fileInfo[pReadBufff[i]]._strCode;
			for (size_t j = 0;j < strCode.size();j++) {
				ch <<= 1;
				//ch |= strCode[j] - '0';
				if (strCode[j] == '1') {
					ch |= 1;
				}
				count++;
				if (8 == count) {
					fputc(ch, fout);
					count = 0;
				}
			}
		}
		if (count > 0) {
			ch <<= (8 - count);
			fputc(ch, fout);
			count = 0;
		}
	}
	fclose(fout);
	fclose(fIn);
}
void FileCompressHuff::UNCompressFile(const std::string& path) {
	FILE* fIn = fopen(path.c_str(), "rb");
	if (fIn == nullptr) {
		assert(false);
		return;
	}
	//1.获取文件后缀
	std::string filePosFix;
	readLine(fIn, filePosFix);
	//2.字符信息的总行数获取
	std::string sline;
	readLine(fIn, sline);
	int line = atoi(sline.c_str());//十进制转换
	//A:1

	//3.获取压缩信息
	string strCount;
	for (int i = 0;i < line;i++) {
		readLine(fIn, strCount);
		if (strCount.empty()) {
			strCount += '\n';
			readLine(fIn, strCount);
			_fileInfo['\n']._count = atoi(strCount.c_str() + 1);
			continue;
		}
		_fileInfo[(unsigned char)strCount[0]]._count = atoi(strCount.c_str() + 2);
	}
	//4.还原Huffman树
	CharInfo no(0);
	HuffmanTree<CharInfo> t(_fileInfo, no);
	//5.获取编码信息
	char buff[1024];
	FILE* fout = fopen("3.txt", "wb");
	while (!feof(fout)) {
		int rdSize = fread(buff, 1, 1024, fIn);
		if (rdSize == 0)
			break;
		HuffmanTreeNode<CharInfo>* pCur = t.getRoot();
		size_t fileSize = pCur->_weight._count;
		int countChar = 0;
		for (int i = 0;i < rdSize;++i) {
			char ch = buff[i];
			for (int pos = 0;pos < 8;++pos) {//bug:若为空树
				if (ch&0x80) {
					pCur = pCur->right;
				}
				else {
					pCur = pCur->left;
				}
				ch <<= 1;
				if (nullptr == pCur->left && nullptr==pCur->right) {
					if (countChar == fileSize) {
						pCur = t.getRoot();

						break;
					}
					fputc(pCur->_weight._ch, fout);
					pCur = t.getRoot();
					countChar++;
				}
			}
		}
	}
	//6.解压缩

}


void FileCompressHuff::GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* pRoot) {
	typedef HuffmanTreeNode<CharInfo> Node;
	if (pRoot == nullptr)
		return;
		GenerateHuffmanCode(pRoot->left);
		GenerateHuffmanCode(pRoot->right);
		if (nullptr == pRoot->left&&nullptr == pRoot->right) {
			string& StrCode= _fileInfo[pRoot->_weight._ch]._strCode;
			Node* pCur = pRoot;
			Node* pParent = pCur->parent;

			while (pParent!=nullptr) {
				if (pCur == pParent->left) {
					StrCode += '0';
				}
				else if (pCur == pParent->right) {
					StrCode += '1';
				}
				pParent = pParent->parent;
				pCur = pCur->parent;
			}
			reverse(StrCode.begin(), StrCode.end());
			//_fileInfo[pRoot->_weight._ch]._strCode = StrCode;
		}
}
void FileCompressHuff::WriteHead(FILE* fout,const std::string& filePosFix) {
	assert(fout);
	string strHead;
	//filePosFix->文件后缀
	strHead += filePosFix + '\n';
	size_t line = 0;
	std::string strChCount;
	char szValue[32] = { 0 };
	for (int i = 0;i < 256;i++) {
		if (_fileInfo[i]._count != 0) {
			CharInfo& charInfo = _fileInfo[i];

			line++;

			strChCount += charInfo._ch;
			strChCount += ':';
			_itoa(charInfo._count, szValue, 10);
			strChCount += szValue;
			strChCount += '\n';
		}
	}

	_itoa(line, szValue, 10);//行数
	strHead += szValue;
	strHead += '\n';
	strHead += strChCount;
	fwrite(strHead.c_str(), 1,strHead.size(),fout);
}
string FileCompressHuff::GetFilePosFix(const string& fileName) {
	return fileName.substr(fileName.rfind('.'));
}
void FileCompressHuff::readLine(FILE* read,std::string& filePosFix) {
	char ch = 0;
	filePosFix = "";
	while (!feof(read)) {
		ch = fgetc(read);
		if (ch != '\n')
			filePosFix += ch;
		else
			return;
	}
}
