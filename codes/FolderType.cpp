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

/// ���� ������ �����ε�
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

/// ����Ʈ ������ �����ε�
ostream& operator<<(ostream& os, const FolderType& data)
{
	cout << data.fdName;
	return os;
}

/// �� ������ �����ε�
bool operator==(const FolderType& data1, const FolderType& data2)
{
	return (data1.fdName == data2.fdName);
}

/// �� ������ �����ε�
bool operator<(const FolderType& data1, const FolderType& data2)
{
	return (data1.fdName < data2.fdName);
}

/// ���ο� ���� �߰��ϱ�
int FolderType::AddFolder()
{
	if (fdSubFolderNum == 0)
		fdFolderList = new SortedLinkedList<FolderType>;

	cout << "\t������ ������ �̸��� �Է����ּ���: ";
	FolderType data;
	data.SetNameFromKB();
	if (fdFolderList->Get(data)) /// �ߺ��Ǵ� ���� �˻�
	{
		cout << "\t�ߺ��Ǵ� ���� �̸��� �ֽ��ϴ�." << endl;
		return 0;
	}
	else /// �ߺ��Ǵ� ������ ���� ���
	{
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// ���� ���� �н� �ڵ� ����
		data.SetDate(); /// date �ڵ� ����
		fdLastModifiedDate = data.GetDate(); /// ������ ������¥ ���� ��¥�� ����
		data.fdUpper = this; /// ���� ������ �ּҰ� �ޱ� (���� ���� ����)

		if (fdFolderList->Add(data))
			fdSubFolderNum++;

		return 1;
	}
}

/// ����/�ٿ��ֱ� �� ���� �߰�
int FolderType::AddFolder_P(FolderType data)
{
	if (fdSubFolderNum == 0)
		fdFolderList = new SortedLinkedList<FolderType>;

	if (fdFolderList->Get(data)) /// �ߺ��Ǵ� ���� �˻�
	{
		string name = data.GetName() + "_copy";
		data.SetName(name);
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// ���� ���� �н� �ڵ� ����
		data.SetDate(); /// date �ڵ� ����
		fdLastModifiedDate = data.GetDate(); /// ������ ������¥ ���� ��¥�� ����
		data.fdUpper = this; /// ���� ������ �ּҰ� �ޱ� (���� ���� ����)

		if (fdFolderList->Add(data))
			fdSubFolderNum++;
		return 1;
	}

	else /// �ߺ��Ǵ� ������ ���� ���
	{
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// ���� ���� �н� �ڵ� ����
		data.SetDate(); /// date �ڵ� ����
		fdLastModifiedDate = data.GetDate(); /// ������ ������¥ ���� ��¥�� ����
		data.fdUpper = this; /// ���� ������ �ּҰ� �ޱ� (���� ���� ����)

		if (fdFolderList->Add(data))
			fdSubFolderNum++;

		return 1;
	}

}

/// ���� �����ϱ�
int FolderType::DeleteFolder()
{
	cout << "\t������ ������ �̸��� �Է����ּ���: ";
	FolderType data;	/// Delete�Լ��� FolderType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetNameFromKB();	/// ����ڿ��Լ� ���� �̸��� �Է¹޴´�.
	if (fdFolderList->Delete(data))	/// Delete�Լ��� data�� �Ѱ��ش�.
	{
		cout << "\t������ �Ϸ��߽��ϴ�." << endl;	/// ������ ���������� �޽����� ����Ѵ�.
		fdSubFolderNum--; /// �������� ���� -1
		return 1; /// ���� �Ϸ�� return 1
	}
	else
	{
		cout << "\t�������� ���߽��ϴ�. �ش� ������ ã�� ���߽��ϴ�." << endl;	/// ������ ���������� �޽����� ����Ѵ�.
		return 0; /// ���� ���н� return 0
	}
}

/// ���� �̸� ����
int FolderType::RenameFolder(FolderType& f, string n)
{
	if (fdFolderList->Get(f))
	{
		FolderType* tmp = fdFolderList->ReturnPointer(f);
		tmp->SetName(n); /// ���� �̸� ����
		tmp->SetModifyDate(); /// ���� ��¥ ����
		tmp->SetLocation(this->fdLocation + "/" + tmp->GetName()); /// ���� ��� ����
		tmp->RelocateSubComponents(); /// �ش� ���� ��� ����
		return 1;
	}
	else
		return 0;

}

