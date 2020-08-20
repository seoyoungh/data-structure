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
	*	@brief	Ű����κ��� Folder Name �Է�.
	*	@pre	none.
	*	@post	Folder Name is set.
	*/
	void SetNameFromKB();

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
	FolderType& operator=(const FolderType& data);

	/**
	*	@brief	����Ʈ ������ �����ε�
	*/
	friend ostream& operator<<(ostream& os, const FolderType& data);

	/**
	*	@brief	�� ������ �����ε�
	*/
	friend bool operator==(const FolderType& data1, const FolderType& data2);

	/**
	*	@brief	�� ������ �����ε�
	*/
	friend bool operator<(const FolderType& data1, const FolderType& data2);

	/**
	*	@brief	������ ������ Ű����κ��� �о ��������Ʈ�� �߰�, sortedList�� �������� �Ҵ��Ͽ� �ʱ�ȭ �ϰ� �߰�
	*	@pre	list should be initialized.
	*	@post	added the folder into the list.
	*	@param	data.
	*	@return	return 1 if this function works well.
	*/
	int AddFolder();

	/**
	*	@brief	Parameter�� ���� ������ ��������Ʈ�� �߰�
	*	@pre	list should be initialized.
	*	@post	added the folder into the list.
	*	@param	data.
	*	@return	return 1 if this function works well.
	*/
	int AddFolder_P(FolderType data);

	/**
	*	@brief	������ ���� ������ Ű����κ��� �о �ش� ������ ã�Ƽ� ����
	*	@post	����ڰ� �Է��� �׸��� �����ȴ�.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int DeleteFolder();

	/**
	*	@brief	�̸��� ������ ���� ������ Ű����κ��� �о �ش� ������ ã�� �̸� ����
	*	@post	������ �̸��� ����ȴ�.
	*	@param	���� ����, �ٲ� ���� �̸�
	*	@return �ش� ������ ã�� ���濡 ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int RenameFolder(FolderType& f, string n);

	/**
	*	@brief	�ش� ������ �̸� ����� Sub folders, filese�� ��θ� �������ش�.
	*	@post	Sub folders, files�� ��ΰ� ����ȴ�.
	*/
	void RelocateSubComponents();

	/**
	*	@brief	Sub filese�� ��θ� �������ش�.
	*	@post	Sub files�� ��ΰ� ����ȴ�.
	*/
	void RelocateSubFiles();

	/**
	*	@brief	���� ������ ������ ���ο� ������ �߰��Ѵ�.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ ���纻�� �����ȴ�.
	*	@return	������ ���纻�� ���ϵȴ�.
	*/
	FolderType DuplicateFolder();

	/**
	*	@brief	���� ������ ������ ���ο� ������ �߰��Ѵ�.
	*	@pre	���� ������ �����ؾ��Ѵ�.
	*	@post	���� ������ ���纻�� �����ȴ�.
	*	@return ������ ���纻�� ���ϵȴ�.
	*/
	FileType DuplicateFile(FileType* data);

	/**
	*	@brief	���� ���� ������ �����͸� ��ȯ���ش�.
	*	@post	�ش� ������ �����ؾ� �Ѵ�.
	*	@return �ش�Ǵ� ������ ã�� ���� ������ ����.
	*/
	FolderType* OpenSubFolder(FolderType& data);


	/**
	*	@brief	���� ������ file list���� �ش� �˻�� ������ ������ ã�´�.
	*	@post	ã�� ������ �̸����� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetrieveFileByKeyword(string& key);

	/**
	*	@brief	�˻�� Ű����κ��� �о ����Ʈ���� �ش� �˻����� ������ ����, ������ ã�´�.
	*	@post	ã�� ������ �̸����� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetrieveByKeyword(string& key);

	/**
	*	@brief	���� �̸��� �޾� �ش� ������ ���� ���θ� Ȯ���Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetrieveFolderByName(FolderType& data);

	/**
	*	@brief	��� ���� ���� �̸� ȭ�� ��� (�̸���)
	*	@post	��� ���� ������ �̸����� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void DisplayAllFoldersByName();


	/**
	*	@brief	��� ���� ���� �̸� ȭ�� ��� (���� ��¥��)
	*	@post	��� ���� ������ �̸����� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void DisplayAllFoldersByDate();


	/**
	*	@brief	��� ���� ���� �̸� ȭ�� ��� (ũ���)
	*	@post	��� ���� ������ �̸����� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void DisplayAllFoldersBySize();

	/**
	*	@brief	�� ���� ������ Ű����κ��� �о ����Ʈ�� �߰�
	*	@pre	list should be initialized.
	*	@post	added the file into the list.
	*	@param	data.
	*	@return	return 1 if this function works well.
	*/
	int AddFile();

	/**
	*	@brief	Parameter�� ���� ������ ���ϸ���Ʈ�� �߰�
	*	@pre	list should be initialized.
	*	@post	added the folder into the list.
	*	@param	data.
	*	@return	return 1 if this function works well.
	*/
	int AddFile_P(FileType data);

	/**
	*	@brief	������ ���� ������ Ű����κ��� �о �ش� ������ ã�Ƽ� ����
	*	@post	����ڰ� �Է��� �׸��� �����ȴ�.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int MyDeleteFile();

	/**
	*	@brief	�ش� ������ ����.
	*	@post	�ش� txt ������ ������ ��µȴ�.
	*	@return return 1 if this function works well.
	*/
	int OpenFile(FileType& data);

	/**
	*	@brief	�̸��� ������ ���� ������ Ű����κ��� �о �ش� ������ ã�� �̸� ����
	*	@post	������ �̸��� ����ȴ�.
	*	@param	���� �̸�, �ٲ� ���� �̸�
	*	@return �ش� ������ ã�� ���濡 ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int RenameFile(FileType& f, string n);

	/**
	*	@brief	���� �̸��� �޾� �ش� ������ ���� ���θ� Ȯ���Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int RetrieveFileByName(FileType& data);

	/**
	*	@brief	��� ���� ���� �̸� ȭ�� ��� (�̸���)
	*	@post	��� ���� ������ �̸����� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void DisplayAllFilesByName();

	/**
	*	@brief	��� ���� ���� �̸� ȭ�� ��� (���� ��¥��)
	*	@post	��� ���� ������ �̸����� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void DisplayAllFilesByDate();


	/**
	*	@brief	��� ���� ���� �̸� ȭ�� ��� (ũ���)
	*	@post	��� ���� ������ �̸����� ��µȴ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void DisplayAllFilesBySize();

	/**
	*	@brief	������ ��� count�� +1 ���ش�.
	*	@post	count�� ũ�Ⱑ 1 ����
	*/
	void IncreaseCount();

	/**
	*	@brief	�������� �����Ѵ�.
	*	@post	�������� �����ȴ�.
	*	@param	fdName
	*/
	void SetName(string n)
	{
		fdName = n;
	}

	/**
	*	@brief	���� ��ġ�� �����Ѵ�.
	*	@post	���� ��ġ�� �����ȴ�.
	*	@param	fdLocation
	*/
	void SetLocation(string n)
	{
		fdLocation = n;
	}

	/**
	*	@brief	������ ������ ��¥�� �����Ѵ�.
	*	@post	������ ������ ��¥�� �����ȴ�.
	*	@param	fdDate
	*/
	void SetDate()
	{
		string tmp = MyGetCurrentTime();
		fdDate = tmp;
	}


	/**
	*	@brief	���� ����� �����Ѵ�.
	*	@post	���� ����� �����ȴ�.
	*	@param	fdSize
	*/
	void SetSize(int command, int num)
	{
		/// command�� -1�϶� (������ ����)
		if (command == -1)
		{
			fdSize = fdSize - num;
		}

		/// command�� 1�϶� (������ �ø���)
		if (command == 1)
		{
			fdSize = fdSize + num;
		}

	}

	/**
	*	@brief	�ֱ� ��� ��¥�� �����Ѵ�.
	*	@post	�ֱ� ��� ��¥�� �����ȴ�.
	*	@param	fdLastOpenedDate
	*/
	void SetOpenDate()
	{
		fdLastOpenedDate = MyGetCurrentTime();
	}

	/**
	*	@brief	�ֱ� ������ ��¥�� �����Ѵ�.
	*	@post	�ֱ� ������ ��¥�� �����ȴ�.
	*	@param	fdLastModifiedDate
	*/
	void SetModifyDate()
	{
		string tmp = MyGetCurrentTime();
		fdLastModifiedDate = tmp;
	}

	/**
	*	@brief	���� �̸��� �����´�.
	*	@pre	���� �̸��� �����Ǿ� �ִ�.
	*	@return	fdName
	*/
	string GetName()
	{
		return fdName;
	}

	/**
	*	@brief	���� ��ġ�� �����´�.
	*	@pre	���� ��ġ�� �����Ǿ� �ִ�.
	*	@return	fdLocation
	*/
	string GetLocation()
	{
		return fdLocation;
	}

	/**
	*	@brief	���� ���� ��¥�� �����´�.
	*	@pre	���� ���� ��¥�� �����Ǿ� �ִ�.
	*	@return	fdDate
	*/
	string GetDate()
	{
		return fdDate;
	}

	/**
	*	@brief	���� ũ�⸦ �����´�.
	*	@pre	���� ũ�Ⱑ �����Ǿ� �ִ�.
	*	@return	fdSize
	*/
	int GetSize()
	{
		return fdSize;
	}

	/**
	*	@brief	���� ���� count�� �����´�.
	*	@pre	���� ���� count�� �����Ǿ� �ִ�.
	*	@return	count
	*/
	int GetCount()
	{
		return fdCount;
	}

	/**
	*	@brief	���� ���� ������ �����´�.
	*	@pre	���� ���� ������ �����Ǿ� �ִ�.
	*	@return	fdSubFolderNum
	*/
	int GetSubFolderNum()
	{
		return fdSubFolderNum;
	}

	/**
	*	@brief	���� ���� ������ �����´�.
	*	@pre	���� ���� ������ �����Ǿ� �ִ�.
	*	@return	fdSubFileNum
	*/
	int GetSubFileNum()
	{
		return fdSubFileNum;
	}

	/**
	*	@brief	������ ���� �ð��� �����´�.
	*	@pre	������ ���� �ð��� �����Ǿ� �ִ�.
	*	@return fdLastOpenedDate
	*/
	string GetOpenDate()
	{
		return fdLastOpenedDate;
	}

	/**
	*	@brief	������ ���� �ð��� �����´�.
	*	@pre	������ ���� �ð��� �����Ǿ� �ִ�.
	*	@return	fdLastModifiedDate
	*/
	string GetModifyDate()
	{
		return fdLastModifiedDate;
	}

	/**
	*	@brief	���� ���� ����Ʈ�� �ҷ��´�.
	*	@pre	���� ���� ����Ʈ�� �����Ѵ�.
	*	@return	fdFolderList
	*/
	SortedLinkedList<FolderType>* GetFolderList()
	{
		return fdFolderList;
	}

	/**
	*	@brief	���� ���� ����Ʈ�� �ҷ��´�.
	*	@pre	���� ���� ����Ʈ�� �����Ѵ�.
	*	@return	fdFileList
	*/
	SortedLinkedList<FileType>* GetFileList()
	{
		return fdFileList;
	}

	/**
	*	@brief	���� ���� �ּҰ��� �����´�.
	*	@pre	���� ������ �����Ǿ� �ִ�.
	*	@return	fdUpper
	*/
	FolderType* GetUpperFolder()
	{
		return fdUpper;
	}


	/**
	*	@brief	���� �̸��� ǥ���Ѵ�.
	*	@pre	���� �̸��� �����Ǿ� �ִ�.
	*	@post	���� �̸��� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayName()
	{
		cout << fdName << endl;
	}

	/**
	*	@brief	���� ��ġ�� ǥ���Ѵ�.
	*	@pre	���� ��ġ�� �����Ǿ� �ִ�.
	*	@post	���� ��ġ�� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayLocation()
	{
		cout << fdLocation << endl;
	}

	/**
	*	@brief	���� ũ�⸦ ǥ���Ѵ�.
	*	@pre	���� ũ�Ⱑ �����Ǿ� �ִ�.
	*	@post	���� ũ�Ⱑ ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplaySize()
	{
		cout << fdSize << " byte" << endl;
	}

	/**
	*	@brief	���� ���� ��¥�� ǥ���Ѵ�.
	*	@pre	���� ���� ��¥�� �����Ǿ� �ִ�.
	*	@post	���� ���� ��¥�� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayDate()
	{
		cout << fdDate << endl;
	}

	/**
	*	@brief	���� �ֱ� ���� ��¥�� ǥ���Ѵ�.
	*	@pre	���� �ֱ� ���� ��¥�� �����Ǿ� �ִ�.
	*	@post	���� �ֱ� ���� ��¥�� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayModifyDate()
	{
		cout << fdLastModifiedDate << endl;
	}

	/**
	*	@brief	���� �ֱ� ��� ��¥�� ǥ���Ѵ�.
	*	@pre	���� �ֱ� ��� ��¥�� �����Ǿ� �ִ�.
	*	@post	���� �ֱ� ��� ��¥�� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayOpenDate()
	{
		cout << fdLastOpenedDate << endl;
	}

	/**
	*	@brief	�������� ������ ǥ���Ѵ�.
	*	@pre	�������� ������ �����Ǿ��ִ�.
	*	@post	�������� ������ ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayFolderNum()
	{
		cout << fdSubFolderNum << endl;
	}

	/**
	*	@brief	�������� ������ ǥ���Ѵ�.
	*	@pre	�������� ������ �����Ǿ��ִ�.
	*	@post	�������� ������ ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayFileNum()
	{
		cout << fdSubFileNum << endl;
	}

	/**
	*	@brief	���� �Ӽ��� ǥ���Ѵ�.
	*	@pre	���� �Ӽ��� �����Ǿ� �ִ�.
	*	@post	���� �Ӽ��� ȭ�鿡 ǥ�õȴ�.
	*/
	void DisplayProperty()
	{
		cout << "\t==== ���� ���� �Ӽ� ====" << endl;
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
		cout << "\t�ֱ� ��� ��¥: ";
		DisplayOpenDate();
		cout << "\t���� ���� ����: ";
		DisplayFolderNum();
		cout << "\t���� ���� ����: ";
		DisplayFileNum();
	};



protected:
	string fdName; /// ������
	string fdLocation; /// ���� ��ġ
	string fdDate; /// ���� ��¥
	int fdSize; /// ���� ������
	int fdCount; /// ����� Ƚ��
	string fdLastModifiedDate; /// �ֱ� ������ ��¥
	string fdLastOpenedDate; /// �ֱ� ��� ��¥
	int fdSubFolderNum; /// ���� ���� ����
	int fdSubFileNum; /// ���� ���� ����
	SortedLinkedList<FolderType>* fdFolderList; /// ���� ���� ����Ʈ
	SortedLinkedList<FileType>* fdFileList; /// ���� ���� ����Ʈ
	FolderType* fdUpper; /// �������� �ּҰ��� ���� ������
};

#endif	/// _FOLDERTYPE_H
