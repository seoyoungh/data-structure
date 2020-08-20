#include "FileType.h"

FileType::FileType()
{
	flName = "";
	flLocation = "";
	flDate = "";
	flType = "";
	flSize = 0;
	flLastModifiedDate = "";
}

FileType::~FileType()
{

}

RelationType FileType::CompareByName(const FileType& data)
{
	if (this->flName > data.flName)
		return GREATER;
	else if (this->flName < data.flName)
		return LESS;
	else
		return EQUAL;
}

void FileType::SetNameFromKB()
{
	string tmp;
	cin >> tmp;
	flName = tmp;
}

/// ��óhttps://kev1n.tistory.com/14
int FileType::OpenImage()
{
	cout << "\n\t**** " << GetName() << " Opened! ****" << endl;
	return 1;
	/// string to char
	char* name_char = new char[flName.length() + 1];
	strcpy(name_char, flName.c_str());

	///// �̹��� �ҷ�����
	//IplImage* image = cvLoadImage(name_char, 1);

	///// â �����
	//cvNamedWindow("window");

	///// �̹��� ����ϱ�
	//cvShowImage("window", image);
	//cvWaitKey(0);

	///// �̹��� �����ϱ�
	//cvSaveImage("����.jpg", image);

	///// ����
	//cvDestroyWindow("window");
	//cvReleaseImage(&image);

	return 1;
}

/// ��óhttps:///www.youtube.com/watch?v=x7bVCifyZzc
int FileType::OpenMusic()
{
	/// ���� ���� �̸� string to LPCWSTR
	string name_str = GetName();
	wstring stemp = s2ws(name_str);
	LPCWSTR result = stemp.c_str();

	cout << "\t�ش� ������ ����մϴ�." << endl;
	PlaySound(result, NULL, SND_ASYNC);
	return 1;
}

int FileType::Delete()
{
	/// ���� ���� �̸� string to char
	char* name_char = new char[flName.length() + 1];
	strcpy(name_char, flName.c_str());

	if (remove(name_char) != 0) /// ���� ���н�
		return 0;
	else
		return 1;
}

int FileType::Rename(string n)
{
	int result;

	/// ���� ���� �̸� string to char
	char* oldname = new char[flName.length() + 1];
	strcpy(oldname, flName.c_str());

	/// �� ���� �̸� string to char
	char* newname = new char[n.length() + 1];
	strcpy(newname, n.c_str());

	/// �̸��� �ٲٰ� ����� ���� �޴´�.
	result = rename(oldname, newname);

	delete[] oldname;
	delete[] newname;

	if (result == 0)
		return 0;
	else
		return 1;
}

/// Get Size
int FileType::LoadSize()
{
	/// �̹����� ��쿡 ���Ƿ� 30000 ��
	if (flType == "jpg")
	{
		flSize = 30000;
		return 1;
	}
	else
	{
		string n = GetName();
		/// ���� �̸� string to char
		char* filepath = new char[n.length() + 1];
		strcpy(filepath, n.c_str());

		FILE *f;
		f = fopen(filepath, "r");
		fseek(f, 0, SEEK_END);
		int filelength = ftell(f);
		fclose(f);
		flSize = filelength;
		return 1;
	}
}


/// Get current time for record
string FileType::MyGetCurrentTime()
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
FileType& FileType::operator= (const FileType& data)
{
	this->flName = data.flName;
	this->flLocation = data.flLocation;
	this->flDate = data.flDate;
	this->flType = data.flType;
	this->flSize = data.flSize;
	this->flLastModifiedDate = data.flLastModifiedDate;
	return *this;
}

/// ����Ʈ ������ �����ε�
ostream& operator<<(ostream& os, const FileType& data)
{
	cout << data.flName;
	return os;
}

/// �� ������ �����ε�
bool operator==(const FileType& data1, const FileType& data2)
{
	return (data1.flName == data2.flName);
}

/// �� ������ �����ε�
bool operator<(const FileType& data1, const FileType& data2)
{
	return (data1.flName < data2.flName);
}