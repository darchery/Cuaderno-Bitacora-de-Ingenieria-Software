public class Estado {
    private EstadoPrenda estado;
    private Colada colada;
    private Prenda prenda;

    public Estado(EstadoPrenda estado, Colada colada, Prenda prenda){
        this.estado = estado;
        this.colada = colada;
        this.prenda = prenda;
        assert(!colada.contiene(prenda)) : "No se puede poner dos veces una prenda en la misma colada";
        //Para mantener consistencia, tengo que insertar este estado en la Colada y la Prenda
        colada.addEstado(this);
        prenda.addEstado(this);
    }

    public EstadoPrenda getEstado(){return estado;}
    public Colada getColada(){return colada;}
    public Prenda getPrenda(){return prenda;}

    protected void setEstado(EstadoPrenda estado){this.estado = estado;}


}
