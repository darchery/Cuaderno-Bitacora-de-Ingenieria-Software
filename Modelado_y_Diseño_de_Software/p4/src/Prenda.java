import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;

import static java.util.Collections.enumeration;

public class Prenda {
    private TipoPrenda tipo;
    private int peso;
    private List<Estado> estados;

    public Prenda(TipoPrenda tipo, int peso) {
        this.tipo = tipo;
        this.peso = peso;
        estados = new ArrayList<Estado>();
    }

    public TipoPrenda getTipo() {
        return tipo;
    }
    protected void setTipo(TipoPrenda tipo) {
        this.tipo = tipo;
    }

    public int getPeso() {
        return peso;
    }
    protected void setPeso(int peso) {
        this.peso = peso;
    }

    public Enumeration<Estado> getEstados() { return enumeration(estados); }
    protected void addEstado(Estado estado) { estados.add(estado); }
    protected void removeEstado(Estado estado) { estados.remove(estado); }
}
