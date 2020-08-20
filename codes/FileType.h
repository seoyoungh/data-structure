#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef _FILETYPE_H
#define _FILETYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

/// 사진 Open을 위한 헤더
/// #include opencv2\opencv.hpp
/// #include opencv2\highgui.hpp

/// 음악 Open을 위한 헤더
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
	*	@brief	키보드로부터 File Name 입력.
	*	@pre	File Type이 정해져있어야 한다.
	*	@post	File Name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	.jpg 확장자의 이미지 파일을 연다 .
	*	@pre	이미지 파일이 존재해야 한다.
	*	@return	return 1 if this function works well.
	*/
	int OpenImage();

	/**
	*	@brief	.wav 확장자의 음악 파일을 연다.
	*	@pre	이미지 파일이 존재해야 한다.
	*	@return	return 1 if this function works well.
	*/
	int OpenMusic();

	/**
	*	@brief	실제 프로젝트 폴더에서 파일이 삭제된다.
	*	@pre	파일이 존재해야 한다.
	*	@return	return 1 if this function works well.
	*/
	int Delete();

	/**
	*	@brief	실제 프로젝트 폴더에서 파일의 이름을 변경해준다.
	*	@pre	파일의 이름이 지정되어있어야 한다.
	*	@return	return 1 if this function works well.
	*/
	int Rename(string n);


	/**
	*	@brief	실제 프로젝트 폴더에서 파일의 사이즈를 가져온다.
	*	@pre	파일이 존재해야 한다.
	*	@return	return 1 if this function works well.
	*/
	int LoadSize();

	/**
	*	@brief	현재 시간 가져오기.
	*	@pre	없음.
	*	@post	현재 시간을 가져온다.
	*	@return	현재 시간
	*/
	string MyGetCurrentTime();

	/**
	*	@brief	대입 연산자 오버로딩
	*/
	FileType& operator=(const FileType& data);

	/**
	*	@brief	쉬프트 연산자 오버로딩
	*/
	friend ostream& operator<<(ostream& os, const FileType& data);

	/**
	*	@brief	비교 연산자 오버로딩
	*/
	friend bool operator==(const FileType& data1, const FileType& data2);

	/**
	*	@brief	비교 연산자 오버로딩
	*/
	friend bool operator<(const FileType& data1, const FileType& data2);

	/**
	*	@brief	파일명을 지정한다.
	*	@post	파일명이 지정된다.
	*	@param	flName
	*/
	void SetName(string n)
	{
		flName = n + "." + GetType();
	}

	/**
	*	@brief	파일명을 지정한다.
	*	@post	파일명이 지정된다.
	*	@param	flName
	*/
	void SetNameWoType(string n)
	{
		flName = n;
	}

	/**
	*	@brief	파일 위치를 지정한다.
	*	@post	파일 위치가 지정된다.
	*	@param	flLocation
	*/
	void SetLocation(string n)
	{
		flLocation = n;
	}

	/**
	*	@brief	파일을 생성한 날짜를 지정한다.
	*	@post	파일을 생성한 날짜가 지정된다.
	*	@param	flDate
	*/
	void SetDate()
	{
		string tmp = MyGetCurrentTime();
		flDate = tmp;
	}

	/**
	*	@brief	파일 크기를 지정한다.
	*	@post	파일 크기가 지정된다.
	*	@param	flSize
	*/
	void SetSize(int n)
	{
		flSize = n;
	}



	/**
	*	@brief	파일 타입을 지정한다.
	*	@post	파일 타입이 지정된다.
	*	@param	flType
	*/
	void SetType(string n)
	{
		flType = n;
	}

	/**
	*	@brief	최근 수정한 날짜를 수정한다.
	*	@post	최근 수정한 날짜를 수정된다.
	*	@param	fdLastModifiedDate
	*/
	void SetModifyDate()
	{
		string tmp = MyGetCurrentTime();
		flLastModifiedDate = tmp;
	}

	/**
	*	@brief	만든 날짜로 최근 수정한 날짜를 수정한다.
	*	@post	만든 날짜로 최근 수정한 날짜를 수정한다.
	*	@param	fdLastModifiedDate
	*/
	void SetDateByDate()
	{
		flLastModifiedDate = flDate;
	}


	/**
	*	@brief	파일 이름을 가져온다.
	*	@pre	파일 이름이 지정되어 있다.
	*	@return	flName
	*/
	string GetName()
	{
		return flName;
	}

	/**
	*	@brief	파일 위치를 가져온다.
	*	@pre	파일 위치가 지정되어 있다.
	*	@return	flLocation
	*/
	string GetLocation()
	{
		return flLocation;
	}

	/**
	*	@brief	파일 생성 날짜를 가져온다.
	*	@pre	파일 생성 날짜가 지정되어 있다.
	*	@return	flDate
	*/
	string GetDate()
	{
		return flDate;
	}

	/**
	*	@brief	파일 사이즈를 가져온다.
	*	@pre	파일이 존재한다.
	*	@return	flSize
	*/
	int GetSize()
	{
		return flSize;
	}

	/**
	*	@brief	파일 타입을 가져온다.
	*	@post	파일 타입이 지정되어 있다.
	*	@return	flType
	*/
	string GetType()
	{
		return flType;
	}

	/**
	*	@brief	마지막 수정 시간을 가져온다.
	*	@pre	마지막 수정 시간이 지정되어 있다.
	*	@return	flLastModifiedDate
	*/
	string GetModifyDate()
	{
		return flLastModifiedDate;
	}

	/**
	*	@brief	파일 이름을 표시한다.
	*	@pre	파일 이름이 지정되어 있다.
	*	@post	파일 이름이 화면에 표시된다.
	*/
	void DisplayName()
	{
		cout << flName << endl;
	}

	/**
	*	@brief	파일 위치를 표시한다.
	*	@pre	파일 위치가 지정되어 있다.
	*	@post	파일 위치가 화면에 표시된다.
	*/
	void DisplayLocation()
	{
		cout << flLocation << endl;
	}

	/**
	*	@brief	파일 생성 날짜를 표시한다.
	*	@pre	파일 생성 날짜가 지정되어 있다.
	*	@post	파일 생성 날짜가 화면에 표시된다.
	*/
	void DisplayDate()
	{
		cout << flDate << endl;
	}

	/**
	*	@brief	파일 크기를 표시한다.
	*	@pre	파일 크기가 지정되어 있다.
	*	@post	파일 크기가 화면에 표시된다.
	*/
	void DisplaySize()
	{
		cout << flSize << endl;
	}

	/**
	*	@brief	파일 최근 수정 날짜를 표시한다.
	*	@pre	파일 최근 수정 날짜가 지정되어 있다.
	*	@post	파일 최근 수정 날짜가 화면에 표시된다.
	*/
	void DisplayModifyDate()
	{
		cout << flLastModifiedDate << endl;
	}

	/**
	*	@brief	폴더 속성을 표시한다.
	*	@pre	폴더 속성이 지정되어 있다.
	*	@post	폴더 속성이 화면에 표시된다.
	*/
	void DisplayProperty()
	{
		cout << "\t==== 파일 속성 ====" << endl;
		cout << "\t이름: ";
		DisplayName();
		cout << "\t경로: ";
		DisplayLocation();
		cout << "\t파일 사이즈: ";
		DisplaySize();
		cout << "\t생성 날짜: ";
		DisplayDate();
		cout << "\t최근 수정한 날짜: ";
		DisplayModifyDate();
	}


	/// LPCWSTR 변환용 함수
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
	string flType; /// 파일 타입
	int flSize; /// 파일 사이즈
	string flLastModifiedDate; /// 최근 수정한 날짜
};

#endif	/// _FILETYPE_H