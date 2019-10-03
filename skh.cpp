#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "inf_int.h"

bool operator==(const inf_int& a, const inf_int& b) {
	for (unsigned int i = a.length; i > 0; i--) { // 자릿수 순회, 숫자가 거꾸로 저장되기 때문에 -- 사용
		if (*(a.digits + i - 1) != *(b.digits + i - 1)) return false; // 현재 자릿수가 a와 b가 다른 경우 false 출력
		else continue;
	}
	return true; // a와 b가 완전히 같음, true 출력
}

bool operator!=(const inf_int& a, const inf_int& b) {
	return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b) {
	if (a.thesign != b.thesign) { // a와 b의 부호가 서로 다를 경우
		return a.thesign; // a가 양수일 경우 true, b가 양수일 경우 false 반환
	}
	else { // a와 b의 부호가 서로 같을 경우
		 //a와 b의 길이 비교
		if (a.length > b.length) return a.thesign; // a의 길이가 더 길 경우 a가 양수이면 true, a가 음수이면 false 반환
		else if (a.length < b.length) return b.thesign; // a의 길이가 더 길 경우 a가 양수이면 true, a가 음수이면 false 반환
		else { // a와 b의 길이 또한 같을 경우
			for (unsigned int i = a.length; i > 0; i--) { // 자릿수 순회, 숫자가 거꾸로 저장되기 때문에 -- 사용
				if (*(a.digits + i - 1) > *(b.digits + i - 1)) return a.thesign; // 현재 자릿수가 a가 b보다 더 클 경우
				else if (*(a.digits + i - 1) < *(b.digits + i - 1)) return b.thesign; // 현재 자릿수가 a가 b보다 더 작을 경우
				else continue;
			}
			return false; // a와 b가 완전히 같음, false 출력
		}
	}
}

bool operator<(const inf_int& a, const inf_int& b) {
	return !operator>(a, b);
}
