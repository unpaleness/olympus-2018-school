//============================================================================
// Name        : school_olimp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	string str, str2;
	map<string, int> mymap;

	cin >> n;
	getline(cin, str);
	for(int i = 0; i < n; i++){
		cin >> str;
		str.erase(str.end() - 1);
		getline(cin, str2);
		mymap[str] += str2.size() - 1;
	}
	int max = 0;

	for (auto it = mymap.begin(); it != mymap.end(); ++it){
		if(max < it->second){
			max = it->second;
		}
	}
	for(auto it = mymap.begin(); it != mymap.end(); ++it){
		if(max == it->second){
			cout << it->first << " " << it->second << endl;
		}

	}
	return 0;
}
