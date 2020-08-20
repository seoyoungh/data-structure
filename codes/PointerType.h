#ifndef _POINTERTYPE_H
#define _POINTERTYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "FolderType.h"

using namespace std;

class FolderType;

class PointerType 
{
public:

	/**
	*	constructor.
	*/
	PointerType()
	{
		p_Name = "";
		p_Address = NULL;
	}

	/**
	*	destructor.
	*/
	~PointerType()
	{

	}

	/**
	*	@brief	폴더명을 지정한다.
	*	@post	폴더명이 지정된다.
	*	@param	p_Name
	*/
	void SetName(string n)
	{
		p_Name = n;
	}

	/**
	*	@brief	폴더 메모리 주소를 지정한다.
	*	@post	폴더 메모리 주소가 지정된다.
	*	@param	p_Address
	*/
	void SetAddress(FolderType* f)
	{
		p_Address = f;
	}

	/**
	*	@brief	폴더 이름을 가져온다.
	*	@pre	폴더 이름이 지정되어 있다.
	*	@return	p_Name
	*/
	string GetName()
	{
		return p_Name;
	}

	/**
	*	@brief	폴더 메모리 주소를 가져온다.
	*	@pre	폴더 메모리 주소가 지정되어 있다.
	*	@return	p_Address
	*/
	FolderType* GetAddress()
	{
		return p_Address;
	}

	/**
	*	@brief	대입 연산자 오버로딩
	*/
	PointerType& operator=(const PointerType& data)
	{
		this->p_Name = data.p_Name;
		this->p_Address = data.p_Address;

		return *this;
	}

	/**
	*	@brief	쉬프트 연산자 오버로딩
	*/
	friend ostream& operator<<(ostream& os, const PointerType& data)
	{
		cout << data.p_Name; /// 이름 출력
		return os;
	}

	/**
	*	@brief	비교 연산자 오버로딩
	*/
	friend bool operator==(const PointerType& data1, const PointerType& data2)
	{
		return (data1.p_Name == data2.p_Name); /// 이름으로 값 비교
	}

	/**
	*	@brief	비교 연산자 오버로딩
	*/
	friend bool operator<(const PointerType& data1, const PointerType& data2)
	{
		return (data1.p_Name < data2.p_Name);
	};


protected:
	string p_Name;
	FolderType* p_Address;
};

#endif	/// _POINTERTYPE_H
