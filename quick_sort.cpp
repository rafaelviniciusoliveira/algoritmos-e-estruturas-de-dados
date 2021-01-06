#include <iostream>
using namespace std;

void troca(int *v,int i,int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int separa(int *v, int n){
    int pivo=0;
    int p=1;
    int q=n-1;
    while(q>p){
        while(v[p]<v[pivo] && p<n){
            p++;
        }
        while(v[q]>v[pivo]){
            q--;
        }
        if(q>p){
            troca(v,p,q);
        }
    }
    troca(v,pivo,q);
    return q;
}

void sort(int *v, int n){
    int meio = separa(v,n);
    cout<<meio<<endl;
    sort(v,meio);
    sort(v+meio,n-meio-1);
}

int main(){
    int v[] = {6,1,3,9,7,2,4};
    int n = 7;
    sort(v,7);

    for(int i=0; i<n; i++){
        cout<<v[i]<<endl;
    }

    return 0;
}
