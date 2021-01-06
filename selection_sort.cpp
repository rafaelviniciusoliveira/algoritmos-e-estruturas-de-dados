#include <iostream>
using namespace std;

void troca(int v[],int i,int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void sort(int *v, int n){
    for(int i=n-1; i>=0; i--){
        int argmax=0;
        for(int j=0;j<=i;j++){
            if(v[j]>v[argmax]){
                argmax=j;
            }
            troca(v,argmax,i);
        }
    }
}

int main(){
    int v[] = {8,5,1,2,3};
    int n = 5;
    sort(v,5);

    for(int i=0; i<n; i++){
        cout<<v[i]<<endl;
    }
    return 0;
}
