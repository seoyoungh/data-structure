#pragma once
#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
#include "FolderType.h"

using namespace std;

#define MAXSIZE_L 5

class FolderType;

template <typename T>
class SortedArrayList
{
public:
	/**
	*	constructor.
	*/
	SortedArrayList();

	/**
	*	destructor.
	*/
	~SortedArrayList();

	/**
	*	@brief	���� ������ �����ε�
	*/
	SortedArrayList<T>& operator=(const SortedArrayList<T>& data);


	/**
	*	@brief	����Ʈ�� ����.
	*	@post	����Ʈ�� �������.
	*/
	void MakeEmpty();

	/**
	*	@brief	���� ����Ʈ �ȿ� �ִ� item�� ������ �����´�.
	*	@return	���� ����Ʈ �ȿ� �ִ� item�� ����.
	*/
	int GetLength();

	/**
	*	@brief	����Ʈ�� ������� Ȯ���Ѵ�
	*	@return	����Ʈ�� ������� return true, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	�뷮�� �� á���� Ȯ���Ѵ�.
	*	@return	�뷮�� �� á���� return true, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	primary key�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰��Ѵ�.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data.
	*	@return	return 1 if this function works well, �ߺ��Ǵ� ���� ������ -1, ����Ʈ�� ��á���� 0 ����.
	*/
	int Add(T data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	�Ϻθ� ä�����ִ� data(�̸���)�� �˸��� ������ �����Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	����ڰ� ������ ItemType�� �迭���� �����Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� �Է��� �׸��� �����ǰ� length�� 1�پ���.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Delete(T data);

	/**
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�. ����� ã���� Binary Search�� �̿��Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	int GetByBinarySearch(T& data);


	/**
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�. ����� ã���� Binary Search�� �̿��Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	T* ReturnPointer(T& data);

	/**
	*	@brief	���� �����Ͱ� ����Ű�� �׸��� ��ȯ�Ѵ�.
	*	@return	���� �����Ͱ� ����Ű�� �׸�
	*/
	T GetCurrentItem();

	/**
	*	@brief	���� �����Ͱ� ����Ű�� �׸��� �ּҰ��� ��ȯ�Ѵ�.
	*	@return	���� �����Ͱ� ����Ű�� �׸��� �ּҰ�
	*/
	T* GetPoint();

private:
	T * m_Array;	/// list array
	int m_Length;	/// list ����
	int m_CurPointer;	/// iterator pointer
	int m_MaxLength; /// list �ִ� ����
};

template <typename T>
SortedArrayList<T>::SortedArrayList()
{
	m_MaxLength = MAXSIZE_L;
	m_Array = new T[m_MaxLength];
	m_Length = 0;
	ResetList();
}

/// ���� ������ �����ε�
template <typename T>
SortedArrayList<T>& SortedArrayList<T>::operator=(const SortedArrayList<T>& data)
{
	this->m_MaxLength = data.m_MaxLength;
	this->m_Array = data.m_Array;
	this->m_Length = data.m_Length;
	return *this;
}


template <typename T>
SortedArrayList<T>::~SortedArrayList()
{
	delete[] m_Array;
}

template <typename T>
void SortedArrayList<T>::MakeEmpty()
{
	m_Length = 0;
}

template <typename T>
int SortedArrayList<T>::GetLength()
{
	return m_Length;
}

template <typename T>
bool SortedArrayList<T>::IsEmpty()
{
	if (m_Length == 0)
		return true;
	else
		return false;
}

template <typename T>
bool SortedArrayList<T>::IsFull()
{
	if (m_Length > MAXSIZE_L - 1)
		return true;
	else
		return false;
}

template <typename T>
int SortedArrayList<T>::Add(T data)
{
	if (IsFull())
	{
		T *tempArray;
		tempArray = new T[m_MaxLength];

		for (int i = 0; i < m_MaxLength; i++)
			tempArray[i] = m_Array[i];

		delete[] m_Array;
		m_Array = new T[m_MaxLength + 5];

		for (int i = 0; i < m_MaxLength; i++)
			m_Array[i] = tempArray[i];
		delete[] tempArray;

		m_MaxLength += 5;
	}

	else if (IsEmpty())
	{
		m_Array[0] = data;
		m_Length++;

		return 1;
	}

	for (int i = 0; i < m_Length; i++)
	{
		switch (m_Array[i].CompareByName(data))
		{
		case LESS:
			if (i == m_Length - 1)
			{
				m_Array[m_Length] = data;
				m_Length++;
				return 1;
			}
			break;
		case GREATER:
			for (int j = m_Length; j > i; j--)
			{
				m_Array[j] = m_Array[j - 1];
			}
			m_Array[i] = data;
			m_Length++;
			return 1;
			break;
		case EQUAL:
			return 0;
			break;
		}
	}
	return 0;
}

template <typename T>
void SortedArrayList<T>::ResetList()
{
	m_CurPointer = -1;
}

template <typename T>
int SortedArrayList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	/// list pointer ����
	if (m_CurPointer == m_MaxLength)	/// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	/// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

template <typename T>
int SortedArrayList<T>::Get(T& data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetName() == data.GetName())	/// data�� 'm_Array �� �ϳ��� �׸�'�� �̸��� ���� ��
		{
			data = m_Array[i];
			return 1;	/// data�� ��� ���� ��ü�� �������� �� 1�� �����Ѵ�.
		}
	}
	return 0;	/// ã�� ���ϸ� 0�� �����Ѵ�.
}

