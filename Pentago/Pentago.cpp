#include <iostream>
#include <iomanip>

using namespace std;

struct gracz {
	string imie;
	string kolor;
	string zeton;
};

//stałe symbole
const char rlg = 0xC9; // ╔
const char rpg = 0xBB; // ╗
const char rld = 0xC8; // ╚
const char rpd = 0xBC; // ╝
const char kpion = 0xB3; // │
const char kpionp = 0xBA; // ║
const char kpoz = 0xC4; // ─
const char kpozp = 0xCD; // ═
const char kpionkpoz = 0xC5; // ┼
const char kpionkpozp = 0xCE; // ╬
const char kg = 0xCB; //╦
const char kd = 0xCA; //╩
const char kle = 0xCC; //╠
const char kpr = 0xB9; //╣
const char zeton = 0xDC; // ▄
const char block = 0xDB; // █
string RESET = "\033[0m";
string RED = "\033[0;31m";
string BLUE = "\033[0;34m";

//wczytanie imienia gracza 1
string wczytaj_gracz1(string gracz1) {
	cout << "Imie gracza 1: ";
	cin >> gracz1;
	return gracz1;
}

//wczytanie imienia gracza 2
string wczytaj_gracz2(string gracz2) {
	cout << "Imie gracza 2: ";
	cin >> gracz2;
	return gracz2;
}

//wybor gry
char wybor_gry() {
	char gra;
	cout << "Wybor gry:" << endl << "Kolko i krzyzyk - wcisnij 1" << endl << "Pentago - wcisnij 2" << endl;
	cin >> gra;
	return gra;
}

//informacja którego gracza jest tura
string tura_gracza(string gracz) {
	string tura = "Tura gracza: ";
	return tura + gracz;
}

//wczytanie pustej planszy pentago
void wczytaj_pentago(string p[25][60]) {
	system("cls");
	p[0][0] = rlg;
	for (int k = 1; k < 24; k += 1) {
		p[0][k] = kpozp;
	} p[0][24] = kg;
	for (int k = 25; k < 48; k += 1) {
		p[0][k] = kpozp;
	} p[0][48] = rpg;
	for (int k = 49; k < 60; k += 1) {
		p[0][k] = " ";
	}
	for (int n = 1; n < 12; n += 4) {
		for (int w = n; w < n + 3; w += 1) {
			p[w][0] = kpionp;
			for (int m = 1; m < 48; m += 24) {
				for (int k = m; k < m + 7; k += 1) {
					p[w][k] = " ";
				} p[w][m + 7] = kpion;
				for (int k = m + 8; k < m + 15; k += 1) {
					p[w][k] = " ";
				} p[w][m + 15] = kpion;
				for (int k = m + 16; k < m + 23; k += 1) {
					p[w][k] = " ";
				} p[w][m + 23] = kpionp;
			}
			for (int k = 49; k < 60; k += 1) {
				p[w][k] = " ";
			}
		}
		p[n + 3][0] = kpionp;
		for (int k = 1; k < 8; k += 1) {
			p[n + 3][k] = kpoz;
		} p[n + 3][8] = kpionkpoz;
		for (int k = 9; k < 16; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][16] = kpionkpoz;
		for (int k = 17; k < 24; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][24] = kpionp;
		for (int k = 25; k < 32; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][32] = kpionkpoz;
		for (int k = 33; k < 40; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][40] = kpionkpoz;
		for (int k = 41; k < 48; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][48] = kpionp;
		for (int k = 49; k < 60; k += 1) {
			p[n + 3][k] = " ";
		}
	}
	p[12][0] = kle;
	for (int k = 1; k < 24; k += 1) {
		p[12][k] = kpozp;
	} p[12][24] = kpionkpozp;
	for (int k = 25; k < 48; k += 1) {
		p[12][k] = kpozp;
	} p[12][48] = kpr;
	for (int k = 49; k < 60; k += 1) {
		p[12][k] = " ";
	}
	for (int n = 13; n < 24; n += 4) {
		for (int w = n; w < n + 3; w += 1) {
			p[w][0] = kpionp;
			for (int m = 1; m < 48; m += 24) {
				for (int k = m; k < m + 7; k += 1) {
					p[w][k] = " ";
				} p[w][m + 7] = kpion;
				for (int k = m + 8; k < m + 15; k += 1) {
					p[w][k] = " ";
				} p[w][m + 15] = kpion;
				for (int k = m + 16; k < m + 23; k += 1) {
					p[w][k] = " ";
				} p[w][m + 23] = kpionp;
			}
			for (int k = 49; k < 60; k += 1) {
				p[w][k] = " ";
			}
		}
		p[n + 3][0] = kpionp;
		for (int k = 1; k < 8; k += 1) {
			p[n + 3][k] = kpoz;
		} p[n + 3][8] = kpionkpoz;
		for (int k = 9; k < 16; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][16] = kpionkpoz;
		for (int k = 17; k < 24; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][24] = kpionp;
		for (int k = 25; k < 32; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][32] = kpionkpoz;
		for (int k = 33; k < 40; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][40] = kpionkpoz;
		for (int k = 41; k < 48; k += 1) {
			p[n + 3][k] = kpoz;
		}
		p[n + 3][48] = kpionp;
		for (int k = 49; k < 60; k += 1) {
			p[n + 3][k] = " ";
		}
	}
	for (int w = 21; w < 24; w += 1) {
		p[w][0] = kpionp;
		for (int m = 1; m < 48; m += 24) {
			for (int k = m; k < m + 7; k += 1) {
				p[w][k] = " ";
			} p[w][m + 7] = kpion;
			for (int k = m + 8; k < m + 15; k += 1) {
				p[w][k] = " ";
			} p[w][m + 15] = kpion;
			for (int k = m + 16; k < m + 23; k += 1) {
				p[w][k] = " ";
			} p[w][m + 23] = kpionp;
		}
		for (int k = 49; k < 60; k += 1) {
			p[w][k] = " ";
		}
	}
	p[24][0] = rld;
	for (int k = 1; k < 24; k += 1) {
		p[24][k] = kpozp;
	} p[24][24] = kd;
	for (int k = 25; k < 48; k += 1) {
		p[24][k] = kpozp;
	} p[24][48] = rpd;
	for (int k = 49; k < 60; k += 1) {
		p[24][k] = " ";
	}
}

//wyswietlanie pustej planszy pentago
void wyswietl_pentago(string p[25][60]) {
	for (int w = 0; w < 25; w += 1) {
		for (int k = 0; k < 60; k += 1) {
			cout << p[w][k];
		} cout << endl;
	}
}

