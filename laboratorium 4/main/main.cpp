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


// flaga polska
void flagaPolska(int *tab, int n, int granica){
    int i = 0;
    int j = n-1;
    int temp;
    while(i < j){
        while(tab[i] <= granica && i < j){
            i++;
        }
        while(tab[j] > granica && i < j){
            j--;
        }
        if(i < j){
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }
}

// flaga francuska
void flagaFrancuska(int *tab, int n, int granica1, int granica2){
    int i = -1;
    int j = 0;
    int k = n;
    int temp;

    while(j < k){
        if(tab[j] <= granica1){
            i++;
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            j++;
        }
        else{
            if(tab[j] > granica2){
                k--;
                temp = tab[k];
                tab[k] = tab[j];
                tab[j] = temp;
            }
            else{
                j++;
            }
        }
    }
}

int main()
{

    int *tab;
    przydzielPamiec1D(tab, 30);
    wypelnijTablice1D(tab, 30, 0, 10);
    wyswietl1D(tab, 30);
    flagaPolska(tab, 30, 5);
    wyswietl1D(tab, 30);
    flagaFrancuska(tab, 30, 3, 6);
    wyswietl1D(tab, 30);

    return 0;
}
