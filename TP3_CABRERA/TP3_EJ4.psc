Algoritmo  calculadora 
	
	definir  n1 Como entero
	definir  n2   Como entero
	definir  op como real
	definir  suma , resta, division, multiplicacion, potencia, respuesta Como real
	Escribir  "calculadora"
	escribir  "elija la opcion que necesite"
	escribir  "(1) suma"
	escribir  "(2) resta"
	escribir  "(3) multiplicacion"
	escribir  "(4) división"
	escribir  "(5) potencia"
	leer  op
	
	Repetir
		Segun  op Hacer
			1 :  Escribir  "selecciono suma"
				escribir  "ingrese primer numero"
				leer  n1
				escribir  "ingrese segundo numero"
				leer  n2
				suma = n1 + n2
				escribir  "el resultado es"  suma
				escribir  "desea (1) continuar o (2) finalizar el ejercicio"
				leer  respuesta
				
				
				
				
				
			2 :
				escribir  "selecciono resta"
				escribir  "ingrese primer numero"
				leer  n1
				escribir  "ingrese segundo numero"
				leer  n2
				resta = n1 - n2
				escribir  "el resultado es"  resta 
				escribir  "desea (1) continuar o (2) finalizar el ejercicio"
				leer  respuesta
				
				
			3 :
				escribir  "selecciono multiplicacion"
				escribir  "ingrese primer numero"
				leer  n1
				escribir  "ingrese segundo numero"
				leer  n2
				multiplicacion = n1 * n2
				escribir  "el resultado es"  multiplicacion
				escribir  "desea (1) continuar o (2) finalizar el ejercicio"
				leer  respuesta
				
				
				
			4 :
				escribir  "selecciono division"
				escribir  "ingrese primer numero"
				leer  n1
				escribir  "ingrese segundo numero"
				leer  n2
				división = n1 / n2
				escribir división "el resultado es" 
				escribir  "desea (1) continuar o (2) finalizar el ejercicio"
				leer  respuesta
				
				
				
			5 :
				escribir  "selecciono potencia"
				escribir  "ingrese numero base"
				leer  n1
				escribir  "ingrese numero exponente"
				leer  n2
				potencia =  n1 ^ n2
				escribir "el resultado es"  potencia
				escribir  "desea (1) continuar o (2) finalizar el ejercicio"
				leer  respuesta
				
				
				
			De  Otro Modo:
				Escribir  "la opcion ingresada es incorrecta"
		FinSegun
	Hasta Que  opcion_salir == 1
FinAlgoritmo