//wczytanie pustej planszy kółko i krzyżyk
void wczytaj_kik(string kik[23][60]) {
	system("cls");
	for (int m = 3; m < 20; m += 4) {
		for (int w = m - 3; w < m; w += 1) {
			for (int n = 7; n < 40; n += 8) {
				for (int k = n - 7; k < n; k += 1) {
					kik[w][k] = " ";
				}
				kik[w][n] = kpion;
			} for (int k = 40; k < 60; k += 1) {
				kik[w][k] = " ";
			}
		}
		for (int n = 7; n < 40; n += 8) {
			for (int k = n - 7; k < n; k += 1) {
				kik[m][k] = kpoz;
			}
			kik[m][n] = kpionkpoz;
		}
		for (int k = 40; k < 47; k += 1) {
			kik[m][k] = kpoz;
		}
		for (int k = 47; k < 60; k += 1) {
			kik[m][k] = " ";
		}
	} for (int w = 20; w < 23; w += 1) {
		for (int n = 7; n < 40; n += 8) {
			for (int k = n - 7; k < n; k += 1) {
				kik[w][k] = " ";
			}
			kik[w][n] = kpion;
		} for (int k = 40; k < 60; k += 1) {
			kik[w][k] = " ";
		}
	}
}

//obrot planszy
void obroc_plansze(string p[25][60], string* obr) {
	while (*obr != "qz" && *obr != "wz" && *obr != "sz" && *obr != "az" && *obr != "qx" && *obr != "wx" && *obr != "sx" && *obr != "ax") {
		system("cls");
		p[8][59] = "Bledna kombinacja, sprobuj ponownie.";
		wyswietl_pentago(p);
		cin >> *obr;
	}
	int wp = 0;
	int kp = 0;
	if (*obr == "qz" || *obr == "wz" || *obr == "sz" || *obr == "az") {
		if (*obr == "qz") {
			wp += 1;
			kp += 2;
		}
		else if (*obr == "wz") {
			wp += 1;
			kp += 26;
		}
		else if (*obr == "sz") {
			wp += 13;
			kp += 26;
		}
		else if (*obr == "az") {
			wp += 13;
			kp += 2;
		}
		string temp7[3][5], temp4[3][5];
		for (int w = wp; w < wp + 3; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				temp7[w - wp][k - kp] = p[w][k];
			}
		}
		for (int w = wp + 4; w < wp + 7; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				temp4[w - wp - 4][k - kp] = p[w][k];
			}
		}
		//1 na 7
		for (int w = wp; w < wp + 3; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				p[w][k] = p[w + 8][k];
			}
		}
		//2 na 4
		for (int w = wp + 4; w < wp + 7; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				p[w][k] = p[w + 4][k + 8];
			}
		}
		//3 na 1
		for (int w = wp + 8; w < wp + 11; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				p[w][k] = p[w][k + 16];
			}
		}
		//6 na 2
		for (int w = wp + 8; w < wp + 11; w += 1) {
			for (int k = kp + 8; k < kp + 13; k += 1) {
				p[w][k] = p[w - 4][k + 8];
			}
		}
		//9 na 3
		for (int w = wp + 8; w < wp + 11; w += 1) {
			for (int k = kp + 16; k < kp + 21; k += 1) {
				p[w][k] = p[w - 8][k];
			}
		}
		//8 na 6
		for (int w = wp + 4; w < wp + 7; w += 1) {
			for (int k = kp + 16; k < kp + 21; k += 1) {
				p[w][k] = p[w - 4][k - 8];
			}
		}
		//7 na 9
		for (int w = wp; w < wp + 3; w += 1) {
			for (int k = kp + 16; k < kp + 21; k += 1) {
				p[w][k] = temp7[w - wp][k - kp - 16];
			}
		}
		//4 na 8
		for (int w = wp; w < wp + 3; w += 1) {
			for (int k = kp + 8; k < kp + 13; k += 1) {
				p[w][k] = temp4[w - wp][k - kp - 8];
			}
		}
	}
	else {
		if (*obr == "qx") {
			wp += 1;
			kp += 2;
		}
		else if (*obr == "wx") {
			wp += 1;
			kp += 26;
		}
		else if (*obr == "sx") {
			wp += 13;
			kp += 26;
		}
		else if (*obr == "ax") {
			wp += 13;
			kp += 2;
		}
		string temp7[3][5], temp8[3][5];
		for (int w = wp; w < wp + 3; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				temp7[w - wp][k - kp] = p[w][k];
			}
		}
		for (int w = wp; w < wp + 3; w += 1) {
			for (int k = kp + 8; k < kp + 13; k += 1) {
				temp8[w - wp][k - kp - 8] = p[w][k];
			}
		}
		//9 na 7
		for (int w = wp; w < wp + 3; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				p[w][k] = p[w][k + 16];
			}
		}
		//6 na 8
		for (int w = wp + 4; w < wp + 7; w += 1) {
			for (int k = kp + 16; k < kp + 21; k += 1) {
				p[w - 4][k - 8] = p[w][k];
			}
		}
		//3 na 9
		for (int w = wp + 8; w < wp + 11; w += 1) {
			for (int k = kp + 16; k < kp + 21; k += 1) {
				p[w - 8][k] = p[w][k];
			}
		}
		//2 na 6
		for (int w = wp + 8; w < wp + 11; w += 1) {
			for (int k = kp + 8; k < kp + 13; k += 1) {
				p[w - 4][k + 8] = p[w][k];
			}
		}
		//1 na 3
		for (int w = wp + 8; w < wp + 11; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				p[w][k + 16] = p[w][k];
			}
		}
		//4 na 2
		for (int w = wp + 4; w < wp + 7; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				p[w + 4][k + 8] = p[w][k];
			}
		}
		//7 na 1
		for (int w = wp; w < wp + 3; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				p[w + 8][k] = temp7[w - wp][k - kp];
			}
		}
		//8 na 4
		for (int w = wp + 4; w < wp + 7; w += 1) {
			for (int k = kp; k < kp + 5; k += 1) {
				p[w][k] = temp8[w - wp - 4][k - kp];
			}
		}
	}
}

