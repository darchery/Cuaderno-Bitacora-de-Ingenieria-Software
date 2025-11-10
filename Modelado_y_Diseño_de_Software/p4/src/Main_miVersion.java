public class Main_miVersion {
    public static void main(String[] args) {
        /** Ejercicio 4:
         * Una vez desarrolladas las clases de andamiaje correspondientes, se pide crear un métod0
         * Main desde el que se invoquen estas clases y se ejemplifique la instanciación de objetos
         * en el sistema. Por ejemplo, se pueden crear lavadoras, prendas y coladas que laven estas
         * prendas en las lavadoras. Se puede ejemplificar cómo comienzan y terminan las coladas.*/
        // Creamos instancias de lavadoras con valores inventados
        LavadoraNormal lavadoraNormal = new LavadoraNormal("BOSCH", 100, 60,
                1000, 8, 50);
        LavadoraSecadora lavadoraSecadora = new LavadoraSecadora("LG", 120, 40,
                1200, 10, 40);

        // Creamos 6 prendas: 2 jerséis, 2 pantalones y 2 camisetas
        Prenda jersey1 = new Prenda(TipoPrenda.JERSEY, 700);
        Prenda jersey2 = new Prenda(TipoPrenda.JERSEY, 750);
        Prenda pantalon1 = new Prenda(TipoPrenda.PANTALON, 800);
        Prenda pantalon2 = new Prenda(TipoPrenda.PANTALON, 850);
        Prenda camiseta1 = new Prenda(TipoPrenda.CAMISETA, 300);
        Prenda camiseta2 = new Prenda(TipoPrenda.CAMISETA, 350);

        // Creamos una colada normal asociada a la LavadoraNormal. Hay que incializarla con una prenda, es el pantalon1
        ColadaNormal coladaNormal = new ColadaNormal(50, 400, 60, EstadoPrenda.MUY_SUCIO,
                pantalon1, 50, lavadoraNormal);

        // Asociamos prendas a la colada Normal a través de un estado
        // (el constructor de Estado se encarga de la asociación)
        Estado estadoColada1Jersey1 = new Estado(EstadoPrenda.SUCIO, coladaNormal, jersey1);
        Estado estadoColada1Camiseta1 = new Estado(EstadoPrenda.SUCIO, coladaNormal, camiseta1);

        //Comienza la colada:
        coladaNormal.setInicioC(2);

        System.out.println("Lavadora Normal: " + lavadoraNormal.getMarca());
        System.out.println("  - Colada 1:");
        System.out.println("    - Peso total: " + coladaNormal.getPeso() + " gramos");
        System.out.println("    - Cantidad de detergente: " + coladaNormal.getCantDetergente() + " ml");
        System.out.println("    - ¿Está en funcionamiento?:" + lavadoraNormal.enFuncionamiento());
        // Se limpia la ropa
        coladaNormal.concluyeColada(10);

        System.out.println("    - La ropa se ha limpiado y la colada ha terminado");
        System.out.println("    - ¿Está en funcionamiento?:" + lavadoraNormal.enFuncionamiento());

        // -------------------------------------------------------------------------------------------------------------

        //Creamos una segunda colada. Hay que incializarla con una prenda, es el pantalon2
        ColadaSecado coladaSecado = new ColadaSecado(60,  800, 100, EstadoPrenda.SUCIO, pantalon2,
                40, lavadoraSecadora);
        // Asociamos otras prendas a la segunda colada Normal a través de un estado
        Estado estadoColada1Jersey2 = new Estado(EstadoPrenda.MUY_SUCIO, coladaSecado, jersey2);
        Estado estadoColada1Camiseta2 = new Estado(EstadoPrenda.SUCIO, coladaSecado, camiseta2);
        coladaSecado.setInicioC(5);
        coladaSecado.setInicioS(8);
        System.out.println("\nLavadora Secadora: " + lavadoraSecadora.getMarca());
        System.out.println("  - Colada 2:");
        System.out.println("    - Peso total: " + coladaSecado.getPeso() + " gramos");
        System.out.println("    - Cantidad de detergente: " + coladaSecado.getCantDetergente() + " ml");
        System.out.println("    - ¿Está en funcionamiento?:" + lavadoraSecadora.enFuncionamiento());
        // Se limpia la ropa
        coladaSecado.concluyeColada(12);

        System.out.println("    - La ropa se ha limpiado y la colada ha terminado");
        System.out.println("    - ¿Está en funcionamiento?:" + lavadoraSecadora.enFuncionamiento());

        System.out.println("\nDetalles de las Prendas:");
        System.out.println("  - Jersey 1 (Colada 1): " + jersey1.getTipo() + ", " + jersey1.getPeso() + "g");
        System.out.println("  - Pantalón 1 (Colada 1): " + pantalon1.getTipo() + ", " + pantalon1.getPeso() + "g");
        System.out.println("  - Camiseta 1 (Colada 1): " + camiseta1.getTipo() + ", " + camiseta1.getPeso() + "g");
        System.out.println("  - Jersey 2 (Colada 2): " + jersey2.getTipo() + ", " + jersey2.getPeso() + "g");
        System.out.println("  - Pantalón 2 (Colada 2): " + pantalon2.getTipo() + ", " + pantalon2.getPeso() + "g");
        System.out.println("  - Camiseta 2 (Colada 2): " + camiseta2.getTipo() + ", " + camiseta2.getPeso() + "g");
    }
}
