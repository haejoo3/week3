#include "Str.h"
#include <cstring>
#include <iostream>
using namespace std;

Str::Str (int leng) { // string의 길이인 leng을 입력받아 길이가 leng인 문자열을 만듦
	if(leng < 0) { // 길이가 0보다 작으면 오류 메세지 출력
		cerr << "string length error!\n";
		len = 0;
	}
	str = new char[leng+1];
	for(int i = 0; i <= leng; i++) {
		str[i] = ' ';
	}
	str[leng] = '\0';
	len = leng;
}

Str::Str (char *neyong) { // 초기화할 내용인 neyong을 입력받음
	if(neyong == NULL) { // 입력받은 neyong이 NULL일 경우 오류 메세지 출력
		cerr << "char * error!\n";
		str = new char[1];
		str[0] = '\0';
		len = 0;
	}
	else {
		len = strlen(neyong);
		str = new char[len+1];
		strcpy(str, neyong); // 입력받은 neyong으로 str 초기화
	}
}

Str::~Str () { // 소멸자
	delete[] str;
}

int Str::length (void) { // string의 길이를 리턴하는 함수
	return len;
}

char *Str::contents (void) { // string의 내용을 리턴하는 함수
	return str;
}

int Str::compare (class Str& a) { // a의 내용과 str을 비교하는 함수
	return strcmp(str, a.contents());
}

int Str::compare(char *a) { // a의 내용과 str을 비교하는 함수
	return strcmp(str, a);
}

void Str::operator = (char * a) { // string의 값을 대입하는 함수
	delete[] str;	
	if(a == NULL) { // 입력받은 a가 NULL일 경우
		str = new char[0];
		str[0] = '\0';
		len = 0;
	}
	else {
		len = strlen(a);
		str = new char[len+1];
		strcpy(str, a);
	}
}

void Str::operator = (class Str& a) { // a의 내용을 대입하는 함수
	delete[] str;
	len = a.length();
	str = new char[len+1];
	strcpy(str, a.contents());
}