template <typename T>
int SortedArrayList<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i].GetName() == data.GetName())	/// data�� 'm_Array �� �ϳ��� �׸�'�� ID���� ���� ��
		{
			for (int j = i; j<m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;	/// ���� �׸��� �ڸ��� ���� �׸��� �����ϰ� �̰��� ������ �׸���� �ݺ��Ѵ�. m_Length�� 1 �ٿ��ش�.
			return 1;	/// �׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
		}
	}
	return 0;	/// �׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
}

template <typename T>
int SortedArrayList<T>::GetByBinarySearch(T& data)
{
	int first = 0;
	int last = m_Length - 1;
	bool found = 0;
	while (first <= last && !found)	/// first�� last���� Ŀ���� ���̻� �������� �ʴ´�. found�� 1�� �Ǹ� �������� �ʴ´�.
	{
		int mid = (first + last) / 2;	/// mid�� first�� last�� ��հ�
		switch (data.CompareByName(m_Array[mid]))	/// data�� m_Array[mid]�� ID�� ��
		{
		case LESS:
			last = mid - 1;
			break;	/// data�� ID���� �� ������, last�� mid-1�� �Ű��ش�.
		case GREATER:
			first = mid + 1;
			break;	/// data�� ID���� �� Ŭ��, first�� mid+1�� �Ű��ش�.
		case EQUAL:
			data = m_Array[mid];
			found = 1;
			return 1;	/// data�� m_Array[mid]�� ID���� ������ data�� ��ü�� �������ְ� 1�� �����Ѵ�. �ݺ����� ���������� ���� found=1�� ���ش�.
			break;
		}
	}
	return 0;	/// ã�� �������Ƿ� 0�� �������ش�.
}

template <typename T>
T* SortedArrayList<T>::ReturnPointer(T& data)
{
	int first = 0;
	int last = m_Length - 1;
	bool found = 0;
	while (first <= last && !found)	/// first�� last���� Ŀ���� ���̻� �������� �ʴ´�. found�� 1�� �Ǹ� �������� �ʴ´�.
	{
		int mid = (first + last) / 2;	/// mid�� first�� last�� ��հ�
		switch (data.CompareByName(m_Array[mid]))	/// data�� m_Array[mid]�� ID�� ��
		{
		case LESS:
			last = mid - 1;
			break;	/// data�� ID���� �� ������, last�� mid-1�� �Ű��ش�.
		case GREATER:
			first = mid + 1;
			break;	/// data�� ID���� �� Ŭ��, first�� mid+1�� �Ű��ش�.
		case EQUAL:
			data = m_Array[mid]; /// data�� m_Array[mid]�� ID���� ������ data�� ��ü�� �������ش�.
			found = 1;
			return &m_Array[mid]; /// �ش� �׸��� �ּҰ��� ���� �����͸� �����Ѵ�.
			break;
		}
	}
	return NULL;
}

template<typename T>
T SortedArrayList<T>::GetCurrentItem()
{
	return m_Array[m_CurPointer];
}


template<typename T>
T* SortedArrayList<T>::GetPoint()
{
	return &m_Array[m_CurPointer];
}

#endif	/// _SORTEDLIST_H