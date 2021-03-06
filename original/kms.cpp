/**
	@file   constructor.cpp
	@date   2019/10/04
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  생성자 소멸자
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <regex>
#include "inf_int.h"

inf_int::inf_int() {
	new (this) inf_int("0");
}

inf_int::inf_int(int arg_int) {
	int intTemp = arg_int;
	size_t intLen = 0;

	do {
		++intLen;
	} while (intTemp /= 10);

	char* intToStr = (char*)malloc(sizeof(char) * (intLen + 2));	//NULL 자리 포함해서 +1
	snprintf(intToStr, sizeof(char) * (intLen + 2), "%d", arg_int);	//NULL, 앞의 부호 자리 포함해서 +2 

	new (this) inf_int((const char*)intToStr);

	free(intToStr);
}


inf_int::inf_int(const char* arg_str) {
	//0으로만 이루어진 문자열은 "0"으로 생성자 호출
	std::regex onlyZero("^[-0]{2,}$");
	if (regex_match(arg_str, onlyZero)) {
		new (this) inf_int("0");
		return;
	}

	thesign = arg_str[0] != '-';

	size_t start_i = 0;
	for (size_t i = 0; i < strlen(arg_str); i++) {
		if (arg_str[i] >= '1' && arg_str[i] <= '9') {
			start_i = i;
			break;
		}
	}

	length = strlen(arg_str) - start_i;

	digits = (char*)malloc(sizeof(char) * length);

	for (size_t i = 1; i <= length; ++i)
		digits[length - i] = arg_str[start_i++] - '0';
}

inf_int::inf_int(const inf_int& arg_int) {
	digits = (char*)malloc(sizeof(char) * arg_int.length);
	memcpy(this->digits, arg_int.digits, sizeof(char) * arg_int.length);
	this->length = arg_int.length;
	this->thesign = arg_int.thesign;
}

inf_int::~inf_int() {
	free(digits);
}
