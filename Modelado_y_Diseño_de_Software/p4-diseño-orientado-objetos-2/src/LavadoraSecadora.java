import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;

import static java.util.Collections.enumeration;

public class LavadoraSecadora extends Lavadora {
    private int maxTempSecado;
    private List<ColadaSecado> coladas;

    public LavadoraSecadora(String marca, int capDetergente, int maxTempLavado, int maxCentrifugado, int maxPeso, int maxTempSecado) {
        // 3.
        assert (maxTempLavado <= 40) : "(2) La temperatura máxima de lavadoras de secado es: 40";
        // 4.
        assert (maxCentrifugado <= 1200) : "(3) Las rpm máximas en lavadoras de secado es: 1200";

        super(marca, capDetergente, maxTempLavado, maxCentrifugado, maxPeso);
        this.maxTempSecado = maxTempSecado;
        this.coladas = new ArrayList<ColadaSecado>();
    }

    public int getMaxTempSecado() { return maxTempSecado; }
    protected void setMaxTempSecado(int maxTempSecado) { this.maxTempSecado = maxTempSecado; }

    public Enumeration<ColadaSecado> getColadas() { return enumeration(coladas); }
    protected void addColada(ColadaSecado colada) { coladas.add(colada); }
    protected void removeColada(ColadaSecado colada) { coladas.remove(colada); }

    //Los atributos derivados los convertimos en métodos
    public boolean enFuncionamiento(){
        ColadaSecado ultimaColada = coladas.getLast();
        return (ultimaColada.getInicioC()!=-1 || ultimaColada.getInicioL()!=-1) && ultimaColada.getInicioS() != -1 && ultimaColada.getFin()==-1;
        //return ultimaColada.getFin()==-1;
    }
}
