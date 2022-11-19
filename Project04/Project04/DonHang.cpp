#include "DonHang.h"

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
float DonHang::getfTongTien() {
	return fTongTien;
}
void DonHang::setfTongTien(float x) {
	fTongTien = x;
}
LoaiHang DonHang::getlhLoaiHang() {
	return lhLoaiHang;
}

void DonHang::setlhLoaiHang(LoaiHang lh) {
	lhLoaiHang = lh;
}
DonHang::DonHang() {
	strTenKhachHang = "";
	strDiaChi = "";
	strSoDienThoai = "";
	strNgayDatHang = "";
	fTongTien = 0;
}

istream& operator >> (istream& is, DonHang& dh) {
	is >> dh.lhLoaiHang;
	is >> dh.fTongTien;
	if (dh.fTongTien < 0) {
		cout << "Tong tien phai lon hon khong!!! Moi nhap lai" << endl;
		is >> dh.fTongTien;
	}
	is.ignore();
	getline(is, dh.strTenKhachHang);
	getline(is, dh.strDiaChi);
	getline(is, dh.strSoDienThoai);
	if (dh.strSoDienThoai.length() != 10) {
		cout << "So dien thoai phai co 10 so!!! Moi nhap lai" << endl;
		getline(is, dh.strSoDienThoai);
	}
	getline(is, dh.strNgayDatHang);
	if (dh.strNgayDatHang.length() != 10) {
		cout << "Ngay dat hang phai co 10 ky tu!!! Moi nhap lai" << endl;
		getline(is, dh.strNgayDatHang);
	}
}

