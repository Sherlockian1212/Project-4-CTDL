#include "DonHang.h"

int DonHang::getiSTT() {
	return stt;
}
void DonHang::setiSTT(int stt) {
	this->stt = stt;
}

string DonHang::getstrTenKhachHang() {
	return strTenKhachHang;
}
void DonHang::setstrTenKhachHang(string s) {
	strTenKhachHang = s;
}
string DonHang::getstrDiaChi() {
	return strDiaChi;
}
void DonHang::setstrDiaChi(string s) {
	strDiaChi = s;
}
string DonHang::getstrSoDienThoai() {
	return strSoDienThoai;
}
void DonHang::setstrSoDienThoai(string s) {
	strSoDienThoai = s;
}
string DonHang::getstrNgayDatHang() {
	return strNgayDatHang;
}
void DonHang::setstrNgayDatHang(string s) {
	strNgayDatHang = s;
}
int DonHang::getiTongTien() {
	return iTongTien;
}
void DonHang::setiTongTien(int x) {
	iTongTien = x;
}
vector<string> DonHang::getlhLoaiHang() {
	return this->MaHang;
}

void DonHang::setlhLoaiHang(vector<string> mh) {
	this->MaHang = mh;
}

vector<int> DonHang::getSl() {
	return this->SoLuong;
}

void DonHang::setSl(vector<int> sl) {
	this->SoLuong = sl;
}

DonHang::DonHang() {
	strTenKhachHang = "";
	strDiaChi = "";
	strSoDienThoai = "";
	strNgayDatHang = "";
	iTongTien = 0;
}

