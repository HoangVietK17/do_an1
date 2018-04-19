#include<iostream>
#include<conio.h>
#include<io.h>
#include<malloc.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>
using namespace std;
//1212123, Nguyễn Văn A, Công nghê thông tin, 1212123@gmail.com, 2012, 20 / 01 / 1992., 1212123.jpg, Dễ thương, Âm nhạc : Kpop; Vpop, Điện ảnh : Harry Potter
// KEY KHI THAY DOI TEMPLATE THAY DOI TEN DEMO
wchar_t*  mau = L"HCMUS - Nguyễn Văn A";
wchar_t*  mau1 = L"NGUYỄN VĂN A - 1212123";
wchar_t* mau2 =L"KHOA CÔNG NGHỆ THÔNG TIN" ;
wchar_t* mau3 =L"Email: nva@gmail.com";
wchar_t* mau4 = L"Images/HinhCaNhan.jpg";
wchar_t * mau5=L"Họ và tên: Nguyễn Văn A";
wchar_t* mau6 =L"MSSV: 1212123";
wchar_t* mau7 =L"Sinh viên khoa Công nghệ thông tin";
wchar_t* mau8 =L"Ngày sinh: 20/01/1994";
wchar_t* mau9 =L"Email: nva@gmail.com";
wchar_t* mau10 = L"Âm nhạc: POP, Balad";
wchar_t* mau11 = L"Ẩm thực: bún riêu, bún thịt nướng";
wchar_t* mau12 = L"Tôi là một người rất thân thiện.";
#pragma warning ( disable:4996 )
// Struct

struct SinhVien
{
	wchar_t MSSV[11];
	wchar_t Ten[31];
	wchar_t Khoa[31];
	wchar_t Email[31];
	int Namvaohoc;
	wchar_t * Day;
	wchar_t Birth[11];
	wchar_t Hinhanh[16];
	wchar_t Motabanthan[1001];
	wchar_t Sothich1[101];
	wchar_t Sothich2[101];
};
//	//int 1212123,Nguy?n V?n A,Công nghê thông tin,1212123@gmail.com,2012, 20/01/1994 ,1212123.jpg,D? th??ng,Âm nh?c: Kpop; Vpop,?i?n ?nh: Harry Potter

// chuyển dữ liệu
void trans(wchar_t *b, wchar_t a[])
{
	if (!b) return;
	for (int i = 0; i <= wcslen(b); i++)
	{
		if (b[i] == L';')
		{
			b[i] = L',';
		}
		a[i] = b[i];

	}
}
 
