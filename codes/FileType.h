#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef _FILETYPE_H
#define _FILETYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

/// ���� Open�� ���� ���
/// #include opencv2\opencv.hpp
/// #include opencv2\highgui.hpp

/// ���� Open�� ���� ���
#include<stdio.h>
#include<Windows.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")

/// for renaming, deleting, getting a size
#include <stdio.h>

using namespace std;

/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };

template <typename T>
class SortedLinkedList;

class FileType
{
public:
	/**
	*	constructor.
	*/
	FileType();

	/**
	*	destructor.
	*/
	~FileType();

	RelationType CompareByName(const FileType& data);

	/**
	*	@brief	Ű����κ��� File Name �Է�.
	*	@pre	File Type�� �������־�� �Ѵ�.
	*	@post	File Name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	.jpg Ȯ������ �̹��� ������ ���� .
	*	@pre	�̹��� ������ �����ؾ� �Ѵ�.
	*	@return	return 1 if this function works well.
	*/
	int OpenImage();

	/**
	*	@brief	.wav Ȯ������ ���� ������ ����.
	*	@pre	�̹��� ������ �����ؾ� �Ѵ�.
	*	@return	return 1 if this function works well.
	*/
	int OpenMusic();

	/**
	*	@brief	���� ������Ʈ �������� ������ �����ȴ�.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@return	return 1 if this function works well.
	*/
	int Delete();

	/**
	*	@brief	���� ������Ʈ �������� ������ �̸��� �������ش�.
	*	@pre	������ �̸��� �����Ǿ��־�� �Ѵ�.
	*	@return	return 1 if this function works well.
	*/
	int Rename(string n);


	/**
	*	@brief	���� ������Ʈ �������� ������ ����� �����´�.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@return	return 1 if this function works well.
	*/
	int LoadSize();

	/**
	*	@brief	���� �ð� ��������.
	*	@pre	����.
	*	@post	���� �ð��� �����´�.
	*	@return	���� �ð�
	*/
	string MyGetCurrentTime();

	/**
	*	@brief	���� ������ �����ε�
	*/
	FileType& operator=(const FileType& data);

	/**
	*	@brief	����Ʈ ������ �����ε�
	*/
	friend ostream& operator<<(ostream& os, const FileType& data);

	/**
	*	@brief	�� ������ �����ε�
	*/
	friend bool operator==(const FileType& data1, const FileType& data2);

	/**
	*	@brief	�� ������ �����ε�
	*/
	friend bool operator<(const FileType& data1, const FileType& data2);

	/**
	*	@brief	���ϸ��� �����Ѵ�.
	*	@post	���ϸ��� �����ȴ�.
	*	@param	flName
	*/
	void SetName(string n)
	{
		flName = n + "." + GetType();
	}

	/**
	*	@brief	���ϸ��� �����Ѵ�.
	*	@post	���ϸ��� �����ȴ�.
	*	@param	flName
	*/
	void SetNameWoType(string n)
	{
		flName = n;
	}

	/**
	*	@brief	���� ��ġ�� �����Ѵ�.
	*	@post	���� ��ġ�� �����ȴ�.
	*	@param	flLocation
	*/
	void SetLocation(string n)
	{
		flLocation = n;
	}

	/**
	*	@brief	������ ������ ��¥�� �����Ѵ�.
	*	@post	������ ������ ��¥�� �����ȴ�.
	*	@param	flDate
	*/
	void SetDate()
	{
		string tmp = MyGetCurrentTime();
		flDate = tmp;
	}

	/**
	*	@brief	���� ũ�⸦ �����Ѵ�.
	*	@post	���� ũ�Ⱑ �����ȴ�.
	*	@param	flSize
	*/
	void SetSize(int n)
	{
		flSize = n;
	}



	/**
	*	@brief	���� Ÿ���� �����Ѵ�.
	*	@post	���� Ÿ���� �����ȴ�.
	*	@param	flType
	*/
	void SetType(string n)
	{
		flType = n;
	}

	/**
	*	@brief	�ֱ� ������ ��¥�� �����Ѵ�.
	*	@post	�ֱ� ������ ��¥�� �����ȴ�.
	*	@param	fdLastModifiedDate
	*/
	void SetModifyDate()
	{
		string tmp = MyGetCurrentTime();
		flLastModifiedDate = tmp;
	}

