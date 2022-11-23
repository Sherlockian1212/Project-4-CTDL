#include "DanhSachHangHoa.h"
#include "Display.h"

DanhSachHangHoa::DanhSachHangHoa() {
	_pHead = NULL;
	_pTail = NULL;
	iSoLuong = 0;
};

void DanhSachHangHoa::AddTail(HangHoa a) {
	Node* pAdd = new Node(a);
	if (_pTail == NULL) {
		_pHead = _pTail = pAdd;
	}
	else {
		_pTail->_pNext = pAdd;
		_pTail = pAdd;
	}
	iSoLuong++;
};

void DanhSachHangHoa::Nhap(string Path)
{
	ifstream input(Path);
	HangHoa a;
	while (!input.eof()) {
		string str;

		while (getline(input, str)) {
			if (str[0] == '/' && str[1] == '/') continue;
			stringstream ss(str);
			string word;
			vector<string> hanghoa;
			while (!ss.eof()) {
				getline(ss, word, ';');
				word.erase(word.find_last_not_of(" ") + 1);
				word.erase(0, word.find_first_not_of(" "));
				hanghoa.push_back(word);
			}
			if (hanghoa.size() == 7) {
				a.setMaHang(hanghoa[0]);
				a.setTenHang(hanghoa[1]);
				a.setNoiSanXuat(hanghoa[2]);
				a.setMauSac(hanghoa[3]);
				a.setGiaBan(stoi(hanghoa[4]));
				a.setNgayNhapKho(hanghoa[5]);
				a.setSoLuong(stoi(hanghoa[6]));
				AddTail(a);
			}
		}
	}
	input.close();
};
void DanhSachHangHoa::ThemHH() {
	HangHoa a;
	cout << "Vui long nhap cac thong tin cua hang hoa:" << endl;
	cin >> a;
	if (!IsInHangHoa(a.getMaHang()) && a.getMaHang().length() == 4) {
		AddTail(a);
		return;
	};
	string MH;
	while (!IsInHangHoa(a.getMaHang())) {
		cout << "Ma hang da ton tai, vui long nhap lai thong tin ma hang";
		cin >> MH;
	};
	a.setMaHang(MH);
	while (a.getMaHang().length() != 4) {
		cout << "Ma hang chi bao gom 4 ki tu vui long nhap lai ma hang";
		cin >> MH;
	}
	a.setMaHang(MH);
	AddTail(a);
}

void DanhSachHangHoa::Find(string x) {
	string cls = "                                                                                                                                   ";
	gotoxy(2, 8); cout << cls;
	gotoxy(2, 9); cout << cls;
	gotoxy(2, 10); cout << cls;
	gotoxy(2, 11); cout << cls;
	gotoxy(2, 12); cout << cls;
	gotoxy(2, 13); cout << cls;
	gotoxy(2, 14); cout << cls;
	gotoxy(2, 16); cout << cls;
	gotoxy(2, 8);
	bool flag = false;
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		if (pTemp->data.getTenHang() == x || pTemp->data.getMaHang() == x)
		{
			flag = true;
			cout << "Ma: " << pTemp->data.getMaHang();
			gotoxy(2, 9); cout << "Ten SP: " << pTemp->data.getTenHang();
			gotoxy(2, 10); cout << "Noi SX: " << pTemp->data.getNoiSanXuat();
			gotoxy(2, 11); cout << "Mau: " << pTemp->data.getMauSac();
			gotoxy(2, 12); cout << "Ngay nhap kho: " << pTemp->data.getNgayNhapKho();
			gotoxy(2, 13); cout << "Gia: " << pTemp->data.getGiaBan();
			gotoxy(2, 14); cout << "So luong: " << pTemp->data.getSoLuong();
			gotoxy(2, 16); cout << "Bam Tab hoac Enter de tiep tuc!";
			break;
		}
		pTemp = pTemp->_pNext;
	}
	if (!flag) {
		cout << "Hang hoa hien khong ton tai";
		gotoxy(2, 10); cout << "Bam Tab hoac Enter de tiep tuc!";
	}
	while (true) {
		char _ch = _getch();
		if (_ch == '\t' || _ch == IN::IN_RET) {
			short wx = x.length() >= 98 ? 98 : x.length();
			gotoxy(13 + wx, 2);
			break;
		}
	}
}

