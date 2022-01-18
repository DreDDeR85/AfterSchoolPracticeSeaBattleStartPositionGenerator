#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <math.h>
using namespace std;

int randnum() {
	//Chto tyt imenno proishodit ia i sam hz)
	//No tyt generiryetsa slychainoe chislo
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 99);
	return dist(gen);
}

bool netliradomkorablei(int n, vector <vector <char>>& SeaBattle) { // Proverka na to, net li radom korablei
	vector <int> checker(8);
	checker[0] = n + 1 - 10;
	checker[1] = n - 10;
	checker[2] = n - 1 - 10;
	checker[3] = n - 1;
	checker[4] = n + 1;
	checker[5] = n + 1 + 10;
	checker[6] = n + 10;
	checker[7] = n - 1 + 10;
	if (SeaBattle[n / 10][n % 10] == '*') {
		return false;
	}
	if ((n % 10 != 0) and (n % 10 != 9) and (n / 10 != 9) and (n / 10 != 0)) {
		for (int i = 0; i < 8; i++) {
			if (SeaBattle[checker[i] / 10][checker[i] % 10] == '*') {
				return false;
			}
		}
	}
	else if (n == 0) {
		if ((SeaBattle[0][1] == '*') or (SeaBattle[1][0] == '*') or (SeaBattle[1][1] == '*')) {
			return false;
		}
	}
	else if (n == 9) {
		if ((SeaBattle[0][8] == '*') or (SeaBattle[1][8] == '*') or (SeaBattle[1][9] == '*')) {
			return false;
		}
	}
	else if (n == 90) {
		if ((SeaBattle[9][1] == '*') or (SeaBattle[8][0] == '*') or (SeaBattle[8][1] == '*')) {
			return false;
		}
	}
	else if (n == 99) {
		if ((SeaBattle[9][8] == '*') or (SeaBattle[8][8] == '*') or (SeaBattle[8][9] == '*')) {
			return false;
		}
	}
	else if (n / 10 == 0) {
		for (int i = 3; i < 8; i++) {
			if (SeaBattle[checker[i] / 10][checker[i] % 10] == '*') {
				return false;
			}
		}
	}
	else if (n % 10 == 0) {
		if ((SeaBattle[checker[1] / 10][checker[1] % 10] == '*') or (SeaBattle[checker[0] / 10][checker[0] % 10] == '*') or (SeaBattle[checker[4] / 10][checker[4] % 10] == '*') or (SeaBattle[checker[5] / 10][checker[5] % 10] == '*') or (SeaBattle[checker[6] / 10][checker[6] % 10] == '*')) {
			return false;
		}
	}
	else if (n / 10 == 9) {
		for (int i = 0; i < 5; i++) {
			if (SeaBattle[checker[i] / 10][checker[i] % 10] == '*') {
				return false;
			}
		}
	}
	else if (n % 10 == 9) {
		if ((SeaBattle[checker[1] / 10][checker[1] % 10] == '*') or (SeaBattle[checker[2] / 10][checker[2] % 10] == '*') or (SeaBattle[checker[3] / 10][checker[3] % 10] == '*') or (SeaBattle[checker[7] / 10][checker[7] % 10] == '*') or (SeaBattle[checker[6] / 10][checker[6] % 10] == '*')) {
			return false;
		}
	}
	return true;
}

bool isthisintable(int iznachkoord, int n) { //Proverka syshestvovania korablya 
	if ((iznachkoord <= 99) and (iznachkoord >= 0) and (n <= 99) and (n >= 0) and (((iznachkoord / 10) == (n / 10)) or ((iznachkoord % 10) == (n % 10)))) {
		return true;
	}
	return false;
}

