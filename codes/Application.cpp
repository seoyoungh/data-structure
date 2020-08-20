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
		case 1:		/// �� ���� ����
			NewFolder();
			break;
		case 2:		/// ���� ����
			DeleteFolder();
			break;
		case 3:		/// ���� ����
			OpenFolder();
			break;
		case 4:		/// ���� �̸� ����
			RenameFolder();
			break;
		case 5: /// ���� copy&paste
			CopyPasteFolder();
			break;
		case 6:		/// ���� ����
			DuplicateFolder();
			break;
		case 7:		/// ���� �Ӽ� ����
			DisplayFolderProperty();
			break;
		case 8:		/// �� ���� ����
			NewFile();
			break;
		case 9:		/// ���� ����
			MyDeleteFile();
			break;
		case 10:		/// ���� ����
			OpenFile();
			break;
		case 11:		/// ���� �̸� ����
			RenameFile();
			break;
		case 12: /// ���� copy&paste
			CopyPasteFile();
			break;
		case 13:		/// ���� ����
			DuplicateFile();
			break;
		case 14:		/// ���� �Ӽ� ����
			DisplayFileProperty();
			break;
		case 15:		/// ���� �� ���� �˻�
			Retrieve();
			break;
		case 16:		/// �ֱ� ��� ���� �� ����
			DisplayRecents();
			break;
		case 17:		/// ���� ����� ����
			DisplayFavourites();
			break;
		case 18:		/// ���� ������ �̵�
			GoToUpperFolder();
			break;
		case 19:		/// ���� ���� ����
			SortCurrentFolder();
			break;
		case 20:		/// ���� ���� �Ӽ�
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
	cout << "\t|   1 : ���� ����\t\t  |" << endl;
	cout << "\t|   2 : ���� ����\t\t  |" << endl;
	cout << "\t|   3 : ���� ����\t\t  |" << endl;
	cout << "\t|   4 : ���� �̸� ����\t\t  |" << endl;
	cout << "\t|   5 : ���� ����/�ٿ��ֱ�\t  |" << endl;
	cout << "\t|   6 : ���� ����\t\t  |" << endl;
	cout << "\t|   7 : ���� �Ӽ� ����\t\t  |" << endl;
	cout << "\t----------------------------------- " << endl;
	cout << "\t|   8 : ���� ����\t\t  |" << endl;
	cout << "\t|   9 : ���� ����\t\t  |" << endl;
	cout << "\t|  10 : ���� ����\t\t  |" << endl;
	cout << "\t|  11 : ���� �̸� ����\t\t  |" << endl;
	cout << "\t|  12 : ���� ����/�ٿ��ֱ�\t  |" << endl;
	cout << "\t|  13 : ���� ����\t\t  |" << endl;
	cout << "\t|  14 : ���� �Ӽ� ����\t\t  |" << endl;
	cout << "\t----------------------------------- " << endl;
	cout << "\t|  15 : ���� �� ���� �˻�\t  |" << endl;
	cout << "\t|  16 : �ֱ� ��� ����\t  |" << endl;
	cout << "\t|  17 : ���� ����� ����\t  |" << endl;
	cout << "\t|  18 : ���� ������ �̵�\t  |" << endl;
	cout << "\t|  19 : ���� ���� ����\t\t  |" << endl;
	cout << "\t|  20 : ���� ���� �Ӽ� ����\t  |" << endl;
	cout << "\t|   0 : Quit\t\t\t  |" << endl;
	cout << "\t-----------------------------------" << endl;

	cout << endl << "\tChoose a Command --> ";
	cin >> command;
	cout << endl;

	return command;
}

/// ���� ���� ���, ����, ���� ����Ʈ�� �����ش�.
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
			m_curFolder->DisplayAllFoldersByName(); /// �̸���
			break;
		case 2:
			m_curFolder->DisplayAllFoldersByDate(); /// ���� ��¥��
			m_SortOption = 1; /// �ٽ� �̸����� �⺻���� ��
			break;
		case 3:
			m_curFolder->DisplayAllFoldersBySize(); /// ũ���
			m_SortOption = 1; /// �ٽ� �̸����� �⺻���� ��
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
			m_curFolder->DisplayAllFilesByName(); /// �̸���
			break;
		case 2:
			m_curFolder->DisplayAllFilesByDate(); /// ���� ��¥��
			m_SortOption = 1; /// �ٽ� �̸����� �⺻���� ��
			break;
		case 3:
			m_curFolder->DisplayAllFilesBySize(); /// ũ���
			m_SortOption = 1; /// �ٽ� �̸����� �⺻���� ��
			break;
		}
	}

}

