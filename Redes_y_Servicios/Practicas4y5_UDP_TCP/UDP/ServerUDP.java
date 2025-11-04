package UDP;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.nio.charset.StandardCharsets;

public class ServerUDP {
    public static void main(String[] args) throws IOException {
        // Reservar el puerto y crear las colas correspondientes
        //int port = 54322; // Puerto laboratorio
        int port = 2000; // Ejemplo profe

        // Versión lectura del puerto por argumentos
        /**port = Integer.parseInt(args[0]);*/

        // Comprobación y creación del socket
        DatagramSocket server_socket = null;

        try {
            server_socket = new DatagramSocket(port);
        } catch (SocketException e) {
            System.err.println("Error:" + e.getMessage());
            System.exit(1);
        } catch (IllegalArgumentException e) {
            System.out.println("Puerto fuera del rango: " + port);
            System.err.println("Error: " + e.getMessage());
        }
        System.out.println("Puerto asignado al servidor: " + port);

        // Un DatagramPacket vacío para la recepción con el tamaño máximo y un array de bytes
        int tam = 1000;
        byte [] buffer = null;

        while (true) {
            buffer = new byte[tam];
            System.out.println();
            System.out.println("Espernado un datagrama del cliente...");
            DatagramPacket dp = new DatagramPacket(
                    buffer, // zona de memoria
                    tam // tamaño de esa zona de memoria
            );
            System.out.println();

            // Recibir un mensaje de Client
            server_socket.receive(dp);

            // Captura del mensaje recibido
            System.out.println("Mensaje recibido de " + dp.getAddress() + ":" + dp.getPort());
            String texto = new String(
                    dp.getData(),
                    dp.getOffset(),
                    dp.getLength(),
                    StandardCharsets.UTF_8
            );
            System.out.println("El mensaje recibido es: " + texto);

            // Enviar respuesta a Client
            // Cifrado césar
            StringBuilder mensaje_respuesta = new StringBuilder();
            int CIFRADO = Character.getNumericValue(texto.charAt(0));
            for (int i = 1; i < texto.length(); i++) {
                char c = texto.charAt(i);
                if (Character.isLowerCase(texto.charAt(i))) {
                    char c_cifrado = (char) ((c - 'a' + CIFRADO) % 26 + 'a');
                    mensaje_respuesta.append(c_cifrado);
                } else {
                    mensaje_respuesta.append(c);
                }
            }

            // Preparación del datagrama packet con el mensaje de respuesta
            DatagramPacket dp_send = new DatagramPacket(
                    mensaje_respuesta.toString().getBytes(StandardCharsets.UTF_8),
                    mensaje_respuesta.toString().getBytes(StandardCharsets.UTF_8).length,
                    dp.getAddress(), // Dirección del emisor anterior(ahora receptor de este mensaje)
                    dp.getPort()    // Puerto del emisor anterior(ahora receptor de este mensaje)
            );

            // Mensajes de control
            System.out.println();
            System.out.println("Enviando el mensaje:" + mensaje_respuesta);
            server_socket.send(dp_send);
            System.out.println("El mensaje de respuesta se ha enviado");
        }
    }
}