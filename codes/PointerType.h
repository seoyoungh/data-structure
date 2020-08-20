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
	*	@brief	�������� �����Ѵ�.
	*	@post	�������� �����ȴ�.
	*	@param	p_Name
	*/
	void SetName(string n)
	{
		p_Name = n;
	}

	/**
	*	@brief	���� �޸� �ּҸ� �����Ѵ�.
	*	@post	���� �޸� �ּҰ� �����ȴ�.
	*	@param	p_Address
	*/
	void SetAddress(FolderType* f)
	{
		p_Address = f;
	}

	/**
	*	@brief	���� �̸��� �����´�.
	*	@pre	���� �̸��� �����Ǿ� �ִ�.
	*	@return	p_Name
	*/
	string GetName()
	{
		return p_Name;
	}

	/**
	*	@brief	���� �޸� �ּҸ� �����´�.
	*	@pre	���� �޸� �ּҰ� �����Ǿ� �ִ�.
	*	@return	p_Address
	*/
	FolderType* GetAddress()
	{
		return p_Address;
	}

	/**
	*	@brief	���� ������ �����ε�
	*/
	PointerType& operator=(const PointerType& data)
	{
		this->p_Name = data.p_Name;
		this->p_Address = data.p_Address;

		return *this;
	}

	/**
	*	@brief	����Ʈ ������ �����ε�
	*/
	friend ostream& operator<<(ostream& os, const PointerType& data)
	{
		cout << data.p_Name; /// �̸� ���
		return os;
	}

	/**
	*	@brief	�� ������ �����ε�
	*/
	friend bool operator==(const PointerType& data1, const PointerType& data2)
	{
		return (data1.p_Name == data2.p_Name); /// �̸����� �� ��
	}

	/**
	*	@brief	�� ������ �����ε�
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
