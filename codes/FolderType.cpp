#include "FolderType.h"


FolderType::FolderType()
{
	fdName = "";
	fdLocation = "";
	fdDate = "";
	fdSize = 0;
	fdCount = 0;
	fdLastModifiedDate = "";
	fdLastOpenedDate = "";
	fdSubFolderNum = 0;
	fdSubFileNum = 0;
	fdFolderList = NULL;
	fdFileList = NULL;
	fdUpper = NULL;
}

FolderType::~FolderType()
{
}

RelationType FolderType::CompareByName(const FolderType& data)
{
	if (this->fdName > data.fdName)
		return GREATER;
	else if (this->fdName < data.fdName)
		return LESS;
	else
		return EQUAL;
}

void FolderType::SetNameFromKB()
{
	cin >> fdName;
}

/// Get current time for record
string FolderType::MyGetCurrentTime()
{
	time_t r;
	struct tm * pTime;
	time(&r);
	pTime = localtime(&r);
	int cTime1 =
		(10000)*(pTime->tm_year + 1900) +
		(100)*(pTime->tm_mon + 1) +
		(pTime->tm_mday);
	int cTime2 =
		(100)*(pTime->tm_hour) +
		pTime->tm_min;
	string cTime2ToStr;
	if (cTime2 < 1000)
		cTime2ToStr = "0" + to_string(cTime2);
	else
		cTime2ToStr = to_string(cTime2);
	return to_string(cTime1) + cTime2ToStr;
}

/// 대입 연산자 오버로딩
FolderType& FolderType::operator= (const FolderType& data)
{
	this->fdName = data.fdName;
	this->fdLocation = data.fdLocation;
	this->fdDate = data.fdDate;
	this->fdSize = data.fdSize;
	this->fdCount = data.fdCount;
	this->fdLastModifiedDate = data.fdLastModifiedDate;
	this->fdLastOpenedDate = data.fdLastOpenedDate;
	this->fdSubFolderNum = data.fdSubFolderNum;
	this->fdSubFileNum = data.fdSubFileNum;

	if (this->fdFolderList != NULL)
	{
		this->fdFolderList = data.fdFolderList;
	}
	if (this->fdFileList != NULL)
	{
		this->fdFileList = data.fdFileList;
	}

	this->fdUpper = data.fdUpper;

	return *this;
}

/// 쉬프트 연산자 오버로딩
ostream& operator<<(ostream& os, const FolderType& data)
{
	cout << data.fdName;
	return os;
}

/// 비교 연산자 오버로딩
bool operator==(const FolderType& data1, const FolderType& data2)
{
	return (data1.fdName == data2.fdName);
}

/// 비교 연산자 오버로딩
bool operator<(const FolderType& data1, const FolderType& data2)
{
	return (data1.fdName < data2.fdName);
}

/// 새로운 폴더 추가하기
int FolderType::AddFolder()
{
	if (fdSubFolderNum == 0)
		fdFolderList = new SortedLinkedList<FolderType>;

	cout << "\t생성할 폴더의 이름을 입력해주세요: ";
	FolderType data;
	data.SetNameFromKB();
	if (fdFolderList->Get(data)) /// 중복되는 폴더 검사
	{
		cout << "\t중복되는 폴더 이름이 있습니다." << endl;
		return 0;
	}
	else /// 중복되는 폴더가 없는 경우
	{
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// 서브 폴더 패스 자동 설정
		data.SetDate(); /// date 자동 설정
		fdLastModifiedDate = data.GetDate(); /// 마지막 수정날짜 만든 날짜로 지정
		data.fdUpper = this; /// 현재 폴더의 주소값 받기 (상위 폴더 설정)

		if (fdFolderList->Add(data))
			fdSubFolderNum++;

		return 1;
	}
}

