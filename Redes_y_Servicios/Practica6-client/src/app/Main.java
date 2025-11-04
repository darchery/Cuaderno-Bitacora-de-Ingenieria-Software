package es.uma.rys.app;

import java.text.SimpleDateFormat;
import java.util.*;

import es.uma.rys.entities.Movie;
import es.uma.rys.entities.Person;
import es.uma.rys.entities.World;

public class Main {	
	private static Random rand; // para números aleatorios
	private static Scanner sc; // para leer de teclado
	private final static String proxy = "proxy.lcc.uma.es";
	private final static String proxy_port = "3128";
	
	private static String [] acierto = {"Ese es el camino", 
										"Eres uno con la Fuerza. La Fuerza esté contigo",
										"Que la fuerza te acompañe",
										"Nada ocurre por accidente",
										"Sin duda, maravillosa tu mente es",
										"Cuando te fuiste, no era más que el aprendiz. Ahora eres el maestro",
										"La Fuerza te está llamando, déjala entrar",
										"Tu cantidad de midiclorianos debe ser muy alta",
										"Una lección aprendida es una lección ganada",
										"Debes creer en ti mismo o nadie lo hará",
										"El camino a la sabiduria es sencillo para aquellos que no se dejan cegar por el ego" };
	private static String [] fracaso = {"El mejor profesor, el fracaso es.",
										"El miedo es el camino hacia el Lado Oscuro. El miedo lleva a la ira, la ira lleva al odio, el odio lleva al sufrimiento. Percibo mucho miedo en ti",
										"Tu carencia de fe resulta molesta",
										"La capacidad de hablar no te hace inteligente",
										"Concéntrate en el momento. Siente, no pienses, usa tu instinto",
										"No lo intentes. Hazlo, o no lo hagas, pero no lo intentes",
										"Paciencia, utiliza la Fuerza. Piensa",
										"Siento una perturbación en la fuerza",
										"El lado oscurso se intensifica en ti",
										"El primer paso para corregir un error es la paciencia",
										"El exceso de confianza es el mas peligroso de los descuidos",
										"El camino de la ignorancia es guiado por el miedo" };

    public static void main(String[] args) {
    	
    	// Descomente las siguiente líneas si lo está probando en el laboratorio y accede a Internet usando el proxy
    	// System.setProperty("https.proxyHost",proxy);
    	// System.setProperty("https.proxyPort",proxy_port);
	
        SWClient sw = new SWClient();
        String respuesta = null;
    	rand = new Random();
        sc = new Scanner(System.in);

        do{
			whenBorn(sw); // Pregunta de 4 opciones
			oldestFilm(sw); // Pregunta de 50/50

        	tallest(sw);
        	whoBornIn1(sw);
        	whoBornIn2(sw);
	       	System.out.println("Desea otra ronda (s/n)?");
	       	respuesta = sc.nextLine();
	    }while(respuesta.equals("s"));
        sc.close();
        
    }
    
    // Genera un número entre 0 y max-1 que no haya sido usado previamente (los usados vienen en l)
    public static Integer getRandomResource(int max, List<Integer> l){
    	if(max == l.size()) return null;

    	Integer p = rand.nextInt(max);
    	while(l.contains(p)){
    		p = (p+1)%max;
    	}
    	return p;
    }
    
    // Pregunta que obtiene dos recursos iguales (personajes en este caso) y los compara
    public static void tallest(SWClient sw){
    	// Obteniendo la cantidad de gente almacenada
    	int max_people = sw.getNumberOfResources("people");
    	if(max_people == 0){
    		System.out.println("No se encontraron personas.");
    		return;
    	}
    	
    	System.out.println("Generando nueva pregunta...");
    	// Cogiendo dos personas al azar sin repetir
        List<Integer> used = new ArrayList<Integer>();
    	List<Person> people = new ArrayList<Person>();
    	int contador = 0;
    	while(contador < 2){
    		Integer p = getRandomResource(max_people, used);
    		Person person = sw.getPerson(sw.generateEndpoint("people", p));
    		if(person == null){
    			System.out.println("Hubo un error al encontrar el recurso " + p);
    		} else {
    			try {
    				Double test = Double.parseDouble(person.height);
					people.add(person);
					contador++;
				}catch (Exception e){
    				continue;
				}
    		}
    		used.add(p);
    	}
    	
    	// Escribiendo la pregunta y leyendo la opción
    	Integer n = null;
    	do{
    		System.out.println("¿Quién es más alto? [0] "+ people.get(0).name + " o [1] " + people.get(1).name);
    		try{
    			n = Integer.parseInt(sc.nextLine());
    		}catch(NumberFormatException ex){
    			n = -1;
    		}
    	}while(n != 0 && n != 1);
    	
    	// Mostrando la información de los personajes elegidos
    	for(Person p: people){
    		System.out.println(p.name + " mide " + p.height);
    	}
    	
    	// Resultado
    	if(Double.parseDouble(people.get(n).height) >= Double.parseDouble(people.get((n+1)%2).height)){
    		System.out.println("Enhorabuena!!! "+ acierto[rand.nextInt(acierto.length)]);
    	} else {
    		System.out.println("Fallaste :( " + fracaso[rand.nextInt(fracaso.length)]);
    	}
    }
    
