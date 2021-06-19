//TP5 JUEGO: SUDOKU     PROGRAMACIÓN I      INTEGRANTES : DIEGO PERUZZI - ANDREA CABRERA
//LIBRERIAS
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int sudoku[9][9];// VARIABLES QUE NO VAN A CAMBIAR/SON FIJAS DURANTE TODO EL JUEGO
int tableroSudoku[9][9];
//  TABLEROS ALEATORIOS
int M0[9][9] = {{0, 7, 0, 4, 0, 0, 5, 0, 0}, {0, 1, 0, 3, 2, 0, 0, 8, 4}, {9, 0, 0, 0, 6, 1, 0, 0, 0}, {0, 0, 5, 0, 8, 0, 0, 2, 9}, {0, 2, 9, 7, 0, 5, 1, 6, 0}, {6, 8, 0, 0, 4, 0, 7, 0, 0}, {0, 0, 0, 8, 1, 0, 0, 0, 7}, {8, 0, 0, 0, 5, 4, 0, 3, 0}, {0, 0, 2, 0, 0, 3, 0, 4, 0}};
int M1[9][9] = {{0, 0, 8, 4, 7, 0, 3, 0, 6}, {0, 6, 0, 0, 0, 2, 0, 1, 0}, {2, 4, 0, 5, 0, 0, 0, 0, 8}, {0, 0, 9, 1, 5, 0, 4, 0, 3}, {0, 7, 0, 0, 0, 0, 0, 5, 0}, {5, 0, 4, 0, 8, 3, 2, 0, 0}, {7, 0, 0, 0, 0, 6, 0, 8, 5}, {0, 9, 0, 7, 0, 0, 0, 3, 0}, {6, 0, 2, 0, 9, 5, 1, 0, 0}};
int M2[9][9] = {{0, 2, 7, 4, 0, 5, 9, 6, 0}, {4, 9, 0, 2, 0, 6, 0, 5, 1}, {0, 0, 1, 0, 0, 0, 0, 7, 0}, {7, 0, 0, 0, 8, 0, 0, 0, 9}, {0, 0, 9, 0, 0, 0, 7, 0, 0}, {1, 0, 0, 0, 6, 0, 0, 0, 5}, {0, 7, 0, 0, 0, 0, 5, 0, 0}, {5, 1, 0, 6, 0, 7, 0, 3, 4}, {0, 4, 2, 8, 0, 3, 6, 1, 0}};
int M3[9][9] = {{7, 0, 8, 0, 3, 0, 0, 0, 6}, {0, 3, 0, 8, 0, 0, 1, 4, 0}, {0, 5, 0, 0, 4, 2, 0, 0, 9}, {0, 0, 7, 0, 2, 0, 0, 6, 0}, {5, 0, 2, 3, 0, 9, 8, 0, 4}, {0, 9, 0, 0, 7, 0, 5, 0, 0}, {8, 0, 0, 1, 9, 0, 0, 2, 0}, {0, 1, 6, 0, 0, 7, 0, 3, 0}, {3, 0, 0, 0, 8, 0, 7, 0, 1}};
int M4[9][9] = {{5, 0, 6, 0, 7, 8, 4, 0, 0}, {9, 0, 0, 0, 0, 0, 0, 2, 0}, {0, 2, 8, 0, 0, 4, 3, 6, 0}, {0, 0, 0, 1, 2, 0, 8, 5, 4}, {0, 0, 0, 9, 0, 3, 0, 0, 0}, {2, 5, 7, 0, 8, 6, 0, 0, 0}, {0, 1, 3, 6, 0, 0, 9, 8, 0}, {0, 4, 0, 0, 0, 0, 0, 0, 5}, {0, 0, 5, 8, 3, 0, 7, 0, 1}};
int M5[9][9] = {{5, 0, 0, 0, 8, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 7, 3, 8, 0}, {6, 0, 0, 0, 0, 2, 1, 7, 9}, {3, 7, 4, 0, 9, 0, 0, 0, 0}, {0, 0, 1, 2, 0, 8, 6, 0, 0}, {0, 0, 0, 0, 1, 0, 5, 9, 3}, {7, 9, 6, 3, 0, 0, 0, 0, 4}, {0, 4, 8, 6, 0, 5, 0, 0, 0}, {0, 0, 0, 0, 4, 0, 0, 0, 2}};
int M6[9][9] = {{0, 0, 0, 0, 9, 4, 7, 0, 0}, {0, 9, 1, 6, 0, 8, 0, 2, 0}, {4, 0, 0, 7, 3, 0, 5, 0, 6}, {0, 0, 0, 8, 0, 0, 1, 0, 5}, {1, 0, 6, 0, 0, 0, 2, 0, 9}, {3, 0, 4, 0, 0, 2, 0, 0, 0}, {5, 0, 2, 0, 8, 9, 0, 0, 3}, {0, 6, 0, 5, 0, 7, 4, 8, 0}, {0, 0, 7, 1, 6, 0, 0, 0, 0}};
int M7[9][9] = {{0, 0, 3, 1, 0, 4, 0, 5, 0}, {6, 8, 0, 3, 0, 0, 2, 7, 0}, {0, 5, 0, 7, 0, 2, 0, 0, 1}, {2, 0, 6, 0, 0, 0, 8, 1, 7}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {5, 4, 8, 0, 0, 0, 6, 0, 9}, {8, 0, 0, 9, 0, 1, 0, 2, 0}, {0, 7, 4, 0, 0, 3, 0, 6, 8}, {0, 3, 0, 6, 0, 8, 4, 0, 0}};
int M8[9][9] = {{0, 4, 0, 0, 0, 2, 3, 0, 8}, {0, 3, 1, 0, 6, 0, 0, 0, 0}, {7, 9, 0, 1, 8, 0, 0, 6, 0}, {1, 0, 4, 8, 0, 6, 0, 0, 9}, {0, 7, 0, 0, 0, 0, 0, 4, 0}, {9, 0, 0, 7, 0, 4, 5, 0, 2}, {0, 2, 0, 0, 3, 1, 0, 9, 6}, {0, 0, 0, 0, 4, 0, 1, 5, 0}, {3, 0, 5, 6, 0, 0, 0, 7, 0}};
int M9[9][9] = {{5, 0, 6, 0, 0, 9, 0, 0, 8}, {9, 4, 0, 0, 7, 0, 5, 0, 0}, {0, 8, 0, 5, 0, 2, 0, 1, 0}, {0, 5, 0, 4, 6, 0, 0, 0, 7}, {8, 0, 3, 0, 0, 0, 6, 0, 4}, {7, 0, 0, 0, 8, 1, 0, 3, 0}, {0, 9, 0, 7, 0, 6, 0, 5, 0}, {0, 0, 2, 0, 3, 0, 0, 4, 9}, {1, 0, 0, 8, 0, 0, 7, 0, 2}};
//SUBPROGRAMAS-FUNCIONES
void menu1();
int iniciarJuego();
void copiarTablero(int tablero[9][9]);
void inicializarSudoku();
void imprimirSudoku();
bool recorrerTablero();
bool recorrerTableroFinal();
//JUEGO
int main()
{
	srand(time(NULL));
    int opcionInicial, fila, columna, valor;
	opcionInicial = iniciarJuego();
    while (opcionInicial != 2)// INGRESA A LA OPCION 1 
    {
        inicializarSudoku();// SUBPROGRAMA
        system("cls");//LIMPIA PANTALLA
        while (recorrerTablero() == false)
        {
            imprimirSudoku();
            cout << endl;
            cout << "Solo se pueden ingresar numeros entre 1 y 9.";
            cout << endl<<endl;
            cout << "INDIQUE LA FILA: ";
            cin >> fila; //NUM DE FILA A OPERAR
            while (fila < 0 || fila > 9)// COMPARA QUE EL VALOR INGRESADO ESTE ENTRE 1 Y 9, CASO CONTRARIO VUELVE A PEDIRLO
            {
            cout << "El numero de la FILA debe estar comprendido entre 1 y 9, intente de nuevo: ";
			cin >> fila;
			cout << endl;
			}
            cout << "INDIQUE LA COLUMNA: ";
			cin >> columna;
			while (columna < 0 || columna > 9)// COMPARA QUE EL VALOR INGRESADO ESTE ENTRE 1 Y 9, CASO CONTRARIO VUELVE A PEDIRLO
            {
            cout << "El numero de la COLUMNA debe estar comprendido entre 1 y 9, intente de nuevo: ";
			cin >> columna;
			cout << endl;
			}
			cout << "INDIQUE EL VALOR: ";
			cin >> valor;
			while (valor < 0 || valor > 9)// COMPARA QUE EL VALOR INGRESADO ESTE ENTRE 1 Y 9, CASO CONTRARIO VUELVE A PEDIRLO
            {
            cout << "El numero del VALOR debe estar comprendido entre 1 y 9, intente de nuevo: ";
			cin >> valor;
			cout << endl;
			cout << endl;
            }
            if (tableroSudoku[fila - 1][columna - 1] == 0 || sudoku[fila - 1][columna - 1] != tableroSudoku[fila - 1][columna - 1])
            {
            tableroSudoku[fila - 1][columna - 1] = valor;// COMPARA LOS VALORES INGRESADOS Y LOS ORDENA EN EL LUGAR CORRESPONDIENTE
            }
            system("cls");
            recorrerTableroFinal();
        }
        imprimirSudoku();
        cout << endl;
        if (recorrerTableroFinal() == true)// REVISÓ EL JUEGO, SI LOS NUMEROS ESTÁN CORRECTAMENTE COLOCADOS, ANUNCIA CORRECTO, SINO PIDE QUE VUELVA A INTENTARLO.
        cout 
<<"  ######      ###    ##    ##    ###     ######  ######## ######## << "<<endl
<<"##    ##    ## ##   ###   ##   ## ##   ##    ##    ##    ##        << "<<endl
<<"##         ##   ##  ####  ##  ##   ##  ##          ##    ##        << "<<endl
<<"##   #### ##     ## ## ## ## ##     ##  ######     ##    ######    << "<<endl
<<"##    ##  ######### ##  #### #########       ##    ##    ##        << "<<endl
<<"##    ##  ##     ## ##   ### ##     ## ##    ##    ##    ##        << "<<endl
<<" ######   ##     ## ##    ## ##     ##  ######     ##    ########  << "<<endl<< endl;
       else
        cout                                                                                                                                                                                                         
                                                                                                                                                                                                        
<<" ######      ###    ##     ## ########     #######  ##     ## ######## ########  "<<endl
<<"##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ## "<<endl
<<"##  ####  ##     ## ## ### ## ######      ##     ## ##     ## ######   ########  "<<endl
<<"##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##   "<<endl
<<"##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ##  "<<endl
<<" ######   ##     ## ##     ## ########     #######     ###    ######## ##     ## "<<endl <<endl; 
        
        cout << endl;
        cout << "¿Jugar de nuevo?" << endl;// PERMITE REUTILIZAR EL SUBPROGRAMA MENU PARA VOLVER A JUGAR
        cout << endl;
		opcionInicial = iniciarJuego();
    }                                                                                                                                                                                                        
                                                                                                                                                                                                        
cout                                                                                                                                                                                                         
<<"########  ##    ## ########    ########  ##    ## ######## "<<endl
<<"##     ##  ##  ##  ##          ##     ##  ##  ##  ##       "<<endl
<<"##     ##   ####   ##          ##     ##   ####   ##       "<<endl
<<"########     ##    ######      ########     ##    ######   "<<endl
<<"##     ##    ##    ##          ##     ##    ##    ##       "<<endl
<<"##     ##    ##    ##          ##     ##    ##    ##       "<<endl
<<"########     ##    ########    ########     ##    ######## "<<endl<<endl;                                                   
    return 0;
}
void menu1()
{
	}
