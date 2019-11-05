#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person {
public:
	Person()
		:name("null")
		,sex("ÄÐ")
	{}
protected:
	char name[32];
	char sex[3];
};

class student :public Person
{
public:
	student() 
		:studentId("null")
		,college("null")
	{}
protected:
	char studentId[12];
	char college[32];
};

int main() {

	student s;
	return 0;
}