//wczytanie predefiniowanej planszy kółko i krzyżyk
void wczytaj_pre_kik(string kik[23][60]) {
	for (int w = 0; w < 3; w += 1) {
		for (int k = 9; k < 14; k += 1) {
			kik[w][k] = BLUE + block + RESET;
		}
	}
	for (int w = 0; w < 3; w += 1) {
		for (int k = 33; k < 38; k += 1) {
			kik[w][k] = RED + block + RESET;
		}
	}
	for (int w = 4; w < 7; w += 1) {
		for (int k = 1; k < 6; k += 1) {
			kik[w][k] = RED + block + RESET;
		}
	}
	for (int w = 4; w < 7; w += 1) {
		for (int k = 9; k < 14; k += 1) {
			kik[w][k] = RED + block + RESET;
		}
	}
	for (int w = 4; w < 7; w += 1) {
		for (int k = 17; k < 22; k += 1) {
			kik[w][k] = BLUE + block + RESET;
		}
	}
	for (int w = 4; w < 7; w += 1) {
		for (int k = 25; k < 30; k += 1) {
			kik[w][k] = RED + block + RESET;
		}
	}
	for (int w = 4; w < 7; w += 1) {
		for (int k = 33; k < 38; k += 1) {
			kik[w][k] = BLUE + block + RESET;
		}
	}
	for (int w = 8; w < 11; w += 1) {
		for (int k = 9; k < 14; k += 1) {
			kik[w][k] = RED + block + RESET;
		}
	}
	for (int w = 12; w < 15; w += 1) {
		for (int k = 1; k < 6; k += 1) {
			kik[w][k] = RED + block + RESET;
		}
	}
	for (int w = 12; w < 15; w += 1) {
		for (int k = 9; k < 14; k += 1) {
			kik[w][k] = RED + block + RESET;
		}
	}
	for (int w = 16; w < 19; w += 1) {
		for (int k = 1; k < 6; k += 1) {
			kik[w][k] = BLUE + block + RESET;
		}
	}
	for (int w = 16; w < 19; w += 1) {
		for (int k = 17; k < 22; k += 1) {
			kik[w][k] = RED + block + RESET;
		}
	}
	for (int w = 16; w < 19; w += 1) {
		for (int k = 33; k < 38; k += 1) {
			kik[w][k] = BLUE + block + RESET;
		}
	}
	for (int w = 20; w < 23; w += 1) {
		for (int k = 9; k < 14; k += 1) {
			kik[w][k] = BLUE + block + RESET;
		}
	}
	for (int w = 20; w < 23; w += 1) {
		for (int k = 33; k < 38; k += 1) {
			kik[w][k] = BLUE + block + RESET;
		}
	}
	for (int w = 20; w < 23; w += 1) {
		for (int k = 41; k < 46; k += 1) {
			kik[w][k] = BLUE + block + RESET;
		}
	}
}

//wczytanie predefiniowanej planszy pentago
void wczytaj_pre_pentago(string p[25][60]) {
	{
		for (int w = 1; w < 4; w += 1) {
			for (int k = 10; k < 15; k += 1) {
				p[w][k] = BLUE + block + RESET;
			}
		}
		for (int w = 1; w < 4; w += 1) {
			for (int k = 34; k < 39; k += 1) {
				p[w][k] = RED + block + RESET;
			}
		}
		for (int w = 5; w < 8; w += 1) {
			for (int k = 2; k < 7; k += 1) {
				p[w][k] = RED + block + RESET;
			}
		}
		for (int w = 5; w < 8; w += 1) {
			for (int k = 10; k < 15; k += 1) {
				p[w][k] = RED + block + RESET;
			}
		}
		for (int w = 5; w < 8; w += 1) {
			for (int k = 18; k < 23; k += 1) {
				p[w][k] = BLUE + block + RESET;
			}
		}
		for (int w = 5; w < 8; w += 1) {
			for (int k = 26; k < 31; k += 1) {
				p[w][k] = RED + block + RESET;
			}
		}
		for (int w = 5; w < 8; w += 1) {
			for (int k = 34; k < 39; k += 1) {
				p[w][k] = BLUE + block + RESET;
			}
		}
		for (int w = 9; w < 12; w += 1) {
			for (int k = 10; k < 15; k += 1) {
				p[w][k] = RED + block + RESET;
			}
		}
		for (int w = 13; w < 16; w += 1) {
			for (int k = 2; k < 7; k += 1) {
				p[w][k] = RED + block + RESET;
			}
		}
		for (int w = 13; w < 16; w += 1) {
			for (int k = 10; k < 15; k += 1) {
				p[w][k] = RED + block + RESET;
			}
		}
		for (int w = 17; w < 20; w += 1) {
			for (int k = 2; k < 7; k += 1) {
				p[w][k] = BLUE + block + RESET;
			}
		}
		for (int w = 17; w < 20; w += 1) {
			for (int k = 18; k < 23; k += 1) {
				p[w][k] = RED + block + RESET;
			}
		}
		for (int w = 17; w < 20; w += 1) {
			for (int k = 34; k < 39; k += 1) {
				p[w][k] = BLUE + block + RESET;
			}
		}
		for (int w = 21; w < 24; w += 1) {
			for (int k = 10; k < 15; k += 1) {
				p[w][k] = BLUE + block + RESET;
			}
		}
		for (int w = 21; w < 24; w += 1) {
			for (int k = 34; k < 39; k += 1) {
				p[w][k] = BLUE + block + RESET;
			}
		}
		for (int w = 21; w < 24; w += 1) {
			for (int k = 42; k < 47; k += 1) {
				p[w][k] = BLUE + block + RESET;
			}
		}
	}
}

//wyświetlanie opcji po naciśnięciu "o" w czasie gry
void opcje() {
	system("cls");
	cout << "Opcje:" << endl << endl;
	cout << "p - pauza" << endl << "o - wczytanie predefiniowanej planszy" << endl << "h - wejscie do opisu programu" << endl << endl;
	cout << "Aby kontynuowac rozgrywke, nacisnij enter";
	cin.ignore();
}

