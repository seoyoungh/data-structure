#pragma once
#include <iostream>

using namespace std;

#define MAXSIZE_Q 10

/**
*	@brief	Exception class thrown by Push when stack is full.
*/
class FullQueue
{
public:
	/**
	*	@brief	Exception class thrown by Pop and Top when stack is empty.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};

/**
*	@brief	Exception class thrown by Pop and Top when stack is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	큐가 비었을 때 메세지 출력.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

/**
*	@brief	CircularQueue Class
*/
template <class T>
class CircularQueue
{
public:
	/**
	*	@brief	MAXSIZE 만큼의 사이즈를 가진 큐를 초기화한다.
	*	@pre	MAXSIZE가 정의되어야 한다.

	*/
	CircularQueue();

	/**
	*	@brief	MAXSIZE만큼의 사이즈를 가진 큐를 초기화한다.
	*	@pre	MAXSIZE가 정의되어야한다.
	*	@post	size의 값에 해당되는 크기의 배열이 만들어진다.
	*	@param	size
	*/
	CircularQueue(int size);

	/**
	*	@brief	destructor
	*/
	~CircularQueue();

	/**
	*	@brief	큐가 꽉찼는지 확인한다.
	*	@pre	큐가 초기화 되어야한다.
	*	@return	큐가 꽉찼으면 1, 아닌 경우에 0을 출력.
	*/
	bool IsFull();

	/**
	*	@brief	큐가 비었는지 확인한다.
	*	@pre	큐가 초기화 되어야한다.
	*	@return	큐가 비었으면 1, 아닌 경우에 0을 출력.
	*/
	bool IsEmpty();

	/**
	*	@brief	큐안의 내용을 모두 삭제한다.
	*	@pre	큐가 존재해야한다.
	*	@post	큐가 비워진다.
	*/
	void MakeEmpty();

	/**
	*	@brief	큐에 새로운 자료를 추가한다.
	*	@pre	큐가 존재해야한다.
	*	@post	큐에 새로운 자료가 추가된다.
	*/
	void EnQueue(T newItem);

	/**
	*	@brief	큐의 제일 먼저 들어온 자료부터 출력한다.
	*	@pre	큐가 존재해야한다.
	*	@post	큐의 데이터를 삭제한다.
	*/
	void DeQueue(T& item);

	/**
	*	@brief	큐에 모든 아이템을 출력한다.
	*	@pre	큐가 존재해야한다.
	*	@return 큐가 비어있으면 return 0, otherwise return 1.
	*/
	int Print();

	/**
	*	@brief	큐에 중복되는 아이템이 있는지 검색한다.
	*	@pre	큐가 존재해야한다.
	*	@post	아이템이 삭제된다. 
	*	@return 삭제 후 return 1, otherwise return 0.
	*/
	int CheckDuplication(T item);

