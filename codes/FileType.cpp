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

/// 출처https://kev1n.tistory.com/14
int FileType::OpenImage()
{
	cout << "\n\t**** " << GetName() << " Opened! ****" << endl;
	return 1;
	/// string to char
	char* name_char = new char[flName.length() + 1];
	strcpy(name_char, flName.c_str());

	///// 이미지 불러오기
	//IplImage* image = cvLoadImage(name_char, 1);

	///// 창 만들기
	//cvNamedWindow("window");

	///// 이미지 출력하기
	//cvShowImage("window", image);
	//cvWaitKey(0);

	///// 이미지 저장하기
	//cvSaveImage("복사.jpg", image);

	///// 해제
	//cvDestroyWindow("window");
	//cvReleaseImage(&image);

	return 1;
}

/// 출처https:///www.youtube.com/watch?v=x7bVCifyZzc
int FileType::OpenMusic()
{
	/// 기존 파일 이름 string to LPCWSTR
	string name_str = GetName();
	wstring stemp = s2ws(name_str);
	LPCWSTR result = stemp.c_str();

	cout << "\t해당 파일을 재생합니다." << endl;
	PlaySound(result, NULL, SND_ASYNC);
	return 1;
}

int FileType::Delete()
{
	/// 기존 파일 이름 string to char
	char* name_char = new char[flName.length() + 1];
	strcpy(name_char, flName.c_str());

	if (remove(name_char) != 0) /// 삭제 실패시
		return 0;
	else
		return 1;
}

int FileType::Rename(string n)
{
	int result;

	/// 기존 파일 이름 string to char
	char* oldname = new char[flName.length() + 1];
	strcpy(oldname, flName.c_str());

	/// 새 파일 이름 string to char
	char* newname = new char[n.length() + 1];
	strcpy(newname, n.c_str());

	/// 이름을 바꾸고 결과를 리턴 받는다.
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
	/// 이미지의 경우에 임의로 30000 줌
	if (flType == "jpg")
	{
		flSize = 30000;
		return 1;
	}
	else
	{
		string n = GetName();
		/// 파일 이름 string to char
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

/// 대입 연산자 오버로딩
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

/// 쉬프트 연산자 오버로딩
ostream& operator<<(ostream& os, const FileType& data)
{
	cout << data.flName;
	return os;
}

/// 비교 연산자 오버로딩
bool operator==(const FileType& data1, const FileType& data2)
{
	return (data1.flName == data2.flName);
}

/// 비교 연산자 오버로딩
bool operator<(const FileType& data1, const FileType& data2)
{
	return (data1.flName < data2.flName);
}