/// 복사/붙여넣기 용 폴더 추가
int FolderType::AddFolder_P(FolderType data)
{
	if (fdSubFolderNum == 0)
		fdFolderList = new SortedLinkedList<FolderType>;

	if (fdFolderList->Get(data)) /// 중복되는 폴더 검사
	{
		string name = data.GetName() + "_copy";
		data.SetName(name);
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// 서브 폴더 패스 자동 설정
		data.SetDate(); /// date 자동 설정
		fdLastModifiedDate = data.GetDate(); /// 마지막 수정날짜 만든 날짜로 지정
		data.fdUpper = this; /// 현재 폴더의 주소값 받기 (상위 폴더 설정)

		if (fdFolderList->Add(data))
			fdSubFolderNum++;
		return 1;
	}

	else /// 중복되는 폴더가 없는 경우
	{
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// 서브 폴더 패스 자동 설정
		data.SetDate(); /// date 자동 설정
		fdLastModifiedDate = data.GetDate(); /// 마지막 수정날짜 만든 날짜로 지정
		data.fdUpper = this; /// 현재 폴더의 주소값 받기 (상위 폴더 설정)

		if (fdFolderList->Add(data))
			fdSubFolderNum++;

		return 1;
	}

}

/// 폴더 삭제하기
int FolderType::DeleteFolder()
{
	cout << "\t삭제할 폴더의 이름을 입력해주세요: ";
	FolderType data;	/// Delete함수는 FolderType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNameFromKB();	/// 사용자에게서 폴더 이름을 입력받는다.
	if (fdFolderList->Delete(data))	/// Delete함수에 data를 넘겨준다.
	{
		cout << "\t삭제를 완료했습니다." << endl;	/// 삭제에 성공했으면 메시지를 출력한다.
		fdSubFolderNum--; /// 하위폴더 개수 -1
		return 1; /// 삭제 완료시 return 1
	}
	else
	{
		cout << "\t삭제하지 못했습니다. 해당 폴더를 찾지 못했습니다." << endl;	/// 삭제에 실패했으면 메시지를 출력한다.
		return 0; /// 삭제 실패시 return 0
	}
}

/// 폴더 이름 변경
int FolderType::RenameFolder(FolderType& f, string n)
{
	if (fdFolderList->Get(f))
	{
		FolderType* tmp = fdFolderList->ReturnPointer(f);
		tmp->SetName(n); /// 폴더 이름 변경
		tmp->SetModifyDate(); /// 수정 날짜 변경
		tmp->SetLocation(this->fdLocation + "/" + tmp->GetName()); /// 폴더 경로 변경
		tmp->RelocateSubComponents(); /// 해당 서브 경로 변경
		return 1;
	}
	else
		return 0;

}

/// 해당 폴더의 이름 변경시 Sub folders, files의 경로를 수정
void FolderType::RelocateSubComponents()
{
	/// 폴더의 파일리스트 경로 수정
	if (this->GetFileList() != NULL)
		this->RelocateSubFiles();

	FolderType tmpFd;
	FolderType* tmpPtr;
	if (this->GetSubFolderNum() != 0) /// SubFolderNum이 0이 아닐 때만 실행
	{
		this->GetFolderList()->ResetList(); /// iterator 초기화
		for (int i = 0; i < this->GetFolderList()->GetLength(); i++) /// 리스트의 마지막까지 반복
		{
			this->GetFolderList()->GetNextItem(tmpFd);
			tmpPtr = this->GetFolderList()->GetPoint();
			tmpPtr->SetLocation(this->fdLocation + "/" + tmpPtr->GetName()); /// 경로 수정
			tmpPtr->SetModifyDate(); /// 수정 날짜 변경

			if (tmpPtr->GetSubFolderNum() != 0)
				tmpPtr->RelocateSubComponents();
		}
	}
}

void FolderType::RelocateSubFiles()
{
	FileType tmpFl; /// 임시 파일 선언
	FileType* tmpPtr;

	this->GetFileList()->ResetList(); /// iterator 초기화
	for (int i = 0; i < this->GetFileList()->GetLength(); i++) /// 리스트의 마지막까지 반복
	{
		this->GetFileList()->GetNextItem(tmpFl);
		tmpPtr = this->GetFileList()->GetPoint();
		tmpPtr->SetLocation(this->fdLocation + "/" + tmpPtr->GetName()); /// 경로 수정
		tmpPtr->SetModifyDate(); /// 수정 날짜 변경
	}
}