/// ���ο� ������ �߰��Ѵ�.
int Application::NewFolder()
{
	if (m_curFolder->AddFolder())
		return 1;
	else
		return 0;
}

/// �ش� ������ �����Ѵ�.
int Application::DeleteFolder()
{
	if (m_curFolder->DeleteFolder())
		return 1;
	else
		return 0;
}

/// ����ڰ� �������ϴ� ������ �����͸� �Ű��ش�.
int Application::OpenFolder()
{
	cout << "\t���� ���� ������ �̸��� �Է����ּ���: ";
	FolderType data;
	data.SetNameFromKB();	/// ����ڿ��Լ� ���� �̸��� �Է¹޴´�.
	if (m_curFolder->RetrieveFolderByName(data)) /// �ش� ������ �����ϴ� ���
	{
		m_curFolder = m_curFolder->OpenSubFolder(data); /// ���� ���� �����Ϳ��� ���� ������ �ּҰ��� �ش�.
		
		m_curFolder->SetOpenDate(); /// ������ �ֱ� ��� �ð� ����

		m_curFolder->IncreaseCount(); /// ������ ���� ī��Ʈ ����

		m_curFolder->SetOpenDate(); /// ���� �ֱ� ������ �ð� ����

		/// ������ Ÿ�Կ� ���� �ּ�, ���� �̸� ����
		PointerType tmp;
		tmp.SetAddress(m_curFolder);
		tmp.SetName(m_curFolder->GetName());

		/// Favourites count üũ
		if (m_curFolder->GetCount() >= 3) /// Favourites count�� 3 �̻��̸� �߰� 
		{
			m_Favourites.CheckDuplication(tmp); /// �ߺ� Ȯ��
			m_Favourites.EnQueue(tmp);
		}

		/// Recents�� �߰�
		m_Recents.CheckDuplication(tmp);
		m_Recents.EnQueue(tmp);
		return 1;
	}
	else
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
}

/// ������ �̸��� �����Ѵ�. 
int Application::RenameFolder()
{
	cout << "\t�̸��� �����ϰ� ���� ������ ���� �̸��� �Է����ּ���: ";
	FolderType data;
	data.SetNameFromKB();
	if (m_curFolder->RetrieveFolderByName(data)) /// �ش� ������ �����ϴ� ���
	{
		cout << "\t������ ���� �̸��� �Է����ּ���: ";
		string new_name;
		cin >> new_name; /// ������ ���� �̸� �Է� ����
		m_curFolder->RenameFolder(data, new_name); /// ���� �̸� ����
		return 1; /// ���� �����ÿ� 1 ��ȯ
	}
	else
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
}

/// ���� ����/�ٿ��ֱ�
int Application::CopyPasteFolder()
{
	/// ����
	if (pasteFolderOption == 0) {

		if (m_curFolder->GetFolderList()->GetLength() == 0)
		{
			cout << "\t������ �������� �ʽ��ϴ�." << endl;
			return 0;
		}
		else
		{
			cout << "\t ������ ���� �̸��� �Է����ּ���: ";
			FolderType data;
			data.SetNameFromKB();
			if (!m_curFolder->RetrieveFolderByName(data))
			{
				cout << "\t������ �������� �ʽ��ϴ�." << endl;
				return 0;
			}

			m_curFolder->GetFolderList()->Get(data);
			tmpFolder = data;
			pasteFolderOption = 1;
			return 1;
		}
	}

	/// �ٿ��ֱ�
	if (pasteFolderOption == 1) {
		if (m_curFolder->AddFolder_P(tmpFolder))
		{
			cout << "\t���� �ٿ��ֱ⸦ �Ϸ��߽��ϴ�." << endl;
			pasteFolderOption = 0;
			return 1;
		}
		else
			return 0;
	}
}

/// ���� ����
int Application::DuplicateFolder()
{

	cout << "\t�����ϰ� ���� ������ �̸��� �Է����ּ���: ";
	FolderType data;
	data.SetNameFromKB();	/// ����ڿ��Լ� ���� �̸��� �Է¹޴´�.
	if (m_curFolder->RetrieveFolderByName(data)) /// �ش� ������ �����ϴ� ���
	{
		FolderType newFd;
		FolderType* tmp = m_curFolder->GetFolderList()->ReturnPointer(data);
		newFd = tmp->DuplicateFolder(); /// �����ϱ�
		m_curFolder->GetFolderList()->Add(newFd);
		return 1;
	}
	else
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�.";
		return 0;
	}
}

