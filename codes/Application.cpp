#include "Application.h"

/// Program driver.
void Application::Run()
{
	while (1)
	{
		DisplayCurrentFolder();
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		/// 새 폴더 생성
			NewFolder();
			break;
		case 2:		/// 폴더 삭제
			DeleteFolder();
			break;
		case 3:		/// 폴더 열기
			OpenFolder();
			break;
		case 4:		/// 폴더 이름 변경
			RenameFolder();
			break;
		case 5: /// 폴더 copy&paste
			CopyPasteFolder();
			break;
		case 6:		/// 파일 복제
			DuplicateFolder();
			break;
		case 7:		/// 폴더 속성 보기
			DisplayFolderProperty();
			break;
		case 8:		/// 새 파일 생성
			NewFile();
			break;
		case 9:		/// 파일 삭제
			MyDeleteFile();
			break;
		case 10:		/// 파일 열기
			OpenFile();
			break;
		case 11:		/// 파일 이름 변경
			RenameFile();
			break;
		case 12: /// 폴더 copy&paste
			CopyPasteFile();
			break;
		case 13:		/// 파일 복제
			DuplicateFile();
			break;
		case 14:		/// 파일 속성 보기
			DisplayFileProperty();
			break;
		case 15:		/// 폴더 및 파일 검색
			Retrieve();
			break;
		case 16:		/// 최근 열어본 폴더 및 파일
			DisplayRecents();
			break;
		case 17:		/// 자주 사용한 폴더
			DisplayFavourites();
			break;
		case 18:		/// 상위 폴더로 이동
			GoToUpperFolder();
			break;
		case 19:		/// 현재 폴더 정렬
			SortCurrentFolder();
			break;
		case 20:		/// 현재 폴더 속성
			DisplayCurrentFolderProperty();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

/// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	textcolor(WHITE, BLACK);
	cout << "\t--- ID --------- Command ---------- " << endl;
	cout << "\t|   1 : 폴더 생성\t\t  |" << endl;
	cout << "\t|   2 : 폴더 삭제\t\t  |" << endl;
	cout << "\t|   3 : 폴더 열기\t\t  |" << endl;
	cout << "\t|   4 : 폴더 이름 변경\t\t  |" << endl;
	cout << "\t|   5 : 폴더 복사/붙여넣기\t  |" << endl;
	cout << "\t|   6 : 폴더 복제\t\t  |" << endl;
	cout << "\t|   7 : 폴더 속성 보기\t\t  |" << endl;
	cout << "\t----------------------------------- " << endl;
	cout << "\t|   8 : 파일 생성\t\t  |" << endl;
	cout << "\t|   9 : 파일 삭제\t\t  |" << endl;
	cout << "\t|  10 : 파일 열기\t\t  |" << endl;
	cout << "\t|  11 : 파일 이름 변경\t\t  |" << endl;
	cout << "\t|  12 : 파일 복사/붙여넣기\t  |" << endl;
	cout << "\t|  13 : 파일 복제\t\t  |" << endl;
	cout << "\t|  14 : 파일 속성 보기\t\t  |" << endl;
	cout << "\t----------------------------------- " << endl;
	cout << "\t|  15 : 폴더 및 파일 검색\t  |" << endl;
	cout << "\t|  16 : 최근 열어본 폴더\t  |" << endl;
	cout << "\t|  17 : 자주 사용한 폴더\t  |" << endl;
	cout << "\t|  18 : 상위 폴더로 이동\t  |" << endl;
	cout << "\t|  19 : 현재 폴더 정렬\t\t  |" << endl;
	cout << "\t|  20 : 현재 폴더 속성 보기\t  |" << endl;
	cout << "\t|   0 : Quit\t\t\t  |" << endl;
	cout << "\t-----------------------------------" << endl;

	cout << endl << "\tChoose a Command --> ";
	cin >> command;
	cout << endl;

	return command;
}

/// 현재 폴더 경로, 폴더, 파일 리스트를 보여준다.
void Application::DisplayCurrentFolder()
{
	textcolor(LIGHTBLUE, BLACK);
	cout << "\n\tCurrent Path: ";
	m_curFolder->DisplayLocation();
	textcolor(YELLOW, BLACK);
	cout << "\n\t==== Current Folder List ====" << endl;
	if (m_curFolder->GetSubFolderNum() == 0)
		cout << "\tNONE" << endl;
	else
	{
		switch (m_SortOption)
		{
		case 1:
			m_curFolder->DisplayAllFoldersByName(); /// 이름순
			break;
		case 2:
			m_curFolder->DisplayAllFoldersByDate(); /// 만든 날짜순
			m_SortOption = 1; /// 다시 이름순을 기본으로 함
			break;
		case 3:
			m_curFolder->DisplayAllFoldersBySize(); /// 크기순
			m_SortOption = 1; /// 다시 이름순을 기본으로 함
			break;
		}

	}
	cout << "\n\t==== Current File List ====" << endl;
	if (m_curFolder->GetSubFileNum() == 0)
		cout << "\tNONE" << endl;
	else
	{
		switch (m_SortOption)
		{
		case 1:
			m_curFolder->DisplayAllFilesByName(); /// 이름순
			break;
		case 2:
			m_curFolder->DisplayAllFilesByDate(); /// 만든 날짜순
			m_SortOption = 1; /// 다시 이름순을 기본으로 함
			break;
		case 3:
			m_curFolder->DisplayAllFilesBySize(); /// 크기순
			m_SortOption = 1; /// 다시 이름순을 기본으로 함
			break;
		}
	}

}

/// 새로운 폴더를 추가한다.
int Application::NewFolder()
{
	if (m_curFolder->AddFolder())
		return 1;
	else
		return 0;
}

/// 해당 폴더를 삭제한다.
int Application::DeleteFolder()
{
	if (m_curFolder->DeleteFolder())
		return 1;
	else
		return 0;
}

/// 사용자가 열고자하는 폴더로 포인터를 옮겨준다.
int Application::OpenFolder()
{
	cout << "\t열고 싶은 폴더의 이름을 입력해주세요: ";
	FolderType data;
	data.SetNameFromKB();	/// 사용자에게서 폴더 이름을 입력받는다.
	if (m_curFolder->RetrieveFolderByName(data)) /// 해당 폴더가 존재하는 경우
	{
		m_curFolder = m_curFolder->OpenSubFolder(data); /// 현재 폴더 포인터에는 하위 폴더의 주소값을 준다.
		
		m_curFolder->SetOpenDate(); /// 폴더의 최근 열어본 시간 수정

		m_curFolder->IncreaseCount(); /// 폴더의 오픈 카운트 증가

		m_curFolder->SetOpenDate(); /// 폴더 최근 오픈한 시간 갱신

		/// 포인터 타입에 폴더 주소, 폴더 이름 저장
		PointerType tmp;
		tmp.SetAddress(m_curFolder);
		tmp.SetName(m_curFolder->GetName());

		/// Favourites count 체크
		if (m_curFolder->GetCount() >= 3) /// Favourites count가 3 이상이면 추가 
		{
			m_Favourites.CheckDuplication(tmp); /// 중복 확인
			m_Favourites.EnQueue(tmp);
		}

		/// Recents에 추가
		m_Recents.CheckDuplication(tmp);
		m_Recents.EnQueue(tmp);
		return 1;
	}
	else
	{
		cout << "\t해당 폴더가 존재하지 않습니다." << endl;
		return 0;
	}
}

/// 폴더의 이름을 변경한다. 
int Application::RenameFolder()
{
	cout << "\t이름을 변경하고 싶은 폴더의 현재 이름을 입력해주세요: ";
	FolderType data;
	data.SetNameFromKB();
	if (m_curFolder->RetrieveFolderByName(data)) /// 해당 폴더가 존재하는 경우
	{
		cout << "\t변경할 폴더 이름을 입력해주세요: ";
		string new_name;
		cin >> new_name; /// 변경할 폴더 이름 입력 받음
		m_curFolder->RenameFolder(data, new_name); /// 폴더 이름 변경
		return 1; /// 변경 성공시에 1 반환
	}
	else
	{
		cout << "\t해당 폴더가 존재하지 않습니다." << endl;
		return 0;
	}
}

/// 폴더 복사/붙여넣기
int Application::CopyPasteFolder()
{
	/// 복사
	if (pasteFolderOption == 0) {

		if (m_curFolder->GetFolderList()->GetLength() == 0)
		{
			cout << "\t폴더가 존재하지 않습니다." << endl;
			return 0;
		}
		else
		{
			cout << "\t 복사할 폴더 이름을 입력해주세요: ";
			FolderType data;
			data.SetNameFromKB();
			if (!m_curFolder->RetrieveFolderByName(data))
			{
				cout << "\t폴더가 존재하지 않습니다." << endl;
				return 0;
			}

			m_curFolder->GetFolderList()->Get(data);
			tmpFolder = data;
			pasteFolderOption = 1;
			return 1;
		}
	}

	/// 붙여넣기
	if (pasteFolderOption == 1) {
		if (m_curFolder->AddFolder_P(tmpFolder))
		{
			cout << "\t폴더 붙여넣기를 완료했습니다." << endl;
			pasteFolderOption = 0;
			return 1;
		}
		else
			return 0;
	}
}

/// 폴더 복제
int Application::DuplicateFolder()
{

	cout << "\t복제하고 싶은 폴더의 이름을 입력해주세요: ";
	FolderType data;
	data.SetNameFromKB();	/// 사용자에게서 폴더 이름을 입력받는다.
	if (m_curFolder->RetrieveFolderByName(data)) /// 해당 폴더가 존재하는 경우
	{
		FolderType newFd;
		FolderType* tmp = m_curFolder->GetFolderList()->ReturnPointer(data);
		newFd = tmp->DuplicateFolder(); /// 복제하기
		m_curFolder->GetFolderList()->Add(newFd);
		return 1;
	}
	else
	{
		cout << "\t해당 폴더가 존재하지 않습니다.";
		return 0;
	}
}

/// 폴더 속성 출력
void Application::DisplayFolderProperty()
{
	cout << "\t속성을 확인할 폴더의 이름을 입력해주세요: ";
	FolderType data;
	data.SetNameFromKB();	/// 사용자에게서 현재 파일 이름을 입력받는다.
	if (m_curFolder->GetFolderList()->Get(data))
	{
		FolderType* tmp = m_curFolder->GetFolderList()->ReturnPointer(data);
		tmp->DisplayProperty();
	}
	else
		cout << "\t해당 폴더가 존재하지 않습니다.";
}

/// 파일을 생성한다.
int Application::NewFile()
{
	if (m_curFolder->AddFile())
	{
		/// 상위 폴더들 사이즈 변경해주기
		FolderType* tmpPtr;
		tmpPtr = m_curFolder->GetUpperFolder(); /// 상위 폴더 포인터를 담는 임시 포인터
		while (tmpPtr != NULL) /// 해당 폴더의 모든 상위 폴더들의 사이즈도 변경해줌
		{
			tmpPtr->SetSize(1, m_curFolder->GetSize());
			tmpPtr = tmpPtr->GetUpperFolder();
		}
		return 1;
	}
	else
		return 0;
}

/// 해당 이름을 가진 파일을 삭제한다.
int Application::MyDeleteFile()
{
	if (m_curFolder->MyDeleteFile())
	{
		/// 상위 폴더들 사이즈 변경해주기
		FolderType* tmpPtr;
		tmpPtr = m_curFolder->GetUpperFolder(); /// 상위 폴더 포인터를 담는 임시 포인터
		while (tmpPtr != NULL) /// 해당 폴더의 모든 상위 폴더들의 사이즈도 변경해줌
		{
			tmpPtr->SetSize(-1, m_curFolder->GetSize());
			tmpPtr = tmpPtr->GetUpperFolder();
		}
		return 1;
	}
	else
		return 0;
}

/// 사용자가 열고자하는 파일을 실행시킨다. txt파일을 출력한다.
int Application::OpenFile()
{
	FileType data;
	string fType;
	string fName;
	cout << "\t열고 싶은 파일의 확장자를 입력해주세요: ";
	cin >> fType;
	data.SetType(fType);
	cout << "\t열고 싶은 파일의 이름을 입력해주세요: ";
	cin >> fName;
	data.SetName(fName);	/// 사용자에게서 파일 이름을 입력받는다.
	if (m_curFolder->RetrieveFileByName(data)) /// 해당 폴더가 존재하는 경우
	{
		int oldSize = m_curFolder->GetSize();
		string tmp = data.GetName(); /// item의 name을 담을 임시 변수 만들어줌
		m_curFolder->OpenFile(data);
		int newSize = m_curFolder->GetSize();
		/// 파일 사이즈가 변경된 경우를 위해 상위 폴더들 사이즈 변경해주기
		FolderType* tmpPtr;
		tmpPtr = m_curFolder->GetUpperFolder(); /// 상위 폴더 포인터를 담는 임시 포인터
		while (tmpPtr != NULL) /// 해당 폴더의 모든 상위 폴더들의 사이즈도 변경해줌
		{
			tmpPtr->SetSize(-1, oldSize);
			tmpPtr->SetSize(1, newSize);
			tmpPtr = tmpPtr->GetUpperFolder();
		}
		return 1;

		return 1;
	}
	else
	{
		cout << "\t해당 파일이 존재하지 않습니다." << endl;
		return 0;
	}
}

/// 파일의 이름을 변경한다.
int Application::RenameFile()
{
	cout << "\t이름을 변경하고 싶은 파일의 현재 이름을 입력해주세요: ";
	FileType data;
	data.SetNameFromKB();	/// 사용자에게서 현재 파일 이름을 입력받는다.
	if (m_curFolder->RetrieveFileByName(data)) /// 해당 파일이 존재하는 경우
	{
		cout << "\t변경할 파일 이름을 입력해주세요: ";
		string new_name;
		cin >> new_name; /// 변경할 파일 이름 입력 받음
		m_curFolder->RenameFile(data, new_name); /// 폴더 이름 변경
		return 1; /// 변경 성공시에 1 반환
	}
	else
	{
		cout << "\t해당 파일이 존재하지 않습니다." << endl;
		return 0;
	}
}

/// 파일 복사/붙여넣기
int Application::CopyPasteFile()
{
	/// 복사
	if (pasteFileOption == 0) {

		if (m_curFolder->GetFileList()->GetLength() == 0)
		{
			cout << "\t파일이 존재하지 않습니다." << endl;
			return 0;
		}
		else
		{
			cout << "\t복사할 파일 이름을 입력해주세요: ";
			FileType data;
			data.SetNameFromKB();
			if (!m_curFolder->RetrieveFileByName(data))
			{
				cout << "\t파일이 존재하지 않습니다." << endl;
				return 0;
			}

			m_curFolder->GetFileList()->Get(data);
			tmpFile = data;
			pasteFileOption = 1;
			return 1;
		}
	}

	/// 붙여넣기
	if (pasteFileOption == 1) {
		if (m_curFolder->AddFile_P(tmpFile))
		{
			cout << "\t폴더 붙여넣기를 완료했습니다." << endl;
			pasteFileOption = 0;
			return 1;
		}
		else
			return 0;
	}
}

/// 파일 복제
int Application::DuplicateFile()
{
	cout << "\t복제하고 싶은 파일의 이름을 입력해주세요: ";
	FileType data;
	data.SetNameFromKB();	/// 사용자에게서 파일 이름을 입력받는다.
	if (m_curFolder->RetrieveFileByName(data)) /// 해당 폴더가 존재하는 경우
	{
		FileType newFl;
		FileType* tmp = m_curFolder->GetFileList()->ReturnPointer(data);
		newFl = m_curFolder->DuplicateFile(tmp); /// 복제하기
		m_curFolder->GetFileList()->Add(newFl);
		m_curFolder->SetSize(1, newFl.GetSize()); /// 폴더 사이즈 변경

		/// 상위 폴더들 사이즈 변경해주기
		FolderType* tmpPtr;
		tmpPtr = m_curFolder->GetUpperFolder(); /// 상위 폴더 포인터를 담는 임시 포인터
		while (tmpPtr != NULL) /// 해당 폴더의 모든 상위 폴더들의 사이즈도 변경해줌
		{
			tmpPtr->SetSize(1, m_curFolder->GetSize());
			tmpPtr = tmpPtr->GetUpperFolder();
		}
		return 1;
	}
	else
	{
		cout << "\t해당 파일이 존재하지 않습니다.";
		return 0;
	}
}

/// 파일 속성 출력
void Application::DisplayFileProperty()
{
	cout << "\t속성을 확인할 파일의 이름을 입력해주세요: ";
	FileType data;
	data.SetNameFromKB();	/// 사용자에게서 현재 파일 이름을 입력받는다.
	if (m_curFolder->GetFileList()->Get(data))
	{
		FileType* tmp = m_curFolder->GetFileList()->ReturnPointer(data);
		tmp->DisplayProperty();
	}
	else
		cout << "\t해당 폴더가 존재하지 않습니다.";
}

/// 리스트에서 해당 검색어를 포함한 폴더, 파일을 모두 찾아 출력한다.
int Application::Retrieve()
{
	int check = 0;
	string key;
	cout << "\t검색어를 입력해주세요: ";
	cin >> key; /// 사용자에게서 검색어를 입력받는다.

	cout << "\n\t==== 검색 결과 ====" << endl;
	if (m_curFolder->RetrieveFileByKeyword(key) == 1) /// 현재 폴더의 파일 리스트 먼저 검색
		check = 1;
	if (m_curFolder->RetrieveByKeyword(key) == 1) /// 폴더 리스트 및 하위 폴더의 파일리스트 검색
		check = 1;

	else
	{
		cout << "\t해당 검색어를 포함한 폴더, 파일을 찾지 못했습니다." << endl;
	}

	if (check == 1)
		return 1;
	else 
		return 0;
}

/// 최근 열어본 폴더 및 파일
int Application::DisplayRecents()
{
	cout << "\t==== 최근 열어본 폴더 ====" << endl;
	if (m_Recents.Print() != 0)
	{
		string command;
		cout << "\n\t해당 폴더 중 하나로 이동하시겠어요?\n\t원하면 폴더 이름을, 원하지 않으면 Quit를 입력하세요 : ";
		cin >> command;

		if (command == "Quit")
			return 1;
		else
		{
			FolderType* tmpPtr;
			PointerType tmp;
			tmp.SetName(command);

			if (m_Recents.Retrieve(tmp) == 1) /// 해당 파일이 존재하는 경우
			{
				tmpPtr = tmp.GetAddress();
				m_curFolder = tmpPtr; /// 현재 폴더 포인터를 옯겨준다.
				m_curFolder->IncreaseCount(); /// 폴더의 오픈 카운트 증가
				m_curFolder->SetOpenDate(); /// 폴더 최근 오픈한 시간 갱신


				/// 포인터 타입에 폴더 주소, 폴더 이름 저장
				PointerType tmp;
				tmp.SetAddress(m_curFolder);
				tmp.SetName(m_curFolder->GetName());

				/// Favourites count 체크
				if (m_curFolder->GetCount() >= 3) /// Favourites count가 3 이상이면 추가 
				{
					m_Favourites.CheckDuplication(tmp); /// 중복 확인
					m_Favourites.EnQueue(tmp);
				}

				/// Recents에 추가
				m_Recents.CheckDuplication(tmp); /// 중복 확인
				m_Recents.EnQueue(tmp);
			}
		}
		return 1;
	}
	return 1;


}

/// 자주 사용한 폴더
int Application::DisplayFavourites()
{
	cout << "\t==== 자주 사용한 폴더 ====" << endl;
	if (m_Favourites.Print() != 0)
	{
		string command;
		cout << "\n\t해당 폴더 중 하나로 이동하시겠어요?\n\t원하면 폴더 이름을, 원하지 않으면 Quit를 입력하세요 : ";
		cin >> command;

		if (command == "Quit")
			return 1;
		else
		{
			FolderType* tmpPtr;
			PointerType tmp;
			tmp.SetName(command);

			if (m_Favourites.Retrieve(tmp) == 1) /// 해당 파일이 존재하는 경우
			{
				tmpPtr = tmp.GetAddress();
				m_curFolder = tmpPtr; /// 현재 폴더 포인터를 옯겨준다.
				m_curFolder->IncreaseCount(); /// 폴더의 오픈 카운트 증가
				m_curFolder->SetOpenDate(); /// 폴더 최근 오픈한 시간 갱신

				/// 포인터 타입에 폴더 주소, 폴더 이름 저장
				PointerType tmp;
				tmp.SetAddress(m_curFolder);
				tmp.SetName(m_curFolder->GetName());


				/// Favourites count 체크
				if (m_curFolder->GetCount() >= 3) /// Favourites count가 3 이상이면 추가 
				{
					m_Favourites.CheckDuplication(tmp); /// 중복 확인
					m_Favourites.EnQueue(tmp);
				}

				/// Recents에 추가
				m_Recents.CheckDuplication(tmp); /// 중복 확인
				m_Recents.EnQueue(tmp);
			}
		}
		return 1;
	}
	return 1;
}

/// 폴더 정렬 기준 설정 (Default = ByName)
void Application::SortCurrentFolder()
{
	int command;
	cout << "\t1. 이름 순 (Default)" << endl;
	cout << "\t2. 만든 날짜 순" << endl;
	cout << "\t3. 크기 순" << endl;
	cout << "\t폴더 정렬 기준 번호를 입력하세요: ";
	cin >> command;
	m_SortOption = command;
}

/// 폴더의 속성을 화면에 출력해준다.
void Application::DisplayCurrentFolderProperty()
{
	m_curFolder->DisplayProperty();
}

/// 상위 폴더로 이동한다.
void Application::GoToUpperFolder()
{
	if (m_curFolder == &m_RootFolder)
	{
		cout << "\t최상위 폴더입니다!" << endl; /// 현재 root folder인 경우, 더이상의 이동이 불가하므로 오류 메시지 출력
	}
	else
	{
		m_curFolder = m_curFolder->GetUpperFolder(); /// 현재 폴더 포인터는 상위 폴더의 포인터를 가져온다.		
		m_curFolder->IncreaseCount(); /// 폴더의 오픈 카운트 증가
		m_curFolder->SetOpenDate(); /// 폴더 최근 오픈한 시간 갱신

		/// 포인터 타입에 폴더 주소, 폴더 이름 저장
		PointerType tmp;
		tmp.SetAddress(m_curFolder);
		tmp.SetName(m_curFolder->GetName());

		/// Favourites count 체크
		if (m_curFolder->GetCount() >= 3) /// Favourites count가 3 이상이면 추가 
		{
			m_Favourites.CheckDuplication(tmp); /// 중복 확인
			m_Favourites.EnQueue(tmp);
		}
			
		/// Recents에 추가
		m_Recents.CheckDuplication(tmp); /// 중복 확인
		m_Recents.EnQueue(tmp);
	}
}