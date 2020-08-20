#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	/// A data for each node.
	NodeType* next;	/// A node pointer to point succeed node.
};


template <typename T>
class SortedLinkedList
{
public:
	/**
	*	default constructor.
	*/
	SortedLinkedList();

	/**
	*	destructor.
	*/
	~SortedLinkedList();

	/**
	*	@brief	���� ������ �����ε�
	*/
	SortedLinkedList<T>& operator=(const SortedLinkedList<T>& data);

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*	@return	����Ʈ ������ ���� return 0, otherwise return 1. 
	*/
	int GetNextItem(T& item);

	/**
	*	@brief	item�� ��ġ�ϴ� id�� ���� ���ڵ带 ����.
	*	@pre	�ش��ϴ� id�� ���� ���ڵ尡 �־����
	*	@post	�ش� ���ڵ尡 ���ŵ�.
	*/
	int Delete(T item);

	/**
	*	@brief	item�� ��ġ�ϴ� id�� ���� ���ڵ带 ����.
	*	@pre	�ش��ϴ� id�� ���� ���ڵ尡 �־����
	*	@post	�ش� ���ڵ尡 item�� �������� ���ŵ�.
	*/
	int Replace(T item);

	/**
	*	@brief	����Ʈ �ȿ� �ִ� ��� �������� ���
	*	@pre	����Ʈ�� �������� �����ؾ� �Ѵ�. 
	*	@post	����Ʈ �ȿ� �ִ� ��� �����۵��� ��µȴ�.
	*	@return	����Ʈ�� ��������� 0 ����, ���������� ��µǸ� 1 ����
	*/
	int PrintAllItems();

	/**
	*	@brief	����Ʈ�� �ش� �������� ã�� �ּҸ� ��ȯ�Ѵ�.
	*	@return	ã���� �ش� �������� �ּ�, ã�� ���ϸ� NULL�� �����Ѵ�.
	*/
	T* ReturnPointer(T& item);

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
	NodeType<T>* m_pList;	/// Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	/// Node pointer for pointing current node to use iteration.
	int m_nLength;	/// Number of node in the list.
};


/// Class constructor
template <typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


/// Class destructor
template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	MakeEmpty(); /// ����Ʈ���� ��� node ����
}

/// ���� ������ �����ε�
template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& data)
{
	MakeEmpty();
	data.ResetList();

	for (int i = 0; i < data.GetLength(); i++) {
		T* ptr = data.GetNextItem();
		Add(*ptr);
	}

	return *this;
}

/// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
{
	/// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


/// Get number of elements in the list.
template <typename T>
int SortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


/// Add item into this list.
template <typename T>
int SortedLinkedList<T>::Add(T item)
{
	/// ����Ʈ �ʱ�ȭ
	ResetList();

	/// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	/// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	/// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	/// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		/// ���� ������ node �� �̵� �� ����
		while (1)
		{
			/// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			/// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (node->data<dummy)  /// ���� node�� �����Ͱ� �� �۾����� ����; �� ������ �´� ����
			{
				if (pre == NULL)	/// ��ó������ ���� ���ߵǴ� ���, node�� data���� ���� ������
				{
					node->next = m_pCurPointer;
					m_pList = node;		/// ��ó������ �ٲ�;
					break;
				}
				else		/// �߰��� ���� ���� ����
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			/// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				/// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}

/// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SortedLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
};


/// Initializes current pointer for an iteration through the list.
template <typename T>
void SortedLinkedList<T>::ResetList()
{
	/// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


/// Gets the next element in list.
template <typename T>
int SortedLinkedList<T>::GetNextItem(T& item)
{
	/// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
	{
		/// current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;
		if (m_pCurPointer == NULL)
			return 0; /// ���������� �� �� ��� 0 ��ȯ
	}

	/// item �� current position �� info �� ����
	item = m_pCurPointer->data;
	return 1;
}

template <typename T>
int SortedLinkedList<T>::Delete(T item)
{
	NodeType<T> *pre;
	NodeType<T> *toDel;
	ResetList();
	T tmp;
	bool found = false;

	if (Get(item) == 0)	/// �ش��ϴ� ���� ������, 0������ ����
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)		/// id���� ��ġ
		{
			if (pre == NULL) /// �����ؾ��� ��尡 ��ó���϶�
			{
				toDel = m_pList;	/// ��� �Űܵΰ� ����
				m_pList = m_pList->next;	/// ��ó���� �ι�°�ιٲ�
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	/// �� �����Ϳ� ���������͸� ����
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	/// �Ǹ�����, ������ �ٵ�������
			break;


	}
	m_nLength--;
	if (found)
		return 1;
	else
		return 0;

}

template <typename T>
int SortedLinkedList<T>::Replace(T item)
{
	NodeType<T> *pre;
	ResetList();
	T isthere = item;
	T tmp;
	bool found = false;
	/// Get(T& item)�� pass by reference������ �����Ϳְ�߻�
	if (Get(isthere) == 0)	/// �ش��ϴ� ���� ������, 0������ ����
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)			/// '=='�����ڸ� id���� ���� �����ε�����. 	
		{
			m_pCurPointer->data = item;	/// id���� ������ �����͸� ��ü
			found = true;
			break;
		}
		if (m_pCurPointer->next == NULL)	/// �Ǹ�����
		{
			found = true;
			break;
		}

	}
	if (found)
		return 1;
	else
		return 0;

}

template <typename T>
int SortedLinkedList<T>::PrintAllItems()
{
	T temp;
	m_pCurPointer = m_pList;
	while (true)
	{
		/// temp�� current position �� info �� ����
		temp = m_pCurPointer->data;
		cout << temp;
		///���� ��尡 NULL�̸� break
		if (m_pCurPointer->next == NULL)
			break;
		///current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;
	}
	return 1;
}

/// �ش� �������� �����ϴ� ��� �ּ� ����
template <typename T>
T* SortedLinkedList<T>::ReturnPointer(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			return &(location->data);
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (!found)
		return NULL;
}

template<typename T>
T SortedLinkedList<T>::GetCurrentItem()
{
	return m_pCurPointer->data;
}

template<typename T>
T* SortedLinkedList<T>::GetPoint()
{
	return &(m_pCurPointer->data);
}



#endif	/// LINKED_LIST