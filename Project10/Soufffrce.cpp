#include <iostream>
#include <string> 
#include <fstream> 
#include <vector> 
#include <list> 
#include <ctime>
#include <set>
#include <map>

using namespace std;
struct Dictionary {
	map<string, list<string>> words;
	void addWord() {
		list<string> li;
		string word;
		string tmp;
		cout << "¬ведите слово: ";
		cin >> word;
		cout << "¬ведите перевод данного слова, что бы остановить запись введите '%' " << endl;
		while (tmp != "%") {
			cin >> tmp;
			if (tmp != "%") {
				li.push_back(tmp);
			}
		}

		words.insert(pair<string, list<string>>(word, li));
	}
	void show() {
		for (auto it = words.begin(); it != words.end(); it++) {
			cout << it->first << " : ";
			for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
				cout << *iter << " ";
			}
			cout << endl;
		}
	}
	void delWord(string w) {
		map<string, list<string>>::iterator pos;
		pos = words.find(w);
		if (pos != words.end()) {
			words.erase(pos);
		}
		else { cout << "Ќеверное слово!" << endl; }
	}
	void update() {
		cout << "=============================" << endl;
		string word;
		string translate;
		string translate2;
		cout << "¬ведите слово которое хотите изменить:  ";
		cin >> word;
		cout << "¬ведите перевод который хотите изменить:  ";
		cin >> translate;
		cout << "¬ведите новый перевод: ";
		cin >> translate2;

		for (auto it = words.begin(); it != words.end(); it++) {
			if (it->first == word) {
				for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
					if (*iter == translate) {
						*iter = translate2;
					}
				}
			}
		}
		cout << "_0_0_0_0_0_0" << endl;
	}
	void findWord(string word) {
		for (auto it = words.begin(); it != words.end(); it++) {
			if (it->first == word) {
				cout << it->first << " : ";
				for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
					cout << *iter;
				}
			}
		}
	}
	void WriteToTxt() {
		fstream write;
		write.open("wewe.txt", ios::out);
		for (auto it = words.begin(); it != words.end(); it++) {
			write << it->first << " : ";
			for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
				write << *iter << " ";
			}
			write << endl;
		}
	}
};
void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	Dictionary A;
	string str;
	A.addWord();
	A.addWord();
	A.show();
	cout << "¬ведите слово которое хотите найти: ";
	cin >> str;
	A.findWord(str);
	cout << endl;
	cout << "¬ведите слово которое хотите удалить: ";
	cin >> str;
	A.delWord(str);
	A.show();
	A.update();
	A.show();
	A.WriteToTxt();

	system("pause");
};
