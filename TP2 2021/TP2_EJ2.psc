Algoritmo TIPOS_BOMBAS_EJ2
	//Reescribe el programa anterior usando condicionales SI (es decir, en
	//lugar de según nos basaremos exclusivamente en SI).
	Definir bomba Como Entero
	
Escribir "Observe el menú y digite el número que corresponde al tipo de bomba que desea utilizar"
Escribir " 1. Bomba de agua"
Escribir " 2. Bomba de gasolina"
Escribir " 3. Bomba de hormigon"
Escribir " 4. Bomba de pasta alimenticia"
Leer bomba

Si (bomba <1 o bomba > 4) Entonces 
	 Escribir " No existe valor definido para el tipo de bomba o ha introducido un dato inválido"; 
SiNo
	Si ( bomba ==1)
		Escribir "La bomba es una bomba de agua";
	Sino
		Si ( bomba ==2)
			Escribir "La bomba es una bomba de gasolina";
		SiNo
			Si ( bomba ==3)
			    Escribir " La bomba es una bomba de hormigón"
			SiNo
		        Escribir " La bomba es una bomba de pasta alimenticia"
			FinSi
		FinSi
	FinSi
Finsi
FinAlgoritmo