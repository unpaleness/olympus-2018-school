//============================================================================
// Name        : book.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void lineDivision(string*, vector<string>*);

int main() {
	int N, K;
	cin >> N >> K;
	string stroka, result;
	vector <vector<string>> book; // тут будут все страницы книги разбитые на слова
	vector<int> crypt; // запишем К * 2 позиций слов в книге
	int temp; // будем записывать то, что считали, чтобы отправить в вектор crypt

	getline(cin, stroka); // считали строку переход на новую строку после 2 чисел

	for(int i = 0; i < N; i++){
		vector<string> page; // 1 страница книги разбитая на слова
		getline(cin, stroka);
		lineDivision(&stroka, &page); // разбили страницу на слова
		book.push_back(page); // запушили страницу в книгу
	}



	for(int i = 0; i < K * 2; i++){
		cin >> temp;
		crypt.push_back(temp - 1);
	}

	for(int i = 0; i < K * 2; i += 2){
		if(i != 0){
			result += " ";
		}
		result += book[crypt[i]][crypt[i + 1]];
	}
	cout << result << endl;
	return 0;
}

void lineDivision(string* stroka, vector<string>* page){
	//получаем указатель на строку которую бьем на слова
	//и на вектор, в котором они будут лежать
	unsigned int first = 0, second; // начало и конец подстроки
	for(second = 0; second < stroka->size(); second++){
		if(stroka->at(second) == ' '){
			// выделяем подстроку от ее начала и до конца
			page->push_back(stroka->substr(first, second - first));
			first = second + 1;
		}
		if(second == stroka->size() - 1){
			// если достигли конца строки, то его надо записать
			page->push_back(stroka->substr(first, second - first + 1));
		}
	}
}