/// �ش� ������ �̸� ����� Sub folders, files�� ��θ� ����
void FolderType::RelocateSubComponents()
{
	/// ������ ���ϸ���Ʈ ��� ����
	if (this->GetFileList() != NULL)
		this->RelocateSubFiles();

	FolderType tmpFd;
	FolderType* tmpPtr;
	if (this->GetSubFolderNum() != 0) /// SubFolderNum�� 0�� �ƴ� ���� ����
	{
		this->GetFolderList()->ResetList(); /// iterator �ʱ�ȭ
		for (int i = 0; i < this->GetFolderList()->GetLength(); i++) /// ����Ʈ�� ���������� �ݺ�
		{
			this->GetFolderList()->GetNextItem(tmpFd);
			tmpPtr = this->GetFolderList()->GetPoint();
			tmpPtr->SetLocation(this->fdLocation + "/" + tmpPtr->GetName()); /// ��� ����
			tmpPtr->SetModifyDate(); /// ���� ��¥ ����

			if (tmpPtr->GetSubFolderNum() != 0)
				tmpPtr->RelocateSubComponents();
		}
	}
}

void FolderType::RelocateSubFiles()
{
	FileType tmpFl; /// �ӽ� ���� ����
	FileType* tmpPtr;

	this->GetFileList()->ResetList(); /// iterator �ʱ�ȭ
	for (int i = 0; i < this->GetFileList()->GetLength(); i++) /// ����Ʈ�� ���������� �ݺ�
	{
		this->GetFileList()->GetNextItem(tmpFl);
		tmpPtr = this->GetFileList()->GetPoint();
		tmpPtr->SetLocation(this->fdLocation + "/" + tmpPtr->GetName()); /// ��� ����
		tmpPtr->SetModifyDate(); /// ���� ��¥ ����
	}
}

FolderType FolderType::DuplicateFolder()
{
	FolderType newFd; /// ���ο� ����
	FolderType tmpFd; /// �ӽ� ���� ����


	/// ���� ���� ����
	/// �̸� ����
	string new_name = this->GetName();
	tmpFd.SetName(new_name);

	while (true) /// �ߺϵǴ� �̸��� ���� ������
	{
		int check = this->GetUpperFolder()->GetFolderList()->Get(tmpFd);
		if (check == 1)
		{
			new_name = new_name + "_copy"; /// �ڿ� _copy �ٿ��ֱ�
			tmpFd.SetName(new_name);
			continue;
		}
		else if (check == 0)
			break;
	}

	newFd.SetName(new_name); /// �ش� �̸����� ���ο� ���� �̸� ����

	newFd.SetDate(); /// ��¥ ����
	newFd.SetLocation(GetUpperFolder()->GetLocation() + "/" + newFd.GetName()); /// ��� ����
	newFd.fdSize = 0; /// ũ�� ����
	newFd.fdCount = 0; /// count Ƚ���� 0
	newFd.fdLastModifiedDate = newFd.GetDate(); /// �ֱ� ���� ��¥ ����
	newFd.fdSubFolderNum = 0; /// 0���� �ʱ� ����
	newFd.fdSubFileNum = 0; /// 0���� �ʱ� ����
	newFd.fdUpper = this->GetUpperFolder(); /// ���� ���� ������ ����
	return newFd;
}

FileType FolderType::DuplicateFile(FileType* data)
{
	FileType newFl; /// ���ο� ����
	FileType tmpFl; /// �ӽ� ���� ����

	/// �̸� ����
	string new_name = data->GetName();
	tmpFl.SetNameWoType(new_name);
	string type = data->GetType();

	while (true) /// �ߺϵǴ� �̸��� ���� ������
	{
		int check = this->GetFileList()->Get(tmpFl);
		if (check == 1)
		{
			new_name = new_name + "_copy." + type; /// �ڿ� _copy �ٿ��ֱ�
			tmpFl.SetNameWoType(new_name);
			continue;
		}
		else if (check == 0)
			break;
	}

	newFl.SetNameWoType(new_name); /// �ش� �̸����� ���ο� ���� �̸� ����

	newFl.SetDate(); /// ��¥ ����
	newFl.SetLocation(this->GetLocation() + "/" + newFl.GetName()); /// ��� ����
	newFl.SetSize(data->GetSize()); /// ũ�� ����
	newFl.SetType(data->GetType()); /// Ÿ�� ����
	newFl.SetDateByDate(); /// �ֱ� ���� ��¥ ����
	return newFl;
}