//sprawdzenie czy wprowadzona jest prawidlowa wartosc pola przez gracza
//(czy kombinacja jest prawidłowa oraz czy pole nie jest juz zajęte)
bool test_pola(string* kl, string kik[23][60]) {
	if (*kl == "q7") {
		if (kik[1][3] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "q8") {
		if (kik[1][11] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "q9") {
		if (kik[1][19] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w7") {
		if (kik[1][27] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w8") {
		if (kik[1][35] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w9") {
		if (kik[1][43] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "q4") {
		if (kik[5][3] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "q5") {
		if (kik[5][11] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "q6") {
		if (kik[5][19] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w4") {
		if (kik[5][27] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w5") {
		if (kik[5][35] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w6") {
		if (kik[5][43] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "q1") {
		if (kik[9][3] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "q2") {
		if (kik[9][11] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "q3") {
		if (kik[9][19] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w1") {
		if (kik[9][27] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w2") {
		if (kik[9][35] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "w3") {
		if (kik[9][43] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a7") {
		if (kik[13][3] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a8") {
		if (kik[13][11] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a9") {
		if (kik[13][19] == " ") {
			return true;
		}
	}
	else if (*kl == "s7") {
		if (kik[13][27] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "s8") {
		if (kik[13][35] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "s9") {
		if (kik[13][43] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a4") {
		if (kik[17][3] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a5") {
		if (kik[17][11] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a6") {
		if (kik[17][19] == " ") {
			return true;
		}
	}
	else if (*kl == "s4") {
		if (kik[17][27] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "s5") {
		if (kik[17][35] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "s6") {
		if (kik[17][43] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a1") {
		if (kik[21][3] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a2") {
		if (kik[21][11] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "a3") {
		if (kik[21][19] == " ") {
			return true;
		}
	}
	else if (*kl == "s1") {
		if (kik[21][27] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "s2") {
		if (kik[21][35] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "s3") {
		if (kik[21][43] == " ") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (*kl == "o") {
		return true;
	}
	else if (*kl == "m") {
		return true;
	}
	else if (*kl == "h") {
		return true;
	}
	else if (*kl == "p") {
		return true;
	}
	else {return false; }
}

//sprawdza czy po położeniu żetonu gracz wygrywa;
bool test_wygranej(string zeton, string plansza[23][60]) {
	if  //wygrane w pionie
		(((plansza[1][3] == zeton) && (plansza[5][3] == zeton) && (plansza[9][3] == zeton) && (plansza[13][3] == zeton) && (plansza[17][3] == zeton)) ||
			((plansza[21][3] == zeton) && (plansza[5][3] == zeton) && (plansza[9][3] == zeton) && (plansza[13][3] == zeton) && (plansza[17][3] == zeton)) ||
			((plansza[1][11] == zeton) && (plansza[5][11] == zeton) && (plansza[9][11] == zeton) && (plansza[13][11] == zeton) && (plansza[17][11] == zeton)) ||
			((plansza[21][11] == zeton) && (plansza[5][11] == zeton) && (plansza[9][11] == zeton) && (plansza[13][11] == zeton) && (plansza[17][11] == zeton)) ||
			((plansza[1][19] == zeton) && (plansza[5][19] == zeton) && (plansza[9][19] == zeton) && (plansza[13][19] == zeton) && (plansza[17][19] == zeton)) ||
			((plansza[21][19] == zeton) && (plansza[5][19] == zeton) && (plansza[9][19] == zeton) && (plansza[13][19] == zeton) && (plansza[17][19] == zeton)) ||
			((plansza[1][27] == zeton) && (plansza[5][27] == zeton) && (plansza[9][27] == zeton) && (plansza[13][27] == zeton) && (plansza[17][27] == zeton)) ||
			((plansza[21][27] == zeton) && (plansza[5][27] == zeton) && (plansza[9][27] == zeton) && (plansza[13][27] == zeton) && (plansza[17][27] == zeton)) ||
			((plansza[1][35] == zeton) && (plansza[5][35] == zeton) && (plansza[9][35] == zeton) && (plansza[13][35] == zeton) && (plansza[17][35] == zeton)) ||
			((plansza[21][35] == zeton) && (plansza[5][35] == zeton) && (plansza[9][35] == zeton) && (plansza[13][35] == zeton) && (plansza[17][35] == zeton)) ||
			((plansza[1][43] == zeton) && (plansza[5][43] == zeton) && (plansza[9][43] == zeton) && (plansza[13][43] == zeton) && (plansza[17][43] == zeton)) ||
			((plansza[21][43] == zeton) && (plansza[5][43] == zeton) && (plansza[9][43] == zeton) && (plansza[13][43] == zeton) && (plansza[17][43] == zeton)) ||
			//wygrane w poziomie
			((plansza[1][3] == zeton) && (plansza[1][11] == zeton) && (plansza[1][19] == zeton) && (plansza[1][27] == zeton) && (plansza[1][35] == zeton)) ||
			((plansza[1][43] == zeton) && (plansza[1][11] == zeton) && (plansza[1][19] == zeton) && (plansza[1][27] == zeton) && (plansza[1][35] == zeton)) ||
			((plansza[5][3] == zeton) && (plansza[5][11] == zeton) && (plansza[5][19] == zeton) && (plansza[5][27] == zeton) && (plansza[5][35] == zeton)) ||
			((plansza[5][43] == zeton) && (plansza[5][11] == zeton) && (plansza[5][19] == zeton) && (plansza[5][27] == zeton) && (plansza[5][35] == zeton)) ||
			((plansza[9][3] == zeton) && (plansza[9][11] == zeton) && (plansza[9][19] == zeton) && (plansza[9][27] == zeton) && (plansza[9][35] == zeton)) ||
			((plansza[9][43] == zeton) && (plansza[9][11] == zeton) && (plansza[9][19] == zeton) && (plansza[9][27] == zeton) && (plansza[9][35] == zeton)) ||
			((plansza[13][3] == zeton) && (plansza[13][11] == zeton) && (plansza[13][19] == zeton) && (plansza[13][27] == zeton) && (plansza[13][35] == zeton)) ||
			((plansza[13][43] == zeton) && (plansza[13][11] == zeton) && (plansza[13][19] == zeton) && (plansza[13][27] == zeton) && (plansza[13][35] == zeton)) ||
			((plansza[17][3] == zeton) && (plansza[17][11] == zeton) && (plansza[17][19] == zeton) && (plansza[17][27] == zeton) && (plansza[17][35] == zeton)) ||
			((plansza[17][43] == zeton) && (plansza[17][11] == zeton) && (plansza[17][19] == zeton) && (plansza[17][27] == zeton) && (plansza[17][35] == zeton)) ||
			((plansza[21][3] == zeton) && (plansza[21][11] == zeton) && (plansza[21][19] == zeton) && (plansza[21][27] == zeton) && (plansza[21][35] == zeton)) ||
			((plansza[21][43] == zeton) && (plansza[21][11] == zeton) && (plansza[21][19] == zeton) && (plansza[21][27] == zeton) && (plansza[21][35] == zeton)) ||
			//wygrane na ukos 
			((plansza[5][3] == zeton) && (plansza[9][11] == zeton) && (plansza[13][19] == zeton) && (plansza[17][27] == zeton) && (plansza[21][35] == zeton)) ||
			((plansza[1][3] == zeton) && (plansza[5][11] == zeton) && (plansza[9][19] == zeton) && (plansza[13][27] == zeton) && (plansza[17][35] == zeton)) ||
			((plansza[21][43] == zeton) && (plansza[5][11] == zeton) && (plansza[9][19] == zeton) && (plansza[13][27] == zeton) && (plansza[17][35] == zeton)) ||
			((plansza[1][11] == zeton) && (plansza[5][19] == zeton) && (plansza[9][27] == zeton) && (plansza[13][35] == zeton) && (plansza[17][43] == zeton)) ||
			((plansza[1][35] == zeton) && (plansza[5][27] == zeton) && (plansza[9][19] == zeton) && (plansza[13][11] == zeton) && (plansza[17][3] == zeton)) ||
			((plansza[1][43] == zeton) && (plansza[5][35]) == zeton && (plansza[9][27] == zeton) && (plansza[13][19] == zeton) && (plansza[17][11] == zeton)) ||
			((plansza[21][3] == zeton) && (plansza[5][35]) == zeton && (plansza[9][27] == zeton) && (plansza[13][19] == zeton) && (plansza[17][11] == zeton)) ||
			((plansza[5][43] == zeton) && (plansza[9][35] == zeton) && (plansza[13][27] == zeton) && (plansza[17][19] == zeton) && (plansza[21][11] == zeton)))
	{
		return true;
	}
	else {
		return false;
	}
}

//wyświetlanie planszy kółko i krzyżyk
void wyswietl_kik(string kik[23][60]) {
	for (int w = 0; w < 23; w += 1) {
		for (int k = 0; k < 60; k += 1) {
			cout << kik[w][k];
		} cout << endl;
	}
}

//wyświetlanie instrukcji o grze kółko i krzyżyk przed rozpoczęciem rozgrywki
void wyswietl_info_kik() {
	system("cls");
	cout << "Zasady gry kolko i krzyzyk:" << endl << endl;
	cout << "Przed kazdym ruchem nalezy uzyc kombinacji dwoch znakow oraz zatwierdzic klawiszem enter:" << endl;
	cout << "q, w, a, s - wybor cwiartki planszy odpowiednio : lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
	cout << "1..9 - wybor pola na cwiartce jak na klawiaturze numerycznej np. 1 to dolne lewe pole" << endl << endl;
	cout << "Klawisze funkcyjne (po kliknieciu zatwierdzic klawiszem enter):" << endl;
	cout << "p - pauza" << endl << "o - wczytanie predefiniowanej planszy" << endl << "m - wejscie do opcji" << endl << "h - wejscie do opisu programu" << endl << endl;
	cout << "Wygrywa gracz, ktory jako pierwszy ulozy 5 zetonow pod rzad w pionie, poziomie lub na ukos." << endl << endl;
	cout << "Po zapoznaniu sie z instrukcja nacisnij enter";
	cin.ignore();
}

//wyświetlanie instrukcji o grze pentago przed rozpoczęciem rozgrywki
void wyswietl_info_pentago() {
	system("cls");
	cout << "Zasady gry pentago:" << endl << endl;
	cout << "Przed kazdym ruchem nalezy wybrac miejsce umieszczenia zetonu za pomoca kombinacji dwoch znakow oraz zatwierdzic klawiszem enter:" << endl;
	cout << "q, w, a, s - wybor cwiartki planszy odpowiednio : lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
	cout << "1..9 - wybor pola na cwiartce jak na klawiaturze numerycznej np. 1 to dolne lewe pole" << endl << endl;
	cout << "Po wybraniu pola nalezy w podobny sposob wybrac czesc planszy, ktora gracz chce obrocic oraz kierunek obrotu:" << endl;
	cout << "q, w, a, s - wybor cwiartki planszy odpowiednio : lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
	cout << "z, x - obrot odpowiednio: zgodnie z ruchem wskazowek zegara, odwrotnie do ruchu wskazowek zegara" << endl << endl;
	cout << "Klawisze funkcyjne (po kliknieciu zatwierdzic klawiszem enter):" << endl;
	cout << "p - pauza" << endl << "u - undo" << endl << "o - wczytanie predefiniowanej planszy" << endl << "m - wejscie do opcji" << endl << "h - wejscie do opisu programu" << endl << "t - zmiana kolorow zetonow graczy" << endl << endl;
	cout << "Uwaga! Klawisze funkcyjne dzialaja przed rozpoczeciem ruchu przez gracza - nie dzialaja miedzy polozeniem zetonu a obrotem planszy" << endl << endl;
	cout << "Wygrywa gracz, ktory jako pierwszy, po pelnym ruchu (polozenie zetonu oraz obrot) ulozy 5 zetonow pod rzad w pionie, poziomie lub na ukos." << endl << endl;
	cout << "Po zapoznaniu sie z instrukcja nacisnij enter";
	cin.ignore();
}

//wyświetlanie instrukcji o grze pentago w trakcie rozgrywki (od wyswietl_info_pentago() różni się tylko ostatnią linijką)
void wyswietl_info_pentago_k() {
	{
		system("cls");
		cout << "Zasady gry pentago:" << endl << endl;
		cout << "Przed kazdym ruchem nalezy wybrac miejsce umieszczenia zetonu za pomoca kombinacji dwoch znakow oraz zatwierdzic klawiszem enter:" << endl;
		cout << "q, w, a, s - wybor cwiartki planszy odpowiednio : lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
		cout << "1..9 - wybor pola na cwiartce jak na klawiaturze numerycznej np. 1 to dolne lewe pole" << endl << endl;
		cout << "Po wybraniu pola nalezy w podobny sposob wybrac czesc planszy, ktora gracz chce obrocic oraz kierunek obrotu:" << endl;
		cout << "q, w, a, s - wybor cwiartki planszy odpowiednio : lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
		cout << "z, x - obrot odpowiednio: zgodnie z ruchem wskazowek zegara, odwrotnie do ruchu wskazowek zegara" << endl << endl;
		cout << "Klawisze funkcyjne (po kliknieciu zatwierdzic klawiszem enter):" << endl;
		cout << "p - pauza" << endl << "u - undo" << endl << "o - wczytanie predefiniowanej planszy" << endl << "m - wejscie do opcji" << endl << "h - wejscie do opisu programu" << endl << "t - zmiana kolorow zetonow graczy" << endl << endl;
		cout << "Uwaga! Klawisze funkcyjne dzialaja przed rozpoczeciem ruchu przez gracza - nie dzialaja miedzy polozeniem zetonu a obrotem planszy" << endl << endl;
		cout << "Wygrywa gracz, ktory jako pierwszy, po pelnym ruchu (polozenie zetonu oraz obrot) ulozy 5 zetonow pod rzad w pionie, poziomie lub na ukos." << endl << endl;
		cout << "Aby kontynuowac rozgrywke, nacisnij enter";
		cin.ignore();
	}
}

//wyświetlanie instrukcji o grze kółko i krzyżyk w trakcie rozgrywki (od wyswietl_info_kik() różni się tylko ostatnią linijką)
void wyswietl_info_kik_k() {
	system("cls");
	cout << "Zasady gry kolko i krzyzyk:" << endl << endl;
	cout << "Przed kazdym ruchem nalezy uzyc kombinacji dwoch znakow oraz zatwierdzic klawiszem enter:" << endl;
	cout << "q, w, a, s - wybor cwiartki planszy odpowiednio : lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
	cout << "1..9 - wybor pola na cwiartce jak na klawiaturze numerycznej np. 1 to dolne lewe pole" << endl << endl;
	cout << "Klawisze funkcyjne (po kliknieciu zatwierdzic klawiszem enter):" << endl;
	cout << "p - pauza" << endl << "u - undo" << endl << "o - wczytanie predefiniowanej planszy" << endl << "m - wejscie do opcji" << endl << "h - wejscie do opisu programu" << endl << endl;
	cout << "Wygrywa gracz, ktory jako pierwszy ulozy 5 zetonow pod rzad w pionie, w poziomie lub na ukos." << endl << endl;
	cout << "Aby kontynuowac rozgrywke, nacisnij enter";
	cin.ignore();
}

//wybranie żetonu przez gracza1;
char wybierz_zeton(string gracz) {
	char zeton;
	cout << gracz << ", " << "wybierz kolor swoich zetonow: " << endl;
	cout << "\u001b[31mCzerwony\u001b[0m - wybierz 1" << endl;
	cout << "\u001B[34mNiebieski\u001b[0m - wybierz 2" << endl;
	cin >> zeton;
	return zeton;
}

//zamiana zetonow
void zamien_zetony(gracz gracz1, gracz gracz2, string p[25][60]) {
	string temp;
	for (int w = 0; w < 25; w += 1) {
		for (int k = 0; k < 60; k += 1) {
			if (p[w][k] == gracz1.zeton) {
				p[w][k] = gracz2.zeton;
			}
			else if (p[w][k] == gracz2.zeton) {
				p[w][k] = gracz1.zeton;
			}
		}
	}
	p[8][59] = "Poloz zeton";
}

int main()
{
	char gra;
	gracz gracz1, gracz2;
	string imie1, imie2;
	gracz1.imie = wczytaj_gracz1(gracz1.imie);
	imie1 = gracz1.imie;
	gracz2.imie = wczytaj_gracz2(gracz2.imie);
	imie2 = gracz2.imie;
	gra = wybor_gry();
	while (gra != '1' && gra != '2') {
		cout << "Nieprawidlowy wybor" << endl;
		gra = wybor_gry();
	}
	if (gra == '1') {
		wyswietl_info_kik();
	}
	else if (gra == '2') {
		wyswietl_info_pentago();
	}
	cin.ignore();
	system("cls");
	char zeton1 = wybierz_zeton(gracz1.imie);
	while (zeton1 != '1' && zeton1 != '2') {
		cout << "Nieprawidlowy wybor" << endl;
		zeton1 = wybierz_zeton(gracz1.imie);
	}
	if (zeton1 == '1') {
		gracz1.kolor = RED;
		gracz1.imie = gracz1.kolor + gracz1.imie + RESET;
		gracz2.kolor = BLUE;
		gracz2.imie = gracz2.kolor + gracz2.imie + RESET;
	}
	else if (zeton1 == '2') {
		gracz1.kolor = BLUE;
		gracz1.imie = gracz1.kolor + gracz1.imie + RESET;
		gracz2.kolor = RED;
		gracz2.imie = gracz2.kolor + gracz2.imie + RESET;
	}
	if (gra == '1') {
		string kik[23][60];
		wczytaj_kik(kik);
		kik[3][59] = tura_gracza(gracz1.imie);
		kik[11][59] = "h - opis gry";
		wyswietl_kik(kik);
		string klawisz;
		string* kl;
		kl = &klawisz;
		gracz1.zeton = gracz1.kolor + block + RESET;
		gracz2.zeton = gracz2.kolor + block + RESET;
		for (int i = 0; i < 36; i += 1) {
			cin >> *kl;
			if (i % 2 == 0) {
				while (test_pola(kl, kik) == false) {
					system("cls");
					kik[7][59] = "Bledny wybor pola, sprobuj ponownie.";
					wyswietl_kik(kik);
					cin >> *kl;
				}
				if (*kl == "q7") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q8") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q9") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w7") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w8") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w9") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q4") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q5") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q6") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w4") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w5") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w6") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q1") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q2") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q3") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w1") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w2") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w3") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a7") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a8") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a9") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s7") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s8") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s9") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a4") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a5") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a6") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s4") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s5") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s6") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a1") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a2") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a3") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s1") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s2") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s3") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz1.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz2.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz1.zeton, kik) == true) {
						kik[3][59] = gracz1.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "o") {
					wczytaj_kik(kik);
					wczytaj_pre_kik(kik);
					if (zeton1 == '1') {
						kik[3][59] = tura_gracza(gracz1.imie);
					}
					if (zeton1 == '2') {
						gracz temp = gracz1;
						gracz1 = gracz2;
						gracz2 = temp;
						kik[3][59] = tura_gracza(gracz1.imie);
					}
					i = 15;
					wyswietl_kik(kik);
				}
				else if (*kl == "m") {
					i -= 1;
					kik[7][59] = " ";
					opcje();
					cin.ignore();
					system("cls");
					wyswietl_kik(kik);
				}
				else if (*kl == "h") {
					i -= 1;
					kik[7][59] = " ";
					wyswietl_info_kik_k();
					cin.ignore();
					system("cls");
					wyswietl_kik(kik);
				}
			}
			else {
				while (test_pola(kl, kik) == false) {
					system("cls");
					kik[7][59] = "Bledny wybor pola, sprobuj ponownie.";
					wyswietl_kik(kik);
					cin >> *kl;
				}
				if (*kl == "q7") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q8") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q9") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w7") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w8") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w9") {
					for (int w = 0; w < 3; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q4") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q5") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q6") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w4") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w5") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w6") {
					for (int w = 4; w < 7; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q1") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q2") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "q3") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w1") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w2") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "w3") {
					for (int w = 8; w < 11; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a7") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a8") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a9") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s7") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s8") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s9") {
					for (int w = 12; w < 15; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a4") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a5") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a6") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s4") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s5") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s6") {
					for (int w = 16; w < 19; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a1") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 1; k < 6; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a2") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 9; k < 14; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "a3") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 17; k < 22; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s1") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 25; k < 30; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s2") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 33; k < 38; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "s3") {
					for (int w = 20; w < 23; w += 1) {
						for (int k = 41; k < 46; k += 1) {
							kik[w][k] = gracz2.zeton;
						}
					}
					kik[3][59] = tura_gracza(gracz1.imie);
					kik[7][59] = " ";
					system("cls");
					wyswietl_kik(kik);
					if (test_wygranej(gracz2.zeton, kik) == true) {
						kik[3][59] = gracz2.imie + " wygral(a)!"; kik[7][59] = " "; system("cls");
						wyswietl_kik(kik);
						return 0;
					}
				}
				else if (*kl == "o") {
					wczytaj_kik(kik);
					wczytaj_pre_kik(kik);
					if (zeton1 == '1') {
						kik[3][59] = tura_gracza(gracz1.imie);
					}
					if (zeton1 == '2') {
						gracz temp = gracz1;
						gracz1 = gracz2;
						gracz2 = temp;
						kik[3][59] = tura_gracza(gracz1.imie);
					}
					i = 15;
					wyswietl_kik(kik);
				}
				else if (*kl == "m") {
					kik[7][59] = " ";
					i -= 1;
					opcje();
					cin.ignore();
					system("cls");
					wyswietl_kik(kik);
				}
				else if (*kl == "h") {
					kik[7][59] = " ";
					i -= 1;
					wyswietl_info_kik_k();
					cin.ignore();
					system("cls");
					wyswietl_kik(kik);
				}
			}
		}
		kik[3][59] = "REMIS!";
		system("cls");
		wyswietl_kik(kik);
		return 0;
	}
	else if (gra == '2') {
		string p[25][60], gracz11[25][60], gracz12[25][60], gracz13[25][60], gracz14[25][60], gracz21[25][60], gracz22[25][60], gracz23[25][60], gracz24[25][60];
		string** tab = new string * [60];
		wczytaj_pentago(p);
		p[4][59] = tura_gracza(gracz1.imie);
		p[8][59] = "Poloz zeton";
		p[12][59] = "h - opis gry";
		wyswietl_pentago(p);
		string klawisz, obrot;
		string* obr;
		string* kl;
		kl = &klawisz;
		obr = &obrot;
		gracz1.zeton = gracz1.kolor + block + RESET;
		gracz2.zeton = gracz2.kolor + block + RESET;
		for (int i = 0; i < 36; i += 1) {
			cin >> *kl;
			if (i % 2 == 0) {
				while (test_pola(kl, p) == false && *kl != "u" && *kl != "t") {
					system("cls");
					p[8][59] = "Bledny wybor pola, sprobuj ponownie.";
					wyswietl_pentago(p);
					cin >> *kl;
				}
				if (*kl == "u") {
					if (i > 1) {
						if ((i - 2) % 8 == 0) {
							for (int w = 0; w < 25; w += 1) {
								for (int k = 0; k < 60; k += 1) {
									p[w][k] = gracz11[w][k];
								}
							}
							system("cls");
							p[4][59] = tura_gracza(gracz1.imie);
							wyswietl_pentago(p);
						}
						else if ((i - 2) % 8 == 2) {
							for (int w = 0; w < 25; w += 1) {
								for (int k = 0; k < 60; k += 1) {
									p[w][k] = gracz12[w][k];
								}
							}
							system("cls");
							p[4][59] = tura_gracza(gracz1.imie);
							wyswietl_pentago(p);
						}
						else if ((i - 2) % 8 == 4) {
							for (int w = 0; w < 25; w += 1) {
								for (int k = 0; k < 60; k += 1) {
									p[w][k] = gracz13[w][k];
								}
							}
							system("cls");
							p[4][59] = tura_gracza(gracz1.imie);
							wyswietl_pentago(p);
						}
						else if ((i - 2) % 8 == 6) {
							for (int w = 0; w < 25; w += 1) {
								for (int k = 0; k < 60; k += 1) {
									p[w][k] = gracz14[w][k];
								}
							}
							system("cls");
							p[4][59] = tura_gracza(gracz1.imie);
							wyswietl_pentago(p);
						}
						i -= 3;
					}
					else {
						p[8][59] = "Funkcja niedostepna";
						i -= 1;
						system("cls");
						wyswietl_pentago(p);
					}
				}
				else if (*kl == "q7") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q8") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q9") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w7") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w8") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w9") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q4") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q5") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q6") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w4") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w5") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w6") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q1") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q2") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q3") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w1") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w2") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w3") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a7") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a8") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a9") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s7") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s8") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s9") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a4") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a5") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a6") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s4") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s5") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s6") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a1") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a2") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a3") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s1") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s2") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s3") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz1.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz1.zeton, p) == true) {
						p[4][59] = gracz1.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "o") {
					wczytaj_pentago(p);
					wczytaj_pre_pentago(p);
					if (zeton1 == '1') {
						p[4][59] = tura_gracza(gracz1.imie);
					}
					if (zeton1 == '2') {
						gracz temp = gracz1;
						gracz1 = gracz2;
						gracz2 = temp;
						p[4][59] = tura_gracza(gracz1.imie);
					}
					i = 16;
					wyswietl_pentago(p);
				}
				else if (*kl == "m") {
					i -= 1;
					p[8][59] = "Poloz zeton";
					opcje();
					cin.ignore();
					system("cls");
					wyswietl_pentago(p);
				}
				else if (*kl == "h") {
					i -= 1;
					p[8][59] = "Poloz zeton";
					wyswietl_info_pentago_k();
					cin.ignore();
					system("cls");
					wyswietl_pentago(p);
				}
				else if (*kl == "p") {
					i -= 1;
					system("cls");
					cout << "PAUZA" << endl << "Aby kontynuowac gre, nacisnij enter";
					cin.ignore();
					cin.ignore();
					system("cls");
					wyswietl_pentago(p);
				}
				else if (*kl == "t") {
					i -= 1;
					zamien_zetony(gracz1, gracz2, p);
					if (gracz1.kolor == BLUE) {
						gracz1.kolor = RED;
					}
					else if (gracz1.kolor == RED) {
						gracz1.kolor = BLUE;
					}
					if (gracz2.kolor == BLUE) {
						gracz2.kolor = RED;
					}
					else if (gracz2.kolor == RED) {
						gracz2.kolor = BLUE;
					}
					gracz1.imie = gracz1.kolor + imie1 + RESET;
					gracz2.imie = gracz2.kolor + imie2 + RESET;
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
				}
				if (*kl != "t" && *kl != "p" && *kl != "m" && *kl != "h") {
					if (i % 8 == 0) {
						for (int w = 0; w < 25; w += 1) {
							for (int k = 0; k < 60; k += 1) {
								gracz11[w][k] = p[w][k];
							}
						}
					}
					else if (i % 8 == 2) {
						for (int w = 0; w < 25; w += 1) {
							for (int k = 0; k < 60; k += 1) {
								gracz12[w][k] = p[w][k];
							}
						}
					}
					else if (i % 8 == 4) {
						for (int w = 0; w < 25; w += 1) {
							for (int k = 0; k < 60; k += 1) {
								gracz13[w][k] = p[w][k];
							}
						}
					}
					else if (i % 8 == 6) {
						for (int w = 0; w < 25; w += 1) {
							for (int k = 0; k < 60; k += 1) {
								gracz14[w][k] = p[w][k];
							}
						}
					}
				}
			}
			else {
				while (test_pola(kl, p) == false && *kl != "u" && *kl != "t") {
					system("cls");
					p[8][59] = "Bledny wybor pola, sprobuj ponownie.";
					wyswietl_pentago(p);
					cin >> *kl;
				}
				if (*kl == "u") {
					if (i > 2) {
						if ((i - 2) % 8 == 1) {
							for (int w = 0; w < 25; w += 1) {
								for (int k = 0; k < 60; k += 1) {
									p[w][k] = gracz21[w][k];
								}
							}
							system("cls");
							p[4][59] = tura_gracza(gracz2.imie);
							wyswietl_pentago(p);
						}
						else if ((i - 2) % 8 == 3) {
							for (int w = 0; w < 25; w += 1) {
								for (int k = 0; k < 60; k += 1) {
									p[w][k] = gracz22[w][k];
								}
							}
							system("cls");
							p[4][59] = tura_gracza(gracz2.imie);
							wyswietl_pentago(p);
						}
						else if ((i - 2) % 8 == 5) {
							for (int w = 0; w < 25; w += 1) {
								for (int k = 0; k < 60; k += 1) {
									p[w][k] = gracz23[w][k];
								}
							}
							system("cls");
							p[4][59] = tura_gracza(gracz2.imie);
							wyswietl_pentago(p);
						}
						else if ((i - 2) % 8 == 7) {
							for (int w = 0; w < 25; w += 1) {
								for (int k = 0; k < 60; k += 1) {
									p[w][k] = gracz24[w][k];
								}
							}
							system("cls");
							p[4][59] = tura_gracza(gracz2.imie);
							wyswietl_pentago(p);
						}
						i -= 3;
					}
					else {
						p[8][59] = "Funkcja niedostepna";
						i -= 1;
						system("cls");
						wyswietl_pentago(p);
					}
				}
				else if (*kl == "q7") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q8") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q9") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w7") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w8") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w9") {
					for (int w = 1; w < 4; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q4") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q5") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q6") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w4") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w5") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w6") {
					for (int w = 5; w < 8; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q1") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q2") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "q3") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w1") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w2") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "w3") {
					for (int w = 9; w < 12; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a7") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a8") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a9") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s7") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s8") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s9") {
					for (int w = 13; w < 16; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a4") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a5") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a6") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s4") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s5") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s6") {
					for (int w = 17; w < 20; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a1") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 2; k < 7; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a2") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 10; k < 15; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "a3") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 18; k < 23; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s1") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 26; k < 31; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s2") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 34; k < 39; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "s3") {
					for (int w = 21; w < 24; w += 1) {
						for (int k = 42; k < 47; k += 1) {
							p[w][k] = gracz2.zeton;
						}
					}
					p[8][59] = "Obroc plansze";
					system("cls");
					wyswietl_pentago(p);
					cin >> *obr;
					obroc_plansze(p, obr);
					p[8][59] = "Poloz zeton";
					p[4][59] = tura_gracza(gracz1.imie);
					system("cls");
					wyswietl_pentago(p);
					if (test_wygranej(gracz2.zeton, p) == true) {
						p[4][59] = gracz2.imie + " wygral(a)!"; p[8][59] = " "; system("cls");
						wyswietl_pentago(p);
						return 0;
					}
				}
				else if (*kl == "o") {
					wczytaj_pentago(p);
					wczytaj_pre_pentago(p);
					if (zeton1 == '1') {
						p[4][59] = tura_gracza(gracz1.imie);
					}
					if (zeton1 == '2') {
						gracz temp = gracz1;
						gracz1 = gracz2;
						gracz2 = temp;
						p[4][59] = tura_gracza(gracz1.imie);
					}
					i = 16;
					wyswietl_pentago(p);
				}
				else if (*kl == "m") {
					p[8][59] = "Poloz zeton";
					i -= 1;
					opcje();
					cin.ignore();
					system("cls");
					wyswietl_pentago(p);
				}
				else if (*kl == "h") {
					p[8][59] = "Poloz zeton";
					i -= 1;
					wyswietl_info_pentago_k();
					cin.ignore();
					system("cls");
					wyswietl_pentago(p);
				}
				else if (*kl == "p") {
					i -= 1;
					system("cls");
					cout << "PAUZA" << endl << "Aby kontynuowac gre, nacisnij enter";
					cin.ignore();
					cin.ignore();
					system("cls");
					wyswietl_pentago(p);
				}
				else if (*kl == "t") {
					i -= 1;
					zamien_zetony(gracz1, gracz2, p);
					if (gracz1.kolor == BLUE) {
						gracz1.kolor = RED;
					}
					else if (gracz1.kolor == RED) {
						gracz1.kolor = BLUE;
					}
					if (gracz2.kolor == BLUE) {
						gracz2.kolor = RED;
					}
					else if (gracz2.kolor == RED) {
						gracz2.kolor = BLUE;
					}
					gracz1.imie = gracz1.kolor + imie1 + RESET;
					gracz2.imie = gracz2.kolor + imie2 + RESET;
					p[4][59] = tura_gracza(gracz2.imie);
					system("cls");
					wyswietl_pentago(p);
				}
				if (*kl != "t" && *kl != "p" && *kl != "m" && *kl != "h") {
					if (i % 8 == 1) {
						for (int w = 0; w < 25; w += 1) {
							for (int k = 0; k < 60; k += 1) {
								gracz21[w][k] = p[w][k];
							}
						}
					}
					else if (i % 8 == 3) {
						for (int w = 0; w < 25; w += 1) {
							for (int k = 0; k < 60; k += 1) {
								gracz22[w][k] = p[w][k];
							}
						}
					}
					else if (i % 8 == 5) {
						for (int w = 0; w < 25; w += 1) {
							for (int k = 0; k < 60; k += 1) {
								gracz23[w][k] = p[w][k];
							}
						}
					}
					else if (i % 8 == 7) {
						for (int w = 0; w < 25; w += 1) {
							for (int k = 0; k < 60; k += 1) {
								gracz24[w][k] = p[w][k];
							}
						}
					}
				}
			}
		}
		p[8][59] = " ";
		p[4][59] = "REMIS!";
		system("cls");
		wyswietl_kik(p);
		return 0;
	}
}