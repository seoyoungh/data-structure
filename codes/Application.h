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
		m_RootFolder.SetName("root"); /// ��Ʈ ���� �̸� ����
		m_RootFolder.SetLocation("/root"); /// ��Ʈ ���� ��� ����
		m_RootFolder.SetDate(); /// ��Ʈ ���� ���� �ð� ����
		m_RootFolder.SetOpenDate();
		m_RootFolder.IncreaseCount(); /// ��Ʈ �������� ī��Ʈ ����
		/// ������ Ÿ�Կ� ���� �ּ�, ���� �̸� ����
		PointerType tmp;
		tmp.SetAddress(&m_RootFolder);
		tmp.SetName("root");
		m_Recents.EnQueue(tmp); /// ��� ���� ����Ʈ�� ��Ʈ ���� �߰�
		pasteFolderOption = 0; /// ����/�߶󳻱�� ������ ���ٴ� �ɼ�
		pasteFileOption = 0; /// ����/�߶󳻱�� ������ ���ٴ� �ɼ�
	}

	/**
	*	destructor.
	*/
	~Application() {}

	/// �ܼ� �۾� �ٲپ��ִ� �Լ�
	/// ��ó https:///andrew0409.tistory.com/162 
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
	*	@brief	���� ������ ��ο� ���� �� ���� ����� �����ش�.
	*	@pre	���, ��������Ʈ, ���ϸ���Ʈ�� �����ؾ� �Ѵ�.
	*	@post	ȭ�鿡 ���� ������ ��ο� ���� ����� ��Ÿ����.
	*/
	void DisplayCurrentFolder();

	/// �� �Ʒ��� ���� ���� �Լ�

	/**
	*	@brief	���ο� ������ �߰��Ѵ�. 
	*	@post	������ ��������Ʈ�� �߰��ȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int NewFolder();

	/**
	*	@brief	����Ʈ���� �ش� Name�� ���� ������ ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� ������ ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ���� �ش� ������ ���ŵȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteFolder();

	/**
	*	@brief	�ش� ������ ����.
	*	@pre	������ ��Ʈ������ �����ؾ� �Ѵ�.
	*	@post	�ش� ������ sub folders ����� �����ش�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int OpenFolder();

	/**
	*	@brief	�ش� ������ �̸��� �����Ѵ�.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@post	�ش� ������ �̸��� ����ȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RenameFolder();

	/**
	*	@brief	�ش� ������ �����ϰ� �ٿ��ִ´�.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@post	�ش� ������ ��ġ�� ����ȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int CopyPasteFolder();

	/**
	*	@brief	�ش� ������ �����ȴ�.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@post	�ش� ������ ���纻�� �����ȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DuplicateFolder();

	/**
	*	@brief	Display Folder property on screen.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@post	none.
	*/
	void DisplayFolderProperty();


	/// �� �Ʒ��� ���� ���� �Լ�

	/**
	*	@brief	���ο� ������ �߰��Ѵ�. (txt ������ �����Ѵ�.)
	*	@post	������ ���ϸ���Ʈ�� �߰��ȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int NewFile();

	/**
	*	@brief	����Ʈ���� �ش� Name�� ���� ���� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� ������ ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ���� �ش� ������ ���ŵȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int MyDeleteFile();

	/**
	*	@brief	�ش� ������ ����.
	*	@pre	������ ��Ʈ������ �����ؾ� �Ѵ�.
	*	@post	�ش� ������ �����Ѵ�. (txt������ ��µȴ�.)
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int OpenFile();

	/**
	*	@brief	�ش� ������ �̸��� �����Ѵ�.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@post	�ش� ������ �̸��� ����ȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RenameFile();


	/**
	*	@brief	�ش� ������ �����ϰ� �ٿ��ִ´�.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@post	�ش� ������ ��ġ�� ����ȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int CopyPasteFile();

	/**
	*	@brief	�ش� ������ �����ȴ�.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@post	�ش� ������ ���纻�� �����ȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DuplicateFile();

	/**
	*	@brief	Display File property on screen.
	*	@pre	������ �����ؾ� �Ѵ�.
	*	@post	none.
	*/
	void DisplayFileProperty();

	/// �� �Ʒ��� ��ü�� �����ϴ� �Լ�

	/**
	*	@brief	����Ʈ���� �ش� ���ڸ� ������ item�� ��� ã�� ����Ѵ�.
	*	@pre	����.
	*	@post	ã�� item���� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int Retrieve();

	/**
	*	@brief	�ֱ� ��� ������ ����Ѵ�.
	*	@pre	�ֱ� ��� ������ �־�� �Ѵ�.
	*	@post	�ֱ� ��� ������ ��µȴ�.
	*	@return ���� ���½� 1�� ����, �������� ������ 0�� ����.
	*/
	int DisplayRecents();

	/**
	*	@brief	���� ����� ������ ����Ѵ�.
	*	@pre	���� ����� ������ �־�� �Ѵ�.
	*	@post	���� ����� ������ ��µȴ�.
	*	@return ���� ���½� 1�� ����, �������� ������ 0�� ����.
	*/
	int DisplayFavourites();

	/**
	*	@brief	���� ������ �̵��Ѵ�.
	*	@pre	none.
	*	@post	none.
	*/
	void GoToUpperFolder();

	/**
	*	@brief	���� ������ �����ؼ� �����ش�.
	*	@pre	���� ������ �־�� �Ѵ�.
	*	@post	���� ������ ���ĵǾ� ��µȴ�.
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
	int m_SortOption;			/// ���� �ɼ�
	FolderType m_RootFolder;	/// ���� �ֻ��� ����.
	FolderType* m_curFolder;	/// ���� ����Ű�� �ִ� ����.
	CircularQueue<PointerType> m_Recents;	/// �ֱ� ��� ���� ���, ������ �ּҰ� ����
	CircularQueue<PointerType> m_Favourites; /// ���� ����� ����, ������ �ּҰ� ����
	FolderType tmpFolder; /// �ӽ� ����
	FileType tmpFile; ///  �ӽ� ����
	int pasteFolderOption; /// ����/�߶󳻱�� ������ �ִ��� Ȯ���ϴ� �ɼ�
	int pasteFileOption; /// ����/�߶󳻱�� ������ �ִ��� Ȯ���ϴ� �ɼ�
};

#endif	/// _APPLICATION_H