import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;

import static java.util.Collections.enumeration;

public abstract class Lavadora {
    private String marca;
    private int capDetergente;
    private int maxTempLavado;
    private int maxCentrifugado;
    private int maxPeso;

    public Lavadora(String marca, int capDetergente, int maxTempLavado, int maxCentrifugado, int maxPeso) {
        this.marca = marca;
        this.capDetergente = capDetergente;
        this.maxTempLavado = maxTempLavado;
        this.maxCentrifugado = maxCentrifugado;
        this.maxPeso = maxPeso;
    }

    public String getMarca() { return marca; }
    protected void setMarca(String marca) { this.marca = marca; }

    public int getCapDetergente() { return capDetergente; }
    protected void setCapDetergente(int capDetergente) { this.capDetergente = capDetergente; }

    public int getMaxTempLavado() { return maxTempLavado; }
    protected void setMaxTempLavado(int maxTempLavado) { this.maxTempLavado = maxTempLavado; }

    public int getMaxCentrifugado() { return maxCentrifugado; }
    protected void setMaxCentrifugado(int maxCentrifugado) { this.maxCentrifugado = maxCentrifugado; }

    public int getMaxPeso() { return maxPeso; }
    protected void setMaxPeso(int maxPeso) { this.maxPeso = maxPeso; }

    //Los atributos derivados los convertimos en métodos
    public abstract boolean enFuncionamiento();

}
