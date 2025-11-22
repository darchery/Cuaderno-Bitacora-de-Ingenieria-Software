public class Estado {

	Colada colada;
	Prenda prenda;
	private EstadoPrenda estado;

	public Estado(EstadoPrenda estado,Colada colada , Prenda prenda) {
		this.estado = estado;
		this.colada = colada;
		this.prenda = prenda;
		assert(!colada.contiene(prenda)) : "No se puede poner 2 veces una prenda en la misma colada";
		//Para mantener consistencia, tengo que insertar este estado en la Colada y la Prenda
		colada.addEstado(this);
		prenda.addEstado(this);
	}

	public Colada getColada() {
		return colada;
	}

	public Prenda getPrenda() {
		return prenda;
	}

	public EstadoPrenda getEstado() {
		return estado;
	}
	protected void setEstado(EstadoPrenda estado) {
		this.estado = estado;
	}
}