package org.example;

import java.util.Scanner;
import java.util.Arrays;

public class DesajusteMinimo {

    public static void main( String[] args){
        try (Scanner sc = new Scanner(System.in)){
            String[] speso = sc.next().split(",");

            int[] peso = new int[speso.length];

            for (int i = 0 ; i < peso.length; i++) peso[i] = Integer.parseInt(speso[i]);

            int k = desajusteMinimo(peso);

            System.out.println(Integer.toString(k));
        }
    }


    public static int desajusteMinimo ( int[] p){


        int[][]SePuede = new int[p.length+1][]; // Matriz que marca con 1 o 0 si se puede meter o no
        int PesoTotal=0;
        int cant;

        // Necesitamos saber cuanto es la mitad del peso total para intentar repartirla entre 2 conjuntos
        for (int i= 0; i< p.length; i++){
            PesoTotal= PesoTotal + p[i];
        }
        cant= PesoTotal/2;

        for (int i = 0; i<SePuede.length; i++){
            SePuede [i] = new int[cant+1];
        }
        for (int i= 0; i< SePuede.length; i++){
            SePuede [i][0] = 1; // Hasta el objeto i , cantidad 0, se puede
        }
        for (int j= 1; j < cant+1; j++){
            SePuede [0][j] = 0; // Con 0 objetos NO podemos repartir una cantidad j, no se puede
        }

        for (int i= 1; i< SePuede.length; i++){
            for (int j = 1;j < SePuede [i].length;j++){
                if (p[i] > j) {
                    SePuede[i][j]= SePuede [i-1][j];
                }
                else {
                    SePuede[i][j] = Math.max(SePuede[i-1][j], SePuede[i-1][j-p[i]]);
                }
            }
        }

        // Hacemos marcha atrás para calcular el peso óptimo mínimo
        int val_aprox = cant;

        while (SePuede[p.length-1][val_aprox] == 0){
            val_aprox --;
        }
        return val_aprox;
    }

}//end class Mochila01