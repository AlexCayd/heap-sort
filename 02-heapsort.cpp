#include <stdio.h>

// Mantiene la propiedad de min-heap en el subárbol con raíz en i
void heapify(int a[], int n, int i) {
    int smallest = i;       // Raíz actual
    int l = 2*i + 1;        // Hijo izquierdo
    int r = 2*i + 2;        // Hijo derecho
    
    // Encuentra el menor entre raíz, hijo izquierdo y derecho
    if (l < n && a[l] < a[smallest]) 
        smallest = l;
    if (r < n && a[r] < a[smallest]) 
        smallest = r;
    
    // Si la raíz no es el menor, intercambiar y heapify recursivo
    if (smallest != i) {
        int t = a[i]; 
        a[i] = a[smallest]; 
        a[smallest] = t;
        heapify(a, n, smallest);
    }
}

// Ordena el arreglo usando heapsort (orden ascendente)
void heapsort(int a[], int n) {
    // Construir min-heap
    for (int i = n/2 - 1; i >= 0; i--) 
        heapify(a, n, i);
    
    // Extraer elementos uno por uno del heap
    for (int i = n - 1; i > 0; i--) {
        // Mover raíz al final
        int t = a[0]; 
        a[0] = a[i]; 
        a[i] = t;
        
        // Heapify la raíz reducida
        heapify(a, i, 0);
    }
}

int main(void) {
    int arr[] = {2, 8, 5, 3, 9, 1};
    int n = sizeof arr / sizeof *arr;
    
    heapsort(arr, n);
    
    // Imprimir arreglo ordenado
    for (int i = 0; i < n; i++) 
        printf("%d%c", arr[i], i == n-1 ? '\n' : ' ');
    
    return 0;
}