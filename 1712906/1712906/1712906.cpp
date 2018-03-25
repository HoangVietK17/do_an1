﻿#include<iostream>
#include<conio.h>
#include<io.h>
#include<malloc.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>
using namespace std;
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


		a[i] = b[i];


}
void transnam(wchar_t *b, wchar_t a[])
{
	wmemset(a, *b, 11);



}
SinhVien* getinform(wchar_t a[])
{
	int index = 0;
	SinhVien* sv = (SinhVien*)malloc(sizeof(SinhVien));
	wchar_t **temp = (wchar_t **)malloc(9 * sizeof(wchar_t));//chưa cấp phát số mảng thích hợp 
	wchar_t *p;
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
	 
	 
	wmemset(sv->Birth, L' ', 11);
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
	SinhVien *sv = getinform(a);
	wchar_t filename[60];
	wcscpy(filename, sv->MSSV);
	wcscat(filename, L".html");
	FILE* fo = _wfopen(filename, L"w, ccs=UTF-8");
	_setmode(_fileno(fo), _O_U8TEXT);
	_setmode(_fileno(stdout), _O_U8TEXT); //needed for output
										  //_setmode(_fileno(stdin), _O_U8TEXT); //needed for input
	fwprintf(fo, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(fo, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(fo, L"	<head>\n");
	fwprintf(fo, L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
	fwprintf(fo, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	fwprintf(fo, L"		<title>HCMUS - %ls</title>\n", sv->MSSV);
	fwprintf(fo, L"	</head>\n");
	fwprintf(fo, L"	<body>\n");
	fwprintf(fo, L"		<div class=\"Layout_container\">\n");
	fwprintf(fo, L"			<!-- Begin Layout Banner Region -->\n");
	fwprintf(fo, L"			<div class=\"Layout_Banner\" >\n");
	fwprintf(fo, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
	fwprintf(fo, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"			<!-- End Layout Banner Region -->\n");
	fwprintf(fo, L"			<!-- Begin Layout MainContents Region -->\n");
	fwprintf(fo, L"			<div class=\"Layout_MainContents\">\n");
	fwprintf(fo, L"				<!-- Begin Below Banner Region -->\n");
	fwprintf(fo, L"				<div class=\"Personal_Main_Information\">\n");
	fwprintf(fo, L"					<!-- Begin Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(fo, L"					<div class=\"Personal_Location\"> \n");
	fwprintf(fo, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	fwprintf(fo, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", sv->Ten, sv->MSSV);
	fwprintf(fo, L"						<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<div class=\"Personal_Phone\">EMAIL: %ls\n", sv->Email);
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"					<!-- End Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(fo, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	fwprintf(fo, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv->Hinhanh);
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"				<!-- End Below Banner Region -->\n");
	fwprintf(fo, L"				<!-- Begin MainContents Region -->\n");
	fwprintf(fo, L"				<div class=\"MainContain\">\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"					<!-- Begin Top Region -->\n");
	fwprintf(fo, L"					<div class=\"MainContain_Top\">\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	fwprintf(fo, L"                              <li>Họ và tên: %ls </li>\n", sv->Ten);
	fwprintf(fo, L"								 <li>MSSV: %ls </li>\n", sv->MSSV);
	fwprintf(fo, L"								 <li>Sinh viên khoa %ls </li>\n", sv->Khoa);
	fwprintf(fo, L"								 <li>Ngày sinh: %ls </li>\n", sv->Day);
	fwprintf(fo, L"								 <li>Email: %ls </li>\n", sv->Email);
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	fwprintf(fo, L"                              <li>%ls</li>\n", sv->Sothich1);
	fwprintf(fo, L"								 <li>%ls</li>\n", sv->Sothich2);
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
	fwprintf(fo, L"						<div class=\"Description\">\n");
	fwprintf(fo, L"                            %ls.\n", sv->Motabanthan);
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"			<!-- Begin Layout Footer -->\n");
	fwprintf(fo, L"			<div class=\"Layout_Footer\">\n");
	fwprintf(fo, L"				<div class=\"divCopyright\">\n");
	fwprintf(fo, L"					<br />\n");
	fwprintf(fo, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
	fwprintf(fo, L"					<br />\n");
	fwprintf(fo, L"				@2018</br>\n");
	fwprintf(fo, L"				Đồ án giữa kì</br>\n");
	fwprintf(fo, L"				Kỹ thuật lâp trình</br>\n");
	fwprintf(fo, L"				TH2018/03</br>\n");
	fwprintf(fo, L"				172906 - Nguyễn Hoàng Việt</br>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"			<!-- End Layout Footer -->\n");
	fwprintf(fo, L"		</div>\n");
	fwprintf(fo, L"	</body>\n");
	fwprintf(fo, L"</html>");
	fclose(fo);
	fclose(fo);
	free(sv);
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