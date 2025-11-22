package ej2;

public class Verde extends Estado{
    private static Verde verde;

    private Verde() {
        // Constructor privado
    }
    // Patron Singleton
    static Verde verde() {
        if (verde == null) {
            verde = new Verde();
        }
        return verde;
    }
    // Ahora la estrategia(ej2) se ocupa de abrir y cerrar en los estados rojo, amarillo y verde
    @Override
    void abrir(Dispositivo dispositivo) {
        assert (dispositivo != null);
        throw new RuntimeException("No puedes abrir un dispositivo con estado Verde");
    }

    @Override
    void cerrar(Dispositivo dispositivo) {
        assert (dispositivo != null);
        dispositivo.getEstrategia().cerrar(this ,dispositivo);
    }

    @Override
    String estado(Dispositivo dispositivo) {
        assert (dispositivo != null);
        return "abierto";
    }
}
