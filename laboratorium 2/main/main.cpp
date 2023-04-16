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



// sortowanie bombelkowe :)
void bubbleSort(int *tab, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(tab[j] < tab[i]){
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

// sortowanie przez wybor
void selectionSort(int *tab, int n){
    int minIndex;
    int temp;

    for(int i = 0; i < n-1; i++){
        minIndex = i;
        for(int j = i; j < n; j++){
            if(tab[minIndex] > tab[j]){
                minIndex = j;
            }
        }
        temp = tab[minIndex];
        tab[minIndex] = tab[i];
        tab[i] = temp;
    }
}

// sortowanie przez wstawienie
void insertionSort(int *tab, int n){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && tab[j] < tab[j-1]){
            int temp = tab[j-1];
            tab[j-1] = tab[j];
            tab[j] = temp;
            j--;
        }
    }
}

int main()
{
    int *tab;
    int n = 20;

    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, 0, 10);
    wyswietl1D(tab, n);
    bubbleSort(tab, n);
    wyswietl1D(tab, n);

    cout << "\n\n";

    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, 0, 10);
    wyswietl1D(tab, n);
    selectionSort(tab, n);
    wyswietl1D(tab, n);

    cout << "\n\n";

    przydzielPamiec1D(tab, n);
    wypelnijTablice1D(tab, n, 0, 10);
    wyswietl1D(tab, n);
    insertionSort(tab, n);
    wyswietl1D(tab, n);

    return 0;
}
