#pragma once
#ifndef __HANGHOA_H__ 
#define __HANGHOA_H__
#include <iostream>
#include <string>
using namespace std;
struct LoaiHang {
	string strMaHang;
	int iSoLuong;

	string getstrMaHang() {
		return strMaHang;
	}
	void setstrMaHang(string s) {
		strMaHang = s;
	}
	int getiSoLuong() {
		return iSoLuong;
	}
	void setiSoLuong(int x) {
		iSoLuong = x;
	}

	friend istream& operator >> (istream& is, LoaiHang& lh) {
		is.ignore();
		getline(is, lh.strMaHang);
		if (lh.strMaHang.length() != 4) {
			cout << "Ma hang gom 4 ki tu !!! Moi nhap lai." << endl;
			getline(is, lh.strMaHang);
		}
		is >> lh.iSoLuong;
		if (lh.iSoLuong < 0) {
			cout << "So luong hang phai lon hon 0!!! Moi nhap lai." << endl;
			is >> lh.iSoLuong;
		}
		return is;
	}
};

class DonHang {
	LoaiHang lhLoaiHang;
	float fTongTien;
	string strTenKhachHang, strDiaChi, strSoDienThoai, strNgayDatHang;
public:
	string getstrTenKhachHang();
	void setstrTenKhachHang(string s);
	string getstrDiaChi();
	void setstrDiaChi(string s);
	string getstrSoDienThoai();
	void setstrSoDienThoai(string s);
	string getstrNgayDatHang();
	void setstrNgayDatHang(string s);
	float getfTongTien();
	void setfTongTien(float x);
	LoaiHang getlhLoaiHang();
	void setlhLoaiHang(LoaiHang lh);
	DonHang();
	friend istream& operator >> (istream& is, DonHang& dh);

};

#endif // !1#pragma once
