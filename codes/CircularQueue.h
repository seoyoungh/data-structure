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
	*	@brief	ť�� ����� �� �޼��� ���.
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
	*	@brief	MAXSIZE ��ŭ�� ����� ���� ť�� �ʱ�ȭ�Ѵ�.
	*	@pre	MAXSIZE�� ���ǵǾ�� �Ѵ�.

	*/
	CircularQueue();

	/**
	*	@brief	MAXSIZE��ŭ�� ����� ���� ť�� �ʱ�ȭ�Ѵ�.
	*	@pre	MAXSIZE�� ���ǵǾ���Ѵ�.
	*	@post	size�� ���� �ش�Ǵ� ũ���� �迭�� ���������.
	*	@param	size
	*/
	CircularQueue(int size);

	/**
	*	@brief	destructor
	*/
	~CircularQueue();

	/**
	*	@brief	ť�� ��á���� Ȯ���Ѵ�.
	*	@pre	ť�� �ʱ�ȭ �Ǿ���Ѵ�.
	*	@return	ť�� ��á���� 1, �ƴ� ��쿡 0�� ���.
	*/
	bool IsFull();

	/**
	*	@brief	ť�� ������� Ȯ���Ѵ�.
	*	@pre	ť�� �ʱ�ȭ �Ǿ���Ѵ�.
	*	@return	ť�� ������� 1, �ƴ� ��쿡 0�� ���.
	*/
	bool IsEmpty();

	/**
	*	@brief	ť���� ������ ��� �����Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	ť�� �������.
	*/
	void MakeEmpty();

	/**
	*	@brief	ť�� ���ο� �ڷḦ �߰��Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	ť�� ���ο� �ڷᰡ �߰��ȴ�.
	*/
	void EnQueue(T newItem);

	/**
	*	@brief	ť�� ���� ���� ���� �ڷ���� ����Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	ť�� �����͸� �����Ѵ�.
	*/
	void DeQueue(T& item);

	/**
	*	@brief	ť�� ��� �������� ����Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@return ť�� ��������� return 0, otherwise return 1.
	*/
	int Print();

	/**
	*	@brief	ť�� �ߺ��Ǵ� �������� �ִ��� �˻��Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	�������� �����ȴ�. 
	*	@return ���� �� return 1, otherwise return 0.
	*/
	int CheckDuplication(T item);

	/**
	*	@brief	ť�� �ش��ϴ� �������� �ִ��� �˻��Ѵ�.
	*	@pre	ť�� �����ؾ��Ѵ�.
	*	@post	item�� update�ȴ�.
	*	@return ã���� return 1, otherwise return 0.
	*/
	int Retrieve(T& item);

private:
	int m_iFront;			/// ť�� ���� ��Ÿ���� �÷���
	int m_iRear;			/// ť�� �ڸ� ��Ÿ���� �÷���
	int m_nMaxQueue;		/// ť�� ������
	T* m_pItems;		/// ������Ÿ�� ������ ����

};

/// Allocate dynamic array whose size is MAX_ITEMS 30.
template <class T>
CircularQueue<T>::CircularQueue()
{
	m_nMaxQueue = MAXSIZE_Q + 1;		/// ���� ť�� �ִ� ũ�⸦ MAX_ITEM +1�� �����ؼ� ��ĭ�� ����Ѵ�.
	m_iFront = m_nMaxQueue - 1;		/// ���� ť�� ���θ� �ִ�ũ�� -1 �� ����
	m_iRear = m_nMaxQueue - 1;			/// ���� ť�� �Ĺ̸� �ִ�ũ�� -1 �� ����
	m_pItems = new T[m_nMaxQueue];
}

/// ť�� ����� �޾ƿ� ��ŭ �Ҵ����ش�.
template <class T>
CircularQueue<T>::CircularQueue(int size)
{
	m_nMaxQueue = size + 1;			/// ���� ť�� �ִ� ũ�⸦ size�� �����ؼ� ��ĭ�� ����Ѵ�.
	m_iFront = m_nMaxQueue - 1;			/// ���� ť�� ���θ� �ִ�ũ�� -1 �� ����
	m_iRear = m_nMaxQueue - 1;			/// ���� ť�� �Ĺ̸� �ִ�ũ�� -1 �� ����
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
	if ((m_iRear + 1) % m_nMaxQueue == m_iFront)  /// ���ο� �Ĺ��� ��ġ�� ���Ͽ� ť�� �����ִ��� �˻��Ѵ�.
		return true;
	else
		return false;
}

/// Determines whether the queue is empty.
template <class T>
bool CircularQueue<T>::IsEmpty()
{
	if (m_iFront == m_iRear) /// ���ο� �Ĺ��� ��ġ�� ���Ͽ� ť�� ����ִ��� �˻��Ѵ�.
		return true;
	else
		return false;
}

/// ť�� ����ش�.
template <class T>
void CircularQueue<T>::MakeEmpty()
{
	m_iFront = m_iRear;				/// ���ο� �Ĺ��� ��ġ�� ������ queue�� �� ������ ����ȴ�.
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
		m_iRear = (m_iRear + 1) % m_nMaxQueue;		/// if queue is not full, �Ĺ��� ��ġ�� �Ѵܰ� �ű��.
		m_pItems[m_iRear] = newItem;				/// �ű� ��ġ�� ���ο� �������� �߰��Ѵ�.
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
		m_iFront = (m_iFront + 1) % m_nMaxQueue;		/// if queue is not empty, ������ ��ġ�� �Ѵܰ� �ű��.
		item = m_pItems[m_iFront];					/// �ű� ��ġ�� ������ �迭�� ����
	}
}

/// Print all the items in the queue on screen
template <class T>
int CircularQueue<T>::Print()
{
	int first = m_iFront;
	int last = m_iRear;
	if (first == last) /// ��������� 0 return
	{
		cout << "\tNONE" << endl;
		return 0;
	}

	while (first != last)				/// Rear���� front�� ���� ���� ����. front�� ������ ���� �ϳ��� ���
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
	/// Queue ���� ��� element�� ���� �˻�.
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) ///ť�� ó��+1���� ����ؼ� ť�� ���������� Ȯ���Ѵ�. ��� �˻��� mod�� ��ȯ�ϰ� �Ѵ�.
	{
		if (item == m_pItems[i]) /// ã�� ���
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
	return 0; /// ã�� ���ϸ� 0 ��ȯ
}

template <class T>
int CircularQueue<T>::Retrieve(T& item)
{
	/// Queue ���� ��� element�� ���� �˻�.
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
	return 0; /// ã�� ���ϸ� 0 ��ȯ
}