string povorot(int n, int b, vector <vector <char>>& SeaBattle) { //Povorot korablya i generacia koordinat, esli korabl nevozmozhno sgenerirovat v nachalnoi pozicii
	//n - chislo, b - kol-vo palub
	if (b == 4) {
		int sampov = randnum() % 4;
		int kn = 1000;
		string ans = "";
		while (!isthisintable(n, kn)) {
			sampov = randnum() % 4;
			if (sampov == 0) {
				kn = n + b - 1;
			}
			else if (sampov == 1) {
				kn = n - (b - 1) * 10;
			}
			else if (sampov == 2) {
				kn = n - b + 1;
			}
			else if (sampov == 3) {
				kn = n + (b - 1) * 10;
			}
		}
		if (sampov == 0) {
			for (int j = 1; j < b; j++) {
				int anss = n + b - j;
				string temp = to_string(anss);
				if (anss < 10) {
					ans = ans + '0' + temp + " ";
				}
				else {
					ans = ans + temp + " ";
				}
			}
		}
		else if (sampov == 1) {
			for (int j = 1; j < b; j++) {
				int anss = n - (b - j) * 10;
				string temp = to_string(anss);
				if (anss < 10) {
					ans = ans + '0' + temp + " ";
				}
				else {
					ans = ans + temp + " ";
				}
			}
		}
		else if (sampov == 2) {
			for (int j = 1; j < b; j++) {
				int anss = n - b + j;
				string temp = to_string(anss);
				if (anss < 10) {
					ans = ans + '0' + temp + " ";
				}
				else {
					ans = ans + temp + " ";
				}

			}
		}
		else if (sampov == 3) {
			for (int j = 1; j < b; j++) {
				int anss = n + (b - j) * 10;
				string temp = to_string(anss);
				if (anss < 10) {
					ans = ans + '0' + temp + " ";
				}
				else {
					ans = ans + temp + " ";
				}
			}
		}
		if (n < 10) {
			ans += '0' + to_string(n) + " ";
		}
		else {
			ans += to_string(n) + " ";
		}
		return ans;
	}
	else {
		int sampov = randnum() % 4;
		int kn;
		int u = n;
		if (sampov == 0) {
			kn = u + b - 1;
		}
		else if (sampov == 1) {
			kn = u - (b - 1) * 10;
		}
		else if (sampov == 2) {
			kn = u - b + 1;
		}
		else if (sampov == 3) {
			kn = u + (b - 1) * 10;
		}
		vector <int> breakers(4, 0);
		string ans = "";
		while (!((isthisintable(u, kn)) and (netliradomkorablei(u, SeaBattle)) and (netliradomkorablei(kn, SeaBattle)))) {
			sampov = randnum() % 4;
			if (sampov == 0) {
				kn = u + b - 1;
			}
			else if (sampov == 1) {
				kn = u - (b - 1) * 10;
			}
			else if (sampov == 2) {
				kn = u - b + 1;
			}
			else if (sampov == 3) {
				kn = u + (b - 1) * 10;
			}
			if ((breakers[0] >= 2) and (breakers[1] >= 2) and (breakers[2] >= 2) and (breakers[3] >= 2)) {
				u = randnum();
				sampov = randnum() % 4;
				if (sampov == 0) {
					kn = u + b - 1;
				}
				else if (sampov == 1) {
					kn = u - (b - 1) * 10;
				}
				else if (sampov == 2) {
					kn = u - b + 1;
				}
				else if (sampov == 3) {
					kn = u + (b - 1) * 10;
				}
			}
			breakers[sampov] += 1;
		}
		if (sampov == 0) {
			for (int j = 1; j < b; j++) {
				int anss = u + b - j;
				string temp = to_string(anss);
				if (anss < 10) {
					ans = ans + '0' + temp + " ";
				}
				else {
					ans = ans + temp + " ";
				}
			}
		}
		else if (sampov == 1) {
			for (int j = 1; j < b; j++) {
				int anss = u - (b - j) * 10;
				string temp = to_string(anss);
				if (anss < 10) {
					ans = ans + '0' + temp + " ";
				}
				else {
					ans = ans + temp + " ";
				}
			}
		}
		else if (sampov == 2) {
			for (int j = 1; j < b; j++) {
				int anss = u - b + j;
				string temp = to_string(anss);
				if (anss < 10) {
					ans = ans + '0' + temp + " ";
				}
				else {
					ans = ans + temp + " ";
				}
			}
		}
		else if (sampov == 3) {
			for (int j = 1; j < b; j++) {
				int anss = u + (b - j) * 10;
				string temp = to_string(anss);
				if (anss < 10) {
					ans = ans + '0' + temp + " ";
				}
				else {
					ans = ans + temp + " ";
				}
			}
		}
		if (u < 10) {
			ans += '0' + to_string(u) + " ";
		}
		else {
			ans += to_string(u) + " ";
		}
		return ans;
	}
}


