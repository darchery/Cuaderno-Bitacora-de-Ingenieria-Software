package org.example;

public class MenorQueNoEstaEnLaLista_Parcial_1_1819 {
    public static void main( String[] args ) {

        int[] a1 = {0, 1, 2, 6, 9, 11, 15};
        int[] a2 = {1, 2, 3, 4, 6, 9, 11,15};
        int[] a3 = {0, 1, 2, 3, 4, 5, 6};

        System.out.println("Version fuerza bruta: ");
        System.out.println("El menor elemento omitido es " + menorNoLista(a1));
        System.out.println("El menor elemento omitido es " + menorNoLista(a2));
        System.out.println("El menor elemento omitido es " + menorNoLista(a3) +"\n");

        System.out.println("Version recursiva D&V: ");
        System.out.println("El menor elemento omitido es " + menorNoListaREC(a1, 0, a1.length-1));
        System.out.println("El menor elemento omitido es " + menorNoListaREC(a2, 0, a1.length-1));
        System.out.println("El menor elemento omitido es " + menorNoListaREC(a3,0, a1.length-1));
    }

    private static int menorNoListaREC(int[] a, int inf, int sup) {
        int minOm; int n = a.length;
        if (a[inf] > inf) { minOm = inf;}
        else if ( a[sup] == sup ) { minOm = sup+1;}
        else if (sup-inf <= 1) { minOm = inf+1;}
        else {
            int med = (inf + sup) / 2;
            if (a[med] == med) {
                minOm = menorNoListaREC(a, med+1, sup); }
            else {
                minOm = menorNoListaREC(a, inf, med-1); } }
        return minOm;
    }

    private static int menorNoLista(int[] a) {
        int minOmitido = 0;
        int i = 0;

        if (a[i] > 0) {
            minOmitido = 0;
        } else {
            i = 1;

            while(i < a.length && a[i] - i == 0) {
                i++;
            }
            minOmitido = i;
        }
        return minOmitido;
    }
}
