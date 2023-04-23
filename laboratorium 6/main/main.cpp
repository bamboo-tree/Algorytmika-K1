#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


int stworzHasz(char symbol, int podstawa, int pozycja, int faza){
    int hasz = (symbol-faza)*pow(podstawa, pozycja);
    return hasz;
}

int aktualizujHasz(int hasz, int poprzedni, int nastepny, int podstawa, int dlugoscWzorca, int faza){
    int nowyHasz = hasz - ((poprzedni-faza) * pow(podstawa, dlugoscWzorca-1));
    nowyHasz *= podstawa;
    nowyHasz += nastepny - faza;
    return nowyHasz;
}

bool algorytmNaiwny(string text, string pattern, int a){
    for(int i = a; i < pattern.size()+a; i++){
        if(text[i] != pattern[i-a]){
            return false;
        }
    }
    return true;
}

void algorytmKR(string wzorzec, string tekst, int podstawa, int faza){
    int wzorzecHasz = 0;
    int tekstHasz = 0;
    int i = 0;

    while(i < wzorzec.size()){
        wzorzecHasz += stworzHasz(wzorzec[i], podstawa, wzorzec.size()-1-i, faza);
        tekstHasz += stworzHasz(tekst[i], podstawa, wzorzec.size()-1-i, faza);
        i++;
    }
    i = wzorzec.size();
    int j = 0;

    while(i <= tekst.size()){
        if(wzorzecHasz == tekstHasz){
            if(algorytmNaiwny(tekst, wzorzec, j)){
                cout << "indeks: " << j << endl;
            }
        }
        if(i <= tekst.size()){
            tekstHasz = aktualizujHasz(tekstHasz, tekst[j], tekst[i], podstawa, wzorzec.size(), faza);
            i++;
            j++;
        }
    }
}

int main()
{
    ifstream plik;
    plik.open("./tekst.txt");

    string wzorzec;
    string tekst;

    plik >> wzorzec;
    cout << "wzorzec: " << wzorzec << endl;

    while(!plik.eof()){
        plik >> tekst;
        cout << "tekst: " << tekst << endl;
        algorytmKR(wzorzec, tekst, 3, 65);
    }

    return 0;
}
