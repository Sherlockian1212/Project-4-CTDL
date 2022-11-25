#pragma once
#include <iostream>
#include <string>
#include "HangHoa.h"
#include <vector>
#include <sstream>
#include<fstream>

using namespace std;

class DanhSachHangHoa;
class Node {
	HangHoa data;
	Node* _pNext;
	friend DanhSachHangHoa;
public:
	Node(HangHoa a) {
		data = a;
		_pNext = NULL;
	}
};
class DanhSachHangHoa {
	Node* _pHead;
	Node* _pTail;
	int iSoLuong;
public:
	DanhSachHangHoa();
	void AddTail(HangHoa a);
	void Nhap(string Path);
	void UpdateFile(string Path);
	int Display();
	bool IsInHangHoa(string TenHH);
	void Find(string x);
	void PrintFind();
	void ThemHH();
	void Xoa(string x);
	void CapNhatSoLuong(string x, int sl);
	int GetSoLuongMatHang(string x);
	int GetGiaMatHang(string x);
	void QLHangHoa();
};