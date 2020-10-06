#include "Array.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Array::Array(int size) { // 생성자
	if (size <= 0) { // size가 0 이하 값이면 에러메시지 출력하고 종료
		cerr << "Size error!" << endl; 
		exit(-1);
	}
	data = new int[size]; // size가 양수이면 new를 사용하여 배열 data를 할당, len값 초기화	
	if (data == NULL) {
		cerr << " Memory allocation error!" << endl;
		exit(-1);
	}
	len = size;
}

Array::~Array() { //소멸자; 할당된 메모리 해제
	delete[] data;
}

int Array::length() { // 배열의 크기 리턴
	return len;
}

// 배열에 원소를 대입하거나 값을 반환하는 부분으로 []연산자의 다중정의이다.
int & Array::operator [](int i) { // left value : 배열에 원소를 삽입
	static int tmp;
	if (0 <= i && i < len) { // 배열의 인덱스가 범위 내에 있으면 해당 원소를 리턴
		return data[i];
	}	
	else { // 그렇지 않으면 에러 메시지 출력하고 tmp를 리턴
		cerr << "Array bound error!" << endl;
		return tmp;
	}
}

int Array::operator [](int i) const { // right value : 배열의 원소의 값을 반환
	if (0 <= i && i < len) { // 배열의 인덱스가 범위 내에 있으면 값을 리턴
		return data[i];
	}	
	else { // 그렇지 않으면 에러 메시지 출력하고 0을 리턴
		cerr << "Index error!" << endl;
		return 0;
	}
}

void Array::print() { // 배열의 모든 내용을 출력해주는 함수
	cout << '[';
	for (int i = 0; i < len; i++) {
		cout << ' ' << data[i];
	}
	cout << "]" << endl;
}