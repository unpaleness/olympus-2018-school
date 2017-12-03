//============================================================================
// Name        : gorgeous.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, k, temp;
	int Nk = 5;
	vector <int> people;
	map <int, vector<int>> pretender;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp;
		people.push_back(temp);
	}
	sort(people.begin(), people.end());

	for(int i = 0; i < n; i++){
		pretender[abs(people[i] - k)].push_back(people[i]);
	}

	people.clear();
	temp = 0;

	for(auto it = pretender.begin(); it != pretender.end(); it++){
		for(unsigned int i = 0; i < it->second.size(); i++){
			if(temp < Nk){
				people.push_back(it->second[i]);
				temp ++;
			}
		}
	}
	for(unsigned int i = 0; i < people.size(); i++){
		if(i != people.size() - 1){
			cout << people[i] << " ";
		}
		else{
			cout << people[i] << endl;
		}
	}

	return 0;
}