/// �ش�Ǵ� ������ ã�� ���� ������ ����
/// �ش�Ǵ� ������ �ִٴ� �����Ͽ� ���, ����ó�� �� ��
FolderType* FolderType::OpenSubFolder(FolderType& data)
{
	FolderType* tmp;
	tmp = fdFolderList->ReturnPointer(data); /// �ش� ������ �����ϴ� ��� �ش� ������ �����Ͱ� ��ȯ
	return tmp;
}

/// �˻���� ���������� ���� ����Ʈ���� �˻�
int FolderType::RetrieveFileByKeyword(string& key)
{
	FileType tmpFl; /// �ӽ� ���� ����
	int check = 0;
	if (this->GetSubFileNum() != 0) /// ������ ������ ���� �ִ� ���
	{
		this->GetFileList()->ResetList(); /// iterator �ʱ�ȭ
		while (this->GetFileList()->GetNextItem(tmpFl) != 0)
		{
			if (tmpFl.GetName().find(key) != -1) /// ���� �ش� ����Ʈ�� �̸��� key�� �����ϸ�	
			{
				cout << "\t";
				tmpFl.DisplayName(); /// �ش� ���� �̸� display
				check = 1;   /// ã�����Ƿ� check ����
			}
		}
	}
	if (check == 1)
		return 1;
	else
		return 0;
}

/// �˻���� �ش� �˻�� ������ ���� ���� �� ���� �˻�
int FolderType::RetrieveByKeyword(string& key)
{
	FolderType tmpFd; /// �ӽ� ���� ����
	FolderType* tmpPtr; /// �ӽ� ���� ������ ����
	int check = 0; /// ã�� ��츦 Ȯ���ϱ� ���� ����

	if (this->GetSubFolderNum() == 0) /// ������ ���� ���
	{
		cout << "\t���� ������ ������ �����ϴ�." << endl;
		return 0; /// return -1
	}

	/// Sub folder �˻�
	this->GetFolderList()->ResetList(); /// iterator �ʱ�ȭ

	while (this->GetFolderList()->GetNextItem(tmpFd) != 0) /// ����Ʈ�� ���������� �ݺ�
	{
		/// ���� �˻�
		if (tmpFd.GetName().find(key) != -1) /// ���� �ش� ����Ʈ�� �̸��� key�� �����ϸ�
		{
			cout << "\t";
			tmpFd.DisplayName(); /// �ش� ���� �̸� display
			check = 1;   /// ã�����Ƿ� check ����
		}

		/// ������ ���� ����Ʈ �˻�
		if (tmpFd.GetFileList() != NULL)
			tmpFd.RetrieveFileByKeyword(key);

		tmpPtr = this->GetFolderList()->GetPoint();
		if (tmpPtr->GetSubFolderNum() != 0)
			tmpPtr->RetrieveByKeyword(key);
	}

	if (check == 1)   /// �߰��� ���
		return 1;
	else   /// �߰� ���ϴ� ���
		return 0;
}

/// �˻���� Sub folder list���� �ش� ���� �˻�, ã���� 1, otherwise 0 ���
int FolderType::RetrieveFolderByName(FolderType& data)
{
	if (fdFolderList == NULL) /// �ش� ���� ����Ʈ�� NULL�̸� return 0
		return 0;

	else if (fdFolderList->Get(data)) /// �ش� ������ �����ϴ��� Ȯ��
	{
		return 1; /// �����ϸ� 1 ����
	}

	else
		return 0;
}

