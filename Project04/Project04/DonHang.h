#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DonHang {
	int stt;
	vector<string> MaHang;
	vector<int> SoLuong;
	int iTongTien;
	string strTenKhachHang, strDiaChi, strSoDienThoai, strNgayDatHang;
public:
	int getiSTT();
	void setiSTT(int stt);
	string getstrTenKhachHang();
	void setstrTenKhachHang(string s);
	string getstrDiaChi();
	void setstrDiaChi(string s);
	string getstrSoDienThoai();
	void setstrSoDienThoai(string s);
	string getstrNgayDatHang();
	void setstrNgayDatHang(string s);
	int getiTongTien();
	void setiTongTien(int x);
	vector<string> getlhLoaiHang();
	void setlhLoaiHang(vector<string> mh);
	vector<int> getSl();
	void setSl(vector<int> sl);
	DonHang();
};