    // Pregunta que relaciona varios recursos:
    // - Elige un recurso (planeta en este caso)
    // - Pregunta sobre algún recurso relacionado (persona que nació o fue crear ahí)
    // - Busca ese recurso y comprueba si está relacionado con el primero (si la persona buscada tiene como
	//   planeta el original)
    public static void whoBornIn1(SWClient sw){
    	// Obteniendo la cantidad de planetas
    	int max_planet = sw.getNumberOfResources("planets");
    	if(max_planet == 0){
    		System.out.println("No se encontraron planetas.");
    		return;
    	}
    	
    	System.out.println("Generando nueva pregunta...");
    	// Obteniendo el planeta (que tenga personas)
        List<Integer> used = new ArrayList<Integer>();
        World planet = null;
        do{
        	Integer p = getRandomResource(max_planet, used);
        	planet = sw.getWorld(sw.generateEndpoint("planets", p));
    		if(planet == null){
    			System.out.println("Hubo un error al encontrar el recurso " + p);
    		}
        	used.add(p);
        }while(planet == null || planet.residents == null || planet.residents.length < 1 || planet.name.equals("unknown"));

        // Planteamos la pregunta
        String s = null;
   		System.out.println("¿Quién nació o fue creado en " + planet.name + "?");
   		s = sc.nextLine();
   		// Buscamos la persona indicada
   		Person p = sw.searchPersonByName(s);
   		
   		// Validamos la respuesta y mostramos sus datos
   		if(p == null){
   			System.out.println("No hay nadie con ese nombre");
   		} else {
   			System.out.println(p.name + " nació en " + p.homeplanet.name);
   		}
   		
   		// Resultados
   		if(p != null && p.homeplanet.name.equals(planet.name)){
    		System.out.println("Enhorabuena!!! "+ acierto[rand.nextInt(acierto.length)]);
    	} else {
    		System.out.println("Fallaste :( " + fracaso[rand.nextInt(fracaso.length)]);
    	}
    }
    
    // Similar a la previa pero en vez de solicitar que escriba se le ofrecen alternativa para ello:
    // - Se elige una al azar de las disponibles en el recurso, persona del planeta (la correcta)
    // - Se buscar aleatoriamente otras 3 que no estén relacionados con el recurso (las incorrectas)
    // - Se inserta la correcta de forma aleatoria
    public static void whoBornIn2(SWClient sw){
    	
    	// Obteniendo la cantidad de planetas y personas
    	int max_people = sw.getNumberOfResources("people");
    	int max_planet = sw.getNumberOfResources("planets");
    	if(max_people == 0 || max_planet == 0){
    		System.out.println("No se encontraron personas o planetas.");
    		return;
    	}
    	
    	System.out.println("Generando nueva pregunta...");
    	// Obteniendo el planeta (con personas)
        List<Integer> used = new ArrayList<Integer>();
        World planet = null;
        do{
        	Integer p = getRandomResource(max_planet, used);
        	planet = sw.getWorld(sw.generateEndpoint("planets", p));
    		if(planet == null){
    			System.out.println("Hubo un error al encontrar el recurso " + p);
    		}
        	used.add(p);
        }while(planet == null || planet.residents == null || planet.residents.length < 1 || planet.name.equals("unknown"));
        used.clear();
        // Cogemos uno al azar como acierto
        String [] residents = planet.residents;
        Person correcta = sw.getPerson(residents[rand.nextInt(residents.length)]);
        // Metemos todas las personas del planeta como usados para que no se seleccionen
        for(String s: residents){
        	used.add(sw.getIDFromURL(s));
        }
        
        // Buscamos 3 más
        List<Person> people = new ArrayList<Person>();
        int contador = 0;
    	while(contador < 3){
    		Integer p = getRandomResource(max_people, used);
    		Person person = sw.getPerson(sw.generateEndpoint("people", p));
    		if(person == null){
    			System.out.println("Hubo un error al encontrar el recurso " + p);
    		} else {
    			people.add(person);
    			contador++;
    		}
    		used.add(p);
    	}
    	// Metemos el correcto de forma aleatoria
    	int pos_acierto = rand.nextInt(4);
    	people.add(pos_acierto, correcta);
    	
    	// Leemos la opci�n
    	Integer n = null;
    	do{
    		System.out.print("¿Quién nació o fue fabricado en "+planet.name +"?");
    		for(int i = 0; i < 4; i++){
    			System.out.print(" ["+i+"] "+ people.get(i).name);
    		}
    		System.out.println();
    		try{
    			n = Integer.parseInt(sc.nextLine());
    		}catch(NumberFormatException ex){
    			n = -1;
    		}
    	}while(n < 0 || n > 3);
    	
    	// Se muestran los resultados    	
    	for(Person p: people){
    		System.out.println(p.name + " nació en " + p.homeplanet.name);
    	}
    	
    	// Resultados
    	if(n == pos_acierto){
    		System.out.println("Enhorabuena!!! "+ acierto[rand.nextInt(acierto.length)]);
    	} else {
    		System.out.println("Fallaste :( " + fracaso[rand.nextInt(fracaso.length)]);
    	}
    }


