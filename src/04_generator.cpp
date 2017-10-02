//============================================================================
// Name        : Generator_2000.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
void test_Generation(int);
void ans_Generation(int);
void dark_Magic(fstream&, int);

void read_Mas(double**, int, fstream&);
void write_Ans(vector<int>*, int);
void spiral_Key(double**, vector<int>*, int);
void spiral_Crypted(double**, vector<int>*, int);
void sum_Mas(vector<int>*, vector<int>*, vector<int>*);
void convert_Sum(vector<int>*);
int convert(int);

int main() {
	srand(time(0));
	int n;
	cout << "Number of tests:" << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		test_Generation(i + 2);
		ans_Generation(i + 2);
	}
	return 0;
}


void test_Generation(int n){
	fstream file;
	char fileName[8] = {'0','0','1','.','d','a','t'};
	if(n <= 9){
		fileName[2] = n + '0';
	}
	else{
		if(n <= 99){
			fileName[2] = (n % 10 ) + '0';
			fileName[1] = (n / 10) + '0';
		}
		else{
			fileName[2] = (n % 10 ) + '0';
			fileName[1] = ((n % 10)/ 10) + '0';
			fileName[0] = (n / 100) + '0';
		}
	}
	file.open( fileName, ios_base::trunc | ios_base::out);
	int N = 5 + rand() % 21;
	int K = 2 + rand() % 14;
	if(N % 2 == 0){
		N++;
	} // only odd dimensions
	file << N << " " << K << endl;
	for(int k = 0; k < K + 1; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				file << 0 + rand() % 10 << " ";
			}
			file << endl;
		}
	}
	file.close();
}

void ans_Generation(int n){
	fstream file;
	char fileName[8] = {'0','0','1','.','d','a','t'};
	if(n <= 9){
		fileName[2] = n  + '0';
	}
	else{
		if(n <= 99){
			fileName[2] = (n % 10 ) + '0';
			fileName[1] = (n / 10) + '0';
		}
		else{
			fileName[2] = (n % 10 ) + '0';
			fileName[1] = ((n % 10)/ 10) + '0';
			fileName[0] = (n / 100) + '0';
		}
	}
	file.open( fileName, ios_base::in);

	dark_Magic(file, n);
	file.close();
}

void dark_Magic(fstream &file, int k){
	vector <int> key;
	vector <int> crypted;
	vector <int> sum;

	int N;
	file >> N;
	int K;
	file >> K;


	double **mas = new double* [N];
	for(int n = 0; n < N; n++){
		mas[n] = new double[N];
	}

	read_Mas(mas, N, file);
	spiral_Key(mas, &key, N);
	for(int i = 0; i < K; i++){
		read_Mas(mas, N, file);
		spiral_Crypted(mas, &crypted, N);
		sum_Mas(&key, &crypted, &sum);
	}

//	file.close();

	convert_Sum(&sum);
	write_Ans(&sum, k);

	//make destroy all
	delete mas;
	key.clear();
	crypted.clear();
	sum.clear();
}


void read_Mas(double** mas, int size, fstream &file){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			file >> mas[i][j];
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
		sum->at(i) = temp;
	}
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

void write_Ans(vector<int>* sum, int n){
	fstream file;
	char fileName[8] = {'0','0','1','.','a','n','s'};
	if(n <= 9){
		fileName[2] = n + '0';
	}
	else{
		if(n <= 99){
			fileName[2] = (n % 10) + '0';
			fileName[1] = (n / 10) + '0';
		}
		else{
			fileName[2] = (n % 10) + '0';
			fileName[1] = ((n % 10)/ 10) + '0';
			fileName[0] = (n / 100) + '0';
		}
	}
	file.open( fileName, ios_base::trunc | ios_base::out);

	for(unsigned int i = 0; i < sum->size(); i++){
		if(i != sum->size() - 1){
			file << sum->at(i) << " ";
		}
		else{
			file << sum->at(i);
		}
	}
//	file << endl;
	file.close();
}
