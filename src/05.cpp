//============================================================================
// Name        : strange_dialect.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool isVowel(char);
bool isConsonant(char);
char findKey(string*);
//void printDecode(string*, char);

void printDecode(string*);

int main(){
    string stroka;

    getline(cin, stroka);

//    char key = findKey(&stroka);
//    printDecode(&stroka, key);
    printDecode(&stroka);
    return 0;
}


bool isVowel(char letter){
    string g="aeiouyAEIOUY";
    for(unsigned int i = 0; i < g.size(); i++){
        if(letter == g[i]){
            return true;
        }
    }
    return false;
}

bool isConsonant(char letter){
    string s="bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
    for(unsigned int i = 0; i < s.size(); i++){
        if(letter == s[i]){
            return true;
        }
    }
    return false;
}

char findKey(string* stroka){
    map <char, int> keys;
    vector<char> simvol;
    for(unsigned int i = 0; i < stroka->size() - 2;){
        if(isVowel(stroka->at(i)) && isConsonant(stroka->at(i + 1)) && (stroka->at(i) == stroka->at(i + 2))){
            simvol.push_back(stroka->at(i + 1));
            keys[stroka->at(i + 1)]++;
            i += 3;
        }
        else{
        	i += 1;
        }
    }
    int max = 0;
    for(auto it = keys.begin(); it != keys.end(); it++){
        if(it->second > max){
            max = it->second;
        }
    }

    for(unsigned int i = 0; i < simvol.size();i++){
        if(keys[simvol[i]] == max){
            return simvol[i];
        }
    }

    return 'r';
}

//void printDecode(string* stroka, char key){
//	bool flag = false;
//    for(unsigned int i = 0; i < stroka->size() - 2;){
//        if(isVowel(stroka->at(i)) && isConsonant(stroka->at(i + 1)) && (stroka->at(i) == stroka->at(i + 2)) && (stroka->at(i + 1) == key)){
//        	cout << stroka->at(i);
//        	if(i == stroka->size() - 3){
//        		flag = true;
//        	}
//            i += 3;
//        }
//        else{
//        	cout << stroka->at(i);
//        	i += 1;
//        }
//    }
//    if(!flag){
//        for(unsigned int i = stroka->size() - 2; i < stroka->size(); i++){
//        	cout << stroka->at(i);
//        }
//    }
//    cout << endl;
//}

void printDecode(string* stroka){
    for(unsigned int i = 0; i < stroka->size();){
    	if(i < stroka->size() - 2){
            if(isVowel(stroka->at(i)) && isConsonant(stroka->at(i + 1)) && (stroka->at(i) == stroka->at(i + 2))){
            	cout << stroka->at(i);
            	if(i == stroka->size() - 3){
            	}
            	if(i == stroka->size() - 4){
            	}
                i += 3;
            }
            else{
            	cout << stroka->at(i);
            	i += 1;
            }
    	}
        else{
        	cout << stroka->at(i);
        	i += 1;
        }
    }
    cout << endl;
}