FolderType FolderType::DuplicateFolder()
{
	FolderType newFd; /// 새로운 폴더
	FolderType tmpFd; /// 임시 폴더 선언


	/// 현재 폴더 복사
	/// 이름 설정
	string new_name = this->GetName();
	tmpFd.SetName(new_name);

	while (true) /// 중북되는 이름이 없을 때까지
	{
		int check = this->GetUpperFolder()->GetFolderList()->Get(tmpFd);
		if (check == 1)
		{
			new_name = new_name + "_copy"; /// 뒤에 _copy 붙여주기
			tmpFd.SetName(new_name);
			continue;
		}
		else if (check == 0)
			break;
	}

	newFd.SetName(new_name); /// 해당 이름으로 새로운 폴더 이름 설정

	newFd.SetDate(); /// 날짜 설정
	newFd.SetLocation(GetUpperFolder()->GetLocation() + "/" + newFd.GetName()); /// 경로 설정
	newFd.fdSize = 0; /// 크기 설정
	newFd.fdCount = 0; /// count 횟수는 0
	newFd.fdLastModifiedDate = newFd.GetDate(); /// 최근 수정 날짜 설정
	newFd.fdSubFolderNum = 0; /// 0으로 초기 설정
	newFd.fdSubFileNum = 0; /// 0으로 초기 설정
	newFd.fdUpper = this->GetUpperFolder(); /// 상위 폴더 포인터 설정
	return newFd;
}

FileType FolderType::DuplicateFile(FileType* data)
{
	FileType newFl; /// 새로운 폴더
	FileType tmpFl; /// 임시 폴더 선언

	/// 이름 설정
	string new_name = data->GetName();
	tmpFl.SetNameWoType(new_name);
	string type = data->GetType();

	while (true) /// 중북되는 이름이 없을 때까지
	{
		int check = this->GetFileList()->Get(tmpFl);
		if (check == 1)
		{
			new_name = new_name + "_copy." + type; /// 뒤에 _copy 붙여주기
			tmpFl.SetNameWoType(new_name);
			continue;
		}
		else if (check == 0)
			break;
	}

	newFl.SetNameWoType(new_name); /// 해당 이름으로 새로운 폴더 이름 설정

	newFl.SetDate(); /// 날짜 설정
	newFl.SetLocation(this->GetLocation() + "/" + newFl.GetName()); /// 경로 설정
	newFl.SetSize(data->GetSize()); /// 크기 설정
	newFl.SetType(data->GetType()); /// 타입 설정
	newFl.SetDateByDate(); /// 최근 수정 날짜 설정
	return newFl;
}


/// 해당되는 폴더를 찾아 폴더 포인터 리턴
/// 해당되는 폴더가 있다는 가정하에 사용, 예외처리 안 함
FolderType* FolderType::OpenSubFolder(FolderType& data)
{
	FolderType* tmp;
	tmp = fdFolderList->ReturnPointer(data); /// 해당 폴더가 존재하는 경우 해당 폴더의 포인터값 반환
	return tmp;
}

/// 검색어로 현재폴더의 파일 리스트에서 검색
int FolderType::RetrieveFileByKeyword(string& key)
{
	FileType tmpFl; /// 임시 파일 선언
	int check = 0;
	if (this->GetSubFileNum() != 0) /// 폴더가 파일을 갖고 있는 경우
	{
		this->GetFileList()->ResetList(); /// iterator 초기화
		while (this->GetFileList()->GetNextItem(tmpFl) != 0)
		{
			if (tmpFl.GetName().find(key) != -1) /// 만약 해당 리스트의 이름에 key가 존재하면	
			{
				cout << "\t";
				tmpFl.DisplayName(); /// 해당 파일 이름 display
				check = 1;   /// 찾았으므로 check 변경
			}
		}
	}
	if (check == 1)
		return 1;
	else
		return 0;
}