void DanhSachHangHoa::PrintFind() {
	short vs = 1; //1: tim kiem, 2: tim, 3: back;
	box(2, 1, 110, 1, "Tim Kiem: ", false);
	box(107, 4, 5, 1, "Tim", false);
	box(2, 4, 6, 1, "Back", false);
	gotoxy(13, 2);
	string x = "";


	while (true) {
		char _inp = _getch();
		if (_inp == 27) return;
		switch (vs) {
		case 1:
			if (_inp == '\t') {
				gotoxy(111, 5);
				vs = 2; continue;
			}
			else if (_inp == IN::IN_RET) Find(x);
			else {
				takeInput(x, _inp, false, 98);
			}
			continue;
		case 2:
			if (_inp == '\t') { gotoxy(7, 5); vs = 3; }
			else if (_inp == IN::IN_RET) {
				Find(x);
				vs = 1;
			}
			continue;
		case 3:
			if (_inp == '\t') {
				short wx = x.length() >= 98 ? 98 : x.length();
				gotoxy(13 + wx, 2);
				vs = 1; continue;
			}
			else if (_inp == IN::IN_RET) break;
			continue;
		default:
			break;
		}
		break;
	}
	

}
void DanhSachHangHoa::Display() {
	Node* pTemp = _pHead;
	box(2, 1, 110, 1, "", false);
	gotoxy(3, 2); cout << "Ma";
	gotoxy(10, 2); cout << "Ten Hang";
	gotoxy(38, 2); cout << "Noi SX";
	gotoxy(58, 2); cout << "Mau Sac";
	gotoxy(72, 2); cout << "Gia ban";
	gotoxy(85, 2); cout << "Ngay nhap kho";
	gotoxy(102, 2); cout << "So luong";
	int i = 1;
	while (pTemp != NULL) {
		box(2, i * 2 + 1, 110, 1, "", true);
		gotoxy(3, i * 2 + 2); cout << pTemp->data.getMaHang();
		gotoxy(10, i * 2 + 2); cout << pTemp->data.getTenHang();
		gotoxy(38, i * 2 + 2); cout << pTemp->data.getNoiSanXuat();
		gotoxy(58, i * 2 + 2); cout << pTemp->data.getMauSac();
		gotoxy(72, i * 2 + 2); cout << pTemp->data.getGiaBan();
		gotoxy(85, i * 2 + 2); cout << pTemp->data.getNgayNhapKho();
		gotoxy(102, i * 2 + 2); cout << pTemp->data.getSoLuong();
		pTemp = pTemp->_pNext;
		i++;
	};
	box(2, i * 2 + 3, 6, 1, "Back", false);
	gotoxy(7, i * 2 + 4);
	while (true) {
		char _inp = _getch();
		if (_inp == IN::IN_RET) break;
	}
};

bool DanhSachHangHoa::IsInHangHoa(string x) {
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		if (pTemp->data.getMaHang() == x)
			return true;
		pTemp = pTemp->_pNext;
	};
	return false;
}
void DanhSachHangHoa::Xoa(string x) {
	if (_pHead->data.getMaHang() == x) {
		Node* pTemp = _pHead;
		_pHead = _pHead->_pNext;
		iSoLuong--;
	}
	else {
		Node* pWalker = _pHead;
		Node* pTemp = NULL;
		while (pWalker != NULL && pWalker->data.getMaHang() != x) {
			pTemp = pWalker;
			pWalker = pWalker->_pNext;
		}
		if (pWalker == NULL)
			return;
		if (pTemp != NULL) {
			if (pWalker == _pTail) {
				_pTail = pTemp;
				_pTail->_pNext = NULL;
			}
			pTemp->_pNext = pWalker->_pNext;
			delete pWalker;
			iSoLuong--;
		}
	}
};
void DanhSachHangHoa::CapNhatSoLuong(string x, int sl) {
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		if (pTemp->data.getMaHang() == x) {
			pTemp->data.setSoLuong(sl);
			return;
		}
		pTemp = pTemp->_pNext;
	}
}