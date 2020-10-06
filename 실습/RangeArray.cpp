#include "RangeArray.h"
#include <iostream>
#include <cstdlib>
using namespace std;

RangeArray::RangeArray (int low, int high) : Array (high - low + 1) { // 생성자
	this->low = low;
	this->high = high;
}

RangeArray::~RangeArray () { // 소멸자
}

int RangeArray::baseValue () { // index의 최소값
	return low;
}

int RangeArray::endValue () { // index의 최대값
	return high;
}


// 배열에 원소를 대입하거나 값을 반환하는 부분으로 []연산자의 다중정의이다.
int & RangeArray::operator[](int i) { // left value : 배열에 원소를 삽입
	static int tmp;
	if (low <= i && i <= high) { // 배열의 인덱스가 범위 내에 있으면 해당 원소를 리턴
		return data[i-low];
	}
	else { // 그렇지 않으면 에러 메시지 출력하고 tmp를 리턴
		cerr << "Array bound error!" << endl;
		return tmp;
	}
}

int RangeArray::operator[] (int i) const { // right value : 배열의 원소의 값을 반환	
	if (low <= i && i <= high) { // 배열의 인덱스가 범위 내에 있으면 값을 리턴
		return data[i-low];
	}
	else { // 그렇지 않으면 에러 메시지 출력하고 0을 리턴
		cerr << "Array bound error!" << endl;
		return 0;
	}
}