/// 검색어로 해당 검색어를 포함한 서브 폴더 및 파일 검색
int FolderType::RetrieveByKeyword(string& key)
{
	FolderType tmpFd; /// 임시 폴더 선언
	FolderType* tmpPtr; /// 임시 폴더 포인터 선언
	int check = 0; /// 찾은 경우를 확인하기 위한 변수

	if (this->GetSubFolderNum() == 0) /// 폴더가 없는 경우
	{
		cout << "\t현재 생성된 폴더가 없습니다." << endl;
		return 0; /// return -1
	}

	/// Sub folder 검색
	this->GetFolderList()->ResetList(); /// iterator 초기화

	while (this->GetFolderList()->GetNextItem(tmpFd) != 0) /// 리스트의 마지막까지 반복
	{
		/// 폴더 검색
		if (tmpFd.GetName().find(key) != -1) /// 만약 해당 리스트의 이름에 key가 존재하면
		{
			cout << "\t";
			tmpFd.DisplayName(); /// 해당 폴더 이름 display
			check = 1;   /// 찾았으므로 check 변경
		}

		/// 폴더의 파일 리스트 검색
		if (tmpFd.GetFileList() != NULL)
			tmpFd.RetrieveFileByKeyword(key);

		tmpPtr = this->GetFolderList()->GetPoint();
		if (tmpPtr->GetSubFolderNum() != 0)
			tmpPtr->RetrieveByKeyword(key);
	}

	if (check == 1)   /// 발견한 경우
		return 1;
	else   /// 발견 못하는 경우
		return 0;
}

/// 검색어로 Sub folder list에서 해당 폴더 검색, 찾으면 1, otherwise 0 출력
int FolderType::RetrieveFolderByName(FolderType& data)
{
	if (fdFolderList == NULL) /// 해당 폴더 리스트가 NULL이면 return 0
		return 0;

	else if (fdFolderList->Get(data)) /// 해당 폴더가 존재하는지 확인
	{
		return 1; /// 존재하면 1 리턴
	}

	else
		return 0;
}

/// 모든 서브 폴더 리스트 이름순 출력
void FolderType::DisplayAllFoldersByName()
{
	this->GetFolderList()->ResetList(); /// iterator 초기화

	FolderType tmpFd; /// 임시 폴더 선언
	for (int i = 0; i < this->GetFolderList()->GetLength(); i++) /// 리스트의 마지막까지 반복
	{
		this->GetFolderList()->GetNextItem(tmpFd);
		cout << "\t";
		tmpFd.DisplayName();
	}
}

/// 모든 서브 폴더 리스트 만든 날짜순 출력
void FolderType::DisplayAllFoldersByDate()
{
	FolderType tmpFd; /// 임시 폴더 선언
	int length = this->GetFolderList()->GetLength(); /// 리스트 길이 구하기
	string *arr_name = new string[length]; /// 리스트 길이로 폴더 이름 배열 동적 할당
	string *arr_date = new string[length]; /// 리스트 길이로 폴더 날짜 배열 동적 할당
	this->GetFolderList()->ResetList(); /// iterator 초기화
	for (int i = 0; i < length; i++) /// 리스트의 마지막까지 반복
	{
		/// 리스트에 추가
		this->GetFolderList()->GetNextItem(tmpFd);
		arr_name[i] = tmpFd.GetName();
		arr_date[i] = tmpFd.GetDate();
	}
	/// 날짜순으로 임시 array sort 실행
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr_date[i] > arr_date[j])
			{
				string temp_date = arr_date[j];
				arr_date[j] = arr_date[i];
				arr_date[i] = temp_date;
				string temp_name = arr_name[j];
				arr_name[j] = arr_name[i];
				arr_name[i] = temp_name;
			}
		}
	}

	/// sort 결과에 따라 출력
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << arr_name[i] << "(만든 날짜: " << arr_date[i] << ")" << endl;
	}

	delete[] arr_name; /// 동적할당 해제
	delete[] arr_date; /// 동적할당 해제
}

