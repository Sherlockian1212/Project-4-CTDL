#ifndef __DANHSACHHANGHOA_H__ 
#define __DANHSACHHANGHOA_H__
#include <iostream>
#include <string>
#include "HangHoa.h"
#include <vector>
#include <sstream>

using namespace std;

#endif // !1

#include<iostream>
#include<fstream>
#include<string>

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
	void Display();
	bool IsInHangHoa(string TenHH);
	void PrintFind(string TenHH);
	void ThemHH();
	void Xoa(string x);
	void CapNhatSoLuong(string x, int sl);
};