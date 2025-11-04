package org.example;

public class PicoArrayUnimodal {
    public static void main( String[] args ) {

        int[] a = {1,5,7,3,1};
        System.out.println("El pico es: " + pico(a));
    }

    private static int pico(int[] a) {
        int i = 1;

        while (i < a.length && a[i] > a[i-1]){
            i++;
        }
        return a[i-1];
    }
}