/// ��� ���� ���� ����Ʈ �̸��� ���
void FolderType::DisplayAllFoldersByName()
{
	this->GetFolderList()->ResetList(); /// iterator �ʱ�ȭ

	FolderType tmpFd; /// �ӽ� ���� ����
	for (int i = 0; i < this->GetFolderList()->GetLength(); i++) /// ����Ʈ�� ���������� �ݺ�
	{
		this->GetFolderList()->GetNextItem(tmpFd);
		cout << "\t";
		tmpFd.DisplayName();
	}
}

/// ��� ���� ���� ����Ʈ ���� ��¥�� ���
void FolderType::DisplayAllFoldersByDate()
{
	FolderType tmpFd; /// �ӽ� ���� ����
	int length = this->GetFolderList()->GetLength(); /// ����Ʈ ���� ���ϱ�
	string *arr_name = new string[length]; /// ����Ʈ ���̷� ���� �̸� �迭 ���� �Ҵ�
	string *arr_date = new string[length]; /// ����Ʈ ���̷� ���� ��¥ �迭 ���� �Ҵ�
	this->GetFolderList()->ResetList(); /// iterator �ʱ�ȭ
	for (int i = 0; i < length; i++) /// ����Ʈ�� ���������� �ݺ�
	{
		/// ����Ʈ�� �߰�
		this->GetFolderList()->GetNextItem(tmpFd);
		arr_name[i] = tmpFd.GetName();
		arr_date[i] = tmpFd.GetDate();
	}
	/// ��¥������ �ӽ� array sort ����
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

	/// sort ����� ���� ���
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << arr_name[i] << "(���� ��¥: " << arr_date[i] << ")" << endl;
	}

	delete[] arr_name; /// �����Ҵ� ����
	delete[] arr_date; /// �����Ҵ� ����
}

/// ��� ���� ���� ����Ʈ ũ��� ���
void FolderType::DisplayAllFoldersBySize()
{
	FolderType tmpFd; /// �ӽ� ���� ����
	int length = this->GetFolderList()->GetLength(); /// ����Ʈ ���� ���ϱ�
	string *arr_name = new string[length]; /// ����Ʈ ���̷� ���� �̸� �迭 ���� �Ҵ�
	int *arr_size = new int[length]; /// ����Ʈ ���̷� ���� ũ�� �迭 ���� �Ҵ�
	this->GetFolderList()->ResetList(); /// iterator �ʱ�ȭ
	for (int i = 0; i < length; i++) /// ����Ʈ�� ���������� �ݺ�
	{
		/// ����Ʈ�� �߰�
		this->GetFolderList()->GetNextItem(tmpFd);
		arr_name[i] = tmpFd.GetName();
		arr_size[i] = tmpFd.GetSize();
	}
	/// ũ������� �ӽ� array sort ����
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

	/// sort ����� ���� ���
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << arr_name[i] << "(���� ũ��: " << arr_size[i] << " Byte)" << endl;
	}

	delete[] arr_name; /// �����Ҵ� ����
	delete[] arr_size; /// �����Ҵ� ����
}

/// ���� �߰�
int FolderType::AddFile()
{
	if (fdSubFileNum == 0)
		fdFileList = new SortedLinkedList<FileType>;

	cout << "\t������ ������ ���� Ȯ���ڸ� �Է����ּ���: ";
	string type;
	cin >> type;
	FileType data;
	data.SetType(type);
	string fName;
	cout << "\t������ ������ �̸��� �Է����ּ���: ";
	cin >> fName;
	data.SetName(fName);
	if (fdFileList->Get(data)) /// �ߺ��Ǵ� ���� �˻�
	{
		cout << "\t�ߺ��Ǵ� ���� �̸��� �ֽ��ϴ�." << endl;
		return 0;
	}
	else /// �ߺ��Ǵ� ���� ���� ���
	{
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// ���� ���� �н� �ڵ� ����
		data.SetDate(); /// date �ڵ� ����
		data.SetDateByDate(); /// ���� ��¥�� ���� ��¥ ����

		if (data.GetType() == "txt") /// �ؽ�Ʈ ������ ���
		{
			cout << "\t���Ͽ� �߰��� ������ �Է��ϼ���. Quit�� �Է��Ͻø� ���� �߰��� ����˴ϴ�." << endl;
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

			data.LoadSize();	/// ���� ������ ����
			SetSize(1, data.GetSize());	/// ���� ������� ���� ������ ������Ʈ

			if (fdFileList->Add(data))
				fdSubFileNum++;

			return 1;
		}

		else /// �̹���, ���� ������ ���
		{
			data.LoadSize();	/// ���� ������ ����
			SetSize(1, data.GetSize());	/// ���� ������� ���� ������ ������Ʈ
			if (fdFileList->Add(data))
				fdSubFileNum++;
			return 1;
		}
	}
}

