package TCP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class ClientTCP {
    private static final String FINAL_MENSSAGE = "FINAL_MENSSAGE";

    public static void main(String[] args) throws IOException {
        // TAREA 1
        boolean fin = false;
        Socket socket = null;
        // Dirección IP y puerto usado
        String IP = "127.0.0.1";
        int port = 12000;

        // Versión que recoge la dirección y el puerto por el argumento
        /**IP = args[0];
        port = Integer.parseInt(args[1]);*/

        // Creación del socket para enviar y recibir mensajes
        try {
            socket = new Socket(IP, port); // Mío
            // socket = new Socket("192.168.134.170", 12345); // Servidor laboratorio
        } catch (IOException e){ // Posible error en la creación
            System.out.println("Error: No se pudo crear un socket para enviar a " + socket.getInetAddress() +  " con puerto " + socket.getPort());
            System.err.println(e.getMessage());
            System.exit(-1);
        }
        System.out.println("Puerto asignado al cliente: " + socket.getLocalPort());
        System.out.println();

        // Obtener flujos
        BufferedReader in = new BufferedReader(
                new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8)
        );
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true, StandardCharsets.UTF_8);

        // Preparación para leer de teclado
        Scanner sc = new Scanner(System.in, StandardCharsets.UTF_8.name());
        String mensaje_envio = null;

        while (!fin) {
            String mensaje_recibido_server = null;

            // enviar mensaje/nuevo intento
            System.out.print("Escriba un mensaje_envio: ");
            mensaje_envio = sc.nextLine();

            // mientras que lo leído sea correcto => Se envía
            if (Character.isDigit(mensaje_envio.charAt(0))) {
                // Envío
                out.println(mensaje_envio);
                System.out.println("Mensaje enviado: " + mensaje_envio);
            }
            // lo leído es incorrecto => Se envía mensaje de finalización
            else {
                fin = true;
                // Enviar FINAL_MESSAGE
                out.println(FINAL_MENSSAGE);
                System.out.println("Mensaje enviado: " + FINAL_MENSSAGE);
            }
            // Esperando respuesta => En ambos casos esperamos su respuesta
            System.out.println();
            System.out.println("Conectado a " + IP + ":" + port + ", Esperando la respuesta....");

            // recibir respuesta
            System.out.println();
            mensaje_recibido_server = in.readLine();
            System.out.println("Recibido: " + mensaje_recibido_server);
            System.out.println();
        }

        // Finalizar y liberar recursos
        sc.close();
        in.close();
        out.close();
        socket.close();
    }
}
