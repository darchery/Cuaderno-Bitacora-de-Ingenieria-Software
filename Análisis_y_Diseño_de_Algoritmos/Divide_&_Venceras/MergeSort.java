package org.example;

public class MergeSort {
    public static void main(String[] args) {
        int a[] = {3,5,1,7,2,6};

        System.out.println("Array sin ordenar: ");
        escribirArray(a);
        System.out.println("Array ordenado: ");
        mergeSort(a, 0, a.length-1);
        escribirArray(a);
    }

    private static void mergeSort(int[] a, int i, int j) {
        if (i < j) {
            mergeSort(a, i,(i+j)/2);
            mergeSort(a,(i+j)/2+1, j);
            merge(a, i ,(i+j)/2, j);
        }
    }

    private static void merge(int[] a, int inf,int medio ,int sup) {
        int i = inf;
        int j = medio + 1;
        int[] nuevoVector = new int[sup-inf+1];
        int k = 0;

        // Introducimos ordenadamente los valores mas pequeños de las 2 partes
        while (i <= medio && j <= sup) {
            if(a[i] <= a[j]) {
                nuevoVector[k] = a[i];
                i++;
            } else{
                nuevoVector[k] = a[j];
                j++;
            }
            k++;
        }

        // Introducimos los elementos restantes de cada array
        while (i <= medio) {
            nuevoVector[k] = a[i];
            i++;
            k++;
        }
        while (j <= sup) {
            nuevoVector[k] = a[j];
            j++;
            k++;
        }

        // Copiamos el nuevo array en el array original
        k = 0;
        for (int l = inf; l <= sup; l++) {
            a[l] = nuevoVector[k];
            k++;
        }
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


/*private static void mergeSort(int[] a, int i, int j) {
        if (i < j) {
            mergeSort(a, i, (i+j)/2);
            mergeSort(a, (i+j)/2+1, j);
            merge(a, i, (i+j)/2, j);
        }
    }
    private static void merge(int[] a, int inf, int medio, int sup) {
        int i = inf;
        int j = medio + 1;
        int newVec[] = new int[sup-inf+1];
        int k = 0;

        while (i <= medio && j <= sup) {
            if (a[i] <= a[j]){
                newVec[k] = a[i];
                i++;
            } else {
                newVec[k] = a[j];
                j++;
            }
            k++;
        }

        while (i <= medio) {
            newVec[k] = a[i];
            i++;
            k++;
        }
        while (j <= sup) {
            newVec[k] = a[j];
            j++;
            k++;
        }

        k = 0;
        for (int l = inf; l <= sup; l++) {
            a[l] = newVec[k];
            k++;
        }
    }*/