	/**
	*	@brief	큐에 해당하는 아이템이 있는지 검색한다.
	*	@pre	큐가 존재해야한다.
	*	@post	item이 update된다.
	*	@return 찾으면 return 1, otherwise return 0.
	*/
	int Retrieve(T& item);

private:
	int m_iFront;			/// 큐의 앞을 나타내는 플래그
	int m_iRear;			/// 큐의 뒤를 나타내는 플래그
	int m_nMaxQueue;		/// 큐의 사이즈
	T* m_pItems;		/// 아이템타입 포인터 변수

};

/// Allocate dynamic array whose size is MAX_ITEMS 30.
template <class T>
CircularQueue<T>::CircularQueue()
{
	m_nMaxQueue = MAXSIZE_Q + 1;		/// 원형 큐의 최대 크기를 MAX_ITEM +1로 선언해서 한칸은 비게한다.
	m_iFront = m_nMaxQueue - 1;		/// 원형 큐의 선두를 최대크기 -1 로 선언
	m_iRear = m_nMaxQueue - 1;			/// 원형 큐의 후미를 최대크기 -1 로 선언
	m_pItems = new T[m_nMaxQueue];
}

/// 큐의 사이즈를 받아온 만큼 할당해준다.
template <class T>
CircularQueue<T>::CircularQueue(int size)
{
	m_nMaxQueue = size + 1;			/// 원형 큐의 최대 크기를 size로 선언해서 한칸은 비게한다.
	m_iFront = m_nMaxQueue - 1;			/// 원형 큐의 선두를 최대크기 -1 로 선언
	m_iRear = m_nMaxQueue - 1;			/// 원형 큐의 후미를 최대크기 -1 로 선언
	m_pItems = new T[m_nMaxQueue];
}

/// Destruct the object. Free the array dynamically allocated.
template <class T>
CircularQueue<T>::~CircularQueue()
{
	delete[] m_pItems;
}

/// Determines whether the queue is full.
template <class T>
bool CircularQueue<T>::IsFull()
{
	if ((m_iRear + 1) % m_nMaxQueue == m_iFront)  /// 선두와 후미의 위치를 비교하여 큐가 꽉차있는지 검사한다.
		return true;
	else
		return false;
}

/// Determines whether the queue is empty.
template <class T>
bool CircularQueue<T>::IsEmpty()
{
	if (m_iFront == m_iRear) /// 선두와 후미의 위치를 비교하여 큐가 비어있는지 검사한다.
		return true;
	else
		return false;
}

/// 큐를 비워준다.
template <class T>
void CircularQueue<T>::MakeEmpty()
{
	m_iFront = m_iRear;				/// 선두와 후미의 위치가 같으면 queue가 빈 것으로 연산된다.
}

/// Adds newItem to the top of the queue.
template <class T>
void CircularQueue<T>::EnQueue(T newItem)
{
	if (IsFull())
	{
		throw FullQueue();
	}
	else
	{
		m_iRear = (m_iRear + 1) % m_nMaxQueue;		/// if queue is not full, 후미의 위치를 한단계 옮긴다.
		m_pItems[m_iRear] = newItem;				/// 옮긴 위치에 새로운 아이템을 추가한다.
	}
}

/// Removes top item from the queue.
template <class T>
void CircularQueue<T>::DeQueue(T& item)
{
	if (IsEmpty())
	{
		throw EmptyQueue();
	}
	else
	{
		m_iFront = (m_iFront + 1) % m_nMaxQueue;		/// if queue is not empty, 선두의 위치를 한단계 옮긴다.
		item = m_pItems[m_iFront];					/// 옮긴 위치의 아이템 배열을 삭제
	}
}

/// Print all the items in the queue on screen
template <class T>
int CircularQueue<T>::Print()
{
	int first = m_iFront;
	int last = m_iRear;
	if (first == last) /// 비어있으면 0 return
	{
		cout << "\tNONE" << endl;
		return 0;
	}

	while (first != last)				/// Rear값과 front가 같지 않을 동안. front로 시작해 값을 하나씩 출력
	{
		cout << "\t" << m_pItems[(first + 1) % m_nMaxQueue] << endl;
		first = (first + 1) % m_nMaxQueue;
	}
	return 1;
	cout << endl;
}

template <class T>
int CircularQueue<T>::CheckDuplication(T item)
{
	/// Queue 내의 모든 element에 대해 검색.
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) ///큐의 처음+1에서 출발해서 큐의 마지막까지 확인한다. 모든 검색시 mod로 순환하게 한다.
	{
		if (item == m_pItems[i]) /// 찾은 경우
		{
			for (; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue)
			{
				m_pItems[i] = m_pItems[i + 1];
			}
			if (m_iRear == 0)
				m_iRear = m_nMaxQueue - 1;
			else
				m_iRear = m_iRear - 1;
			return 1;
		}
	}
	return 0; /// 찾지 못하면 0 반환
}

template <class T>
int CircularQueue<T>::Retrieve(T& item)
{
	/// Queue 내의 모든 element에 대해 검색.
	int first = m_iFront;
	int last = m_iRear;
	while (first != last)
	{
		if (item == m_pItems[(first + 1) % m_nMaxQueue])
		{
			item = m_pItems[(first + 1) % m_nMaxQueue];
			return 1;
		}
		first = (first + 1) % m_nMaxQueue;
	}
	return 0; /// 찾지 못하면 0 반환
}