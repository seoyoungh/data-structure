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
	*	@brief	대입 연산자 오버로딩
	*/
	SortedArrayList<T>& operator=(const SortedArrayList<T>& data);


	/**
	*	@brief	리스트를 비운다.
	*	@post	리스트가 비워진다.
	*/
	void MakeEmpty();

	/**
	*	@brief	현재 리스트 안에 있는 item의 개수를 가져온다.
	*	@return	현재 리스트 안에 있는 item의 개수.
	*/
	int GetLength();

	/**
	*	@brief	리스트가 비었는지 확인한다
	*	@return	리스트가 비었으면 return true, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	용량이 꽉 찼는지 확인한다.
	*	@return	용량이 꽉 찼으면 return true, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	primary key를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가한다.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data.
	*	@return	return 1 if this function works well, 중복되는 값이 있으면 -1, 리스트가 꽉찼으면 0 리턴.
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
	*	@brief	일부만 채워져있는 data(이름만)에 알맞은 정보를 저장한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	int Get(T& data);

	/**
	*	@brief	사용자가 지정한 ItemType를 배열에서 삭제한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	사용자가 입력한 항목은 삭제되고 length가 1줄어든다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int Delete(T data);

	/**
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다. 대상을 찾을때 Binary Search를 이용한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	int GetByBinarySearch(T& data);


	/**
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다. 대상을 찾을때 Binary Search를 이용한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	T* ReturnPointer(T& data);

	/**
	*	@brief	현재 포인터가 가르키는 항목을 반환한다.
	*	@return	현재 포인터가 가르키는 항목
	*/
	T GetCurrentItem();

	/**
	*	@brief	현재 포인터가 가르키는 항목의 주소값을 반환한다.
	*	@return	현재 포인터가 가르키는 항목의 주소값
	*/
	T* GetPoint();

private:
	T * m_Array;	/// list array
	int m_Length;	/// list 길이
	int m_CurPointer;	/// iterator pointer
	int m_MaxLength; /// list 최대 길이
};

template <typename T>
SortedArrayList<T>::SortedArrayList()
{
	m_MaxLength = MAXSIZE_L;
	m_Array = new T[m_MaxLength];
	m_Length = 0;
	ResetList();
}

/// 대입 연산자 오버로딩
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
	m_CurPointer++;	/// list pointer 증가
	if (m_CurPointer == m_MaxLength)	/// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	/// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

template <typename T>
int SortedArrayList<T>::Get(T& data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetName() == data.GetName())	/// data와 'm_Array 중 하나의 항목'의 이름이 같을 때
		{
			data = m_Array[i];
			return 1;	/// data에 멤버 변수 전체를 복사해준 뒤 1을 리턴한다.
		}
	}
	return 0;	/// 찾지 못하면 0을 리턴한다.
}

template <typename T>
int SortedArrayList<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i].GetName() == data.GetName())	/// data와 'm_Array 중 하나의 항목'의 ID값이 같을 때
		{
			for (int j = i; j<m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;	/// 지울 항목의 자리에 다음 항목을 복사하고 이것을 마지막 항목까지 반복한다. m_Length를 1 줄여준다.
			return 1;	/// 항목을 삭제하는데 성공했으므로 1을 리턴해준다.
		}
	}
	return 0;	/// 항목을 삭제하는데 실패했으므로 0을 리턴해준다.
}

template <typename T>
int SortedArrayList<T>::GetByBinarySearch(T& data)
{
	int first = 0;
	int last = m_Length - 1;
	bool found = 0;
	while (first <= last && !found)	/// first가 last보다 커지면 더이상 진행하지 않는다. found가 1이 되면 진행하지 않는다.
	{
		int mid = (first + last) / 2;	/// mid는 first와 last의 평균값
		switch (data.CompareByName(m_Array[mid]))	/// data와 m_Array[mid]의 ID값 비교
		{
		case LESS:
			last = mid - 1;
			break;	/// data의 ID값이 더 작을때, last를 mid-1로 옮겨준다.
		case GREATER:
			first = mid + 1;
			break;	/// data의 ID값이 더 클때, first를 mid+1로 옮겨준다.
		case EQUAL:
			data = m_Array[mid];
			found = 1;
			return 1;	/// data와 m_Array[mid]의 ID값이 같으면 data에 객체를 복사해주고 1을 리턴한다. 반복문을 빠져나오기 위해 found=1을 해준다.
			break;
		}
	}
	return 0;	/// 찾지 못했으므로 0을 리턴해준다.
}

template <typename T>
T* SortedArrayList<T>::ReturnPointer(T& data)
{
	int first = 0;
	int last = m_Length - 1;
	bool found = 0;
	while (first <= last && !found)	/// first가 last보다 커지면 더이상 진행하지 않는다. found가 1이 되면 진행하지 않는다.
	{
		int mid = (first + last) / 2;	/// mid는 first와 last의 평균값
		switch (data.CompareByName(m_Array[mid]))	/// data와 m_Array[mid]의 ID값 비교
		{
		case LESS:
			last = mid - 1;
			break;	/// data의 ID값이 더 작을때, last를 mid-1로 옮겨준다.
		case GREATER:
			first = mid + 1;
			break;	/// data의 ID값이 더 클때, first를 mid+1로 옮겨준다.
		case EQUAL:
			data = m_Array[mid]; /// data와 m_Array[mid]의 ID값이 같으면 data에 객체를 복사해준다.
			found = 1;
			return &m_Array[mid]; /// 해당 항목의 주소값을 가진 포인터를 리턴한다.
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