import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;

import static java.util.Collections.enumeration;

public class LavadoraNormal extends Lavadora {
    private int capSuavizante;
    private List<ColadaNormal> coladas;

    public LavadoraNormal(String marca, int capDetergente, int maxTempLavado, int maxCentrifugado, int maxPeso, int capSuavizante) {
        // 1.
        assert (maxTempLavado <= 60) : "(1) La temperatura máxima de lavadoras normales es: 60";
        // 2.
        assert (maxCentrifugado <= 1800) : "(2) Las rpm máximas en lavadoras normales es: 1800";

        super(marca, capDetergente, maxTempLavado, maxCentrifugado, maxPeso);
        this.capSuavizante = capSuavizante;
        this.coladas = new ArrayList<ColadaNormal>();
    }

    public int getCapSuavizante() { return capSuavizante; }
    protected void setCapSuavizante(int capSuavizante) { this.capSuavizante = capSuavizante; }

    public Enumeration<ColadaNormal> getColadas() { return enumeration(coladas); }
    protected void addColada(ColadaNormal colada) { coladas.add(colada); }
    protected void removeColada(ColadaNormal colada) { coladas.remove(colada); }

    //Los atributos derivados los convertimos en métodos
    public boolean enFuncionamiento(){
        ColadaNormal ultimaColada = coladas.get(coladas.size()-1);
        return (ultimaColada.getInicioC()!=-1 || ultimaColada.getInicioL()!=-1) && ultimaColada.getFin()==-1;
    }
}
