Algoritmo RAIZ_DE_UN_NUMERO
	//Desarrolle un algoritmo que permita introducir dos números y mostrar la raíz del primer valor sobre el segundo.
	DEFINIR numero1 Como Real
	DEFINIR numero2 Como Real
	Escribir " Ingrese el numero que corresponde al indice ( no debe ser mayor a 3)"
	Leer numero1;
	Escribir " Ingrese el numero que corresponde al radicando"
	Leer numero2;
	resultado =numero2 ^(1/numero1)
	Escribir " La raiz de " numero2 "es" resultado; 
FinAlgoritmo
