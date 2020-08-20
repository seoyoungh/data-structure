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
	*	@brief	대입 연산자 오버로딩
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
	*	@return	리스트 끝까지 돌면 return 0, otherwise return 1. 
	*/
	int GetNextItem(T& item);

	/**
	*	@brief	item과 일치하는 id를 가진 레코드를 제거.
	*	@pre	해당하는 id를 가진 레코드가 있어야함
	*	@post	해당 레코드가 제거됨.
	*/
	int Delete(T item);

	/**
	*	@brief	item과 일치하는 id를 가진 레코드를 갱신.
	*	@pre	해당하는 id를 가진 레코드가 있어야함
	*	@post	해당 레코드가 item의 내용으로 갱신됨.
	*/
	int Replace(T item);

	/**
	*	@brief	리스트 안에 있는 모든 아이템을 출력
	*	@pre	리스트에 아이템이 존재해야 한다. 
	*	@post	리스트 안에 있는 모든 아이템들이 출력된다.
	*	@return	리스트가 비어있으면 0 리턴, 정상적으로 출력되면 1 리턴
	*/
	int PrintAllItems();

	/**
	*	@brief	리스트에 해당 아이템을 찾아 주소를 반환한다.
	*	@return	찾으면 해당 아이템의 주소, 찾지 못하면 NULL을 리턴한다.
	*/
	T* ReturnPointer(T& item);

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
	MakeEmpty(); /// 리스트내의 모든 node 제거
}

/// 대입 연산자 오버로딩
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
	/// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	/// 리스트 초기화
	ResetList();

	/// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	/// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	/// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	/// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		/// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			/// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			/// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (node->data<dummy)  /// 값이 node의 데이터가 더 작아지는 순간; 즉 순서에 맞는 순간
			{
				if (pre == NULL)	/// 맨처음으로 값이 들어가야되는 경우, node의 data값이 가장 작을때
				{
					node->next = m_pCurPointer;
					m_pList = node;		/// 맨처음으로 바꿈;
					break;
				}
				else		/// 중간에 값이 들어가는 순간
				{
					pre->next = node;
					node->next = m_pCurPointer;
					break;
				}
			}


			/// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				/// 마지막 node 와 새로운 node 연결
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
	/// current pointer 초기화
	m_pCurPointer = NULL;
}


/// Gets the next element in list.
template <typename T>
int SortedLinkedList<T>::GetNextItem(T& item)
{
	/// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
	{
		/// current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;
		if (m_pCurPointer == NULL)
			return 0; /// 마지막까지 다 돈 경우 0 반환
	}

	/// item 에 current position 의 info 를 삽입
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

	if (Get(item) == 0)	/// 해당하는 값이 없으면, 0보내고 종료
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)		/// id값이 일치
		{
			if (pre == NULL) /// 삭제해야할 노드가 맨처음일때
			{
				toDel = m_pList;	/// 잠시 옮겨두고 삭제
				m_pList = m_pList->next;	/// 맨처음을 두번째로바꿈
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	/// 전 포인터와 다음포인터를 연결
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	/// 맨마지막, 루프를 다돌았을때
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
	/// Get(T& item)이 pass by reference임으로 데이터왜곡발생
	if (Get(isthere) == 0)	/// 해당하는 값이 없으면, 0보내고 종료
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)			/// '=='연산자를 id값에 대해 오버로딩했음. 	
		{
			m_pCurPointer->data = item;	/// id값이 같으면 데이터를 대체
			found = true;
			break;
		}
		if (m_pCurPointer->next == NULL)	/// 맨마지막
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
		/// temp에 current position 의 info 를 삽입
		temp = m_pCurPointer->data;
		cout << temp;
		///다음 노드가 NULL이면 break
		if (m_pCurPointer->next == NULL)
			break;
		///current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;
	}
	return 1;
}

/// 해당 아이템이 존재하는 경우 주소 리턴
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