/// ����/�ٿ��ֱ� �� ���� �߰�
int FolderType::AddFile_P(FileType data)
{
	if (fdSubFileNum == 0)
		fdFileList = new SortedLinkedList<FileType>;

	if (fdFileList->Get(data)) /// �ߺ��Ǵ� ���� �˻�
	{
		string new_name = data.GetName() + "_copy." + data.GetType(); /// �ڿ� _copy �ٿ��ֱ�
		data.SetNameWoType(new_name);
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// ���� ���� �н� �ڵ� ����
		data.SetDate(); /// date �ڵ� ����
		data.SetDateByDate(); /// ���� ��¥�� ���� ��¥ ����

		if (fdFileList->Add(data))
			fdSubFileNum++;
		return 1;

	}

	else /// �ߺ��Ǵ� ������ ���� ���
	{
		data.SetLocation(this->fdLocation + "/" + data.GetName()); /// ���� ���� �н� �ڵ� ����
		data.SetDate(); /// date �ڵ� ����
		data.SetDateByDate(); /// ���� ��¥�� ���� ��¥ ����

		if (fdFileList->Add(data))
			fdSubFileNum++;
		return 1;
	}
}

/// ���� ����
int FolderType::MyDeleteFile()
{
	cout << "\t������ ������ �̸��� �Է����ּ���: ";
	FileType data;	/// Delete�Լ��� FileType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetNameFromKB();	/// ����ڿ��Լ� ���� �̸��� �Է¹޴´�.
	FileType* tmpPtr = fdFileList->ReturnPointer(data);
	if (tmpPtr != NULL)	/// ��� ������ �����ϸ�
	{
		/// ������Ʈ �������� ������ ����
		tmpPtr->Delete();
		fdFileList->Delete(data);
		cout << "\t������ �Ϸ��߽��ϴ�." << endl;	/// ������ ���������� �޽����� ����Ѵ�.
		fdSubFileNum--; /// ���� ���� ���� -1
		SetSize(-1, data.GetSize());	/// ���� ������� ���� ������ ������Ʈ
		return 1; /// ���� �Ϸ�� return 1
	}
	else
	{
		cout << "\t�������� ���߽��ϴ�. �ش� ������ ã�� ���߽��ϴ�." << endl;	/// ������ ���������� �޽����� ����Ѵ�.
		return 0; /// ���� ���н� return 0
	}
}

