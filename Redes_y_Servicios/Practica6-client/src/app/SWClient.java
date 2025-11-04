package es.uma.rys.app;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URLEncoder;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.net.http.HttpResponse.BodyHandlers;
import java.nio.charset.StandardCharsets;
import java.rmi.server.UID;
import java.util.ArrayList;

import com.google.gson.Gson;

import es.uma.rys.entities.ResourceCountResult ;
import es.uma.rys.entities.Movie;
import es.uma.rys.entities.QueryResponse;
import es.uma.rys.entities.Specie;
import es.uma.rys.entities.SpaceShip;
import es.uma.rys.entities.Vehicle;
import es.uma.rys.entities.World;
import es.uma.rys.entities.Person;

public class SWClient {
    private final String app_name = "Star Wars quiz";
    private final int year = 2025;
    private final String url_api = "https://swapi.py4e.com/api/";

    // Métodos auxiliares

    // Obtiene la URL del recurso id del tipo resource
	public String generateEndpoint(String resource, Integer id){
	    return url_api + resource + "/" + id + "/";
	}

	// Dada una URL de un recurso obtiene su ID
	public Integer getIDFromURL(String url){
		String[] parts = url.split("/");

		return Integer.parseInt(parts[parts.length-1]);
	}

	// Consulta un recurso y devuelve cuántos elementos tiene
    public int getNumberOfResources(String resource) {
        String urlname = url_api + resource + "/";
        int number = 0;

        try {
            // Creamos un cliente HTTP
            HttpClient client = HttpClient.newBuilder()
                    .version(HttpClient.Version.HTTP_1_1)
                    .build();

            // Creamos una petición HTTP
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(new URI(urlname))
                    .header("User-Agent", app_name + "-" + year)
                    .header("Accept", "application/json")
                    .GET()
                    .build();

            // Enviamos la petición al cliente
            HttpResponse response = client.send(request, BodyHandlers.ofString());

            // Comprobamos que la respuesta es correcta => código 2xx
            if (response.statusCode() <= 199 || response.statusCode() >= 300 ) {
                System.out.println("La petición dio el error " + response.statusCode());
                return 0;
            }

            // Deserialice la respuesta
            Gson parser = new Gson();
            ResourceCountResult c = parser.fromJson(response.body().toString(), ResourceCountResult.class);
            number = c.count;

        } catch (Exception e) {
            System.err.println(e.getMessage());
            return 0;
        }

        return number;
    }

    public Person getPerson(String urlname) {
        Person p = null;
        try {
            // Cambiamos http por https para usar una comunicación cifrada
            urlname = urlname.replaceAll("http:", "https:");

            // Creamos un cliente HTTP
            HttpClient client = HttpClient.newBuilder()
                    .version(HttpClient.Version.HTTP_1_1)
                    .build();

            // Creamos una petición HTTP
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(new URI(urlname)) // URL a la que hacemos la petición
                    .header("User-Agent", app_name + "-" + year) // Cabeceras con información adicional
                    .header("Accept", "application/json") // Información adicional para respuesta por parte de la API
                    .GET() // Solicitamos el recurso al servidor(con información sobre los personajes de Star Wars)
                    .build();

            // Enviamos la petición al cliente
            HttpResponse response = client.send(request, BodyHandlers.ofString());

            // Comprobamos que la respuesta es correcta => código 2xx
            if (response.statusCode() <= 199 || response.statusCode() >= 300 ) {
                System.out.println("La petición dio el error " + response.statusCode());
                return null;
            }
            // Deserializamos la respuesta usando la clase Person
            Gson parser = new Gson();
            p = parser.fromJson(response.body().toString(), Person.class);


            urlname = p.homeworld; // Petición HTTP del planeta natal
            // Cambiamos http por https para usar una comunicación cifrada
            urlname = urlname.replaceAll("http:", "https:");

            // Creamos otra petición HTTP
            request = HttpRequest.newBuilder()
                    .uri(new URI(urlname))
                    .header("User-Agent", app_name + "-" + year)
                    .header("Accept", "application/json")
                    .GET()
                    .build();

            // Enviamos la petición al cliente
            response = client.send(request, BodyHandlers.ofString());

            // Analizamos el código de respuesta
            if (response.statusCode() <= 199 || response.statusCode() >= 300 ) {
                System.out.println("La petición dio el error " + response.statusCode());
                return null;
            }

            // Deserializamos la respuesta usando la clase World
            p.homeplanet = parser.fromJson(response.body().toString(), World.class); // String del planeta natal del personaje

        } catch (Exception e) {
            System.err.println(e.getMessage());
            return null;
        }
        return p;
    }