int main() {
	// Chetirehpalybniy korabl
	vector <vector <char>> SeaBattle(10, vector <char>(10, '.'));
	int pos4 = randnum();
	string spos4 = povorot(pos4, 4, SeaBattle);
	vector <int> vpos4(4);
	int k_v = 0, k_ch = 1, temp = 0;
	for (int i = 0; i < spos4.length(); i++) {
		if (spos4[i] != ' ') {
			temp += ((int)spos4[i] - '0') * pow(10, k_ch);
			k_ch--;
		}
		else {
			vpos4[k_v] = temp;
			temp = 0;
			k_ch = 1;
			k_v++;
		}
	}
	for (int i = 0; i < vpos4.size(); i++) {
		SeaBattle[vpos4[i] / 10][vpos4[i] % 10] = '*';
	}

	// Trehpalubnie Korabli
	int pos3 = randnum();
	string spos3 = povorot(pos3, 3, SeaBattle);
	vector <int> vpos3(3);
	int k_v3 = 0, k_ch3 = 1;
	temp = 0;
	for (int temporary = 0; temporary < 2; temporary++) {
		pos3 = randnum();
		spos3 = povorot(pos3, 3, SeaBattle);
		vpos3[0] = 0;
		vpos3[1] = 0;
		vpos3[2] = 0;
		k_v3 = 0;
		k_ch3 = 1;
		temp = 0;
		for (int i = 0; i < spos3.length(); i++) {
			if (spos3[i] != ' ') {
				temp += ((int)spos3[i] - '0') * pow(10, k_ch3);
				k_ch3--;
			}
			else {
				vpos3[k_v3] = temp;
				temp = 0;
				k_ch3 = 1;
				k_v3++;
			}
		}
		for (int i = 0; i < vpos3.size(); i++) {
			SeaBattle[vpos3[i] / 10][vpos3[i] % 10] = '*';
		}
	}
	
	// Dvyhpalubnie Korabli
	int pos2a = randnum();
	string spos2a = povorot(pos2a, 2, SeaBattle);
	vector <int> vpos2a(2);
	int k_v2a = 0, k_ch2a = 1;
	temp = 0;
	for (int temporary = 0; temporary < 3; temporary++) {
		pos2a = randnum();
		spos2a = povorot(pos2a, 2, SeaBattle);
		vpos2a[0] = 0;
		vpos2a[1] = 0;
		k_v2a = 0; 
		k_ch2a = 1;
		temp = 0;
		for (int i = 0; i < spos2a.length(); i++) {
			if (spos2a[i] != ' ') {
				temp += ((int)spos2a[i] - '0') * pow(10, k_ch2a);
				k_ch2a--;
			}
			else {
				vpos2a[k_v2a] = temp;
				temp = 0;
				k_ch2a = 1;
				k_v2a++;
			}
		}
		for (int i = 0; i < vpos2a.size(); i++) {
			SeaBattle[vpos2a[i] / 10][vpos2a[i] % 10] = '*';
		}
	}

	// Odnopalybnie Korabli
	int pos1a = randnum();
	string spos1a = povorot(pos1a, 1, SeaBattle);
	vector <int> vpos1a(1);
	int k_v1a = 0, k_ch1a = 1;
	temp = 0;
	for (int temporary = 0; temporary < 4; temporary++) {
		pos1a = randnum();
		spos1a = povorot(pos1a, 1, SeaBattle);
		vpos1a[0] = 1;
		k_v1a = 0; 
		k_ch1a = 1;
		temp = 0;
		for (int i = 0; i < spos1a.length(); i++) {
			if (spos1a[i] != ' ') {
				temp += ((int)spos1a[i] - '0') * pow(10, k_ch1a);
				k_ch1a--;
			}
			else {
				vpos1a[k_v1a] = temp;
				temp = 0;
				k_ch1a = 1;
				k_v1a++;
			}
		}
		for (int i = 0; i < vpos1a.size(); i++) {
			SeaBattle[vpos1a[i] / 10][vpos1a[i] % 10] = '*';
		}
	}

	// Vivod
	cout << "# 0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
		for (int j = 0; j < 10; j++) {
			cout << SeaBattle[i][j] << " ";
		}
		cout << endl;
	}
}
