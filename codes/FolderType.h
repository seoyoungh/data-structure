#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef _FOLDERTYPE_H
#define _FOLDERTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include "CircularQueue.h"
#include "SortedLinkedList.h"
#include "SortedLinkedList.h"
#include "FileType.h"
#include "PointerType.h"

using namespace std;

template <typename T>
class SortedLinkedList;

class FolderType
{
public:
	/**
	*	constructor.
	*/
	FolderType();

	/**
	*	destructor.
	*/
	~FolderType();

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByName(const FolderType& data);

	/**
	*	@brief	키보드로부터 Folder Name 입력.
	*	@pre	none.
	*	@post	Folder Name is set.
	*/
	void SetNameFromKB();

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
	FolderType& operator=(const FolderType& data);

	/**
	*	@brief	쉬프트 연산자 오버로딩
	*/
	friend ostream& operator<<(ostream& os, const FolderType& data);

	/**
	*	@brief	비교 연산자 오버로딩
	*/
	friend bool operator==(const FolderType& data1, const FolderType& data2);

	/**
	*	@brief	비교 연산자 오버로딩
	*/
	friend bool operator<(const FolderType& data1, const FolderType& data2);

	/**
	*	@brief	새폴더 정보를 키보드로부터 읽어서 폴더리스트에 추가, sortedList를 동적으로 할당하여 초기화 하고 추가
	*	@pre	list should be initialized.
	*	@post	added the folder into the list.
	*	@param	data.
	*	@return	return 1 if this function works well.
	*/
	int AddFolder();

	/**
	*	@brief	Parameter로 받은 폴더를 폴더리스트에 추가
	*	@pre	list should be initialized.
	*	@post	added the folder into the list.
	*	@param	data.
	*	@return	return 1 if this function works well.
	*/
	int AddFolder_P(FolderType data);

	/**
	*	@brief	삭제할 폴더 정보를 키보드로부터 읽어서 해당 폴더를 찾아서 삭제
	*	@post	사용자가 입력한 항목은 삭제된다.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int DeleteFolder();

	/**
	*	@brief	이름을 변경할 폴더 정보를 키보드로부터 읽어서 해당 파일을 찾아 이름 변경
	*	@post	폴더의 이름이 변경된다.
	*	@param	기존 폴더, 바꿀 폴더 이름
	*	@return 해당 폴더를 찾아 변경에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int RenameFolder(FolderType& f, string n);

	/**
	*	@brief	해당 폴더의 이름 변경시 Sub folders, filese의 경로를 수정해준다.
	*	@post	Sub folders, files의 경로가 변경된다.
	*/
	void RelocateSubComponents();

	/**
	*	@brief	Sub filese의 경로를 수정해준다.
	*	@post	Sub files의 경로가 변경된다.
	*/
	void RelocateSubFiles();

	/**
	*	@brief	현재 폴더를 복제해 새로운 폴더를 추가한다.
	*	@pre	현재 폴더가 존재해야한다.
	*	@post	현재 폴더의 복사본이 생성된다.
	*	@return	폴더의 복사본이 리턴된다.
	*/
	FolderType DuplicateFolder();

	/**
	*	@brief	현재 파일을 복제해 새로운 파일을 추가한다.
	*	@pre	현재 파일이 존재해야한다.
	*	@post	현재 파일의 복사본이 생성된다.
	*	@return 파일의 복사본이 리턴된다.
	*/
	FileType DuplicateFile(FileType* data);

	/**
	*	@brief	열고 싶은 폴더의 포인터를 반환해준다.
	*	@post	해당 폴더가 존재해야 한다.
	*	@return 해당되는 폴더를 찾아 폴더 포인터 리턴.
	*/
	FolderType* OpenSubFolder(FolderType& data);


