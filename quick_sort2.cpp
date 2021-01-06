#include <iostream>
using namespace std;


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int separar (int v[], int p, int q)
{
    int pivot = v[q];
    int i = (p - 1);

    for (int j = p; j <= q- 1; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[q]);
    return (i + 1);
}

void quickSort(int v[], int p, int q)
{
    if (p < q)
    {
        int pi = separar(v, p, q);
        quickSort(v, p, pi - 1);
        quickSort(v, pi + 1, q);
    }
}

void printArray(int v[], int n)
{
    for (int i=0; i < n; i++){
        cout<<v[i]<<" "<<endl;
    }
}

int main()
{
    int v[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    quickSort(v, 0, n-1);
    printArray(v, n);
    return 0;
}