/// 모든 서브 폴더 리스트 크기순 출력
void FolderType::DisplayAllFoldersBySize()
{
	FolderType tmpFd; /// 임시 폴더 선언
	int length = this->GetFolderList()->GetLength(); /// 리스트 길이 구하기
	string *arr_name = new string[length]; /// 리스트 길이로 폴더 이름 배열 동적 할당
	int *arr_size = new int[length]; /// 리스트 길이로 폴더 크기 배열 동적 할당
	this->GetFolderList()->ResetList(); /// iterator 초기화
	for (int i = 0; i < length; i++) /// 리스트의 마지막까지 반복
	{
		/// 리스트에 추가
		this->GetFolderList()->GetNextItem(tmpFd);
		arr_name[i] = tmpFd.GetName();
		arr_size[i] = tmpFd.GetSize();
	}
	/// 크기순으로 임시 array sort 실행
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr_size[i] > arr_size[j])
			{
				int temp_size = arr_size[j];
				arr_size[j] = arr_size[i];
				arr_size[i] = temp_size;
				string temp_name = arr_name[j];
				arr_name[j] = arr_name[i];
				arr_name[i] = temp_name;
			}
		}
	}

	/// sort 결과에 따라 출력
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << arr_name[i] << "(폴더 크기: " << arr_size[i] << " Byte)" << endl;
	}

	delete[] arr_name; /// 동적할당 해제
	delete[] arr_size; /// 동적할당 해제
}

/// 파일 추가
int FolderType::AddFile()
{
	if (fdSubFileNum == 0)
		fdFileList = new SortedLinkedList<FileType>;

	cout << "\t생성할 파일의 형식 확장자를 입력해주세요: ";
	string type;
	cin >> type;
	FileType data;
	data.SetType(type);
	string fName;
	cout << "\t생성할 파일의 이름을 입력해주세요: ";
	cin >> fName;
	data.SetName(fName);
	if (fdFileList->Get(data)) /// 중복되는 파일 검사
	{
		cout << "\t중복되는 파일 이름이 있습니다." << endl;
		return 0;
	}
	else /// 중복되는 파일 없는 경우
	{
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// 서브 파일 패스 자동 설정
		data.SetDate(); /// date 자동 설정
		data.SetDateByDate(); /// 만든 날짜로 수정 날짜 설정

		if (data.GetType() == "txt") /// 텍스트 파일인 경우
		{
			cout << "\t파일에 추가할 내용을 입력하세요. Quit를 입력하시면 내용 추가가 종료됩니다." << endl;
			string out_line = "";
			ofstream ofs(data.GetName());
			int check = 1;
			while (check != 0)
			{
				cout << "\t";
				cin >> out_line;
				if (out_line == "Quit")
				{
					check = 1;
					break;
				}
				ofs << out_line << endl;
			}
			ofs.close();

			data.LoadSize();	/// 파일 사이즈 설정
			SetSize(1, data.GetSize());	/// 파일 사이즈로 폴더 사이즈 업데이트

			if (fdFileList->Add(data))
				fdSubFileNum++;

			return 1;
		}

		else /// 이미지, 음악 파일인 경우
		{
			data.LoadSize();	/// 파일 사이즈 설정
			SetSize(1, data.GetSize());	/// 파일 사이즈로 폴더 사이즈 업데이트
			if (fdFileList->Add(data))
				fdSubFileNum++;
			return 1;
		}
	}
}

