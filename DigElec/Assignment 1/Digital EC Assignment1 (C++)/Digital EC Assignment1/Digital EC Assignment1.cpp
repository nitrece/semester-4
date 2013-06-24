// Digital EC Assignment1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Digital EC Assignment1.h"


#define MAX_LOADSTRING 100




// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name






// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
TCHAR*				Convert10toB(TCHAR*, UINT, UINT);







int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), NULL, About);
	return(0);
}




// Message handler for the Dialog Box
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	UINT	opt;
	UINT	y, b;
	BOOL	success;
	TCHAR	buffer[256];

	switch (message)
	{
	case WM_INITDIALOG:
		return((INT_PTR)TRUE);

	case WM_COMMAND:
		opt = LOWORD(wParam);
		if (opt == IDOK)
		{
			y = GetDlgItemInt(hDlg, IDC_EDIT1, &success, FALSE);
			if(!success)
			{
				SetDlgItemText(hDlg, IDC_BUTTON1, _T("Unknown Decimal Number!"));
				return(0);
			}
			b = GetDlgItemInt(hDlg, IDC_EDIT2, &success, FALSE);
			if(!success)
			{
				SetDlgItemText(hDlg, IDC_BUTTON1, _T("Unknown Base Value!"));
				return(0);
			}
			if((b < 2) || (b>36))
			{
				SetDlgItemText(hDlg, IDC_BUTTON1, _T("Improper Base Value!"));
				return(0);
			}
			SetDlgItemText(hDlg, IDC_BUTTON1, Convert10toB(buffer, y, b));
			return(0);
		}
		return(0);
		break;

	case WM_CLOSE:
		EndDialog(hDlg, LOWORD(wParam));
		return((INT_PTR)TRUE);

	}
	return((INT_PTR)FALSE);
}





TCHAR*	Convert10toB(TCHAR* s, UINT y, UINT b)
{
	UINT	i = 0, j;

	while(y)
	{
		j = (y % b);
		s[i++] = (j<10)?(TCHAR)j + _T('0'):(TCHAR)(j - 10) + _T('A');
		y /= b;
	}
	s[i] = NULL;
	_strrev(s);
	return(s);
}