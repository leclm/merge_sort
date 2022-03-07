#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int * v, long int n){
    long int i, j, x;
    for(i=+1; i<=n; i++){
        x = v[i];
        j = i;
        while(x < v[j-1] && j > 0){
            v[j] = v[j-1];
            j--;
        }
        v[j] = x;
    }
}

void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) { // verifica se o array está vazio ou se possui apenas 1 elemento
    }

    int mid = (i + j) / 2;

    if(a[mid] <= a[mid + 1]) { // verifica se o array já estiver ordenado, se sim, não realiza o merge sort
        return;
    }

    if ((j+i) <= 10) { // se o array for de até 10 elementos faz o insertion sort ao inves do merge sort
        insertion_sort(a, j);
        return;
    }

    merge_sort(i, mid, a, aux);
    merge_sort(mid + 1, j, a, aux);

    int esq = i;
    int dir = mid + 1;
    int k;

    for (k = i; k <= j; k++) {
        if (esq == mid + 1) {
            aux[k] = a[dir];
            dir++;
        } else if (dir == j + 1) {
            aux[k] = a[esq];
            esq++;
        } else if (a[esq] < a[dir]) {
            aux[k] = a[esq];
            esq++;
        } else {
            aux[k] = a[dir];
            dir++;
        }
    }

    for (k = i; k <= j; k++) {
        a[k] = aux[k];
    }
}

int main() {
    int *a, n, i;

    printf("Digite o tamanho do array:\n");
    scanf("%d", &n);
    a = (int *) malloc(sizeof(int) * n);

    printf("Digite o elemento:\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(0, n - 1, a, a);

    printf("Array ordenado:\n");

    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    return 0;
}
