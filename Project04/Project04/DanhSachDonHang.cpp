#include "DanhSachDonHang.h"
#include "DonHang.h"
#include "Display.h"


DanhSachDonHang::DanhSachDonHang() {
	_pHead = NULL;
	_pTail = NULL;
	iSoLuong = 0;
}
void DanhSachDonHang::XuLi() {

	while (true) {
		system("CLS");
		int cur = 0;
		if (_pHead != NULL) {
			cout << "Stt: " << _pHead->data.getiSTT() << endl;
			for (int i = 0; i < _pHead->data.getlhLoaiHang().size(); i++) {
				cout << "MaHang: " << _pHead->data.getlhLoaiHang()[i] << '\t' << "So Luong: " << _pHead->data.getSl()[i] << endl;
				cur++;
			}
			cout << "Ten khach: " << _pHead->data.getstrTenKhachHang() << endl;
			cout << "Dia Chi: " << _pHead->data.getstrDiaChi() << endl;
			cout << "SDT: " << _pHead->data.getstrSoDienThoai() << endl;
			cout << "Ngay Dat: " << _pHead->data.getstrNgayDatHang() << endl;
			cout << "Tong tien: " << _pHead->data.getiTongTien() << "\n\n\n\n";
			cur += 7;
			box(0, cur - 1, 7, 1, "Xu li", false);
			gotoxy(0, cur + 2); cout << "bam \"Exc\" de thoat";
			gotoxy(6, cur);
		}
		else {
			cout << "Hien khong co don hang cho xu li, bam \"Exc\" de thoat";
		}
		bool flag = false;
		while (true) {
			char _inp = _getch();
			if (_inp == 27) return;
			if (_inp == IN::IN_RET && _pHead != NULL) {
				_pHead = _pHead->_pNext; flag = true; 
				UpdateFile("./DonHang.txt");
				break;
			}
		}
		if (flag) continue;
		break;
	}
}


void DanhSachDonHang::AddTail(NodeDonHang a) {
	NodeDonHang* pAdd = new NodeDonHang(a);
	if (_pTail == NULL) {
		_pHead = _pTail = pAdd;
	}
	else {
		_pTail->_pNext = pAdd;
		_pTail = pAdd;
	}
	iSoLuong++;
};

void DanhSachDonHang::LoadFile(string Path)
{
	ifstream input(Path);
	DonHang a;
	while (!input.eof()) {
		string str;

		while (getline(input, str)) {
			if (str[0] == '/' && str[1] == '/') continue;
			stringstream ss(str);
			string word;
			vector<string> donhang;
			while (!ss.eof()) {
				getline(ss, word, ';');
				word.erase(word.find_last_not_of(" ") + 1);
				word.erase(0, word.find_first_not_of(" "));
				donhang.push_back(word);
			}
			if (donhang.size() == 8) {
				a.setiSTT(stoi(donhang[0]));
				vector<string> mh;
				stringstream ssDh(donhang[1]);
				while (!ssDh.eof()) {
					getline(ssDh, word, ',');
					word.erase(word.find_last_not_of(" ") + 1);
					word.erase(0, word.find_first_not_of(" "));
					mh.push_back(word);
				}
				a.setlhLoaiHang(mh);
				vector<int> sl;
				stringstream ssSl(donhang[2]);
				while (!ssSl.eof()) {
					getline(ssSl, word, ',');
					word.erase(word.find_last_not_of(" ") + 1);
					word.erase(0, word.find_first_not_of(" "));
					sl.push_back(stoi(word));
				}
				a.setSl(sl);
				a.setiTongTien(stoi(donhang[3]));
				a.setstrTenKhachHang(donhang[4]);
				a.setstrDiaChi(donhang[5]);
				a.setstrSoDienThoai(donhang[6]);
				a.setstrNgayDatHang(donhang[7]);
				AddTail(a);
			}
		}
	}
	input.close();
};

void DanhSachDonHang::UpdateFile(string Path) {
	ofstream output;
	output.open(Path);
	if (output.is_open()) {
		NodeDonHang* pTmp = _pHead;
		while (pTmp != NULL) {
			output << pTmp->data.getiSTT() << "; ";
			for (int i = 0; i < pTmp->data.getlhLoaiHang().size(); i++) {
				output << pTmp->data.getlhLoaiHang()[i] << ", ";
			}
			output << "; ";
			for (int i = 0; i < pTmp->data.getSl().size(); i++) {
				output << pTmp->data.getSl()[i] << ", ";
			}
			output << "; " << pTmp->data.getiTongTien() << "; " << pTmp->data.getstrTenKhachHang() << "; " << pTmp->data.getstrDiaChi()
				<< pTmp->data.getstrSoDienThoai() << "; " << pTmp->data.getstrNgayDatHang() << endl;
			pTmp = pTmp->_pNext;
		}
	}
	output.close();
}