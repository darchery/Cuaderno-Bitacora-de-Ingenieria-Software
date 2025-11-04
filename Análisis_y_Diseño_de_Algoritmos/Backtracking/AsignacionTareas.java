package org.example;

import java.util.Scanner;
import java.util.Arrays;

public class AsignacionTareas {

    // PROPIEDADES DEL PROBLEMA
    int n; // tamaño de la matriz
    int [ ] solucion;
    int [][]matriz;
    int valor;


    public AsignacionTareas (int tam) {
        n = tam;
        solucion = new int [n];
        matriz = new int [n][n];
        valor=Integer.MAX_VALUE;
    }

    void vueltaAtras() {
        // A IMPLEMENTAR POR EL ALUMNO. PUEDE IMPLEMENTAR TANTOS METODOS AUXILIARES COMO CREA CONVENIENTE.
        boolean[] tareasUsadas = new boolean[n]; // Marca que tareas has usado
        int[] solucionParcial = new int[n]; // Actualiza la solucion para luego copiarala a la final
        asignarTareaAOperario(0,0, solucionParcial, tareasUsadas);
    }
    private void asignarTareaAOperario(int operario, int costeActual, int[] solucionParcial, boolean[] tareasUsadas) {
        boolean foundSol = false;

        // Caso base 0: todos los operarios tienen asignadas las tareas
        if (operario == n) {
            if (costeActual < valor) {
                valor = costeActual;
                copiarSol(solucionParcial);
            }
            foundSol = true;
        }

        // Caso general: probamos todas las tareas para cada operario
        if (!foundSol) {
            // Exploramos todas las tareas posibles para el operario actual
            for (int tarea = 0; tarea < n; tarea++) {
                if (!tareasUsadas[tarea]) {
                    //Asignamos tarea
                    solucionParcial[operario] = tarea;
                    tareasUsadas[tarea] = true;

                    // Calculamos nuevo coste
                    int costeNuevo = costeActual + matriz[operario][tarea];

                    // Es una solucion factible
                    if (costeNuevo < valor) {
                        asignarTareaAOperario(operario + 1, costeNuevo, solucionParcial, tareasUsadas);
                    }
                    // No lo es, damos marcha atras
                    tareasUsadas[tarea] = false;
                }
            }
        }
    }

    private void copiarSol(int[] solucionParcial) {
        for (int i = 0; i < n; i++) {
            solucion[i] = solucionParcial[i];
        }
    }

    private static int[][] readMatrix(Scanner scanner) {

        String[] temp = scanner.nextLine().split(" ");
        int nMatrix = temp.length;
        int [][]matrix = new int[nMatrix][nMatrix];
        for (int j = 0; j < nMatrix; j++) {
            matrix[0][j] = Integer.parseInt(temp[j]);
        }
        for (int i = 1; i < nMatrix; i++) {
            String[] numbers = scanner.nextLine().split(" ");
            for (int j = 0; j < nMatrix; j++) {
                matrix[i][j] = Integer.parseInt(numbers[j]);
            }
        }
        scanner.close();
        return matrix;
    }

    public static void main(String [] args){
        int [][]entrada=readMatrix(new Scanner(System.in));
        AsignacionTareas r=new AsignacionTareas(entrada.length);

        r.matriz=entrada.clone();
        r.vueltaAtras();
        System.out.println("Solucion: "+Arrays.toString(r.solucion));
        System.out.print("Coste: "+r.valor);
    }
}