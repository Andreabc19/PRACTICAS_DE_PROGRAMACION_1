Algoritmo CONVERSIONES_ENTRE_MONEDAS
	//Hacer un programa que realice conversiones entre monedas (buscar
//conversiones en Internet). Utilizar un menú como el que sigue:
	//1. Pesos argentinos a dólar.
	// 2. Pesos argentinas a Peso chileno.
	// 3. Pesos argentinos a Libras esterlinas.
	// 4. Pesos argentinos a Sol Peruano.
	// 5. Pesos argentinos a Yuan.
	// 6. Salir
	Definir conversion Como Entero;
	Definir moneda como real
	Definir peso_arg Como Real;
	Definir peso_chileno Como Real;
	Definir dolar Como Real;
	Definir libras_esterlinas Como Real;
	Definir Sol_peruano Como Real;
	Definir yuan Como Real;
	
	Escribir "Bienvenido al programa de conversión de monedas"
	Escribir "**************************************************"
	Escribir "¿A qué moneda quiere convertir el peso argentino?Digite un número del 1 al 5 según la moneda elegida"
	Escribir " 1- Dolares";
	Escribir " 2- Pesos Chilenos";
	Escribir " 3- Libras esterlinas";
	Escribir " 4- Soles Peruanos";
	Escribir " 5- Yuan";
	Escribir " Presione 6 para salir del programa";
	Leer moneda
	
	Escribir " Ingrese el monto en pesos argentinos que desea convertir. (Ej: 500, 1000, 100)"
	Leer peso_arg
	
	factor_conversion_dolar= 0.0109;
	factor_conversion_peso_chileno=7.89;
	factor_conversion_libras_esterlinas=0.0079;
	factor_conversion_soles_peruanos=0.041;
	factor_conversion_yuan=0.072;
	
	Segun moneda Hacer
		Caso 1:
			resultado= peso_arg * factor_conversion_dolar;
			Escribir peso_arg "ARS  es/son en total:" resultado "dolares"
		Caso 2:
			resultado= peso_arg * factor_conversion_peso_chileno;
			Escribir peso_arg "ARS  es/son en total:" resultado "pesos chilenos" ;
		Caso 3:
			resultado= peso_arg * factor_conversion_libras_esterlinas;
			Escribir peso_arg "ARS  es/son en total:" resultado "libras esterlinas"
		Caso 4:
			resultado= peso_arg * factor_conversion_soles_peruanos;
			Escribir peso_arg "ARS  es/son en total:" resultado "Soles Peruanos"
		Caso 5:
			resultado= peso_arg * factor_conversion_yuan;
			Escribir peso_arg "ARS  es/son en total:" resultado "Yuanes"
		Caso 6:
			Escribir " Saliendo...aguarde unos instantes"
		De Otro Modo:
			Escribir "Opcion no valida" 
	Fin Segun
	
	
FinAlgoritmo