	/**
	*	@brief	현재 폴더의 file list에서 해당 검색어를 포함한 파일을 찾는다.
	*	@post	찾은 아이템 이름들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int RetrieveFileByKeyword(string& key);

	/**
	*	@brief	검색어를 키보드로부터 읽어서 리스트에서 해당 검색어을 포함한 폴더, 파일을 찾는다.
	*	@post	찾은 아이템 이름들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int RetrieveByKeyword(string& key);

	/**
	*	@brief	폴더 이름을 받아 해당 폴더의 존재 여부를 확인한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int RetrieveFolderByName(FolderType& data);

	/**
	*	@brief	모든 서브 폴더 이름 화면 출력 (이름순)
	*	@post	모든 서브 폴더의 이름들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void DisplayAllFoldersByName();


	/**
	*	@brief	모든 서브 폴더 이름 화면 출력 (만든 날짜순)
	*	@post	모든 서브 폴더의 이름들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void DisplayAllFoldersByDate();


	/**
	*	@brief	모든 서브 폴더 이름 화면 출력 (크기순)
	*	@post	모든 서브 폴더의 이름들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void DisplayAllFoldersBySize();

	/**
	*	@brief	새 파일 정보를 키보드로부터 읽어서 리스트에 추가
	*	@pre	list should be initialized.
	*	@post	added the file into the list.
	*	@param	data.
	*	@return	return 1 if this function works well.
	*/
	int AddFile();

	/**
	*	@brief	Parameter로 받은 파일을 파일리스트에 추가
	*	@pre	list should be initialized.
	*	@post	added the folder into the list.
	*	@param	data.
	*	@return	return 1 if this function works well.
	*/
	int AddFile_P(FileType data);

	/**
	*	@brief	삭제할 파일 정보를 키보드로부터 읽어서 해당 파일을 찾아서 삭제
	*	@post	사용자가 입력한 항목은 삭제된다.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int MyDeleteFile();

	/**
	*	@brief	해당 파일을 연다.
	*	@post	해당 txt 파일의 내용이 출력된다.
	*	@return return 1 if this function works well.
	*/
	int OpenFile(FileType& data);

	/**
	*	@brief	이름을 변경할 파일 정보를 키보드로부터 읽어서 해당 파일을 찾아 이름 변경
	*	@post	파일의 이름이 변경된다.
	*	@param	기존 이름, 바꿀 폴더 이름
	*	@return 해당 파일을 찾아 변경에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int RenameFile(FileType& f, string n);

	/**
	*	@brief	파일 이름을 받아 해당 파일의 존재 여부를 확인한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int RetrieveFileByName(FileType& data);

	/**
	*	@brief	모든 서브 파일 이름 화면 출력 (이름순)
	*	@post	모든 서브 파일의 이름들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void DisplayAllFilesByName();

	/**
	*	@brief	모든 서브 파일 이름 화면 출력 (만든 날짜순)
	*	@post	모든 서브 파일의 이름들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void DisplayAllFilesByDate();


	/**
	*	@brief	모든 서브 파일 이름 화면 출력 (크기순)
	*	@post	모든 서브 파일의 이름들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void DisplayAllFilesBySize();

	/**
	*	@brief	폴더를 열어본 count를 +1 해준다.
	*	@post	count의 크기가 1 증가
	*/
	void IncreaseCount();

	/**
	*	@brief	폴더명을 지정한다.
	*	@post	폴더명이 지정된다.
	*	@param	fdName
	*/
	void SetName(string n)
	{
		fdName = n;
	}

	/**
	*	@brief	폴더 위치를 지정한다.
	*	@post	폴더 위치가 지정된다.
	*	@param	fdLocation
	*/
	void SetLocation(string n)
	{
		fdLocation = n;
	}

	/**
	*	@brief	폴더를 생성한 날짜를 지정한다.
	*	@post	폴더를 생성한 날짜가 지정된다.
	*	@param	fdDate
	*/
	void SetDate()
	{
		string tmp = MyGetCurrentTime();
		fdDate = tmp;
	}


