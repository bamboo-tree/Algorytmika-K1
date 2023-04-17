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


// quick sort
void sortowanie(int *tab, int lewy, int prawy){
    int srodek = (int)(lewy+prawy)/2;
    int pivot = tab[srodek];
    tab[srodek] = tab[prawy];
    int granica = lewy;
    int i = lewy;
    int temp;

    while(i < prawy){
        if(tab[i] < pivot){
            temp = tab[granica];
            tab[granica] = tab[i];
            tab[i] = temp;
            granica++;
        }
        i++;
    }

    tab[prawy] = tab[granica];
    tab[granica] = pivot;

    if(lewy < granica-1){
        sortowanie(tab, lewy, granica-1);
    }
    if(granica+1 < prawy){
        sortowanie(tab, granica+1, prawy);
    }
}

int main()
{

    int *tab;
    przydzielPamiec1D(tab, 20);
    wypelnijTablice1D(tab, 20, 0, 10);
    wyswietl1D(tab, 20);
    //  TRZEBA PAMIETAC, ZEBY PRAWY = DL - 1!!!!!
    sortowanie(tab, 0, 19);
    wyswietl1D(tab, 20);


    return 0;
}
