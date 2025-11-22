import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.List;

import static java.util.Collections.enumeration;

public abstract class Colada {
    private int temp;
    private int rpm;
    private int cantDetergente;
    private int inicioL;
    private int inicioC;
    private int fin;
    private List<Estado> estados;

    //Cuando se crea una colada, suponemos que no conocemos el inicio de lavado ni centrifugado ni el fin de la colada
    public Colada(int temp, int rpm, int cantDetergente, EstadoPrenda estadoPrenda, Prenda prenda) {
        this.temp = temp;
        this.rpm = rpm;
        this.cantDetergente = cantDetergente;
        inicioL = -1;
        inicioC = -1;
        fin = -1;
        this.estados = new ArrayList<Estado>();
        //Una colada necesita, al menos, un estado, así que lo crea:
        Estado estado = new Estado(estadoPrenda,this,prenda);
        /* No necesitamos añadir el objeto estado a la lista estados,
        ya que se hace al crear el Estado (colada.addEstado(this))
         */

        // 7.
        // Si no hay jerseys tod0 bien, pero si hay jerseys => temp <=30
        assert(!hayJerseys() || hayJerseys() && temp<=30): "(7) Si incluye un jersey => temperatura máxima: 30";
        // 8.
        assert (getPeso() <= 5 || !coladasMas5KilosNoMuySuciasMas50()) : "(8) No puede haber coladas que superen los 5 kilos y más del 50% de las prendas\n" +
                "--estuvieran muy sucias";
    }

    public int getTemp() { return temp; }
    protected void setTemp(int temp) { this.temp = temp; }

    public int getRpm() { return rpm; }
    protected void setRpm(int rpm) { this.rpm = rpm; }

    public int getCantDetergente() { return cantDetergente; }
    protected void setCantDetergente(int cantDetergente) { this.cantDetergente = cantDetergente; }

    public int getInicioL() { return inicioL; }
    protected void setInicioL(int inicioL) {
        // 5.
        assert (inicioC == -1 || inicioL < inicioC) : "(5) El lavado debe hacerse antes del centrifugado";
        this.inicioL = inicioL;
    }

    public int getInicioC() { return inicioC; }
    protected void setInicioC(int inicioC) {
        assert (inicioL == -1 || inicioC > inicioL) : "(5) El lavado debe hacerse antes del centrifugado";
        this.inicioC = inicioC;
    }

    public int getFin() { return fin; }
    protected void setFin(int fin) { this.fin = fin; }

    public Enumeration<Estado> getEstados() { return enumeration(estados); }
    protected void addEstado(Estado estado) {
        estados.add(estado);
        /** Tanto al crear como añadir estados debemos comprobar los invariantes*/
        // 7.
        // Si no hay jerseys tod0 bien, pero si hay jerseys => temp <=30
        assert(!hayJerseys() || hayJerseys() && temp<=30): "(7) Si incluye un jersey => temperatura máxima: 30";
        // 8.
        assert (getPeso() <= 5 || !coladasMas5KilosNoMuySuciasMas50()) : "(8) No puede haber coladas que superen los 5 kilos y más del 50% de las prendas\n" +
                "--estuvieran muy sucias";
    }
    protected void removeEstado(Estado estado) { estados.remove(estado); }

    //Los atributos derivados los convertimos en métodos:
    public int getPeso(){
        int sumaPeso=0;
        for (Estado e : estados){sumaPeso+=e.getPrenda().getPeso();}
        return sumaPeso;
    }

    //Un métod0 para comprobar si una Colada contiene una prenda:
    public boolean contiene(Prenda prenda){
        boolean contiene = false;
        Enumeration<Estado> it = this.getEstados();
        while(it.hasMoreElements() && !contiene){
            if(it.nextElement().getPrenda()==prenda) contiene = true;
        }
        return contiene;
    }

    /**
     * Este métod0, además de establecer un valor
     * Modelado y Diseño del Software
     * Grado en Ingeniería del Software – Plan 2023
     * para el atributo fin, debe actualizar los estados asociados a la colada de las prendas que se han
     * lavado. Para ello, sigue el siguiente proceso:
     * o Si la cantidad de detergente de la colada era mayor o igual que 50, todas las prendas pasan
     * a estar limpias.
     * o En caso contrario, las prendas que estaban muy sucias pasan a estar sucias, y las demás
     * pasan a estar limpias.*/
    public void concluyeColada(int fin) {
        // Comprobar que se cumple el ciclo
        assert(fin > inicioL && fin > inicioC) : "La colada debe finalizar tras las fases de lavado y centrifugado";
        setFin(fin);
        for(Estado e : this.estados){
            actualizaEstado(e);
        }
    }

    private void actualizaEstado(Estado e) {
        if (cantDetergente >= 50) {
            e.setEstado(EstadoPrenda.LIMPIO);
        } else {
            if (e.getEstado().equals(EstadoPrenda.MUY_SUCIO)) {
                e.setEstado(EstadoPrenda.SUCIO);
            } else {
                e.setEstado(EstadoPrenda.LIMPIO);
            }
        }
    }

    public boolean coladasMas5KilosNoMuySuciasMas50() {
        int numeroPrendas = estados.size();
        int cont = 0;
        boolean cumpleCondicionTodoBien = false;

        for (Estado e : estados) {
            if (e.getEstado().equals(EstadoPrenda.MUY_SUCIO)) {
                cont++;
            }
        }
        if (numeroPrendas/2 > cont ) {
            cumpleCondicionTodoBien = true;
        }
        return cumpleCondicionTodoBien;
    }

    public boolean hayJerseys() {
        boolean found = false;
        Enumeration<Estado> prendas = this.getEstados();

        while (prendas.hasMoreElements() && !found) {
            if (prendas.nextElement().getPrenda().getTipo().equals(TipoPrenda.JERSEY)) {
                found = true;
            }
        }

        return found;
    }
}

