#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cstdlib>
#include <cstddef>
#include "inf_int.h"


inf_int& inf_int::operator=(const inf_int& rhs) {
	if (this->digits) delete this->digits; // ������ ���ڸ� ����
	this->digits = new char[rhs.length + 1]; // ���ο� digits ����
	memcpy(this->digits, rhs.digits, sizeof(char)*rhs.length + 1); // ���� ����

	this->length = rhs.length; // ���� ����
	this->thesign = rhs.thesign; // ��ȣ ����

	return *this;
}

bool operator==(const inf_int& lhs, const inf_int& rhs) {

	// 1. ��ȣ ��
	if (lhs.thesign != rhs.thesign) return false; // lhs�� rhs�� ��ȣ�� �ٸ� ��� false ���

	// 2. ���� ��
	if (lhs.length != rhs.length) return false; // lhs�� rhs�� ���̰� �ٸ� ��� false ���

	// 3. �ڸ��� ��
	for (std::size_t i = lhs.length; i > 0; i--) { // �ڸ��� ��ȸ, ���ڰ� �Ųٷ� ����Ǳ� ������ -- ���
		if (*(lhs.digits + i - 1) != *(rhs.digits + i - 1)) return false; // ���� �ڸ����� lhs�� rhs�� �ٸ� ��� false ���
		else continue;
	}
	return true; // lhs�� rhs�� ������ ����, true ���
}

bool operator!=(const inf_int& lhs, const inf_int& rhs) {
	return !operator==(lhs, rhs);
}

bool operator>(const inf_int& lhs, const inf_int& rhs) {

	// 1. ��ȣ ��
	if (lhs.thesign != rhs.thesign) return lhs.thesign; // �� ���� ��ȣ�� �ٸ� ��, lhs�� ����� ��� true, lhs�� ������ ��� false ��ȯ

	// 2. ���� ��
	if (lhs.length > rhs.length) return lhs.thesign; // lhs�� ���̰� �� �� ��� lhs�� ����̸� true, lhs�� �����̸� false ��ȯ
	else if (lhs.length < rhs.length) return !lhs.thesign; // rhs�� ���̰� �� �� ��� rhs�� ����̸� true, rhs�� �����̸� false ��ȯ

	// 3. �ڸ��� ��
	for (std::size_t i = lhs.length; i > 0; i--) { // �ڸ��� ��ȸ, ���ڰ� �Ųٷ� ����Ǳ� ������ -- ���
		if (*(lhs.digits + i - 1) > *(rhs.digits + i - 1)) return lhs.thesign; // ���� �ڸ����� lhs�� rhs���� �� Ŭ ���
		else if (*(lhs.digits + i - 1) < *(rhs.digits + i - 1)) return !lhs.thesign; // ���� �ڸ����� lhs�� rhs���� �� ���� ���
		else continue;
	}

	return false; // lhs�� rhs�� ������ ����, false ���
}

bool operator<(const inf_int& lhs, const inf_int& rhs) {

	// 1. ��ȣ ��
	if (lhs.thesign != rhs.thesign) return rhs.thesign; // �� ���� ��ȣ�� �ٸ� ��, rhs�� ����� ��� true, lhs�� ������ ��� false ��ȯ

	// 2. ���� ��
	if (lhs.length > rhs.length) return !lhs.thesign; // lhs�� ���̰� �� �� ��� lhs�� ����̸� false, lhs�� �����̸� true ��ȯ
	else if (lhs.length < rhs.length) return lhs.thesign; // rhs�� ���̰� �� �� ��� rhs�� ����̸� false, rhs�� �����̸� true ��ȯ

	// 3. �ڸ��� ��
	for (std::size_t i = lhs.length; i > 0; i--) { // �ڸ��� ��ȸ, ���ڰ� �Ųٷ� ����Ǳ� ������ -- ���
		if (*(lhs.digits + i - 1) > *(rhs.digits + i - 1)) return !lhs.thesign; // ���� �ڸ����� lhs�� rhs���� �� Ŭ ���
		else if (*(lhs.digits + i - 1) < *(rhs.digits + i - 1)) return lhs.thesign; // ���� �ڸ����� lhs�� rhs���� �� ���� ���
		else continue;
	}

	return false; // lhs�� rhs�� ������ ����, false ���
}