package TCP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.Objects;

class ServerTCP {
    private static final String FINAL_MENSSAGE = "FINAL_MENSSAGE";
    private static final String FINAL_MENSSAGE_OK = "FINAL_MENSSAGE_OK";

    public static String extract_text(String texto){
        String resultado = "";
        // Extraer el dígito al inicio del texto
        int lengthThreshold = Character.getNumericValue(texto.charAt(0));

        // Extraer el resto del texto
        texto = texto.substring(1).trim();

        // Dividir el texto en palabras
        String[] words = texto.split("\\s+");

        // Construir la salida con las palabras que tienen una longitud mayor al dígito inicial
        for (String word : words) {
            if (word.length() > lengthThreshold) {
                resultado += word + " ";
            }
        }

        resultado = resultado.trim();

        return resultado;
    }

    public static void main(String[] args) throws IOException {
        // Puerto por el que recibo peticiones
        int port = 12000; // int port = Integer.parseInt(args[0]);

        // Versión que toma el puerto del argumento
        /**port = Integer.parseInt(args[0]);*/

        // Creación y prearación del server socket
        ServerSocket server = null; // Pasivo (recepción de peticiones)
        try {
            server = new ServerSocket(port, 1);
        } catch (IOException e) { // Posible error en la creación de este
            System.out.println("Error: No se pudo crear un socket para escuchar en el puerto " + port);
            System.out.println(e.getMessage());
            System.exit(-1);
        }
        System.out.println("Puerto asignado al servidor: " + port);

        while(true){ // Bucle de recepción de cliente
            // Espera a los clientes y avisa sobre su conexión
            System.out.println();
            System.out.println("Esperando a los clientes");
            System.out.println();
            Socket client = server.accept(); // Sacamos un cliente de la cola de clientes
            System.out.println("Cliente conectado: " + client.getInetAddress() + ":" + client.getPort());
            System.out.println();

            // FLUJOS PARA EL ENVÍO Y RECEPCIÓN
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(client.getInputStream(), StandardCharsets.UTF_8)
            );
            PrintWriter out = new PrintWriter(client.getOutputStream(), true, StandardCharsets.UTF_8);

            boolean salir = false;
            // Mientras no se haya recibido el mensaje de salida/cliente se haya desconectado
            while(!salir){
                try {
                    // Leemos el mensaje del cliente
                    String mensaje_recibido = in.readLine();
                    System.out.println("Recibido: " + mensaje_recibido);

                    // Si es el mensaje final => Enviamos la confirmación OK
                    if (Objects.equals(mensaje_recibido, FINAL_MENSSAGE)) {
                        out.println(FINAL_MENSSAGE_OK);
                        salir = true;
                        System.out.println("Mensaje enviado: " + FINAL_MENSSAGE_OK);
                        System.out.println("Cliente desconectado: " + client.getInetAddress() + ":" + client.getPort());
                    } else {
                        // Modificar o tratar => Ciframos el mensaje con el cifrado césar
                        StringBuilder mensaje_respuesta = new StringBuilder();
                        int CIFRADO = Character.getNumericValue(mensaje_recibido.charAt(0));
                        for (int i = 1; i < mensaje_recibido.length(); i++) {
                            char c = mensaje_recibido.charAt(i);
                            char base = 'a';
                            if (Character.isLowerCase(c)) {
                                mensaje_respuesta.append((char) (( c - base + CIFRADO) % 26 + base));
                            } else {
                                mensaje_respuesta.append(c);
                            }
                        }

                        // Envíamos nuestra respuesta al servidor con .out
                        out.println(mensaje_respuesta.toString());
                        System.out.println("Mensaje enviado: " + mensaje_respuesta.toString());
                        System.out.println();
                    }
                } catch (IOException e) { // Capturamos la posible desconexión del cliente
                    System.out.println("El cliente " + client.getInetAddress() + ":" + client.getPort() + " se ha desconectado");
                    // System.err.println("Error: " + e.getMessage());
                    salir = true;
                }
            }
            // Liberamos los recursos
            System.out.println("Liberando los recursos...");
            in.close();
            out.close();
            client.close();
            server.close();
        }
    } // fin del metodo
}