SinhVien* getinform(wchar_t a[])
{
	int index = 0;
	SinhVien* sv = (SinhVien*)malloc(sizeof(SinhVien));
	wchar_t **temp = (wchar_t **)malloc(9 * sizeof(wchar_t));//chưa cấp phát số mảng thích hợp 
	wchar_t *p;
	bool flag = false;
	//xu li dau ""
	for (int i = 0; i <= wcslen(a); i++)
	{
		if (a[i] == L'"')
		{
			a[i] = L' ';
			while (a[i] != L'"')
			{
				
				if (a[i] == L',')
				{
					a[i] = L';';
				}
				i++;
			}
			a[i] = L' ';
			
		}
	}
	  p = wcstok(a, L",");
	while (p != NULL)
	{

		
		temp[index] = p;
		index++;
		  p = wcstok(NULL, L",");

	}


	trans(temp[0], sv->MSSV);
	trans(temp[1], sv->Ten);
	trans(temp[2], sv->Khoa);
	trans(temp[3], sv->Email);
	 
	 
	 
	sv->Namvaohoc = _wtoi(temp[4]);
	//trans(temp[5], sv->Birth);// Ở đây bị lôi
	sv->Day = temp[5];
	//	wcsncat(sv->NamSinh, temp[4], 11);
	trans(temp[6], sv->Hinhanh);
	trans(temp[7], sv->Motabanthan);
	trans(temp[8], sv->Sothich1);
	trans(temp[9], sv->Sothich2);


	return sv;

}
wchar_t **TaoMang(FILE *f, int &n)
{
	n = 0;

	wchar_t ** a = (wchar_t**)malloc(1 * sizeof(wchar_t*));
	while (!feof(f))
	{
		a[n] = (wchar_t*)malloc(1000 * sizeof(wchar_t));
		fgetws(a[n], 1000, f);
		if (!feof(f))
		{
			n++;
			a = (wchar_t**)realloc(a, (n + 1) * sizeof(wchar_t*));
		}
		else
			break;
	}
	return a;
}
void inrahtml(wchar_t a[])
{
	int flag =1 ;
	wchar_t * pwc;
	SinhVien *sv = getinform(a);
	wchar_t filename[60];
	wcscpy(filename, sv->MSSV);
	wcscat(filename, L".html");
	FILE *fin = _wfopen(L"mau.html", L"r, ccs=UTF-8");
	_setmode(_fileno(fin), _O_U8TEXT);
	_setmode(_fileno(stdout), _O_U8TEXT);
	wchar_t *b = (wchar_t *)malloc(1000 * sizeof(wchar_t));
	
	FILE* fo = _wfopen(filename, L"w, ccs=UTF-8");
	_setmode(_fileno(fo), _O_U8TEXT);
	_setmode(_fileno(stdout), _O_U8TEXT); //needed for output
										  //_setmode(_fileno(stdin), _O_U8TEXT); //needed for input
	while (!feof(fin))
	{	//int 1212123,Nguy?n V?n A,Công nghê thông tin,1212123@gmail.com,2012, 20/01/1994 ,1212123.jpg,D? th??ng,Âm nh?c: Kpop; Vpop,?i?n ?nh: Harry Potter
		fgetws(b,1000, fin);
		if (pwc = wcsstr(b, mau))
		{
			fwprintf(fo, L"		<title>HCMUS - %ls</title>\n", sv->Ten);
			wprintf(  L"		<title>HCMUS - %ls</title>\n", sv->Ten);
		}
		else if ((pwc = wcsstr(b, mau1)))
		{
			fwprintf(fo, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", sv->Ten, sv->MSSV);
			 wprintf(  L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", sv->Ten, sv->MSSV);
		}
		else if ((pwc = wcsstr(b, mau2)))
		{
			fwprintf(fo, L"						<div class=\"Personal_Department\">KHOA  %ls</div>\n",sv->Khoa);
			 wprintf( L"						<div class=\"Personal_Department\">KHOA  %ls</div>\n", sv->Khoa);
		}
		else if ((pwc = wcsstr(b, mau3))&& flag==1)
		{
			fwprintf(fo, L"						 %ls\n", sv->Email);
			 wprintf(  L"						<div class=\"Personal_Phone\">EMAIL: %ls\n", sv->Email);
			 flag = 2;
		}
		else if ((pwc = wcsstr(b, mau4)))
		{
			fwprintf(fo, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv->Hinhanh);
			 wprintf(  L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv->Hinhanh);
		}
		else if ((pwc = wcsstr(b, mau5)))
		{
			fwprintf(fo, L"                              <li>Họ và tên: %ls </li>\n", sv->Ten);
			 wprintf ( L"                              <li>Họ và tên: %ls </li>\n", sv->Ten);
		}
		else if ((pwc = wcsstr(b, mau6)))
		{
			fwprintf(fo, L"								 <li>MSSV: %ls </li>\n", sv->MSSV);
			 wprintf( L"								 <li>MSSV: %ls </li>\n", sv->MSSV);
		}
		else if ((pwc = wcsstr(b, mau7)))
		{
			fwprintf(fo, L"								 <li>Sinh viên khoa: %ls </li>\n", sv->Khoa);
			 wprintf(  L"								 <li>Sinh viên khoa: %ls </li>\n", sv->Khoa);
		}
		else if ((pwc = wcsstr(b, mau8)))
		{
			fwprintf(fo, L"								 <li>Ngày sinh: %ls </li>\n", sv->Day);
			 wprintf(  L"								 <li>Ngày sinh: %ls </li>\n", sv->Day);
		}
		else if ((pwc = wcsstr(b, mau9))&&flag!=1)
		{
			fwprintf(fo, L"								 <li>Email: %ls </li>\n", sv->Email);
			 wprintf(  L"								 <li>Email: %ls </li>\n", sv->Email);
		}
		else if ((pwc = wcsstr(b, mau10)))
		{
			fwprintf(fo, L"                              <li>%ls</li>\n", sv->Sothich1);
			 wprintf(  L"                              <li>%ls</li>\n", sv->Sothich1);
		}
		else if ((pwc = wcsstr(b, mau11)))
		{
			fwprintf(fo, L"								 <li>%ls</li>\n", sv->Sothich2);
			 wprintf(L"								 <li>%ls</li>\n", sv->Sothich2);
		}
		else if ((pwc = wcsstr(b, mau12)))
		{
			fwprintf(fo, L"                            %ls.\n", sv->Motabanthan);
			 wprintf( L"                            %ls.\n", sv->Motabanthan);
		}
		else
		{
			fwprintf(fo, L"%ls", b);
			wprintf(L"%ls", b);
		}
	}
	fclose(fo);
	fclose(fin);
	free(sv);
	free(b);
}
void main()
{
	wchar_t * name = L"test2.csv";
	int n, i;
	FILE* fo = _wfopen(L"test2.csv", L"rt, ccs=UTF-8");
	wchar_t **a = TaoMang(fo, n);
	for (i = 0; i <= n; i++)
		inrahtml(a[i]);
	if (i == n)
		printf(" \t\t\tThanh cong!!!");
	free(a);
	getch();
}