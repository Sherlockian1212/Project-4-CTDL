#pragma once
#include <iostream>
#include <string>
#include "DonHang.h"
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;


class DanhSachDonHang;
class NodeDonHang {
private:
	friend DanhSachDonHang;
	DonHang data;
	NodeDonHang* _pNext;
public:
	NodeDonHang(DonHang a) {
		data = a;
		_pNext = NULL;
	}
};

class DanhSachDonHang {
private:
	NodeDonHang* _pHead;
	NodeDonHang* _pTail;
	int iSoLuong;
public:
	DanhSachDonHang();
	void LoadFile(string path);
	void UpdateFile(string path);
	void AddTail(NodeDonHang a);
	void XuLi();
	void DatHang();
};