/// 복사/붙여넣기 용 파일 추가
int FolderType::AddFile_P(FileType data)
{
	if (fdSubFileNum == 0)
		fdFileList = new SortedLinkedList<FileType>;

	if (fdFileList->Get(data)) /// 중복되는 폴더 검사
	{
		string new_name = data.GetName() + "_copy." + data.GetType(); /// 뒤에 _copy 붙여주기
		data.SetNameWoType(new_name);
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// 서브 폴더 패스 자동 설정
		data.SetDate(); /// date 자동 설정
		data.SetDateByDate(); /// 만든 날짜로 수정 날짜 설정

		if (fdFileList->Add(data))
			fdSubFileNum++;
		return 1;

	}

	else /// 중복되는 폴더가 없는 경우
	{
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// 서브 폴더 패스 자동 설정
		data.SetDate(); /// date 자동 설정
		data.SetDateByDate(); /// 만든 날짜로 수정 날짜 설정

		if (fdFileList->Add(data))
			fdSubFileNum++;
		return 1;
	}
}

/// 파일 삭제
int FolderType::MyDeleteFile()
{
	cout << "\t삭제할 파일의 이름을 입력해주세요: ";
	FileType data;	/// Delete함수는 FileType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNameFromKB();	/// 사용자에게서 폴더 이름을 입력받는다.
	FileType* tmpPtr = fdFileList->ReturnPointer(data);
	if (tmpPtr != NULL)	/// 헤당 폴더가 존재하면
	{
		/// 프로젝트 폴더에서 실제로 삭제
		tmpPtr->Delete();
		fdFileList->Delete(data);
		cout << "\t삭제를 완료했습니다." << endl;	/// 삭제에 성공했으면 메시지를 출력한다.
		fdSubFileNum--; /// 하위 파일 개수 -1
		SetSize(-1, data.GetSize());	/// 파일 사이즈로 폴더 사이즈 업데이트
		return 1; /// 삭제 완료시 return 1
	}
	else
	{
		cout << "\t삭제하지 못했습니다. 해당 파일을 찾지 못했습니다." << endl;	/// 삭제에 실패했으면 메시지를 출력한다.
		return 0; /// 삭제 실패시 return 0
	}
}

