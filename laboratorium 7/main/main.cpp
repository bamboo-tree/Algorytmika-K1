#include <iostream>

using namespace std;


int naiwny(int *tab, int n, int val){
    for(int i = 0; i < n; i++){
        if(tab[i] == val){
            return i;
        }
    }
}

int binarny(int *tab, int n, int val){     // dla posortowanej tablicy
    int p = n-1;
    int l = 0;
    int m = (p-l)/2;

    while(l <= p){

        if(tab[m] < val){
            l = m+1;
        }
        else if(tab[m] > val){
            p = m-1;
        }
        else{
            return m;
        }
        m = l + (p-l)/2;
    }
}



int main()
{
    int tab[] = {2, 4, 6, 8, 10, 12, 14, 16};
    cout << naiwny(tab, 8, 14) << endl;
    cout << binarny(tab, 8, 4) << endl;
    return 0;
}