	/**
	*	@brief	���� ��¥�� �ֱ� ������ ��¥�� �����Ѵ�.
	*	@post	���� ��¥�� �ֱ� ������ ��¥�� �����Ѵ�.
	*	@param	fdLastModifiedDate
	*/
	void SetDateByDate()
	{
		flLastModifiedDate = flDate;
	}


	/**
	*	@brief	���� �̸��� �����´�.
	*	@pre	���� �̸��� �����Ǿ� �ִ�.
	*	@return	flName
	*/
	string GetName()
	{
		return flName;
	}

	/**
	*	@brief	���� ��ġ�� �����´�.
	*	@pre	���� ��ġ�� �����Ǿ� �ִ�.
	*	@return	flLocation
	*/
	string GetLocation()
	{
		return flLocation;
	}

	/**
	*	@brief	���� ���� ��¥�� �����´�.
	*	@pre	���� ���� ��¥�� �����Ǿ� �ִ�.
	*	@return	flDate
	*/
	string GetDate()
	{
		return flDate;
	}

	/**
	*	@brief	���� ����� �����´�.
	*	@pre	������ �����Ѵ�.
	*	@return	flSize
	*/
	int GetSize()
	{
		return flSize;
	}

	/**
	*	@brief	���� Ÿ���� �����´�.
	*	@post	���� Ÿ���� �����Ǿ� �ִ�.
	*	@return	flType
	*/
	string GetType()
	{
		return flType;
	}

	/**
	*	@brief	������ ���� �ð��� �����´�.
	*	@pre	������ ���� �ð��� �����Ǿ� �ִ�.
	*	@return	flLastModifiedDate
	*/
	string GetModifyDate()
	{
		return flLastModifiedDate;
	}

	/**
	*	@brief	���� �̸��� ǥ���Ѵ�.
	*	@pre	���� �̸��� �����Ǿ� �ִ�.
	*	@post	���� �̸��� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayName()
	{
		cout << flName << endl;
	}

	/**
	*	@brief	���� ��ġ�� ǥ���Ѵ�.
	*	@pre	���� ��ġ�� �����Ǿ� �ִ�.
	*	@post	���� ��ġ�� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayLocation()
	{
		cout << flLocation << endl;
	}

	/**
	*	@brief	���� ���� ��¥�� ǥ���Ѵ�.
	*	@pre	���� ���� ��¥�� �����Ǿ� �ִ�.
	*	@post	���� ���� ��¥�� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayDate()
	{
		cout << flDate << endl;
	}

	/**
	*	@brief	���� ũ�⸦ ǥ���Ѵ�.
	*	@pre	���� ũ�Ⱑ �����Ǿ� �ִ�.
	*	@post	���� ũ�Ⱑ ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplaySize()
	{
		cout << flSize << endl;
	}

	/**
	*	@brief	���� �ֱ� ���� ��¥�� ǥ���Ѵ�.
	*	@pre	���� �ֱ� ���� ��¥�� �����Ǿ� �ִ�.
	*	@post	���� �ֱ� ���� ��¥�� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayModifyDate()
	{
		cout << flLastModifiedDate << endl;
	}

	/**
	*	@brief	���� �Ӽ��� ǥ���Ѵ�.
	*	@pre	���� �Ӽ��� �����Ǿ� �ִ�.
	*	@post	���� �Ӽ��� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayProperty()
	{
		cout << "\t==== ���� �Ӽ� ====" << endl;
		cout << "\t�̸�: ";
		DisplayName();
		cout << "\t���: ";
		DisplayLocation();
		cout << "\t���� ������: ";
		DisplaySize();
		cout << "\t���� ��¥: ";
		DisplayDate();
		cout << "\t�ֱ� ������ ��¥: ";
		DisplayModifyDate();
	}


	/// LPCWSTR ��ȯ�� �Լ�
	wstring s2ws(const string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	};

protected:
	string flName;
	string flLocation;
	string flDate;
	string flType; /// ���� Ÿ��
	int flSize; /// ���� ������
	string flLastModifiedDate; /// �ֱ� ������ ��¥
};

#endif	/// _FILETYPE_H