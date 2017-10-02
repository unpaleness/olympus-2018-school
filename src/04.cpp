//============================================================================
// Name        : hero.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void read_Mas(double**, int);
void spiral_Key(double**, vector<int>*, int);
void spiral_Crypted(double**, vector<int>*, int);
void debug(vector<int>*);
void sum_Mas(vector<int>*, vector<int>*, vector<int>*);
void convert_Sum(vector<int>*);
int convert(int);

int main() {
	vector <int> key;
	vector <int> crypted;
	vector <int> sum;
	int N;
	cin >> N;
	int K;
	cin >> K;


	double **mas = new double* [N];
	for(int n = 0; n < N; n++){
		mas[n] = new double[N];
	}

	read_Mas(mas, N);
	spiral_Key(mas, &key, N);

	for(int i = 0; i < K; i++){
		read_Mas(mas, N);
		spiral_Crypted(mas, &crypted, N);
		sum_Mas(&key, &crypted, &sum);
	}

	convert_Sum(&sum);
//	debug(&sum);
//	debug(&key);


	//make destroy all
	delete mas;
	key.clear();
	crypted.clear();
	sum.clear();
	return 0;
}

void read_Mas(double** mas, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cin >> mas[i][j];
		}
	}
}

void spiral_Key(double** mas, vector<int>* key, int size){
	int step = size;
	int i = 0, j  = 0;
	while(true){
		if(step > 0){
			for(int temp = 0; temp < step; temp++){
				key->push_back(mas[i][j]);
				i++;
			}
			i--;
			j++;
			step--;

			for(int temp = 0; temp < step; temp++){
				key->push_back(mas[i][j]);
				j++;
			}
			j--;
			i--;

			for(int temp = 0; temp < step; temp++){
				key->push_back(mas[i][j]);
				i--;
			}
			i++;
			j--;
			step--;

			for(int temp = 0; temp < step; temp++){
				key->push_back(mas[i][j]);
				j--;
			}
			j++;
			i++;

		}
		else{
			break;
		}
	}
}

void spiral_Crypted(double** mas, vector<int>* crypted, int size){
	int step = size;
	int i = size - 1, j  = size  - 1;
	while(true){
		if(step > 0){
			for(int temp = 0; temp < step; temp++){
				crypted->push_back(mas[i][j]);
				i--;
			}
			i++;
			j--;
			step--;

			for(int temp = 0; temp < step; temp++){
				crypted->push_back(mas[i][j]);
				j--;
			}
			j++;
			i++;

			for(int temp = 0; temp < step; temp++){
				crypted->push_back(mas[i][j]);
				i++;
			}
			i--;
			j++;
			step--;

			for(int temp = 0; temp < step; temp++){
				crypted->push_back(mas[i][j]);
				j++;
			}
			j--;
			i--;

		}
		else{
			break;
		}
	}
	reverse(crypted->begin(), crypted->end()); //cheats on
}

void sum_Mas(vector<int>* key, vector<int>* crypted, vector<int>* sum){
	int temp = 0;
	for(unsigned int i = 0; i < key->size(); i++){
		temp += key->at(i) * crypted->at(i);
	}
	sum->push_back(temp);
}

void convert_Sum(vector<int>* sum){
	for(unsigned int i = 0; i < sum->size(); i++){
		int temp = sum->at(i);
		while(temp / 10 > 0){
			temp = convert(temp);
		}
		if(i != sum->size() - 1){
			cout << temp << " ";
		}
		else{
			cout << temp;
		}
	}
	cout << endl;
}

int convert(int n){
	int temp = 0;
	while(n / 10 > 0){
		temp += n % 10;
		n /= 10;
	}
	temp += n;
	return temp;
}

void debug(vector<int>* mas){
	for (unsigned int i = 0; i < mas->size(); i++){
		cout << mas->at(i) << endl;
	}
}

//5
//1
//1 16 15 14 13
//2 17 24 23 12
//3 18 25 22 11
//4 19 20 21 10
//5 6 7 8 9
//17 18 19 20 21
//16 5 6 7 22
//15 4 1 8 23
//14 3 2 9 24
//13 12 11 10 25
