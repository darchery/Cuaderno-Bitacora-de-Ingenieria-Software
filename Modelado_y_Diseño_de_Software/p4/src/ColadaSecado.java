public class ColadaSecado extends Colada {
    private int inicioS;
    private int tempSecado;
    LavadoraSecadora lavadora;

    //En las coladas de secado, no se conoce el inicio de secado cuando se crea
    public ColadaSecado(int temp, int rpm, int cantDetergente, EstadoPrenda estadoPrenda, Prenda prenda, int tempSecado, LavadoraSecadora lavadora) {
        // 6.
        assert (cantDetergente <= lavadora.getCapDetergente()) : "(6) La cantidad de detergente del lavado debe ser menor o igual al máximo de la lavadora";
        // 12.
        assert (tempSecado <= lavadora.getCapDetergente()) : "(12) La temperatura de secado debe ser menor al máximo de la lavadora secadora";

        super(temp, rpm, cantDetergente,estadoPrenda, prenda);
        this.tempSecado = tempSecado;
        inicioS = -1;
        this.lavadora = lavadora;
        //Para mantener la consistencia, añado esta colada a la Lavadora:
        lavadora.addColada(this);
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
        // 11.
        assert (getPeso() <= lavadora.getMaxPeso()) : "(11) El peso del lavado no puede superar el máximo de la lavadora";

    }

    public int getInicioS() { return inicioS; }
    protected void setInicioS(int inicioS) {
        // 13
        assert (getInicioC() < inicioS || getInicioL() < inicioS) : "(13) El secado debe comenzar tras el centrifugado (o lavado si no hay\n" +
                "centrifugado)";
        this.inicioS = inicioS;
    }

    public int getTempSecado() { return tempSecado; }
    protected void setTempSecado(int tempSecado) { this.tempSecado = tempSecado; }

    public LavadoraSecadora getLavadora(){return lavadora;}
    @Override
    protected void addEstado(Estado estado) {
        super.addEstado(estado);
        /** Tanto al crear como añadir estados debemos comprobar los invariantes*/
        // 7.
        // Si no hay jerseys tod0 bien, pero si hay jerseys => temp <=30
        int temp = getTemp();
        assert(!hayJerseys() || hayJerseys() && temp<=30): "(7) Si incluye un jersey => temperatura máxima: 30";
        // 8.
        assert (getPeso() <= 5 || !coladasMas5KilosNoMuySuciasMas50()) : "(8) No puede haber coladas que superen los 5 kilos y más del 50% de las prendas\n" +
                "--estuvieran muy sucias";
        // 11.
        assert (getPeso() <= lavadora.getMaxPeso()) : "(11) El peso del lavado no puede superar el máximo de la lavadora";

    }
}