int iniciarJuego()
{
	int opcion;
		do {
		cout << endl;
	    cout << "* * * *  | B I E N V E N I D O S   A  S U D O K U    U D A|  * * * *" << endl << endl << endl;
	    cout 
<<"  ######  ##     ## ########   #######  ##    ## ##     ## "<< endl
<<" ##   ##  ##     ## ##     ## ##     ## ##   ##  ##     ## "<< endl
<<" ##       ##     ## ##     ## ##     ## ##  ##   ##     ## "<< endl
<<" ######   ##     ## ##     ## ##     ## #####    ##     ## "<< endl
<<"     ##   ##     ## ##     ## ##     ## ##  ##   ##     ## "<< endl
<<"##   ##   ##     ## ##     ## ##     ## ##   ##  ##     ## "<< endl
<<" ######    #######  ########   #######  ##    ##  #######  "<< endl<< endl;
		cout << "* * * * *  R E G L A S D E L   J U E G O * * * * * "<<endl;
		cout << "Sudoku se juega en una cuadricula de 9 x 9 espacios. Dentro de las filas y columnas hay 9 casilleros"<< endl<<"(compuestos de 3 x 3 espacios). Cada fila, columna y casillero (9 espacios cada uno) debe completarse"<< endl<< "con los numeros del 1 al 9 sin repetir ningun numero dentro de la fila, columna o cuadrado." <<endl<<endl;
	    cout << "Elija 1 para JUGAR o 2 para SALIR: ";
	    cin >> opcion;
		 
	} while (opcion != 1 && opcion != 2);
    system("cls");
        return opcion;
}
void copiarTablero(int tableroModelo[9][9], int tableroDestino[9][9]) //Creacion de tablero
{
	for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            tableroDestino[i][j] = tableroModelo[i][j];
        }
    }
}
 void inicializarSudoku()
{
    srand(time(NULL));
    int s = rand() % 10;
    switch (s)
    {
	    case 0:
			copiarTablero(M0, sudoku);
	        break;
	    case 1:
			copiarTablero(M1, sudoku);
	        break;
	    case 2:
			copiarTablero(M2, sudoku);
	        break;
	    case 3:
			copiarTablero(M3, sudoku);
	        break;        
	    case 4:
			copiarTablero(M4, sudoku);
	        break;
	    case 5:
			copiarTablero(M5, sudoku);
	        break;
	    case 6:
			copiarTablero(M6, sudoku);
	        break;
	    case 7:
			copiarTablero(M7, sudoku);
	        break;
	    case 8:
			copiarTablero(M8, sudoku);
	        break;
	    case 9:
			copiarTablero(M9, sudoku);
	        break;
	}
	copiarTablero(sudoku, tableroSudoku);
}
//imprimir sudoku
void imprimirSudoku()
{
    cout << "* * * *  | S U D O K U |  * * * *" << endl;
    cout << endl;
    int fila = 1;//imprime el número de la fila
    cout << "     1  2  3  4  5  6  7  8  9" << endl;
    cout << "  -------------------------------" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << fila << "_"
        << "||";
        fila++;
        for (int j = 0; j < 9; j++)
        {
            if (tableroSudoku[i][j] == 0)
            {
              cout << "."// PUNTO QUE VA ANTES DEL ESPACIO A COMPLETAR POR EL USUARIO
                   << "x"// ESPACIO A COMPLETAR POR EL USUARIO
                   << ".";// PUNTO QUE VA DESPUES DEL ESPACIO A COMPLETAR POR EL USUARIO
            }
            else
            {
            cout << "." << tableroSudoku[i][j] << ".";
            }
        }
        cout << "||";
        cout << endl;
    }
    cout << "  -------------------------------" << endl;
}
//verificar si tablero esta lleno 
bool recorrerTablero()
{
    int cont = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (tableroSudoku[i][j] != 0)
                cont++;
        }
    }
    if (cont == 81)
        return true;
    else
        return false;
}
//verificar si tablero esta lleno
bool recorrerTableroFinal()
{
    int contadorFila = 0, contadorColumna = 0, contadorCuadrante1 = 0, contadorCuadrante2 = 0, contadorCuadrante3 = 0, contadorCuadrante4 = 0, contadorCuadrante5 = 0, contadorCuadrante6 = 0, contadorCuadrante7 = 0, contadorCuadrante8 = 0, contadorCuadrante9 = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int k = 0; k < 8; k++)
        {
            for (int j = k; j < 8; j++)
            {
                //contador elementos filas
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorFila++;
                }
                //contador elementos columnas
                if (tableroSudoku[k][i] != tableroSudoku[j + 1][i])
                {
                    contadorColumna++;
                }
            }
        }
    }
    //check cuadrante 1 .
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = k; j < 2; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante1++;
                }
                if (tableroSudoku[k][i] != tableroSudoku[j + 1][i])
                {
                    contadorCuadrante1++;
                }
            }
        }
    }
    //check cuadrante 2 .
    for (int i = 0; i < 3; i++)
    {
        for (int k = 3; k < 5; k++)
        {
            for (int j = k; j < 5; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante2++;
                }
            }
        }
    }
    for (int j = 3; j < 6; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int i = k; i < 2; i++)
            {
                if (tableroSudoku[k][j] != tableroSudoku[i + 1][j])
                {
                    contadorCuadrante2++;
                }
            }
        }
    }
    //check cuadrante 3 .
    for (int i = 0; i < 3; i++)
    {
        for (int k = 6; k < 8; k++)
        {
            for (int j = k; j < 8; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante3++;
                }
            }
        }
    }
        for (int j = 6; j < 9; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int i = k; i < 2; i++)
            {
                if (tableroSudoku[k][j] != tableroSudoku[i + 1][j])
                {
                    contadorCuadrante3++;
                }
            }
        }
    }
    //check cuadrante 4 .
    for (int i = 3; i < 6; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = k; j < 2; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante4++;
                }
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        for (int k = 3; k < 5; k++)
        {
            for (int i = k; i < 5; i++)
            {
                if (tableroSudoku[k][j] != tableroSudoku[i + 1][j])
                {
                    contadorCuadrante4++;
                }
            }
        }
    }
    //check cuadrante 5 .
    for (int i = 3; i < 6; i++)
    {
        for (int k = 3; k < 5; k++)
        {
            for (int j = k; j < 5; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante5++;
                }
                if (tableroSudoku[k][i] != tableroSudoku[j + 1][i])
                {
                    contadorCuadrante5++;
                }
            }
        }
    }
    //check cuadrante 6 .
    for (int i = 3; i < 6; i++)
    {
        for (int k = 6; k < 8; k++)
        {
            for (int j = k; j < 8; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante6++;
                }
            }
        }
    }
    for (int j = 6; j < 9; j++)
    {
        for (int k = 3; k < 5; k++)
        {
            for (int i = k; i < 5; i++)
            {
                if (tableroSudoku[k][j] != tableroSudoku[i + 1][j])
                {
                    contadorCuadrante6++;
                }
            }
        }
    }
    //check cuadrante 7 .
    for (int i = 6; i < 9; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = k; j < 2; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante7++;
                }
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        for (int k = 6; k < 8; k++)
        {
            for (int i = k; i < 8; i++)
            {
                if (tableroSudoku[k][j] != tableroSudoku[i + 1][j])
                {
                    contadorCuadrante7++;
                }
            }
        }
    }
    //check cuadrante 8 .
    for (int i = 6; i < 9; i++)
    {
        for (int k = 3; k < 5; k++)
        {
            for (int j = k; j < 5; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante8++;
                }
            }
        }
    }
    for (int j = 3; j < 6; j++)
    {
        for (int k = 6; k < 8; k++)
        {
            for (int i = k; i < 8; i++)
            {
                if (tableroSudoku[k][j] != tableroSudoku[i + 1][j])
                {
                    contadorCuadrante8++;
                }
            }
        }
    }
    //check cuadrante 9 .
    for (int i = 6; i < 9; i++)
    {
        for (int k = 6; k < 8; k++)
        {
            for (int j = k; j < 8; j++)
            {
                if (tableroSudoku[i][k] != tableroSudoku[i][j + 1])
                {
                    contadorCuadrante9++;
                }
                if (tableroSudoku[k][i] != tableroSudoku[j + 1][i])
                {
                    contadorCuadrante9++;
                }
            }
        }
    }
    if (contadorFila == 324 && contadorColumna == 324 && contadorCuadrante1 == 18 && contadorCuadrante2 == 18 && contadorCuadrante3 == 18 && contadorCuadrante4 == 18 && contadorCuadrante5 == 18 && contadorCuadrante6 == 18 && contadorCuadrante7 == 18 && contadorCuadrante8 == 18 && contadorCuadrante9 == 18)
    {
        return true;
    }
    else
        return false;
}
