#include<iostream>
#include<conio.h>
#include<io.h>
#include<malloc.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>
#pragma warning ( disable:4996 ) // Disable loi tu visual 2013
int n;
using namespace std;
//1212123, Nguyễn Văn A, Công nghê thông tin, 1212123@gmail.com, 2012, 20 / 01 / 1992., 1212123.jpg, Dễ thương, Âm nhạc : Kpop; Vpop, Điện ảnh : Harry Potter
// KEY KHI THAY DOI TEMPLATE THAY DOI Tim VI Tri TEN DEMO
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
// Struct
struct SinhVien
{
	wchar_t* MSSV ;
	wchar_t* Ten;
	wchar_t* Khoa;
	wchar_t* Email ;
	int Namvaohoc;
	wchar_t * Day;
	wchar_t* Hinhanh ;
	wchar_t* Motabanthan ;
	wchar_t** Sothich;
	int soluong;
 
};
struct Luachon
{
	int MSSV;
	int Ten;
	int Khoa;
	int Email;
	int Namvaohoc;
	int Day;
	int Hinhanh;
	int  Motabanthan;
	int Sothich;
};
// chuyển dữ liệu
void deletesv(SinhVien *&sv)
{
	 free(sv->MSSV);
	free(sv);

}
void trans(wchar_t *b)
{
	if (!b) return;
	for (int i = 0; i <= wcslen(b); i++)
	{
		if (b[i] == L';')
		{
			b[i] = L',';
		}
	}
}
 
