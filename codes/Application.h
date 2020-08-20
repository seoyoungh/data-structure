#pragma once

#ifndef _APPLICATION_H
#define _APPLICATION_H

#define BLACK 0
#define LIGHTBLUE 9
#define YELLOW 14
#define WHITE 15


#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>

using namespace std;

#include "FolderType.h"
#include "FileType.h"
#include "PointerType.h"
#include "CircularQueue.h"
#include "SortedArrayList.h"
#include "SortedLinkedList.h"


/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
		m_SortOption = 1;
		m_curFolder = &m_RootFolder;
		m_RootFolder.SetName("root"); /// 루트 폴더 이름 설정
		m_RootFolder.SetLocation("/root"); /// 루트 폴더 경로 설정
		m_RootFolder.SetDate(); /// 루트 폴더 생성 시간 설정
		m_RootFolder.SetOpenDate();
		m_RootFolder.IncreaseCount(); /// 루트 폴더오픈 카운트 증가
		/// 포인터 타입에 폴더 주소, 폴더 이름 저장
		PointerType tmp;
		tmp.SetAddress(&m_RootFolder);
		tmp.SetName("root");
		m_Recents.EnQueue(tmp); /// 열어본 폴더 리스트에 루트 폴더 추가
		pasteFolderOption = 0; /// 복사/잘라내기된 폴더가 없다는 옵션
		pasteFileOption = 0; /// 복사/잘라내기된 파일이 없다는 옵션
	}

	/**
	*	destructor.
	*/
	~Application() {}

	/// 콘솔 글씨 바꾸어주는 함수
	/// 출처 https:///andrew0409.tistory.com/162 
	void textcolor(int foreground, int background)
	{
		int color = foreground + background * 16;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	현재 폴더의 경로와 폴더 및 파일 목록을 보여준다.
	*	@pre	경로, 폴더리스트, 파일리스트가 존재해야 한다.
	*	@post	화면에 현재 폴더의 경로와 폴더 목록이 나타난다.
	*/
	void DisplayCurrentFolder();

	/// 이 아래로 폴더 관련 함수

	/**
	*	@brief	새로운 폴더를 추가한다. 
	*	@post	폴더가 폴더리스트에 추가된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int NewFolder();

	/**
	*	@brief	리스트에서 해당 Name을 가진 폴더를 찾아 제거한다.
	*	@pre	입력하는 폴더가 리스트에 존재해야 한다.
	*	@post	리스트에서 해당 폴더가 제거된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteFolder();

	/**
	*	@brief	해당 폴더를 연다.
	*	@pre	폴더가 루트폴더에 존재해야 한다.
	*	@post	해당 폴더의 sub folders 목록을 보여준다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int OpenFolder();

	/**
	*	@brief	해당 폴더의 이름을 변경한다.
	*	@pre	폴더가 존재해야 한다.
	*	@post	해당 폴더의 이름이 변경된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int RenameFolder();

	/**
	*	@brief	해당 폴더를 복사하고 붙여넣는다.
	*	@pre	폴더가 존재해야 한다.
	*	@post	해당 폴더의 위치가 변경된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int CopyPasteFolder();

	/**
	*	@brief	해당 폴더가 복제된다.
	*	@pre	폴더가 존재해야 한다.
	*	@post	해당 폴더의 복사본이 생성된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DuplicateFolder();

	/**
	*	@brief	Display Folder property on screen.
	*	@pre	파일이 존재해야 한다.
	*	@post	none.
	*/
	void DisplayFolderProperty();


	/// 이 아래로 파일 관련 함수

	/**
	*	@brief	새로운 파일을 추가한다. (txt 파일을 생성한다.)
	*	@post	파일이 파일리스트에 추가된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int NewFile();

	/**
	*	@brief	리스트에서 해당 Name을 가진 파일 찾아 제거한다.
	*	@pre	입력하는 파일이 리스트에 존재해야 한다.
	*	@post	리스트에서 해당 파일이 제거된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int MyDeleteFile();

	/**
	*	@brief	해당 파일을 연다.
	*	@pre	파일이 루트폴더에 존재해야 한다.
	*	@post	해당 파일을 실행한다. (txt파일이 출력된다.)
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int OpenFile();

	/**
	*	@brief	해당 폴더의 이름을 변경한다.
	*	@pre	폴더가 존재해야 한다.
	*	@post	해당 폴더의 이름이 변경된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int RenameFile();


	/**
	*	@brief	해당 파일을 복사하고 붙여넣는다.
	*	@pre	파일이 존재해야 한다.
	*	@post	해당 파일의 위치가 변경된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int CopyPasteFile();

	/**
	*	@brief	해당 파일이 복제된다.
	*	@pre	파일이 존재해야 한다.
	*	@post	해당 파일의 복사본이 생성된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DuplicateFile();

	/**
	*	@brief	Display File property on screen.
	*	@pre	파일이 존재해야 한다.
	*	@post	none.
	*/
	void DisplayFileProperty();

	/// 이 아래로 전체를 관리하는 함수

	/**
	*	@brief	리스트에서 해당 문자를 포함한 item을 모두 찾아 출력한다.
	*	@pre	없음.
	*	@post	찾은 item들이 출력된다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int Retrieve();

	/**
	*	@brief	최근 열어본 폴더를 출력한다.
	*	@pre	최근 열어본 폴더가 있어야 한다.
	*	@post	최근 열어본 폴더가 출력된다.
	*	@return 폴더 오픈시 1을 리턴, 오픈하지 않을시 0을 리턴.
	*/
	int DisplayRecents();

	/**
	*	@brief	자주 사용한 폴더를 출력한다.
	*	@pre	자주 사용한 폴더가 있어야 한다.
	*	@post	자주 사용한 폴더가 출력된다.
	*	@return 폴더 오픈시 1을 리턴, 오픈하지 않을시 0을 리턴.
	*/
	int DisplayFavourites();

	/**
	*	@brief	상위 폴더로 이동한다.
	*	@pre	none.
	*	@post	none.
	*/
	void GoToUpperFolder();

	/**
	*	@brief	현재 폴더를 정렬해서 보여준다.
	*	@pre	현재 폴더가 있어야 한다.
	*	@post	현재 폴더가 정렬되어 출력된다.
	*/
	void SortCurrentFolder();

	/**
	*	@brief	Display Current Folder property on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayCurrentFolderProperty();


private:
	int m_Command;				/// current command number.
	int m_SortOption;			/// 정렬 옵션
	FolderType m_RootFolder;	/// 가장 최상위 폴더.
	FolderType* m_curFolder;	/// 현재 가르키고 있는 폴더.
	CircularQueue<PointerType> m_Recents;	/// 최근 열어본 폴더 목록, 폴더의 주소값 가짐
	CircularQueue<PointerType> m_Favourites; /// 자주 사용한 폴더, 폴더의 주소값 가짐
	FolderType tmpFolder; /// 임시 폴더
	FileType tmpFile; ///  임시 파일
	int pasteFolderOption; /// 복사/잘라내기된 폴더가 있는지 확인하는 옵션
	int pasteFileOption; /// 복사/잘라내기된 파일이 있는지 확인하는 옵션
};

#endif	/// _APPLICATION_H