/// 파일 열기
int FolderType::OpenFile(FileType& data)
{
	if (data.GetType() == "txt") /// 텍스트 파일인 경우
	{
		SetSize(-1, data.GetSize());	/// 파일 수정 경우를 위해 폴더 사이즈에서 해당 파일 사이즈 제거
		cout << "\t==== " << data.GetName() << " ====" << endl;
		string in_line;
		ifstream ifs(data.GetName());
		while (getline(ifs, in_line))
			cout << "\t" << in_line << endl;
		ifs.close();
		cout << "\n\t내용 추가를 원하시면 입력해주세요. 추가가 끝나면 Quit를 입력해주세요." << endl;
		string out_line;
		ofstream ofs;
		ofs.open(data.GetName());
		int check = 1;
		while (check != 0)
		{
			cout << "\t";
			cin >> out_line;
			if (out_line == "Quit")
			{
				check = 1;
				break;
			}
			ofs << out_line << endl;
		}
		ofs.close();
		data.LoadSize();	/// 파일 사이즈 수정
		SetSize(1, data.GetSize());	/// 파일 사이즈 다시 추가
		return 1;
	}
	else if (data.GetType() == "jpg") /// 이미지 파일인 경우
	{
		if (data.OpenImage() != 0) /// 성공시
			return 1;
		else
			return 0;
	}
	else if (data.GetType() == "wav") /// 음원 파일인 경우
	{
		if (data.OpenMusic() != 0) /// 성공시
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

/// 파일 이름 변경
int FolderType::RenameFile(FileType& f, string n)
{
	if (fdFileList->Get(f))
	{
		FileType* tmp = fdFileList->ReturnPointer(f);
		tmp->Rename(n); /// 프로젝트 폴더에서 실제로 이름 변경
		tmp->SetNameWoType(n); /// 리스트 내 파일 이름 변경
		tmp->SetLocation(this->fdLocation + "/" + tmp->GetName()); /// 리스트 내 파일 경로 변경
		tmp->SetModifyDate(); /// 리스트 내 최근 수정 날짜 변경
		
		return 1;
	}
	else
		return 0;
}

/// 검색어로 Sub file list에서 해당 file 검색, 찾으면 1, otherwise 0 출력
int FolderType::RetrieveFileByName(FileType& data)
{
	if (fdFileList == NULL) /// 해당 파일 리스트가 NULL이면 return 0
		return 0;
	else if (fdFileList->Get(data)) /// 해당 폴더가 존재하는지 확인
	{
		return 1; /// 존재하면 1 리턴
	}
	else
		return 0;
}

/// 모든 파일 이름 이름순 출력
void FolderType::DisplayAllFilesByName()
{	
	this->GetFileList()->ResetList(); /// iterator 초기화

	FileType tmpFl; /// 임시 폴더 선언
	for (int i = 0; i < this->GetFileList()->GetLength(); i++) /// 리스트의 마지막까지 반복
	{
		this->GetFileList()->GetNextItem(tmpFl);
		cout << "\t";
		tmpFl .DisplayName();
	}
}

/// 모든 파일 이름 만든 날짜순 출력
void FolderType::DisplayAllFilesByDate()
{
	FileType tmpFl; /// 임시 파일 선언
	int length = this->GetFileList()->GetLength(); /// 리스트 길이 구하기
	string *arr_name = new string[length]; /// 리스트 길이로 파일 이름 배열 동적 할당
	string *arr_date = new string[length]; /// 리스트 길이로 파일 날짜 배열 동적 할당
	this->GetFileList()->ResetList(); /// iterator 초기화
	for (int i = 0; i < length; i++) /// 리스트의 마지막까지 반복
	{
		/// 리스트에 추가
		this->GetFileList()->GetNextItem(tmpFl);
		arr_name[i] = tmpFl.GetName();
		arr_date[i] = tmpFl .GetDate();
	}
	/// 날짜순으로 임시 array sort 실행
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr_date[i] > arr_date[j])
			{
				string temp_date = arr_date[j];
				arr_date[j] = arr_date[i];
				arr_date[i] = temp_date;
				string temp_name = arr_name[j];
				arr_name[j] = arr_name[i];
				arr_name[i] = temp_name;
			}
		}
	}

	/// sort 결과에 따라 출력
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << arr_name[i] << "(만든 날짜: " << arr_date[i] << ")" << endl;
	}

	delete[] arr_name; /// 동적할당 해제
	delete[] arr_date; /// 동적할당 해제
}

/// 모든 파일 이름 크기순 출력
void FolderType::DisplayAllFilesBySize()
{
	FileType tmpFl; /// 임시 폴더 선언
	int length = this->GetFileList()->GetLength(); /// 리스트 길이 구하기
	string *arr_name = new string[length]; /// 리스트 길이로 폴더 이름 배열 동적 할당
	int *arr_size = new int[length]; /// 리스트 길이로 폴더 크기 배열 동적 할당
	this->GetFileList()->ResetList(); /// iterator 초기화
	for (int i = 0; i < length; i++) /// 리스트의 마지막까지 반복
	{
		/// 리스트에 추가
		this->GetFileList()->GetNextItem(tmpFl);
		arr_name[i] = tmpFl.GetName();
		arr_size[i] = tmpFl.GetSize();
	}
	/// 크기순으로 임시 array sort 실행
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr_size[i] > arr_size[j])
			{
				int temp_size = arr_size[j];
				arr_size[j] = arr_size[i];
				arr_size[i] = temp_size;
				string temp_name = arr_name[j];
				arr_name[j] = arr_name[i];
				arr_name[i] = temp_name;
			}
		}
	}

	/// sort 결과에 따라 출력
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << arr_name[i] << "(파일 크기: " << arr_size[i] << " Byte)" << endl;
	}

	delete[] arr_name; /// 동적할당 해제
	delete[] arr_size; /// 동적할당 해제
}

/// count 증가
void FolderType::IncreaseCount()
{
	fdCount = fdCount + 1;
}