	/**
	*	@brief	폴더 사이즈를 지정한다.
	*	@post	폴더 사이즈가 지정된다.
	*	@param	fdSize
	*/
	void SetSize(int command, int num)
	{
		/// command가 -1일때 (사이즈 빼기)
		if (command == -1)
		{
			fdSize = fdSize - num;
		}

		/// command가 1일때 (사이즈 늘리기)
		if (command == 1)
		{
			fdSize = fdSize + num;
		}

	}

	/**
	*	@brief	최근 열어본 날짜를 수정한다.
	*	@post	최근 열어본 날짜를 수정된다.
	*	@param	fdLastOpenedDate
	*/
	void SetOpenDate()
	{
		fdLastOpenedDate = MyGetCurrentTime();
	}

	/**
	*	@brief	최근 수정한 날짜를 수정한다.
	*	@post	최근 수정한 날짜를 수정된다.
	*	@param	fdLastModifiedDate
	*/
	void SetModifyDate()
	{
		string tmp = MyGetCurrentTime();
		fdLastModifiedDate = tmp;
	}

	/**
	*	@brief	폴더 이름을 가져온다.
	*	@pre	폴더 이름이 지정되어 있다.
	*	@return	fdName
	*/
	string GetName()
	{
		return fdName;
	}

	/**
	*	@brief	폴더 위치를 가져온다.
	*	@pre	폴더 위치가 지정되어 있다.
	*	@return	fdLocation
	*/
	string GetLocation()
	{
		return fdLocation;
	}

	/**
	*	@brief	폴더 생성 날짜를 가져온다.
	*	@pre	폴더 생성 날짜가 지정되어 있다.
	*	@return	fdDate
	*/
	string GetDate()
	{
		return fdDate;
	}

	/**
	*	@brief	폴더 크기를 가져온다.
	*	@pre	폴더 크기가 지정되어 있다.
	*	@return	fdSize
	*/
	int GetSize()
	{
		return fdSize;
	}

	/**
	*	@brief	폴더 오픈 count를 가져온다.
	*	@pre	폴더 오픈 count가 지정되어 있다.
	*	@return	count
	*/
	int GetCount()
	{
		return fdCount;
	}

	/**
	*	@brief	하위 폴더 개수를 가져온다.
	*	@pre	하위 폴더 개수가 지정되어 있다.
	*	@return	fdSubFolderNum
	*/
	int GetSubFolderNum()
	{
		return fdSubFolderNum;
	}

	/**
	*	@brief	하위 파일 개수를 가져온다.
	*	@pre	하위 파일 개수가 지정되어 있다.
	*	@return	fdSubFileNum
	*/
	int GetSubFileNum()
	{
		return fdSubFileNum;
	}

	/**
	*	@brief	마지막 오픈 시간을 가져온다.
	*	@pre	마지막 오픈 시간이 지정되어 있다.
	*	@return fdLastOpenedDate
	*/
	string GetOpenDate()
	{
		return fdLastOpenedDate;
	}

	/**
	*	@brief	마지막 수정 시간을 가져온다.
	*	@pre	마지막 수정 시간이 지정되어 있다.
	*	@return	fdLastModifiedDate
	*/
	string GetModifyDate()
	{
		return fdLastModifiedDate;
	}

	/**
	*	@brief	하위 폴더 리스트를 불러온다.
	*	@pre	하위 폴더 리스트가 존재한다.
	*	@return	fdFolderList
	*/
	SortedLinkedList<FolderType>* GetFolderList()
	{
		return fdFolderList;
	}

	/**
	*	@brief	하위 파일 리스트를 불러온다.
	*	@pre	하위 파일 리스트가 존재한다.
	*	@return	fdFileList
	*/
	SortedLinkedList<FileType>* GetFileList()
	{
		return fdFileList;
	}

	/**
	*	@brief	상위 폴더 주소값을 가져온다.
	*	@pre	상위 폴더가 지정되어 있다.
	*	@return	fdUpper
	*/
	FolderType* GetUpperFolder()
	{
		return fdUpper;
	}


