//============================================================================
// Name        : labyrinth.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool quickExit(int, int, int**);

void step(int, int, int**, int, int, bool*);

int main() {
	int N, K; // размеры лабиринта
	cin >> N >> K;

	int **labirinth = new int*[N]; // сам лабиринт
	for(int i = 0; i < N; i++){
		labirinth[i] = new int[K];
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < K; j++){
			cin >> labirinth[i][j];
		}
	}

	int x, y; // координаты аспиранта
	cin >> x >> y;

	x -= 1;
	y -= 1;

	if(!quickExit(N, K, labirinth)){
		cout << "No" << endl;
		return 0;
	}

	//будем отмечать 2 в массиве места где мы были
	//по идее в этом смысл алгоритма заливки
	labirinth[x][y] = 2;

	bool flag = false; // вышли из лабиринта?

	step(N, K, labirinth, x, y, &flag);

	if(flag){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < K; j++){
//			cout << labirinth[i][j] << " ";
//		}
//		cout << endl;
//	}

	return 0;
}

bool quickExit(int N, int K, int** labirinth){
	//простомтрим все границы лабираинта
	//если там нет хотя бы одного 0, то значит нет выходов из него
	//исходим из того, что выходов нет, пока не доказано обратное
	// если найдем хотя бы 1 выход, то сообщим об этом
	for(int j = 0; j < K; j++){ //верх
		if(labirinth[0][j] == 0){
			return true;
		}
	}
	for(int j = 0; j < K; j++){ //низ
		if(labirinth[N - 1][j] == 0){
			return true;
		}
	}
	for(int i = 0; i < N; i++){ //лево
		if(labirinth[i][0] == 0){
			return true;
		}
	}
	for(int i = 0; i < N; i++){ //право
		if(labirinth[i][K - 1] == 0){
			return true;
		}
	}
	return false; //отдаем false, так как не нашли ни 1 выхода
}


void step(int N, int K, int** labirinth, int x, int y, bool* flag){
	// принимаем размерность лабиринта N*K
	// сам лабиринт, где 0 - проход, 1 - стена, 2 - места где уже были
	// x, y - текущие координаты в лабиринте
	// flag - вышли из лабиринта или нет?
	// нужен для того, что бы не прогонять поиск после выхода
//	cout << x << " " << y << endl;
	if(x == 0 || x == N - 1 || y == 0 || y == K - 1){
		*flag = true; // значит мы вышли из лабиринта
		// костыль АДСКИЙ
		for(int i = 0; i < N; i++){
			for(int j = 0; j < K; j++){
				if(labirinth[i][j] != 2)
					labirinth[i][j] = 3; // выйдем из рекурсии быстро, но запомним путь к выходу
				// вдруг потом понадобится
			}
		}
	}

	if(x - 1 >= 0 && labirinth[x - 1][y] == 0){ // если сверху не вышли за пределы и там можно пройти
		labirinth[x - 1][y] = 2;
		step(N, K, labirinth, x - 1, y, flag); // идем туда
	}

	if(y + 1 < K && labirinth[x][y + 1] == 0){ // если справа не вышли за пределы и там можно пройти
		labirinth[x][y + 1] = 2;
		step(N, K, labirinth, x, y + 1, flag); // идем туда
	}

	if(x + 1 < N && labirinth[x + 1][y] == 0){ // если снизу не вышли за пределы и там можно пройти
		labirinth[x + 1][y] = 2;
		step(N, K, labirinth, x + 1, y , flag); // идем туда
	}

	if(y - 1 >= 0 && labirinth[x][y - 1] == 0){ // если слева не вышли за пределы и там можно пройти
		labirinth[x][y - 1] = 2;
		step(N, K, labirinth, x, y - 1 , flag); // идем туда
	}
}




//10 8
//1 1 1 1 1 1 1 1
//1 1 1 1 0 1 1 1
//1 0 0 0 0 0 0 1
//1 0 1 1 1 1 0 1
//1 0 1 0 0 0 0 1
//1 1 1 0 1 1 1 1
//1 1 0 0 1 0 0 0
//1 1 0 1 1 0 0 1
//1 0 0 0 0 0 1 1
//1 1 1 1 1 1 1 1
