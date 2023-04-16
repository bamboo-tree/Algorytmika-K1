#include <iostream>
#include <time.h>

using namespace std;

// przydzielanie pamieci
void przydzielPamiec1D(int *&tab, int n){
    tab = new int[n];
}

// wypelnianie losowymi liczbami
void wypelnijTablice1D(int *tab, int n, int a, int b){
    srand(time(NULL));
    for(int i = 0; i < n ; i++){
        tab[i] = a + rand() % (b-a);
    }
}

// wyswietalanie elemetnow tablicy
void wyswietl1D(int *tab, int n){
    for(int i = 0; i < n; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
}

// zwalnianie pamieci
void usun1D(int *tab){
    delete []tab;
}


// przydzielanie pamieci tbalicy dwuwymiarowej (ilosc wierszy od dlugosci ilosci kolumn, ilosc kolumn to dlugosc wierszy)
void przydzielPamiec2D(int **&tab, int w, int k){
    tab = new int*[w];
    for(int i = 0; i < w; i++){
        tab[i] = new int[k];
    }
}

// wypelnianie tablicy 2D
void wypelnijTablice2D(int **tab, int w, int k, int a, int b){
    srand(time(NULL));
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            tab[i][j] = a + rand() % (b-a);
        }
    }
}

// wyswietlanie tablicy 2D
void wyswietl2D(int **tab, int w, int k){
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

// zwalnianie tablicy 2D najpierw zwalniane sa wiersze, potem cala tablica
void usun2D(int **tab, int w){
    for(int i = 0; i < w; i++){
        delete[] tab[i];
    }

    delete[] tab;
}


int main()
{
    int *tab;
    int **tab2;
    int n = 40;
    int w = 20;
    int a = 0;
    int b = 10;

    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, a, b);
    wyswietl1D(tab, n);
    usun1D(tab);

    cout << "\n\n";

    przydzielPamiec2D(tab2, w, n);
    wypelnijTablice2D(tab2, w, n, a, b);
    wyswietl2D(tab2, w, n);
    usun2D(tab2, w);

    return 0;
}
