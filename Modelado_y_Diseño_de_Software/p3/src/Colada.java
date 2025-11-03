import java.util.*;

import static java.util.Collections.enumeration;

public abstract class Colada {

	private List<Estado> estados;
	private int temp;
	private int rpm;
	private int cantDetergente;
	private int inicioL;
	private int inicioC;
	private int fin;


	/** Ejercicio 3.
	 * En cuanto a los atributos inicioL, inicioC, inicioS y fin de las coladas, recordemos que se
	 * refieren al inicio de la fase de lavado, inicio de la fase de centrifugado, inicio de la fase de
	 * secado, y fin de la colada, respectivamente. Vamos a considerar que, al crear una colada,
	 * todos esos atributos se inicializan con el valor -1. Después, a medida que las distintas fases
	 * comiencen, se le debe asignar el instante de tiempo correspondiente.*/
	//Cuando se crea una colada, suponemos que no conocemos el inicio de lavado ni centrifugado ni el fin de la colada
	/** Antes no estaban definidos los tiempos*/
	public Colada(int temp, int rpm, int cantDetergente, EstadoPrenda estadoPrenda, Prenda prenda) {
		this.temp = temp;
		this.rpm = rpm;
		this.cantDetergente = cantDetergente;
		inicioL = -1;
		inicioC = -1;
		fin = -1;
		//Una colada necesita, al menos, un estado, así que lo crea:
		this.estados = new ArrayList<>();
		Estado estado = new Estado(estadoPrenda, this, prenda);
		/* No necesitamos añadir el objeto estado a la lista estados,
        ya que se hace al crear el Estado (colada.addEstado(this))
         */
	}

	public Enumeration<Estado> getEstados() {
		return enumeration(estados);
	}
	protected void addEstado(Estado e) {
		estados.add(e);
	}
	protected void removeEstado(Estado e) {
		estados.remove(e);
	}

	public int getTemp() {
		return temp;
	}
	protected void setTemp(int temp) {
		this.temp = temp;
	}

	public int getRpm() {
		return rpm;
	}
	protected void setRpm(int rpm) {
		this.rpm = rpm;
	}

	public int getCantDetergente() {
		return cantDetergente;
	}
	protected void setCantDetergente(int cantDetergente) {
		this.cantDetergente = cantDetergente;
	}

	public int getInicioL() {
		return inicioL;
	}
	protected void setInicioL(int inicioL) {
		this.inicioL = inicioL;
	}

	public int getInicioC() {
		return inicioC;
	}
	protected void setInicioC(int inicioC) {
		this.inicioC = inicioC;
	}

	public int getFin() {
		return fin;
	}
	protected void setFin(int fin) {
		this.fin = fin;
	}

	/** Ejercicio 1:
	 * El atributo derivado que encontramos, peso (clase Colada), debe convertirse en un métod0
	 * de la clase. El métod0 debe devolver el valor correspondiente cuando se invoque.*/
	//Los atributos derivados los convertimos en métodos:
	public int getPeso() {
		int sumaTotal = 0;
		for (Estado e : estados) {
			sumaTotal += e.getPrenda().getPeso();
		}
		return sumaTotal;
	}

	//Un métod0 para comprobar si una Colada contiene una prenda:
	public boolean contiene(Prenda prenda) {
		boolean tiene = false;

		for (Estado e : estados) {
			if (e.getPrenda().equals(prenda)) {
				tiene = true;
				break;
			}
		}
		return tiene;
	}
	/* Implementación profesor
	public boolean contiene(Prenda prenda){
        boolean contiene = false;
        Enumeration<Estado> it = this.getEstados();
        while(it.hasMoreElements() && !contiene){
            if(it.nextElement().getPrenda()==prenda) contiene = true;
        }
        return contiene;
    }
	* */
}