#include<iomanip>
#include<stdio.h>
#include <cwchar>
#include<stdlib.h>
#include <fcntl.h>
#include <io.h> 
#include<iostream>
using namespace std;
#pragma warning ( disable:4996 )
struct SINHVIEN
{
	wchar_t  *MSSV;
	wchar_t  *HoTen;
	wchar_t  *Khoa;
	//int  
	wchar_t *Lop;
	wchar_t   *NgaySinh;
	wchar_t  *HACN;
	wchar_t  *MTBT;
	wchar_t  *SoThich[100];

};
void main()
{
	SINHVIEN Students[256];
	wchar_t *tmp;
	char* strange = ",";
	int i = 0;
	int j = 0;
	int flag = 0;
	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	wchar_t buf[255];
	char* name = "Test.csv";
	FILE *doc = _wfopen(L"test2.csv", L"r, ccs=UTF-8");
	if (doc == NULL)
	{
		printf("LOI KHONG DOC DUOC \n");
		return;
	}
	while (fgetws(buf, 255, doc) != NULL)
	{
		/*if ((wcslen(buf)>0) && (buf[wcslen(buf) - 1] == '\n'))
		buf[wcslen(buf) - 1] = '\0';*/
		wchar_t *buffer;

		wchar_t* token = wcstok(buf, L",", &buffer);

		Students[i].MSSV = token;
		token = wcstok(nullptr, L",", &buffer);
		Students[i].HoTen = token;
		token = wcstok(nullptr, L",", &buffer);
		Students[i].Khoa = token;
		token = wcstok(nullptr, L",", &buffer);
		Students[i].Lop = token;
		token = wcstok(nullptr, L",", &buffer);
		Students[i].NgaySinh = token;
		token = wcstok(nullptr, L",", &buffer);
		Students[i].HACN = token;
		token = wcstok(nullptr, L",", &buffer);
		Students[i].MTBT = token;
		for (j; wcscmp(token, L"\0") != 0; j++)
		{
			token = wcstok(nullptr, L",", &buffer);
			Students[i].SoThich[j] = token;
		}
		//tempStudent.ID = atoi(buf);

		i++;
		flag = -1;

	}
	fclose(doc);
	cout << "GIA TRI CUA I:= " << i;
	/*if (flag == -1)
	for (int z= 0; z <= i; z++)
	{
	if (Students[z].MSSV != 0)
	wprintf(L"MSSV: %s\n", Students[z].MSSV);
	wprintf(L"Ho ten: %s\n", Students[z].HoTen);
	wprintf(L"Khoa: %s\n", Students[z].Khoa);
	wprintf(L"Khoa' hoc: %s\n", Students[z].Lop);
	wprintf(L"Ngay sinh: %s\n", Students[z].NgaySinh);
	for (int k = 0; k<j; k++)
	wprintf(L"So thich: %s\n", Students[z].SoThich);
	}*/
	system("pause");
}