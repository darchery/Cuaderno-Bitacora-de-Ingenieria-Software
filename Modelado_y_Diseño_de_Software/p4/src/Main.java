public class Main {
    public static void main(String[] args) {
        // Creamos instancias de lavadoras con valores inventados
        LavadoraNormal lavadoraNormal = new LavadoraNormal("LG", 100, 60, 1000, 8, 50);
        LavadoraSecadora lavadoraSecadora = new LavadoraSecadora("Samsung", 120, 90, 1400, 10, 80);

        // Creamos 6 prendas: 2 jerséis, 2 pantalones y 2 camisetas
        Prenda jersey1 = new Prenda(TipoPrenda.JERSEY, 700);
        Prenda jersey2 = new Prenda(TipoPrenda.JERSEY, 750);
        Prenda pantalon1 = new Prenda(TipoPrenda.PANTALON, 800);
        Prenda pantalon2 = new Prenda(TipoPrenda.PANTALON, 850);
        Prenda camiseta1 = new Prenda(TipoPrenda.CAMISETA, 300);
        Prenda camiseta2 = new Prenda(TipoPrenda.CAMISETA, 350);

        // Creamos una colada normal asociada a la LavadoraNormal. Hay que incializarla con una prenda, es el pantalon1
        ColadaNormal coladaNormal1 = new ColadaNormal(40, 800, 30, EstadoPrenda.MUY_SUCIO, pantalon1, 0, lavadoraNormal);

        // Asociamos prendas a la colada Normal a través de un estado
        // (el constructor de Estado se encarga de la asociación)
        Estado estadoColada1Prenda2 = new Estado(EstadoPrenda.SUCIO, coladaNormal1, jersey1);
        Estado estadoColada1Prenda3 = new Estado(EstadoPrenda.SUCIO, coladaNormal1, camiseta1);

        //Comienza la colada:
        coladaNormal1.setInicioC(2);

        System.out.println("Lavadora Normal: " + lavadoraNormal.getMarca());
        System.out.println("  - Colada 1:");
        System.out.println("    - Peso total: " + coladaNormal1.getPeso() + " gramos");
        System.out.println("    - Cantidad de detergente: " + coladaNormal1.getCantDetergente() + " ml");
        System.out.println("    - ¿Está en funcionamiento?:" + lavadoraNormal.enFuncionamiento());
        estadoColada1Prenda2.setEstado(EstadoPrenda.LIMPIO);
        estadoColada1Prenda3.setEstado(EstadoPrenda.LIMPIO);
        coladaNormal1.setFin(10);
        System.out.println("    - La ropa se ha limpiado y la colada ha terminado");
        System.out.println("    - ¿Está en funcionamiento?:" + lavadoraNormal.enFuncionamiento());

        //Creamos una segunda colada. Hay que incializarla con una prenda, es el pantalon2
        ColadaNormal coladaNormal2 = new ColadaNormal(60, 1000, 40, EstadoPrenda.SUCIO, pantalon2, 0,  lavadoraNormal);
        // Asociamos otras prendas a la segunda colada Normal a través de un estado
        Estado estadoColada2Prenda2 = new Estado(EstadoPrenda.MUY_SUCIO, coladaNormal2, jersey2);
        Estado estadoColada2Prenda3 = new Estado(EstadoPrenda.SUCIO, coladaNormal2, camiseta2);
        coladaNormal2.setInicioC(11);

        System.out.println("  - Colada 2:");
        System.out.println("    - Peso total: " + coladaNormal2.getPeso() + " gramos");
        System.out.println("    - Cantidad de detergente: " + coladaNormal2.getCantDetergente() + " ml");

        System.out.println("\nLavadora Secadora: " + lavadoraSecadora.getMarca());
        System.out.println("  - No hay coladas asociadas en este ejemplo, pero está disponible para su uso.");

        System.out.println("\nDetalles de las Prendas:");
        System.out.println("  - Jersey 1 (Colada 1): " + jersey1.getTipo() + ", " + jersey1.getPeso() + "g");
        System.out.println("  - Pantalón 1 (Colada 1): " + pantalon1.getTipo() + ", " + pantalon1.getPeso() + "g");
        System.out.println("  - Camiseta 1 (Colada 1): " + camiseta1.getTipo() + ", " + camiseta1.getPeso() + "g");
        System.out.println("  - Jersey 2 (Colada 2): " + jersey2.getTipo() + ", " + jersey2.getPeso() + "g");
        System.out.println("  - Pantalón 2 (Colada 2): " + pantalon2.getTipo() + ", " + pantalon2.getPeso() + "g");
        System.out.println("  - Camiseta 2 (Colada 2): " + camiseta2.getTipo() + ", " + camiseta2.getPeso() + "g");
    }
}
