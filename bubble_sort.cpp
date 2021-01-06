#include <iostream>
using namespace std;

void troca(int v[],int i,int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void sort(int *v, int n){
    bool conflito;
    do{
        conflito = false;
        for(int i=0; i<n-1; i++){
            if(v[i]>v[i+1]){
                troca(v,i,i+1);
                conflito = true;
            }
        }
    }while(conflito==true);
}

int main(){
    int v[] = {6,1,7,2,4};
    int n = 5;
    sort(v,5);

    for(int i=0; i<n; i++){
        cout<<v[i]<<endl;
    }

    return 0;
}
