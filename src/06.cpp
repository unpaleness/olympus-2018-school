//============================================================================
// Name        : proper.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
//#include <cstdlib>
//#include <time.h>
using namespace std;

//void gener();

int main() {
//	gener();
	int n, temp;
	vector<int> tourists;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		tourists.push_back(temp);
	}
	sort(tourists.begin(), tourists.end());

	if(n % 2 == 1){
		for(int i = 0; i < n / 2; i++){
			cout << tourists[i] << " ";
			cout << tourists[n - i - 1] << " ";
		}
		cout << tourists[n / 2];
	}
	else{
		for(int i = 0; i < n / 2; i++){
			if(i == n / 2 - 1){
				cout << tourists[i] << " ";
				cout << tourists[n - i - 1];
			}
			else{
				cout << tourists[i] << " ";
				cout << tourists[n - i - 1] << " ";
			}
		}
	}

	cout << endl;
	return 0;
}

//void gener(){
//	srand(time(0));
//	for(int i = 0; i < 100; i++){
//		cout << rand() % 100 << " ";
//	}
//}
