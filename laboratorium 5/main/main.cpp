#include <iostream>

using namespace std;

// naiwny
void algorytmNaiwny(string tekst, string wzorzec){
    int i = 0;
    while(i <= tekst.size() - wzorzec.size()){
        int j = 0;
        while(j < wzorzec.size() && wzorzec[j]==tekst[j+i]){
            j++;
        }
        if(j == wzorzec.size()){
            cout << i << "\t";
        }
        i++;
    }
}


// KMP
void tablicaDopasowan(string wzorzec, int *p){
    p[0] = 0;
    p[1] = 0;
    int t = 0;
    int i = 1;
    while(i < wzorzec.size()){
        while(t > 0 && wzorzec[t] != wzorzec[i]){
            t = p[t];
        }
        if(wzorzec[t] == wzorzec[i]){
            t++;
        }
        p[i+1] = t;
        i++;
    }
}

void algorytmKMP(string tekst, string wzorzec){
    int *p = new int[wzorzec.size()+1];
    tablicaDopasowan(wzorzec, p);
    int i = 0;
    int j = 0;
    while(i < tekst.size() - wzorzec.size() + 1){
        while(wzorzec[j] == tekst[i+j] && j < wzorzec.size()){
            j++;
        }
        if(j == wzorzec.size()){
            cout << i << "\t";
        }
        i += max(1, j-p[j]);
        j = p[j];
    }
}


// BM
void tablicaPrzesuniec(string wzorzec, int *p, int pocz, int kon){
    int i = 0;
    while(i < kon - pocz){
        p[i] = -1;
        i++;
    }
    i = 0;
    while(i < wzorzec.size()){
        p[wzorzec[i] - pocz] = i;
        i++;
    }
}

void algorytmBM(string tekst, string wzorzec, int pocz){
    int *p = new int[256];
    tablicaPrzesuniec(wzorzec, p, pocz, wzorzec.size());
    int i = 0;

    while(i <= tekst.size() - wzorzec.size()){
        int j = wzorzec.size() - 1;
        while(j > -1 && wzorzec[j] == tekst[i+j]){
            j--;
        }
        if(j == -1){
            cout << i << "\t";
            i++;
        }
        else{
            i += max(1, j-p[tekst[i+j] - pocz]);
        }
    }
}

int main()
{
//                  0  3         13      21 24
    string tekst = "ABCABCBCBCBCBABCCCCABABCABC";
    string wzorzec = "ABC";

    algorytmNaiwny(tekst, wzorzec);
    cout << endl;
    algorytmKMP(tekst, wzorzec);
    cout << endl;
    algorytmBM(tekst, wzorzec, 0);





    return 0;
}
