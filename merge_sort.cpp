#include <iostream>
#include <cstdlib>
using namespace std;

void merge(int *v, int n, int m){
    int i = 0;
    int p = 0;
    int q = m;

    int *tmp = (int*) malloc(n*sizeof(int));

    while (p<m && q<n){
        if(v[p]<=v[q]){
            tmp[i++]=v[p++];
        }else{
            tmp[i++]=v[q++];
        }
    }

    while(p<m){
       tmp[i++]=v[p++];
    }

    while(q<n){
        tmp[i++]=v[q++];
    }

    for(int j=0;j<n;j++){
        v[j]=tmp[j];
    }
    free(tmp);
}

void mergeSort(int *v,int n,int m){
    int meio = m;
    merge(v,0,meio);
    merge(v,meio,n);
}

int main(){
    int v[] = {6,1,3,9,7,2,4,5};
    int n = sizeof(v);
    int m = n/2;
    mergeSort(v,n,m);

    for(int i=0; i<n; i++){
        cout<<v[i]<<endl;
    }

    return 0;
}
