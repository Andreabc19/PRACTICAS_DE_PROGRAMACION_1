Algoritmo Tablas_Multiplicar 
//1. Desarrollar un algoritmo que imprima la tabla de multiplicar de los
//	n�meros del uno diez.
	
	definir resultado, prod1, prod2 Como Entero
	escribir "A continuaci�n se muestran las tablas de multiplicar del 1 al 10"
	
	Para prod1<-1 Hasta 10 Con Paso 1 Hacer
		escribir "************" "TABLA DEL: " prod1 "*********"
		Para prod2<-1 Hasta 10 Con Paso 1 Hacer
		resultado=prod1*prod2
		Escribir prod1 "x" prod2 "=" resultado
	FinPara
	
	Fin Para
		
FinAlgoritmo