/// ���� �Ӽ� ���
void Application::DisplayFolderProperty()
{
	cout << "\t�Ӽ��� Ȯ���� ������ �̸��� �Է����ּ���: ";
	FolderType data;
	data.SetNameFromKB();	/// ����ڿ��Լ� ���� ���� �̸��� �Է¹޴´�.
	if (m_curFolder->GetFolderList()->Get(data))
	{
		FolderType* tmp = m_curFolder->GetFolderList()->ReturnPointer(data);
		tmp->DisplayProperty();
	}
	else
		cout << "\t�ش� ������ �������� �ʽ��ϴ�.";
}

/// ������ �����Ѵ�.
int Application::NewFile()
{
	if (m_curFolder->AddFile())
	{
		/// ���� ������ ������ �������ֱ�
		FolderType* tmpPtr;
		tmpPtr = m_curFolder->GetUpperFolder(); /// ���� ���� �����͸� ��� �ӽ� ������
		while (tmpPtr != NULL) /// �ش� ������ ��� ���� �������� ����� ��������
		{
			tmpPtr->SetSize(1, m_curFolder->GetSize());
			tmpPtr = tmpPtr->GetUpperFolder();
		}
		return 1;
	}
	else
		return 0;
}

/// �ش� �̸��� ���� ������ �����Ѵ�.
int Application::MyDeleteFile()
{
	if (m_curFolder->MyDeleteFile())
	{
		/// ���� ������ ������ �������ֱ�
		FolderType* tmpPtr;
		tmpPtr = m_curFolder->GetUpperFolder(); /// ���� ���� �����͸� ��� �ӽ� ������
		while (tmpPtr != NULL) /// �ش� ������ ��� ���� �������� ����� ��������
		{
			tmpPtr->SetSize(-1, m_curFolder->GetSize());
			tmpPtr = tmpPtr->GetUpperFolder();
		}
		return 1;
	}
	else
		return 0;
}

