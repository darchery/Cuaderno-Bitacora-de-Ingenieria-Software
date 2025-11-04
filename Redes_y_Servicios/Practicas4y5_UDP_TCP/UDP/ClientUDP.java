package UDP;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class ClientUDP {
    public static void main(String[] args) throws IOException {
        // Reservar un puerto efímero (cualquier libre) y crear las colas:
        // int server_port = 54322; // Puerto del laboratorio
        // Valores predeterminados
        int server_port = 2000; // Ejemplo profe
        String server_IP = "127.0.0.1";

        // Lectura de IP y puerto por consola
        /** Scanner sc = new Scanner(System.in);
        System.out.println("Escriba el la IP y el puerto al que quiere enviar separados por un esapcio:");
        server_IP = sc.next();
        server_port = Integer.parseInt(sc.next());*/
        // Versión lectura de IP y puerto por argumentos
        /**server_IP = args[0];
        server_port = Integer.parseInt(args[1]);*/

        // Creación del socket
        DatagramSocket client_socket = null;

        try {
            client_socket = new DatagramSocket();
        } catch (SocketException e) {
            System.err.println(e.getMessage());
            System.exit(1);
        }
        System.out.println("Puerto asignado al cliente: " + client_socket.getLocalPort());
        System.out.println();

        // Enviar un mensaje a Server
        // Lectura del mensaje
        Scanner scanner = new Scanner(System.in, StandardCharsets.UTF_8.name());
        System.out.print("Escriba un mensaje: ");
        String mensaje = scanner.nextLine();

        // Verificamos que empiece por un dígito
        while(Character.isDigit(mensaje.charAt(0))) {
            // Preparamos el datagrama para enviar nuestro mensaje
            DatagramPacket dp = new DatagramPacket(
                    mensaje.getBytes(StandardCharsets.UTF_8), // la zona de memoria con los datos
                    mensaje.getBytes(StandardCharsets.UTF_8).length, // Tamaño de esos datos
                    //InetAddress.getByName("192.168.132.57"),
                    InetAddress.getByName(server_IP), // Dirección del servidor (InetAddress)  => Ejemplo profe
                    server_port // puerto
            );

            // Mensajes de contexto de envío y espera
            System.out.println();
            System.out.println("Enviando el mensaje:" + mensaje);
            client_socket.send(dp);
            System.out.println("El mensaje se ha enviado");
            System.out.println();
            System.out.println("Conectado a " + InetAddress.getByName(server_IP) + ":" + server_port + ", Esperando la respuesta....");
            System.out.println();

            // Recibir respuesta de Server
            int tam = 1000;
            byte [] buffer = new byte[tam];
            // "Recipiente" para recibir el datagrama del servidor
            DatagramPacket dp_receive = new DatagramPacket(buffer, buffer.length);
            client_socket.receive(dp_receive);

            // Capturamos y enseñamos el mensaje por consola
            System.out.println("Respuesta recibida de " + dp_receive.getAddress() + ":" + dp_receive.getPort());
            String mensaje_recibido = new String(
                    dp_receive.getData(),
                    dp_receive.getOffset(),
                    dp_receive.getLength(),
                    StandardCharsets.UTF_8
            );

            // Mensajes de control
            System.out.println("El mensaje de respuesta recibido es: " + mensaje_recibido);
            System.out.println();
            System.out.print("Escriba un mensaje: ");
            mensaje = scanner.nextLine();
        }

        System.out.println();
        System.out.println("Liberando los recursos...");
        client_socket.close();
    }
}