    public World getWorld(String urlname) {
        World p = null;

        try {
            // Cambiamos http por https para usar una comunicación cifrada
            urlname = urlname.replaceAll("http:", "https:");

            // Creamos un cliente HTTP
            HttpClient client = HttpClient.newBuilder()
                    .version(HttpClient.Version.HTTP_1_1)
                    .build();

            // Creamos una petición HTTP
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(new URI(urlname))
                    .header("User-Agent", app_name + "-" + year)
                    .header("Accept", "application/json")
                    .GET()
                    .build() ;

            // Envíamos la petición HTTP
            HttpResponse response = client.send(request, BodyHandlers.ofString());

            // Revisamos el código de confirmación
            if (response.statusCode() <= 199 || response.statusCode() >= 300 ) {
                System.out.println("La petición dio el error " + response.statusCode());
                return null;
            }

            Gson parser = new Gson();
            // Deserializamos la respuesta
            p = parser.fromJson((String) response.body(), World.class);

        } catch (Exception e) {
            System.err.println(e.getMessage());
            return null;
        }
        return p;
    }

    public Person searchPersonByName (String name) {
        Person p = null;

        try {
            // Creamos la URL del recurso que queremos consultar de la API
            String urlname = url_api + "people/?search=" + URLEncoder.encode(name, StandardCharsets.UTF_8);

            // Cambiamos http por https para usar una comunicación cifrada
            urlname = urlname.replaceAll("http:", "https:");

            // Creamos un cliente HTTP
            HttpClient client = HttpClient.newBuilder()
                    .version(HttpClient.Version.HTTP_1_1)
                    .build();

           // Creamos la petición HTTP
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(new URI(urlname))
                    .header("User-Agent", app_name + "-" + year)
                    .header("Accept", "application/json")
                    .GET()
                    .build();

            // Envíamos la petición
            HttpResponse response = client.send(request, BodyHandlers.ofString());

            // Comprobamos el código
            if (response.statusCode() <= 199 || response.statusCode() >= 300 ) {
                System.out.println("La petición dio el error " + response.statusCode());
                return null;
            }

            // Deserializamos la respuesta con la clase QueryResponse
            Gson parser = new Gson();
            QueryResponse queryResponse = parser.fromJson(response.body().toString(), QueryResponse.class);

            // Si hay 1 o más respuestas escogemos la primera
            if (queryResponse.count >= 1) {
                p = queryResponse.results[0];
            }

            // URL para hacer una petición HTTP del planeta natal del personaje
            urlname = p.homeworld; // Petición HTTP del planeta natal
            // Cambiamos http por https para usar una comunicación cifrada
            urlname = urlname.replaceAll("http:", "https:");

            // Creamos una nueva petición
            request = HttpRequest.newBuilder()
                    .uri(new URI(urlname))
                    .header("User-Agent", app_name + "-" + year)
                    .header("Accept", "application/json")
                    .GET()
                    .build();

            // Enviamos la petición
            response = client.send(request, BodyHandlers.ofString());

            // Verificamos el código
            if (response.statusCode() <= 199 || response.statusCode() >= 300 ) {
                System.out.println("La petición dio el error " + response.statusCode());
                return null;
            }

            // Asignamos a este personaje el mundo deserializando la respuesta con la clase World
            p.homeplanet = parser.fromJson(response.body().toString(), World.class); // String del planeta natal del personaje

        } catch (Exception e) {
            System.err.println(e.getMessage());
            return null;
        }
        return p;
    }

    public Movie getMovie(String urlname) {
        Movie movie = null;

        try {
            // Cambiamos http por https para usar una comunicación cifrada
            urlname = urlname.replaceAll("http:", "https:");

            // Creamos un cliente HTTP
            HttpClient client = HttpClient.newBuilder()
                    .version(HttpClient.Version.HTTP_1_1)
                    .build();

            // Creamos una petición HTTP
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(new URI(urlname))
                    .header("User-Agent", app_name + "-" + year)
                    .header("Accept", "application/json")
                    .GET()
                    .build();

            // Enviamos la petición al cliente
            HttpResponse response = client.send(request, BodyHandlers.ofString());

            // Comprobamos que la respuesta es correcta => código 2xx
            if (response.statusCode() <= 199 || response.statusCode() >= 300 ) {
                System.out.println("La petición dio el error " + response.statusCode());
                return null;
            }

            // Deserialice la respuesta usando la clase Movie
            Gson parser = new Gson();
            movie = parser.fromJson(response.body().toString(), Movie.class);

        } catch (Exception e) {
            System.err.println(e.getMessage());
            return null;
        }
        return movie;
    }
}