	/**
	 * MIS PREGUNTAS */
	// Pregunta que obtiene dos películas y compara la fecha de estreno, teniendo que elegir la más antigua
	public static void oldestFilm(SWClient sw){
		// Obteniendo la cantidad de películas almacenadas
		int max_films = sw.getNumberOfResources("films");
		if(max_films == 0){
			System.out.println("No se encontraron películas.");
			return;
		}

		System.out.println("Generando nueva pregunta...");

		List<Integer> used = new ArrayList<Integer>();
		List<Movie> movies = new ArrayList<Movie>();
		int contador = 0;

		// Cogemos dos personas al azar sin repetir(gracias a getRandomResource)
		while(contador < 2){
			Integer p = getRandomResource(max_films, used);
			Movie movie = sw.getMovie(sw.generateEndpoint("films", p));

			if(movie == null){
				System.out.println("Hubo un error al encontrar el recurso " + p);
			} else {
				try {
					Date date = movie.release_date;
					movies.add(movie);
					contador++;
				}catch (Exception e){
					continue;
				}
			}
			used.add(p);
		}

		// Escribiendo la pregunta y leyendo la opción
		Integer n = null;
		do{
			System.out.println("¿Qué película se estrenó primero? [0] "+ movies.get(0).title + " o [1] " + movies.get(1).title);
			try{
				n = Integer.parseInt(sc.nextLine());
			}catch(NumberFormatException ex){
				n = -1;
			}
		}while(n != 0 && n != 1);

		// Formato más "bonito" para la fecha
		SimpleDateFormat sdf = new SimpleDateFormat("d 'de' MMMM 'de' yyyy", new Locale("es", "ES"));

		// Mostrando la información de los personajes elegidos
		for (Movie movie : movies) {
			String fechaFormateada = sdf.format(movie.release_date);
			System.out.println(movie.title + " se estrenó el " + fechaFormateada);
		}

		// Resultado => Comparamos el año de salida de cada película
		if(movies.get(n).release_date.getYear() <= movies.get((n+1)%2).release_date.getYear()){
			System.out.println("Enhorabuena!!! "+ acierto[rand.nextInt(acierto.length)]);
		} else {
			System.out.println("Fallaste :( " + fracaso[rand.nextInt(fracaso.length)]);
		}
	}

	/**
	 * 1. Elijo 4 personajes aleatoriamente
	 * 2. Escojo uno como correcto
	 * 3. Barajo la lista de personas
	 * 4. Usuario responde*/
	public static void whenBorn(SWClient sw){

		// Obteniendo la cantidad de personas
		int max_people = sw.getNumberOfResources("people");
		if(max_people == 0){
			System.out.println("No se encontraron personas.");
			return;
		}

		System.out.println("Generando nueva pregunta...");
		// Estructuras de datos usadas
		List<Integer> used = new ArrayList<Integer>();
		List<Person> people = new ArrayList<Person>();
		Person person = null;
		int contador = 0;

		// Elegimos 4 al azar sin repetir
		while (contador < 4) {
			Integer p = getRandomResource(max_people, used);
			person = sw.getPerson(sw.generateEndpoint("people", p));

			if (person == null) {
				System.out.println("Hubo un error al encontrar el recurso " + p);
			} else {
				try {
					String test = person.birth_year;
					people.add(person);
					contador++;
				} catch (Exception e) {
					continue;
				}
			}
			used.add(p);
		}

		// Cogemos uno al azar como acierto
		Person correcta = people.get(rand.nextInt(4));

		// Barajamos la lista de personas
		Collections.shuffle(people);

		// Escribimos la pregunta y leemos la opción del usuario
		Integer n = null;
		do{
			System.out.print("¿Quién nació en el año "+ person.birth_year +"?");
			for(int i = 0; i < 4; i++){
				System.out.print(" ["+i+"] "+ people.get(i).name);
			}
			System.out.println();
			try{
				n = Integer.parseInt(sc.nextLine());
			}catch(NumberFormatException ex){
				n = -1;
			}
		}while(n < 0 || n > 3);

		// Se muestran los resultados
		for(Person p: people){
			System.out.println(p.name + " nació en el año " + p.birth_year);
		}

		// Resultados => Si la fecha del personaje elegido es la misma que la del personaje correcto => Acierto
		if(people.get(n).birth_year.equals(correcta.birth_year)){
			System.out.println("Enhorabuena!!! "+ acierto[rand.nextInt(acierto.length)]);
		} else {
			System.out.println("Fallaste :( " + fracaso[rand.nextInt(fracaso.length)]);
		}
	}

}
