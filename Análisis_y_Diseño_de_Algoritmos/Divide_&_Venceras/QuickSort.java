package org.example;

public class QuickSort {
    public static void main(String[] args) {
        int a[] = {3,5,1,8,2,7};

        System.out.println("Array sin ordenar: ");
        escribirArray(a);
        System.out.println("Array ordenado: ");
        quickSort(a, 0, a.length-1);
        escribirArray(a);
    }



    private static void quickSort(int[] a, int i, int j) {
        // Mientras sea i < j
        if (i < j) {
            // Obtenemos un pivote partiendo
            int piv = partir(a, i, j);
            quickSort(a,i, piv-1 );
            quickSort(a, piv+1 , j);
        }
    }

    private static int partir(int[] a, int inf, int sup) {
        int posPivote = inf;
        int i = inf + 1;
        int j = sup;

        while (i <= j) {
            // Buscamos elementos menores que el pivote desde el final de array
            while (i <= j && a[j] >= a[posPivote]) {
                j--;
            }
            // Buscamos elementos mayores que el pivote desde el incio + 1 del array
            while (i <= j && a[i] <= a[posPivote]) {
                i++;
            }
            // Si no se ha cruzado intercambiamos los elemento
            if (i < j) {
                intercambiar(a, i, j);
            }
        }
        // Si el pivote es mayor que el elemento de j intercambiamos
        if (a[posPivote] > a[j]) {
            intercambiar(a,posPivote,j);
        }
        return j;
    }

    private static void intercambiar(int[] a, int i, int j) {
        int aux = a[i];
        a[i] = a[j];
        a[j] = aux;
    }

    private static void escribirArray(int[] a) {
        System.out.print("[");
        for (int i = 0; i < a.length; i++) {
            if (i != a.length - 1){
                System.out.print(a[i] + ", ");
            } else {
                System.out.print(a[i]);
            }
        }
        System.out.print("]\n\n");
    }
}


/*
private static void quickSort(int[] a, int i, int j) {
        if (i < j) {
            int pivote = partir(a, i, j);
            quickSort(a, i, pivote-1);
            quickSort(a, pivote+1, j);
        }
    }

    private static int partir(int[] a, int inf, int sup) {
        int posPivote = inf;
        int i = inf + 1;
        int j  = sup;

        while (i <= j) {
            while (i <= j && a[j] >= a[posPivote]) {
                j--;
            }
            while (i <= j && a[i] <= a[posPivote]) {
                i++;
            }
            if (i < j) {
                intercambiar(a, i, j);
            }
        }
        if (a[posPivote] > a[j]) {
            intercambiar(a, posPivote, j);
        }
        return  j;
    }

    private static void intercambiar(int[] a, int i, int j) {
        int aux = a[i];
        a[i] = a[j];
        a[j] = aux;
    }*/