//============================================================================
// Name        : astronomers.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
	// числа
	string first;
	string second;
	// считываем
	cin >> first;
	cin >> second;

	// позиция запятой
	std::size_t found_First = first.find(",");
	std::size_t found_Second = second.find(",");

	// если дробных частей нет
	if(found_First == string::npos && found_Second == string::npos){
		if(first.size() > second.size()){
			cout << "First" << endl;
			return 0;
		}
		if(first.size() < second.size()){
			cout << "Second" << endl;
			return 0;
		}
		for(unsigned int i = 0; i < first.size(); i++){
			if(first[i] > second[i]){
				cout << "First" << endl;
				return 0;
			}
			if(first[i] < second[i]){
				cout << "Second" << endl;
				return 0;
			}
		}
	}

	// если оба с дробной частью
	if(found_First != string::npos && found_Second != string::npos){
		//если какая- то целая часть длинее, то это число больше
		if(found_First > found_Second){
			cout << "First" << endl;
			return 0;
		}
		if(found_First < found_Second){
			cout << "Second" << endl;
			return 0;
		}
		// просто сравниваем целые части
		for(unsigned int i = 0; i < found_First; i++){
			if(first[i] > second[i]){
				cout << "First" << endl;
				return 0;
			}
			if(first[i] < second[i]){
				cout << "Second" << endl;
				return 0;
			}
		}
		// до тех пор, пока дробная часть наименьшего числа не закончится
		if(first.size() > second.size()){
			for(unsigned int i = found_Second; i < second.size(); i++){
				if(first[i] > second[i]){
					cout << "First" << endl;
					return 0;
				}
				if(first[i] < second[i]){
					cout << "Second" << endl;
					return 0;
				}
			}
			// если число закончилось, но они еще равны, то больше то, которое длинее, ибо равными по условию быть не могут
			cout << "First" << endl;
			return 0;
		}
		if(first.size() < second.size()){
			for(unsigned int i = found_First; i < first.size(); i++){
				if(first[i] > second[i]){
					cout << "First" << endl;
					return 0;
				}
				if(first[i] < second[i]){
					cout << "Second" << endl;
					return 0;
				}
			}
			// если число закончилось, но они еще равны, то больше то, которое длинее, ибо равными по условию быть не могут
			cout << "Second" << endl;
			return 0;
		}
		// если длины дробной части равны
		for(unsigned int i = 0; i < first.size(); i++){
			if(first[i] > second[i]){
				cout << "First" << endl;
				return 0;
			}
			if(first[i] < second[i]){
				cout << "Second" << endl;
				return 0;
			}
		}
	}

	// если только одно дробное
	if(found_First != string::npos){
		//если какая- то целая часть длинее, то это число больше
		if(found_First > second.size()){
			cout << "First" << endl;
			return 0;
		}
		if(found_First < second.size()){
			cout << "Second" << endl;
			return 0;
		}
		// просто сравниваем целые части
		for(unsigned int i = 0; i < found_First; i++){
			if(first[i] > second[i]){
				cout << "First" << endl;
				return 0;
			}
			if(first[i] < second[i]){
				cout << "Second" << endl;
				return 0;
			}
		}
		// если целые части равны, то больше то, где есть дробная часть
		cout << "First" << endl;
		return 0;
	}
	if(found_Second != string::npos){
		//если какая- то целая часть длинее, то это число больше
		if(first.size() > found_Second){
			cout << "First" << endl;
			return 0;
		}
		if(first.size() < found_Second){
			cout << "Second" << endl;
			return 0;
		}
		// просто сравниваем целые части
		for(unsigned int i = 0; i < found_First; i++){
			if(first[i] > second[i]){
				cout << "First" << endl;
				return 0;
			}
			if(first[i] < second[i]){
				cout << "Second" << endl;
				return 0;
			}
		}
		// если целые части равны, то больше то, где есть дробная часть
		cout << "Second" << endl;
		return 0;
	}



	return 0;
}
