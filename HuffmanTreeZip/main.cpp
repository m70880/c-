#include "FileCompressHuff.h"
int main() {
	
	FileCompressHuff h,u;
	h.CompressFile("1.txt");
	u.UNCompressFile("2.txt");
	return 0;
}