	/**
	*	@brief	폴더 이름을 표시한다.
	*	@pre	폴더 이름이 지정되어 있다.
	*	@post	폴더 이름이 화면에 표시된다.
	*/
	void DisplayName()
	{
		cout << fdName << endl;
	}

	/**
	*	@brief	폴더 위치를 표시한다.
	*	@pre	폴더 위치가 지정되어 있다.
	*	@post	폴더 위치가 화면에 표시된다.
	*/
	void DisplayLocation()
	{
		cout << fdLocation << endl;
	}

	/**
	*	@brief	폴더 크기를 표시한다.
	*	@pre	폴더 크기가 지정되어 있다.
	*	@post	폴더 크기가 화면에 표시된다.
	*/
	void DisplaySize()
	{
		cout << fdSize << " byte" << endl;
	}

	/**
	*	@brief	폴더 생성 날짜를 표시한다.
	*	@pre	폴더 생성 날짜가 지정되어 있다.
	*	@post	폴더 생성 날짜가 화면에 표시된다.
	*/
	void DisplayDate()
	{
		cout << fdDate << endl;
	}

	/**
	*	@brief	폴더 최근 수정 날짜를 표시한다.
	*	@pre	폴더 최근 수정 날짜가 지정되어 있다.
	*	@post	폴더 최근 수정 날짜가 화면에 표시된다.
	*/
	void DisplayModifyDate()
	{
		cout << fdLastModifiedDate << endl;
	}

	/**
	*	@brief	폴더 최근 열어본 날짜를 표시한다.
	*	@pre	폴더 최근 열어본 날짜가 지정되어 있다.
	*	@post	폴더 최근 열어본 날짜가 화면에 표시된다.
	*/
	void DisplayOpenDate()
	{
		cout << fdLastOpenedDate << endl;
	}

	/**
	*	@brief	하위폴더 개수를 표시한다.
	*	@pre	하위폴더 개수가 지정되어있다.
	*	@post	하위폴더 개수가 화면에 표시된다.
	*/
	void DisplayFolderNum()
	{
		cout << fdSubFolderNum << endl;
	}

	/**
	*	@brief	하위파일 개수를 표시한다.
	*	@pre	하위파일 개수가 지정되어있다.
	*	@post	하위파일 개수가 화면에 표시된다.
	*/
	void DisplayFileNum()
	{
		cout << fdSubFileNum << endl;
	}

	/**
	*	@brief	폴더 속성을 표시한다.
	*	@pre	폴더 속성이 지정되어 있다.
	*	@post	폴더 속성이 화면에 표시된다.
	*/
	void DisplayProperty()
	{
		cout << "\t==== 현재 폴더 속성 ====" << endl;
		cout << "\t이름: ";
		DisplayName();
		cout << "\t경로: ";
		DisplayLocation();
		cout << "\t폴더 사이즈: ";
		DisplaySize();
		cout << "\t생성 날짜: ";
		DisplayDate();
		cout << "\t최근 수정한 날짜: ";
		DisplayModifyDate();
		cout << "\t최근 열어본 날짜: ";
		DisplayOpenDate();
		cout << "\t하위 폴더 개수: ";
		DisplayFolderNum();
		cout << "\t하위 파일 개수: ";
		DisplayFileNum();
	};



protected:
	string fdName; /// 폴더명
	string fdLocation; /// 폴더 위치
	string fdDate; /// 생성 날짜
	int fdSize; /// 폴더 사이즈
	int fdCount; /// 사용한 횟수
	string fdLastModifiedDate; /// 최근 수정한 날짜
	string fdLastOpenedDate; /// 최근 열어본 날짜
	int fdSubFolderNum; /// 하위 폴더 개수
	int fdSubFileNum; /// 하위 파일 개수
	SortedLinkedList<FolderType>* fdFolderList; /// 서브 폴더 리스트
	SortedLinkedList<FileType>* fdFileList; /// 서브 파일 리스트
	FolderType* fdUpper; /// 상위폴더 주소값을 갖는 포인터
};

#endif	/// _FOLDERTYPE_H
