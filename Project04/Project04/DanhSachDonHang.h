#ifndef __DANHSACHDONHANG_H__ 
#define __DANHSACHDONHANG_H__
#include <iostream>
#include <string>
#include "DonHang.h"

using namespace std;

class DanhSachDonHang;
class Node {
	DonHang data;
	Node* _pNext;
	friend DanhSachDonHang;
public:
	Node(DonHang a) {
		data = a;
		_pNext = NULL;
	}
};
class DanhSachDonHang {
	Node* _pHead;
	Node* _pTail;
	int iSoLuong;
public:
	DanhSachDonHang();
	void XuLi(); 
	void ThemDH(DonHang dh);
};

#endif // !1
