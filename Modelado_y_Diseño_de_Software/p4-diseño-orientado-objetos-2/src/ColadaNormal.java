public class ColadaNormal extends Colada {
    private int cantSuavizante;
    private LavadoraNormal lavadora;

    public ColadaNormal(int temp, int rpm, int cantDetergente,  EstadoPrenda estadoPrenda, Prenda prenda, int cantSuavizante, LavadoraNormal lavadora) {
        // 6.
        assert (cantDetergente <= lavadora.getCapDetergente()) : "(6) La cantidad de detergente del lavado debe ser menor o igual al máximo de la lavadora";
        // 9.
        assert (cantSuavizante <= lavadora.getCapSuavizante()) : "(9) La cantidad de suavizante del lavado debe ser menor o igual al máximo de la\n" +
                "lavadora";

        super(temp, rpm, cantDetergente,estadoPrenda, prenda);
        this.cantSuavizante = cantSuavizante;
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
        // 10.
        // 2 opciones: no hay jerseys => continue, sino la cantSuavizante debe ser 0
        assert (!hayJerseys() || hayJerseys() && cantSuavizante == 0) : "(10) Si el lavado incluye jerseis, entonces no puede llevar suavizante";
        // 11.
        assert (getPeso() <= lavadora.getMaxPeso()) : "(11) El peso del lavado no puede superar el máximo de la lavadora";

    }

    public int getCantSuavizante() {
        return cantSuavizante;
    }
    protected void setCantSuavizante(int cantSuavizante) {
        this.cantSuavizante = cantSuavizante;
    }

    public LavadoraNormal getLavadora(){return lavadora;}

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
        // 10.
        // 2 opciones: no hay jerseys => continue, sino la cantSuavizante debe ser 0
        assert (!hayJerseys() || hayJerseys() && cantSuavizante == 0) : "(10) Si el lavado incluye jerseis, entonces no puede llevar suavizante";
        // 11.
        assert (getPeso() <= lavadora.getMaxPeso()) : "(11) El peso del lavado no puede superar el máximo de la lavadora";

    }
}
