package org.example;


import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class GrafosAvidos {
    public static class Edge implements Comparable<Edge>{
        public int u,v;
        public int peso;

        public Edge(int u, int v, int peso) {
            this.u = u;
            this.v = v;
            this.peso = peso;
        }

        @Override
        public int compareTo(GrafosAvidos.Edge o) {
            return Integer.compare(this.peso, o.peso);
        }
    }

    public static Set<Edge> prim(int[][] L) {
        int n = L.length;
        Set<Edge> T = new HashSet<>();    //Aristas del arbol de recubrimiento
        Set<Integer> U = new HashSet<>(); //Vertices visitados
        Set<Integer> V = new HashSet<>(); //Vertices por Visitar
        int[] proximo = new int[n];       //proximo[i] = j -->
        // --> El mas proximo del nodo i es j
        int[] distMin = new int[n];		  //Con una distancia de distMin[i]

        U.add(0);                         //Añado un vertice
        for (int i = 1; i < n; i++) {
            V.add(i);
            proximo[i] = 0;				  //El más proximo es el unico nodo visitado
            distMin[i] = L[0][i];         //Con L[0][i] de distancia
        }

        while (U.size()<n) {
            //Buscamos el vertice que esta mas cerca del MST
            int min = Integer.MAX_VALUE;
            int k = -1;
            for(Integer j : V) {
                if (distMin[j]<min) {
                    min = distMin[j];
                    k = j;
                }
            }
            //El vertice es k con una distancia min
            //Añadimos arista
            T.add(new Edge(proximo[k], k, L[proximo[k]][k]));
            //Añadimos vertice
            U.add(k);
            V.remove(k);

            //Recalculamos las distancias
            for(Integer j : V) {
                if (L[j][k] < distMin[j]) {
                    min = distMin[j];
                    k = j;
                }
            }
        }
        return T;
    }

    public static Set<Edge> Kruskal(Set<Integer> V, Set<Edge> E){
        int n = V.size();
        Set<Edge> T = new HashSet<>();    //Aristas del arbol de recubrimiento

        //Ordenamos las aristas
        SortedSet<Edge> ESort = new TreeSet<>();
        ESort.addAll(E);

        //Creamos las n particiones
        Set<Set<Integer>> P = new HashSet<>();
        for(Integer v : V) {
            Set<Integer> p = new HashSet<>();
            p.add(v);
            P.add(p);
        }

        //Comienza el algoritmo Avido
        while (!ESort.isEmpty()) {
            //Saco la mejor arista
            Edge e = ESort.iterator().next();
            ESort.remove(e);

            //Busco en que particion esta u y v
            Set<Integer> pu=null,pv=null;
            Iterator<Set<Integer>> it = P.iterator();
            while (pu!= null && pv != null) {
                Set<Integer> p = it.next();
                if (p.contains(e.u)) pu = p;
                if (p.contains(e.v)) pv = p;
            }

            if (pu!=pv) {
                pu.addAll(pv);
                P.remove(pv);
                T.add(e);
            }
        }

        return T;
    }

    public static Set<Edge> Dijkstra(int[][] L, int s){
        int n = L.length;
        Set<Edge> T = new HashSet<>();    //Aristas
        Set<Integer> U = new HashSet<>(); //Vertices visitados
        Set<Integer> V = new HashSet<>(); //Vertices por Visitar
        int[] proximo = new int[n];       //proximo[i] = j -->
        // --> El mas proximo del nodo i es j
        int[] distMin = new int[n];		  //Con una distancia de distMin[i]

        for (int j = 0; j < n; j++) {
            V.add(j);
            proximo[j] = s;
            distMin[j] = L[s][j];         //Con L[s][j] de distancia
        }
        V.remove(s);

        while (V.isEmpty()) {
            int min = Integer.MAX_VALUE;
            int k = -1;
            for(Integer j : V) {
                if (distMin[j]<min) {
                    min = distMin[j];
                    k = j;
                }
            }

            T.add(new Edge(proximo[k],k,min));
            V.remove(k);
            U.add(k);

            for (int j:V) {
                distMin[j]=Math.min(distMin[j], distMin[k]+L[k][j]);
            }
        }
        return T;
    }
}
