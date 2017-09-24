#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int N,M;
    int K;

    cin >> N >> M;
    cin >> K;

    std::vector<string> sheme;

    std::vector<vector<string>> massV;

    string mass;
    for (int f = 0 ; f <= K; f++){//цикл по входным массивам

        std::vector<string> v;//текущая карта

        for (int i = 0 ; i < N; i++){
            cin >> mass;
            v.push_back(mass);
        }
        if (f == K)
            sheme = v; // последняя оригинал
        else
         massV.push_back(v);
    }

pair<bool,int> massAns[K];
for (int l = 0 ; l < K; l++){
    massAns[l].first = false;
    massAns[l].second = 0;
}

for (int l = 0 ; l < K; l++)
    for (int i = 0 ; i < N; i++){
            for (int j = 0 ; j < M; j++){
                massAns[l].second  += ((massV.at(l).at(i).at(j))  - '0');
                if (massV.at(l).at(i).at(j) != sheme.at(i).at(j) && sheme.at(i).at(j) != 'x')
                    massAns[l].first = true;//не подходяшая карта
//                 cout << massV.at(l).at(i).at(j);
            }
//         cout << endl;
    }

//cout <<"//////////////////"<< endl;
//for (int i = 0 ; i < N; i++){
//        for (int j = 0 ; j < M; j++){
//             cout << sheme.at(i).at(j);
//        }
//     cout << endl;
//}

int number = -1, summ = -1;
for (int l = 0 ; l < K; l++){
    if ((massAns[l].first != true) && (massAns[l].second > summ)){
            summ = massAns[l].second;
            number = l + 1;
    }
    }
if( number > -1)
    cout << number <<" "<<summ << endl;
else
    cout << "warning" << endl;
//cout << massAns[l].first<<endl;
// cout << massAns[l].second<<endl;



    return 0;
}
/*

 * тест 1
8 8
2
00000000
00000000
00000000
00099000
00099000
00000000
00000000
00000000
00000800
09000000
00000080
00000000
00400060
33000000
00000400
00400000
00000000
00000000
00000000
000xx000
000xx000
00000000
00000000
00000000
///////
1 36

 * тест 2

2 8
2
10000000
20000000
10000000
40006000
x0000000
x0000000
//////
1 3



тест 3

1 1
9
1
2
3
4
5
6
7
8
9
x
/////
9 9

тест 4

2 3
4
023
024
025
026
027
028
000
000
000
x00
///
4 0

тест 5

1 2
2
12
13
x0
///
warning
*/
