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
			if (hanghoa.size() >= 7 && hanghoa[0].length() == 4 && hanghoa[1].length() && hanghoa[2].length() && hanghoa[3].length() && hanghoa[4].length() 
				&& hanghoa[5].length() && hanghoa[6].length()) {
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
int DanhSachHangHoa::Display() {
	Node* pTemp = _pHead;
	box(2, 1, 110, 1, "", false);
	gotoxy(3, 2); cout << "Ma";
	gotoxy(10, 2); cout << "Ten Hang";
	gotoxy(35, 2); cout << "Noi SX";
	gotoxy(58, 2); cout << "Mau Sac";
	gotoxy(72, 2); cout << "Gia ban";
	gotoxy(85, 2); cout << "Ngay nhap kho";
	gotoxy(102, 2); cout << "So luong";
	int i = 1;
	while (pTemp != NULL) {
		box(2, i * 2 + 1, 110, 1, "", true);
		gotoxy(3, i * 2 + 2); cout << pTemp->data.getMaHang();
		gotoxy(10, i * 2 + 2);
		auto showLengthTenHang = pTemp->data.getTenHang().length() >= 18 ? 18 : pTemp->data.getTenHang().length();
		for (short i = 0; i < showLengthTenHang; i++) {
			cout << pTemp->data.getTenHang()[i];
		}
		if (pTemp->data.getTenHang().length() > 18) cout << "...";
		gotoxy(35, i * 2 + 2); 
		auto showLengthNSX = pTemp->data.getNoiSanXuat().length() >= 18 ? 18 : pTemp->data.getNoiSanXuat().length();
		for (short i = 0; i < showLengthNSX; i++) {
			cout << pTemp->data.getNoiSanXuat()[i];
		}
		if (pTemp->data.getNoiSanXuat().length() > 18) cout << "...";
		
		gotoxy(58, i * 2 + 2); cout << pTemp->data.getMauSac();
		gotoxy(72, i * 2 + 2); cout << pTemp->data.getGiaBan();
		gotoxy(85, i * 2 + 2); cout << pTemp->data.getNgayNhapKho();
		gotoxy(102, i * 2 + 2); cout << pTemp->data.getSoLuong();
		pTemp = pTemp->_pNext;
		i++;
	};
	return i;
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

int DanhSachHangHoa::GetSoLuongMatHang(string x) {
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		if (pTemp->data.getMaHang() == x) {
			return pTemp->data.getSoLuong();
		}
		pTemp = pTemp->_pNext;
	}
	return 0;
}

int DanhSachHangHoa::GetGiaMatHang(string x) {
	Node* pTemp = _pHead;
	while (pTemp != NULL) {
		if (pTemp->data.getMaHang() == x) {
			return pTemp->data.getGiaBan();
		}
		pTemp = pTemp->_pNext;
	}
	return 0;
}

void DanhSachHangHoa::UpdateFile(string path) {
	ofstream output;
	output.open(path);
	if (output.is_open()) {
		Node* pTmp = _pHead;
		while (pTmp != NULL) {
			output << pTmp->data.getMaHang() << "; ";
			output << pTmp->data.getTenHang() << "; ";
			output << pTmp->data.getNoiSanXuat() << "; ";
			output << pTmp->data.getMauSac() << "; ";
			output << pTmp->data.getGiaBan() << "; ";
			output << pTmp->data.getNgayNhapKho() << "; ";
			output << pTmp->data.getSoLuong() << endl;
			pTmp = pTmp->_pNext;
		}
	}
	output.close();
}

void DanhSachHangHoa::QLHangHoa() {
	short route = 1; //1: Menu, 2: Them, 3: Xoa, 4: Cap Nhat So luong
	while (true) {
		system("CLS");
		short vs = 1;

		switch (route)
		{
		case 1:
		{
			short vsX = 25;
			box(vsX, 3, 20, 1, "Them", false);
			box(vsX, 5, 20, 1, "Xoa", true);
			box(vsX, 7, 20, 1, "Cap nhat", true);
			box(vsX, 9, 20, 1, "Quay lai", true);
			gotoxy(vsX + 5, 4);
			while (true) {
				char chose = _getch();
				switch (vs) {
				case 1:
					if (chose == '\t') { vs = 2; gotoxy(vsX + 4, 6); continue; }
					if (chose == IN::IN_RET) { route = 2; }
					break;
				case 2:
					if (chose == '\t') { vs = 3; gotoxy(vsX + 9, 8); continue; }
					if (chose == IN::IN_RET) route = 3;
					break;
				case 3:
					if (chose == '\t') { vs = 4; gotoxy(vsX + 9, 10); continue; }
					if (chose == IN::IN_RET) { route = 4; }
					break;
				case 4:
					if (chose == '\t') { vs = 1; gotoxy(vsX + 5, 4); continue; }
					if (chose == IN::IN_RET) return;
					break;
				default:
					break;
				}
				break;
			}
		}
		break;
		case 2:
		{
			short vsXThem = 15;
			string maHang = "";
			string tenHang = "";
			string noiSanXuat = "";
			string mauSac = "";
			string gia = "";
			string ngayNhap = "";
			string soLuong = "";
			box(vsXThem, 3, 40, 1, "Ma Hang:", false);
			box(vsXThem, 5, 40, 1, "Ten Mat Hang:", true);
			box(vsXThem, 7, 40, 1, "Noi San Xuat:", true);
			box(vsXThem, 9, 40, 1, "Mau Sac:", true);
			box(vsXThem, 11, 40, 1, "Gia ban:", true);
			box(vsXThem, 13, 40, 1, "Ngay nhap kho:", true);
			box(vsXThem, 15, 40, 1, "So Luong:", true);
			box(vsXThem, 17, 40, 1, "               Xac nhan", true);
			gotoxy(vsXThem + 10, 4);
			while (true) {
				char _inp = _getch();
				if (_inp == 27) { route = 1; break; }
				switch (vs) {
				case 1:
				{
					if (_inp == '\t' || _inp == IN::IN_RET) { 
						short vsw = tenHang.length() >= 30 ? 30 : tenHang.length();
						vs = 2; gotoxy(vsXThem + 15 + vsw, 6); continue;
					}
					takeInput(maHang, _inp, false, 30); continue;
				}
				break;
				case 2:
				{
					if (_inp == '\t' || _inp == IN::IN_RET) { 
						short vsw = noiSanXuat.length() >= 30 ? 30 : noiSanXuat.length();
						vs = 3; gotoxy(vsXThem + 15 + vsw, 8); continue;
					}
					takeInput(tenHang, _inp, false, 30); continue;
				}
				break;
				case 3:
				{
					if (_inp == '\t' || _inp == IN::IN_RET) { 
						short vsw = mauSac.length() >= 30 ? 30 : mauSac.length();
						vs = 4; gotoxy(vsXThem + 10 + vsw, 10); continue;
					}
					takeInput(noiSanXuat, _inp, false, 30); continue;
				}
				break;
				case 4:
				{
					if (_inp == '\t' || _inp == IN::IN_RET) { 
						short vsw = gia.length() >= 30 ? 30 : gia.length();
						vs = 5; gotoxy(vsXThem + 10 + vsw, 12); continue;
					}
					takeInput(mauSac, _inp, false, 30); continue;
				}
				break;
				case 5:
				{
					if (_inp == '\t' || _inp == IN::IN_RET) { 
						short vsw = ngayNhap.length() >= 30 ? 30 : ngayNhap.length();
						vs = 6; gotoxy(vsXThem + 16 + vsw, 14); continue;
					}
					takeInput(gia, _inp, false, 30); continue;
				}
				break;
				case 6:
				{
					if (_inp == '\t' || _inp == IN::IN_RET) {
						short vsw = soLuong.length() >= 30 ? 30 : soLuong.length();
						vs = 7; gotoxy(vsXThem + 11 + vsw, 16); continue;
					}
					takeInput(ngayNhap, _inp, false, 30); continue;
				}
				break;
				case 7:
				{
					if (_inp == '\t' || _inp == IN::IN_RET) { vs = 8; gotoxy(vsXThem + 24, 18); continue; }
					takeInput(soLuong, _inp, false, 30); continue;
				}
				break;
				case 8:
				{
					if (_inp == '\t') { 
						short vsw = maHang.length() >= 30 ? 30 : maHang.length();
						vs = 1; gotoxy(vsXThem + 10 + vsw, 4); continue;
					}
					if (_inp == IN::IN_RET) {
						gotoxy(vsXThem, 20); cout << "                                         ";
						gotoxy(vsXThem, 21); cout << "                                         ";
						if (maHang.length() == 4 && tenHang.length() && noiSanXuat.length() && mauSac.length() && gia.length()
							&& ngayNhap.length() && soLuong.length()) {
							if (IsInHangHoa(maHang)) {
								gotoxy(vsXThem, 20); cout << "Ma Hang da ton tai"; continue;
							}
							else {
								HangHoa newHH;
								newHH.setMaHang(maHang);
								newHH.setTenHang(tenHang);
								newHH.setNoiSanXuat(noiSanXuat);
								newHH.setMauSac(mauSac);
								newHH.setGiaBan(stoi(gia));
								newHH.setNgayNhapKho(ngayNhap);
								newHH.setSoLuong(stoi(soLuong));
								AddTail(newHH);
								UpdateFile("./HangHoa.txt");
								gotoxy(vsXThem, 20); cout << "Them thanh cong";
							}
						}
						else {
							gotoxy(vsXThem, 20); cout << "Vui long nhap day du thong tin";
							gotoxy(vsXThem, 21); cout << "Va ma hang phai bang 4 ki tu"; continue;
						}
						
					}
					continue;
				}
				break;
				default:
					break;
				}
				break;
			}
		}
		break;

		case 3:
		{
			while (true) {
				system("CLS");
				string maHang;
				cout << "Nhap ma hang muon xoa: ";
				cin >> maHang;
				if (IsInHangHoa(maHang)) {
					Xoa(maHang);
					UpdateFile("./HangHoa.txt");
					cout << "\nXoa thanh cong";
				}
				else {
					cout << "\nMa hang khong ton tai";
				}
				cout << "\nBam phim bat ki de tiep tuc hoac Exc de thoat";
				char _inp = _getch();
				if (_inp == 27) {
					route = 1; break;
				}
			}
		}
		break;

		case 4:
		{
			while (true) {
				system("CLS");
				string maHang;
				cout << "Nhap ma hang muon cap nhat: ";
				cin >> maHang;
				if (IsInHangHoa(maHang)) {
					int soLuong;
					cout << "Nhap so luong muon cap nhat: ";
					cin >> soLuong;
					CapNhatSoLuong(maHang, soLuong);
					UpdateFile("./HangHoa.txt");
					cout << "\nCap nhat thanh cong";
				}
				else {
					cout << "\nMa hang khong ton tai";
				}
				cout << "\nBam phim bat ki de tiep tuc hoac Exc de thoat";
				char _inp = _getch();
				if (_inp == 27) {
					route = 1; break;
				}
			}
		}
		break;

		break;
		default:
			break;
		}
	}
}