SinhVien* getinform(wchar_t *a)
{ 
	int index = 0;
	SinhVien* sv = (SinhVien*)malloc(sizeof(SinhVien));
	wchar_t **temp = (wchar_t **)malloc( sizeof(wchar_t*)); 
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
		  if (p != NULL)
		  {
			 temp = (wchar_t**) realloc(temp, sizeof(wchar_t*)*(index+1));
		  }
		
	}
	for (int i = 0; i <index; i++)
	{
		 
		 trans(temp[i]);
	}
	sv->soluong = index - 8;
	sv->MSSV = temp[0];
	sv->Ten = temp[1];
	sv->Khoa = temp[2];
	sv->Email = temp[3];
	 	sv->Namvaohoc = _wtoi(temp[4]);
 
	sv->Day = temp[5];
	sv->Hinhanh = temp[6];
	sv->Motabanthan = temp[7];
	sv->Sothich=(wchar_t**)malloc(sizeof(wchar_t*)*(sv->soluong));
	for (int i = 1; i <= sv->soluong;i++)
	{
		sv->Sothich[i - 1] = temp[7 + i];
	}
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
void chonlua(Luachon &luachon)
{
	do
	{
		wprintf(L"In tên: ");
		scanf("%d", &luachon.Ten);
	} while (luachon.Ten != 1 && luachon.Ten != 2);
	do
	{
		wprintf(L"In MSSV: ");
		scanf("%d", &luachon.MSSV);
	} while (luachon.MSSV != 1 && luachon.MSSV != 2);
	do
	{
		wprintf(L"In Khoa: ");
		scanf("%d", &luachon.Khoa);
	} while (luachon.Khoa != 1 && luachon.Khoa != 2);
	do
	{
		wprintf(L"In Email: ");
		scanf("%d", &luachon.Email);
	} while (luachon.Email != 1 && luachon.Email != 2);
	do
	{
		wprintf(L"In Năm Sinh: ");
		scanf("%d", &luachon.Day);
	} while (luachon.Day != 1 && luachon.Day != 2);
	do
	{
		wprintf(L"In Ảnh Đại Diện : ");
		scanf("%d", &luachon.Hinhanh);
	} while (luachon.Hinhanh != 1 && luachon.Hinhanh != 2);
	do
	{
		wprintf(L"In Mô tả: ");
		scanf("%d", &luachon.Motabanthan);
	} while (luachon.Motabanthan != 1 && luachon.Motabanthan != 2);
	do
	{
		wprintf(L"In Sở Thích: ");
		scanf("%d", &luachon.Sothich);
	} while (luachon.Sothich != 1 && luachon.Sothich != 2);
}
void xuatinfor(SinhVien *sv)
{
	//1212123, Nguy ? n V ? n A, Công nghê thông tin, 1212123@gmail.com, 2012, 20 / 01 / 1994, 1212123.jpg, D ? th ? ? ng, Âm nh ? c : Kpop; Vpop, ? i ? n ? nh : Harry Potter
	wprintf(L"\n\nTHÔNG TIN: \n");
	wprintf(L"MSSV: %ls\n", sv->MSSV);
	wprintf(L"Tên: %ls\n", sv->Ten);
	wprintf(L"Khoa: %ls\n", sv->Khoa);
	wprintf(L"Ảnh đại diện: %ls\n", sv->Hinhanh);
	wprintf(L"Email: %ls\n", sv->Email);
	wprintf(L"Ngày Sinh: %ls\n", sv->Day);
	wprintf(L"Mô Tả: %ls\n", sv->Ten);
	wprintf(L"Sở Thích: %ls\n", sv->Ten);
	for (int i = 0; i < sv->soluong; i++)
	{
		wprintf(L"* %ls\n", sv->Sothich[i]);
	}
	wprintf(L"  END.\n\n");

}
void inrahtml(wchar_t *a)
{
	int flag = 1;
	wchar_t * pwc;
	SinhVien *sv = getinform(a);
	wchar_t filename[60];
	wcscpy(filename, sv->MSSV);
	wcscat(filename, L".html");
	FILE *fin = _wfopen(L"mau.html", L"r, ccs=UTF-8");
	_setmode(_fileno(fin), _O_U8TEXT);
	_setmode(_fileno(stdout), _O_U8TEXT);
	wchar_t *b = (wchar_t *)malloc(1000 * sizeof(wchar_t));
	xuatinfor(sv);
	Luachon luachon;
	chonlua(luachon);
	
	FILE* fout = _wfopen(filename, L"w, ccs=UTF-8");
	_setmode(_fileno(fout), _O_U8TEXT);
	_setmode(_fileno(stdout), _O_U8TEXT); //needed for output
										  //_setmode(_fileno(stdin), _O_U8TEXT); //needed for input
	while (!feof(fin))
	{	//int 1212123,Nguy?n V?n A,Công nghê thông tin,1212123@gmail.com,2012, 20/01/1994 ,1212123.jpg,D? th??ng,Âm nh?c: Kpop; Vpop,?i?n ?nh: Harry Potter
		fgetws(b, 1000, fin);
		if (pwc = wcsstr(b, mau))
		{
			
			if (luachon.Ten == 1)
			{
			fwprintf(fout, L"		<title>HCMUS - %ls</title>\n", sv->Ten);
			}
			else
			{
				fwprintf(fout, L"		<title>HCMUS - No Information</title>\n");
			}
			
		}
		else if ((pwc = wcsstr(b, mau1)))
		{
			if (luachon.Ten == 1 && luachon.MSSV == 1)
			{
				fwprintf(fout, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", sv->Ten, sv->MSSV);
			}
			else if (luachon.Ten == 1 && luachon.MSSV != 1)
			{
				fwprintf(fout, L"						<span class=\"Personal_FullName\">%ls -  No Information</span>\n", sv->Ten);
			}
			else if (luachon.Ten != 1 && luachon.MSSV == 1)
			{
				fwprintf(fout, L"						<span class=\"Personal_FullName\">No Information -  %ls</span>\n", sv->MSSV);
			}
			else
			{
				fwprintf(fout, L"						<span class=\"Personal_FullName\">No Information -  No Information </span>\n");
			}
			 
		}
		else if ((pwc = wcsstr(b, mau2)))
		{
			if (luachon.Khoa == 1)
			{
				fwprintf(fout, L"						<div class=\"Personal_Department\">KHOA  %ls</div>\n", sv->Khoa);
			}
			else
			{
				fwprintf(fout, L"						<div class=\"Personal_Department\">KHOA  No Information</div>\n");
			}
			 
		}
		else if ((pwc = wcsstr(b, mau3)))
		{
			
				if (luachon.Email == 1)
				{
					fwprintf(fout, L"						Email: %ls\n", sv->Email);
				}
				else
				{
					fwprintf(fout, L"						Email: No Information\n");
				}
			 
		}
		else if ((pwc = wcsstr(b, mau4)))
		{
			if (luachon.Hinhanh == 1)
			{
				fwprintf(fout, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv->Hinhanh);
			}
			else
			{
				fwprintf(fout, L"						<img src=\"Images/null.jpg\" class=\"Personal_Hinhcanhan\" />\n");
			}
		}
		else if ((pwc = wcsstr(b, mau5)))
		{
			if (luachon.Ten == 1)
			{
				fwprintf(fout, L"                              <li>Họ và tên: %ls </li>\n", sv->Ten);
			}
			else
			{
				fwprintf(fout, L"                              <li>Họ và tên: No Information </li>\n");
			}
		}
		else if ((pwc = wcsstr(b, mau6)))
		{
			if (luachon.MSSV == 1)
			{
				fwprintf(fout, L"								 <li>MSSV: %ls </li>\n", sv->MSSV);
			}
			else
			{
				fwprintf(fout, L"								 <li>MSSV: No Information </li>\n");
			}
		}
		else if ((pwc = wcsstr(b, mau7)))
		{
			if (luachon.Khoa == 1)
			{
				fwprintf(fout, L"								 <li>Sinh viên khoa: %ls </li>\n", sv->Khoa);
			}
			else
			{
				fwprintf(fout, L"								 <li>Sinh viên khoa: No Information </li>\n");
			}
		}
		else if ((pwc = wcsstr(b, mau8)))
		{
			if (luachon.Day == 1)
			{
				fwprintf(fout, L"								 <li>Ngày sinh: %ls </li>\n", sv->Day);
			}
			else
			{
				fwprintf(fout, L"								 <li>Ngày sinh: No Information </li>\n");
			}
		}
		else if ((pwc = wcsstr(b, mau9)))
		{
			if (luachon.Email == 1)
			{
				fwprintf(fout, L"								 <li>Email: %ls </li>\n", sv->Email);
			}
			else
			{
				fwprintf(fout, L"								 <li>Email: No Information </li>\n");
			}
		}
		else if ((pwc = wcsstr(b, mau10))|| (pwc = wcsstr(b, mau11)))
		{
			if (flag == 1)
			{
				if (luachon.Sothich == 1)
				{
					for (int i = 0; i < sv->soluong; i++)

					{
						fwprintf(fout, L"                              <li>%ls</li>\n", sv->Sothich[i]);
						 
					}
				}
				else
				{
					fwprintf(fout, L"                              <li>No Information</li>\n");
				}
			}
			flag = 2;
		}
		else if ((pwc = wcsstr(b, mau12)))
		{
			if (luachon.Sothich == 1)
			{
				fwprintf(fout, L"                            %ls.\n", sv->Motabanthan);
			}
			else
			{ 
				fwprintf(fout, L"                            No Information.\n");
			}
			  
		}
		else
		{
			fwprintf(fout, L"%ls", b);
		}
	}
	fclose(fout);
	fclose(fin);
	deletesv(sv);	// delete tung mang con 
	free(b);// delete hang doc dong
 
}

void main()
{
 
	int  i;
	FILE* fcsv = _wfopen(L"test2.csv", L"rt, ccs=UTF-8");
	wchar_t **a = TaoMang(fcsv, n);
	fclose(fcsv);
	printf("Nhan 1 de in, 2 de khong in: \n ");
	for (i = 0; i <= n; i++)
	{
		inrahtml(a[i]);
	}			
	free(a);// delete con tro sau khi delete het mang con
	 getch();
}