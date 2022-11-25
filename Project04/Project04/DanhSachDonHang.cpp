#include "DanhSachDonHang.h"
#include "DonHang.h"
#include "Display.h"


DanhSachDonHang::DanhSachDonHang() {
	_pHead = NULL;
	_pTail = NULL;
	iSoLuong = 0;
}
void DanhSachDonHang::XuLi() {
	int index = 1;

	while (true) {
		system("CLS");
		int cur = 0;
		if (_pHead != NULL) {
			cout << "Stt: " << index++ << endl;
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
			if (donhang.size() == 8 && donhang[0].length() && donhang[1].length() && donhang[2].length() && donhang[3].length()
				&& donhang[4].length() && donhang[5].length() && donhang[6].length() && donhang[7].length()) {
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
		int index = 1;
		while (pTmp != NULL) {
			output << index++ << "; ";
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

void DanhSachDonHang::DatHang(DanhSachHangHoa dsHH) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);

	int yDsHH = dsHH.Display();
	SetConsoleTextAttribute(hConsole, 15);

	string hoten = "";
	string diachi = "";
	string sdt = "";
	time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
	string soLoaiHangDat = "";

	char buf[16] = { 0 };
	strftime(buf, sizeof(buf), "%Y-%m-%d", localtime(&now));
	string ngayDat = string(buf);
	box(15, yDsHH * 2 + 3, 80, 1, "Ho ten: ", false);
	box(15, yDsHH * 2 + 5, 80, 1, "Dia chi: ", true);
	box(15, yDsHH * 2 + 7, 80, 1, "So Dien Thoai: ", true);
	box(15, yDsHH * 2 + 9, 80, 1, "Ngay dat: " + ngayDat, true);
	box(15, yDsHH * 2 + 11, 80, 1, "So loai hang dat: ", true);
	gotoxy(15 + 9, yDsHH * 2 + 4);
	
	short vs = 1;

	while (true) {
		char _inp = _getch();
		if (_inp == 27) return;
		switch (vs) {
		case 1: {
			if (_inp == '\t' || _inp == IN::IN_RET) {
				vs = 2;
				short wvs = diachi.length() >= 60 ? 60 : diachi.length();
				gotoxy(15 + 10 + wvs, yDsHH * 2 + 6);
				continue;
			}
			else { takeInput(hoten, _inp, false, 60); continue; }
		}
			  break;
		case 2: {
			if (_inp == '\t' || _inp == IN::IN_RET) {
				vs = 3;
				short wvs = sdt.length() >= 15 ? 15 : sdt.length();
				gotoxy(15 + 16 + wvs, yDsHH * 2 + 8);
				continue;
			}
			else { takeInput(diachi, _inp, false, 60); continue; }
		}
			  break;
		case 3: {
			if (_inp == '\t' || _inp == IN::IN_RET) {
				vs = 4;
				short wvs = soLoaiHangDat.length() >= 3 ? 3 : soLoaiHangDat.length();
				gotoxy(15 + 19 + wvs, yDsHH * 2 + 12);
				continue;
			}
			else { takeInput(sdt, _inp, false, 15); continue; }
		}
			  break;
		case 4: {
			if (_inp == '\t') {
				vs = 1;
				short wvs = hoten.length() >= 60 ? 60 : hoten.length();
				gotoxy(15 + 9 + wvs, yDsHH * 2 + 4);
				continue;
			}
			else if (_inp == IN::IN_RET) {
				gotoxy(15, yDsHH * 2 + 17); cout << "                                           ";
				if (hoten.length() && diachi.length() && sdt.length() >= 9 && sdt.length() <= 12) {
					int soLoaiHang = stoi(soLoaiHangDat);
					for (int i = 1; i <= soLoaiHang; i++) {
						box(15, yDsHH * 2 + 11 + (i * 2), 80, 1, "Ma hang:                 So luong: ", true);
					}
					box(85, yDsHH * 2 + 13 + ((soLoaiHang + 1) * 2), 10, 1, "Xac nhan", false);
					gotoxy(15 + 10, yDsHH * 2 + 14);
					vector<string> maHang(soLoaiHang, "");
					vector<string> soLuong(soLoaiHang, "");

					short vsMh = 0;
					bool maH = true;
					while (true) {
						char _inpMH = _getch();
						if (_inpMH == 27) return;

						if (_inpMH == '\t') {
							if (vsMh < soLoaiHang) {
								if (!maH) {
									short wvs = maHang[vsMh].length() >= 10 ? 10 : maHang[vsMh].length();
									gotoxy(15 + 10 + wvs, yDsHH * 2 + 14 + (vsMh * 2));
								}
								else {
									short wvs = soLuong[vsMh].length() >= 20 ? 20 : soLuong[vsMh].length();
									gotoxy(15 + 36 + wvs, yDsHH * 2 + 14 + (vsMh * 2));
									vsMh++;
								}
								maH = !maH;
							}
							else if (vsMh == soLoaiHang) {
								gotoxy(85 + 9, yDsHH * 2 + 14 + ((soLoaiHang + 1) * 2));
								vsMh++;
							}
							else {
								short wvs = maHang[0].length() >= 10 ? 10 : maHang[0].length();
								gotoxy(15 + 10 + wvs, yDsHH * 2 + 14);
								vsMh = 0;
								maH = true;
							}
						}
						else if (_inpMH == IN::IN_RET && vsMh == soLoaiHang + 1) {
							bool flag = true;
							vector<int> sl;
							int totalCoin = 0;

							for (int i = 0; i < soLoaiHang; i++) {
								if (!dsHH.IsInHangHoa(maHang[i]) || (dsHH.GetSoLuongMatHang(maHang[i]) && dsHH.GetSoLuongMatHang(maHang[i]) < stoi(soLuong[i]))) { flag = false; break; }
								sl.push_back(stoi(soLuong[i]));
								totalCoin += (stoi(soLuong[i]) * dsHH.GetGiaMatHang(maHang[i]));
							}
							if (!flag) {
								gotoxy(15, yDsHH * 2 + 15 + ((soLoaiHang + 1) * 2));
								SetConsoleTextAttribute(hConsole, 12);
								cout << "Vui long nhap dung ma hang va so luong!";
								SetConsoleTextAttribute(hConsole, 15);
							}
							else {
								gotoxy(15, yDsHH * 2 + 15 + ((soLoaiHang + 1) * 2));
								cout << "Don hang dang cho xu li, bam Exc hoac Enter de thoat";
								DonHang a;
								a.setstrTenKhachHang(hoten);
								a.setstrDiaChi(diachi);
								a.setstrNgayDatHang(ngayDat);
								a.setstrSoDienThoai(sdt);
								a.setlhLoaiHang(maHang);
								a.setSl(sl);
								a.setiTongTien(totalCoin);
								AddTail(a);
								UpdateFile("./DonHang.txt");
								for (int i = 0; i < soLoaiHang; i++) {
									dsHH.CapNhatSoLuong(maHang[i], (dsHH.GetSoLuongMatHang(maHang[i]) - sl[i]));
								}
								dsHH.UpdateFile("./HangHoa.txt");
								dsHH.Display();
								gotoxy(85 + 9, yDsHH * 2 + 14 + ((soLoaiHang + 1) * 2));
								while (true) {
									char _cls = _getch();
									if (_cls == 27 || _cls == IN::IN_RET) {
										return;
									}
								}
							}
						}
						else if (vsMh < soLoaiHang && maH) {
							takeInput(maHang[vsMh], _inpMH, false, 10);
						}
						else if (vsMh <= soLoaiHang && !maH) {
							takeInput(soLuong[vsMh - 1], _inpMH, false, 20);
						}
						continue;
					}
				}
				else {
					SetConsoleTextAttribute(hConsole, 12);
					gotoxy(15, yDsHH * 2 + 17); cout << "Vui long nhap day du va dung thong tin!";
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			else { takeInput(soLoaiHangDat, _inp, false, 3); continue; }
		}
			  break;
		default:
			break;
		}
	}
}