/// ���� ����
int FolderType::OpenFile(FileType& data)
{
	if (data.GetType() == "txt") /// �ؽ�Ʈ ������ ���
	{
		SetSize(-1, data.GetSize());	/// ���� ���� ��츦 ���� ���� ������� �ش� ���� ������ ����
		cout << "\t==== " << data.GetName() << " ====" << endl;
		string in_line;
		ifstream ifs(data.GetName());
		while (getline(ifs, in_line))
			cout << "\t" << in_line << endl;
		ifs.close();
		cout << "\n\t���� �߰��� ���Ͻø� �Է����ּ���. �߰��� ������ Quit�� �Է����ּ���." << endl;
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
		data.LoadSize();	/// ���� ������ ����
		SetSize(1, data.GetSize());	/// ���� ������ �ٽ� �߰�
		return 1;
	}
	else if (data.GetType() == "jpg") /// �̹��� ������ ���
	{
		if (data.OpenImage() != 0) /// ������
			return 1;
		else
			return 0;
	}
	else if (data.GetType() == "wav") /// ���� ������ ���
	{
		if (data.OpenMusic() != 0) /// ������
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

/// ���� �̸� ����
int FolderType::RenameFile(FileType& f, string n)
{
	if (fdFileList->Get(f))
	{
		FileType* tmp = fdFileList->ReturnPointer(f);
		tmp->Rename(n); /// ������Ʈ �������� ������ �̸� ����
		tmp->SetNameWoType(n); /// ����Ʈ �� ���� �̸� ����
		tmp->SetLocation(this->fdLocation + "/" + tmp->GetName()); /// ����Ʈ �� ���� ��� ����
		tmp->SetModifyDate(); /// ����Ʈ �� �ֱ� ���� ��¥ ����
		
		return 1;
	}
	else
		return 0;
}

/// �˻���� Sub file list���� �ش� file �˻�, ã���� 1, otherwise 0 ���
int FolderType::RetrieveFileByName(FileType& data)
{
	if (fdFileList == NULL) /// �ش� ���� ����Ʈ�� NULL�̸� return 0
		return 0;
	else if (fdFileList->Get(data)) /// �ش� ������ �����ϴ��� Ȯ��
	{
		return 1; /// �����ϸ� 1 ����
	}
	else
		return 0;
}

/// ��� ���� �̸� �̸��� ���
void FolderType::DisplayAllFilesByName()
{	
	this->GetFileList()->ResetList(); /// iterator �ʱ�ȭ

	FileType tmpFl; /// �ӽ� ���� ����
	for (int i = 0; i < this->GetFileList()->GetLength(); i++) /// ����Ʈ�� ���������� �ݺ�
	{
		this->GetFileList()->GetNextItem(tmpFl);
		cout << "\t";
		tmpFl .DisplayName();
	}
}

/// ��� ���� �̸� ���� ��¥�� ���
void FolderType::DisplayAllFilesByDate()
{
	FileType tmpFl; /// �ӽ� ���� ����
	int length = this->GetFileList()->GetLength(); /// ����Ʈ ���� ���ϱ�
	string *arr_name = new string[length]; /// ����Ʈ ���̷� ���� �̸� �迭 ���� �Ҵ�
	string *arr_date = new string[length]; /// ����Ʈ ���̷� ���� ��¥ �迭 ���� �Ҵ�
	this->GetFileList()->ResetList(); /// iterator �ʱ�ȭ
	for (int i = 0; i < length; i++) /// ����Ʈ�� ���������� �ݺ�
	{
		/// ����Ʈ�� �߰�
		this->GetFileList()->GetNextItem(tmpFl);
		arr_name[i] = tmpFl.GetName();
		arr_date[i] = tmpFl .GetDate();
	}
	/// ��¥������ �ӽ� array sort ����
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

	/// sort ����� ���� ���
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << arr_name[i] << "(���� ��¥: " << arr_date[i] << ")" << endl;
	}

	delete[] arr_name; /// �����Ҵ� ����
	delete[] arr_date; /// �����Ҵ� ����
}

/// ��� ���� �̸� ũ��� ���
void FolderType::DisplayAllFilesBySize()
{
	FileType tmpFl; /// �ӽ� ���� ����
	int length = this->GetFileList()->GetLength(); /// ����Ʈ ���� ���ϱ�
	string *arr_name = new string[length]; /// ����Ʈ ���̷� ���� �̸� �迭 ���� �Ҵ�
	int *arr_size = new int[length]; /// ����Ʈ ���̷� ���� ũ�� �迭 ���� �Ҵ�
	this->GetFileList()->ResetList(); /// iterator �ʱ�ȭ
	for (int i = 0; i < length; i++) /// ����Ʈ�� ���������� �ݺ�
	{
		/// ����Ʈ�� �߰�
		this->GetFileList()->GetNextItem(tmpFl);
		arr_name[i] = tmpFl.GetName();
		arr_size[i] = tmpFl.GetSize();
	}
	/// ũ������� �ӽ� array sort ����
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

	/// sort ����� ���� ���
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << arr_name[i] << "(���� ũ��: " << arr_size[i] << " Byte)" << endl;
	}

	delete[] arr_name; /// �����Ҵ� ����
	delete[] arr_size; /// �����Ҵ� ����
}

/// count ����
void FolderType::IncreaseCount()
{
	fdCount = fdCount + 1;
}