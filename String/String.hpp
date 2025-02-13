#pragma once

#ifndef STRING_HPP
#define STRING_HPP

#include <string.h>
#include <iostream>
#include <type_traits>

class String {
public:
	String();
	explicit String(int);
	String(const char*);
	
	~String();
	String(const String&);
	String& operator=(const String&);

	String(String&&)noexcept;
	String& operator=(String&&)noexcept;

	friend String operator+(const String& lhs, const String& rhs);
	friend String operator+(char lhs, const String& rhs);
	friend String operator+(const String& lhs, char rhs);

	String& operator+=(const String& rhs);
	String& operator+=(char rhs);

	friend bool operator	==	(const String& lhs, const String& rhs);
	friend bool operator	!=	(const String& lhs, const String& rhs);
	friend bool operator	<	(const String& lhs, const String& rhs);
	friend bool operator	<=	(const String& lhs, const String& rhs);
	friend bool operator	>	(const String& lhs, const String& rhs);
	friend bool operator	>=	(const String& lhs, const String& rhs);

	auto operator[](int i)noexcept			-> char&;
	auto operator[](int i)const noexcept	-> const char&;

	auto at(int i)		-> char&;
	auto at(int i)const	-> const char&;

	int size()const;
	int capacity()const;
	void reserve(int new_capacity);
	void shrink_to_fit();
	void clean();

	bool empty()const;

	//class iterator{};
	//class const_iterator{};
	//class right_iterator{};
	//class const_right_iterator{};

	//iterator begin();
	//iterator end();
	//const_iterator cbegin();
	//const_iterator cend();

	//right_iterator rbegin();
	//right_iterator rend();
	//const_right_iterator crbegin();
	//const_right_iterator crend();

	const char* c_str()const;
	char* data();

	void push_back(char ch);
	void pop_back();

	//void emplace_back(char ch);
	//
	//void insert(iterator& place, char ch);
	//void emplace(iterator& place, char ch);

	//void eraise(iterator& place);
	//void eraise(iterator& start,iterator& end);

	friend std::ostream& operator<<(std::ostream& out, const String& obj);
	friend std::istream& operator>>(std::istream& in, const String& obj);

private:
	struct{
		char* allocate	(int size);
		void  deallocate(char* place);
		void  reallocate(char*& place, int old_size, int new_size);
	}allocator_;
	int capacity_;
	char* str_;
};

/*
������� 1
	����������� ������ ���������-���������� ��������� ����
	��������� new � delete, ���� ������� ���������� ������ 
	�� ���������� stdlib.h
������� 2
	����������� ��� ������������ ������ String
	� ���� ������������� �� ������ ������������ ���������
	new/delete ��� ������� ���������� ������ 
	�� ���������� stdlib.h
������� 3
	����������� ���������� ������ � ��������� ������������.
	� ���� ������� �� ������ ������������ ���������
	new/delete ��� ������� ���������� ������
	�� ���������� stdlib.h
������� 4
	����� 1
	����������� �� ������������������ ���������.
	� ���� ������� �� ������ ������������ ���������
	new/delete ��� ������� ���������� ������
	�� ���������� stdlib.h
	����� 2
	���������� ��� ����� � �������� ������� ��� ��������� 
	� ������������������ ����������������� ����� �������������� ����
	� ������� main
������� 5
	����� 1
	����������� �� ������������������ ������ ������
	� ���� ������� �� ������ ������������ ���������
	new/delete ��� ������� ���������� ������
	�� ���������� stdlib.h
	����� 2
	���������� ��� ����� � �������� ������� ��� ���������
	� ������������������ ����������������� ����� �������������� ����
	� ������� main
������� 6* 
	�������� ������ unit-������������ ��� ������ ������ String

13.02.2025 ������� �������� ������
*/

#endif // !STRING_HPP