/// ����ڰ� �������ϴ� ������ �����Ų��. txt������ ����Ѵ�.
int Application::OpenFile()
{
	FileType data;
	string fType;
	string fName;
	cout << "\t���� ���� ������ Ȯ���ڸ� �Է����ּ���: ";
	cin >> fType;
	data.SetType(fType);
	cout << "\t���� ���� ������ �̸��� �Է����ּ���: ";
	cin >> fName;
	data.SetName(fName);	/// ����ڿ��Լ� ���� �̸��� �Է¹޴´�.
	if (m_curFolder->RetrieveFileByName(data)) /// �ش� ������ �����ϴ� ���
	{
		int oldSize = m_curFolder->GetSize();
		string tmp = data.GetName(); /// item�� name�� ���� �ӽ� ���� �������
		m_curFolder->OpenFile(data);
		int newSize = m_curFolder->GetSize();
		/// ���� ����� ����� ��츦 ���� ���� ������ ������ �������ֱ�
		FolderType* tmpPtr;
		tmpPtr = m_curFolder->GetUpperFolder(); /// ���� ���� �����͸� ��� �ӽ� ������
		while (tmpPtr != NULL) /// �ش� ������ ��� ���� �������� ����� ��������
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
		cout << "\t�ش� ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
}

/// ������ �̸��� �����Ѵ�.
int Application::RenameFile()
{
	cout << "\t�̸��� �����ϰ� ���� ������ ���� �̸��� �Է����ּ���: ";
	FileType data;
	data.SetNameFromKB();	/// ����ڿ��Լ� ���� ���� �̸��� �Է¹޴´�.
	if (m_curFolder->RetrieveFileByName(data)) /// �ش� ������ �����ϴ� ���
	{
		cout << "\t������ ���� �̸��� �Է����ּ���: ";
		string new_name;
		cin >> new_name; /// ������ ���� �̸� �Է� ����
		m_curFolder->RenameFile(data, new_name); /// ���� �̸� ����
		return 1; /// ���� �����ÿ� 1 ��ȯ
	}
	else
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
}

/// ���� ����/�ٿ��ֱ�
int Application::CopyPasteFile()
{
	/// ����
	if (pasteFileOption == 0) {

		if (m_curFolder->GetFileList()->GetLength() == 0)
		{
			cout << "\t������ �������� �ʽ��ϴ�." << endl;
			return 0;
		}
		else
		{
			cout << "\t������ ���� �̸��� �Է����ּ���: ";
			FileType data;
			data.SetNameFromKB();
			if (!m_curFolder->RetrieveFileByName(data))
			{
				cout << "\t������ �������� �ʽ��ϴ�." << endl;
				return 0;
			}

			m_curFolder->GetFileList()->Get(data);
			tmpFile = data;
			pasteFileOption = 1;
			return 1;
		}
	}

	/// �ٿ��ֱ�
	if (pasteFileOption == 1) {
		if (m_curFolder->AddFile_P(tmpFile))
		{
			cout << "\t���� �ٿ��ֱ⸦ �Ϸ��߽��ϴ�." << endl;
			pasteFileOption = 0;
			return 1;
		}
		else
			return 0;
	}
}

/// ���� ����
int Application::DuplicateFile()
{
	cout << "\t�����ϰ� ���� ������ �̸��� �Է����ּ���: ";
	FileType data;
	data.SetNameFromKB();	/// ����ڿ��Լ� ���� �̸��� �Է¹޴´�.
	if (m_curFolder->RetrieveFileByName(data)) /// �ش� ������ �����ϴ� ���
	{
		FileType newFl;
		FileType* tmp = m_curFolder->GetFileList()->ReturnPointer(data);
		newFl = m_curFolder->DuplicateFile(tmp); /// �����ϱ�
		m_curFolder->GetFileList()->Add(newFl);
		m_curFolder->SetSize(1, newFl.GetSize()); /// ���� ������ ����

		/// ���� ������ ������ �������ֱ�
		FolderType* tmpPtr;
		tmpPtr = m_curFolder->GetUpperFolder(); /// ���� ���� �����͸� ��� �ӽ� ������
		while (tmpPtr != NULL) /// �ش� ������ ��� ���� �������� ����� ��������
		{
			tmpPtr->SetSize(1, m_curFolder->GetSize());
			tmpPtr = tmpPtr->GetUpperFolder();
		}
		return 1;
	}
	else
	{
		cout << "\t�ش� ������ �������� �ʽ��ϴ�.";
		return 0;
	}
}

/// ���� �Ӽ� ���
void Application::DisplayFileProperty()
{
	cout << "\t�Ӽ��� Ȯ���� ������ �̸��� �Է����ּ���: ";
	FileType data;
	data.SetNameFromKB();	/// ����ڿ��Լ� ���� ���� �̸��� �Է¹޴´�.
	if (m_curFolder->GetFileList()->Get(data))
	{
		FileType* tmp = m_curFolder->GetFileList()->ReturnPointer(data);
		tmp->DisplayProperty();
	}
	else
		cout << "\t�ش� ������ �������� �ʽ��ϴ�.";
}

/// ����Ʈ���� �ش� �˻�� ������ ����, ������ ��� ã�� ����Ѵ�.
int Application::Retrieve()
{
	int check = 0;
	string key;
	cout << "\t�˻�� �Է����ּ���: ";
	cin >> key; /// ����ڿ��Լ� �˻�� �Է¹޴´�.

	cout << "\n\t==== �˻� ��� ====" << endl;
	if (m_curFolder->RetrieveFileByKeyword(key) == 1) /// ���� ������ ���� ����Ʈ ���� �˻�
		check = 1;
	if (m_curFolder->RetrieveByKeyword(key) == 1) /// ���� ����Ʈ �� ���� ������ ���ϸ���Ʈ �˻�
		check = 1;

	else
	{
		cout << "\t�ش� �˻�� ������ ����, ������ ã�� ���߽��ϴ�." << endl;
	}

	if (check == 1)
		return 1;
	else 
		return 0;
}

/// �ֱ� ��� ���� �� ����
int Application::DisplayRecents()
{
	cout << "\t==== �ֱ� ��� ���� ====" << endl;
	if (m_Recents.Print() != 0)
	{
		string command;
		cout << "\n\t�ش� ���� �� �ϳ��� �̵��Ͻðھ��?\n\t���ϸ� ���� �̸���, ������ ������ Quit�� �Է��ϼ��� : ";
		cin >> command;

		if (command == "Quit")
			return 1;
		else
		{
			FolderType* tmpPtr;
			PointerType tmp;
			tmp.SetName(command);

			if (m_Recents.Retrieve(tmp) == 1) /// �ش� ������ �����ϴ� ���
			{
				tmpPtr = tmp.GetAddress();
				m_curFolder = tmpPtr; /// ���� ���� �����͸� �����ش�.
				m_curFolder->IncreaseCount(); /// ������ ���� ī��Ʈ ����
				m_curFolder->SetOpenDate(); /// ���� �ֱ� ������ �ð� ����


				/// ������ Ÿ�Կ� ���� �ּ�, ���� �̸� ����
				PointerType tmp;
				tmp.SetAddress(m_curFolder);
				tmp.SetName(m_curFolder->GetName());

				/// Favourites count üũ
				if (m_curFolder->GetCount() >= 3) /// Favourites count�� 3 �̻��̸� �߰� 
				{
					m_Favourites.CheckDuplication(tmp); /// �ߺ� Ȯ��
					m_Favourites.EnQueue(tmp);
				}

				/// Recents�� �߰�
				m_Recents.CheckDuplication(tmp); /// �ߺ� Ȯ��
				m_Recents.EnQueue(tmp);
			}
		}
		return 1;
	}
	return 1;


}

/// ���� ����� ����
int Application::DisplayFavourites()
{
	cout << "\t==== ���� ����� ���� ====" << endl;
	if (m_Favourites.Print() != 0)
	{
		string command;
		cout << "\n\t�ش� ���� �� �ϳ��� �̵��Ͻðھ��?\n\t���ϸ� ���� �̸���, ������ ������ Quit�� �Է��ϼ��� : ";
		cin >> command;

		if (command == "Quit")
			return 1;
		else
		{
			FolderType* tmpPtr;
			PointerType tmp;
			tmp.SetName(command);

			if (m_Favourites.Retrieve(tmp) == 1) /// �ش� ������ �����ϴ� ���
			{
				tmpPtr = tmp.GetAddress();
				m_curFolder = tmpPtr; /// ���� ���� �����͸� �����ش�.
				m_curFolder->IncreaseCount(); /// ������ ���� ī��Ʈ ����
				m_curFolder->SetOpenDate(); /// ���� �ֱ� ������ �ð� ����

				/// ������ Ÿ�Կ� ���� �ּ�, ���� �̸� ����
				PointerType tmp;
				tmp.SetAddress(m_curFolder);
				tmp.SetName(m_curFolder->GetName());


				/// Favourites count üũ
				if (m_curFolder->GetCount() >= 3) /// Favourites count�� 3 �̻��̸� �߰� 
				{
					m_Favourites.CheckDuplication(tmp); /// �ߺ� Ȯ��
					m_Favourites.EnQueue(tmp);
				}

				/// Recents�� �߰�
				m_Recents.CheckDuplication(tmp); /// �ߺ� Ȯ��
				m_Recents.EnQueue(tmp);
			}
		}
		return 1;
	}
	return 1;
}

/// ���� ���� ���� ���� (Default = ByName)
void Application::SortCurrentFolder()
{
	int command;
	cout << "\t1. �̸� �� (Default)" << endl;
	cout << "\t2. ���� ��¥ ��" << endl;
	cout << "\t3. ũ�� ��" << endl;
	cout << "\t���� ���� ���� ��ȣ�� �Է��ϼ���: ";
	cin >> command;
	m_SortOption = command;
}

/// ������ �Ӽ��� ȭ�鿡 ������ش�.
void Application::DisplayCurrentFolderProperty()
{
	m_curFolder->DisplayProperty();
}

/// ���� ������ �̵��Ѵ�.
void Application::GoToUpperFolder()
{
	if (m_curFolder == &m_RootFolder)
	{
		cout << "\t�ֻ��� �����Դϴ�!" << endl; /// ���� root folder�� ���, ���̻��� �̵��� �Ұ��ϹǷ� ���� �޽��� ���
	}
	else
	{
		m_curFolder = m_curFolder->GetUpperFolder(); /// ���� ���� �����ʹ� ���� ������ �����͸� �����´�.		
		m_curFolder->IncreaseCount(); /// ������ ���� ī��Ʈ ����
		m_curFolder->SetOpenDate(); /// ���� �ֱ� ������ �ð� ����

		/// ������ Ÿ�Կ� ���� �ּ�, ���� �̸� ����
		PointerType tmp;
		tmp.SetAddress(m_curFolder);
		tmp.SetName(m_curFolder->GetName());

		/// Favourites count üũ
		if (m_curFolder->GetCount() >= 3) /// Favourites count�� 3 �̻��̸� �߰� 
		{
			m_Favourites.CheckDuplication(tmp); /// �ߺ� Ȯ��
			m_Favourites.EnQueue(tmp);
		}
			
		/// Recents�� �߰�
		m_Recents.CheckDuplication(tmp); /// �ߺ� Ȯ��
		m_Recents.EnQueue(tmp);
	}
}