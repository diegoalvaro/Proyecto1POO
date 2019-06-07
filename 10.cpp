#include <iostream>
#include <vector>
#include "10.h"
using namespace std;



int main()
{	//
	int caso;
	bool posible = 1, mal = 1;
	vector< vector<int>> matrix; //inicializando la matriz , luegola usaremos en la funcion crear matriz
	// TENER EN CUENTA Y1 FILA DE ORIGEN X1 ES COLUMNA DE ORIGEN, Y2 FILA DE DESTINO X2 COLUMNA DE DESTINO
	int tipo, x1, y1, x2, y2;    //posiciones
	cout <<"---Menu -Juego Senku---" << endl;
	cout << "-------------------------" << endl;
	cout << "  1.- Estilo Aleman" << endl;
	cout << "  2.-Estilo  Ingles " << endl;;
	cout << "  3. - Estilo  Diamante" << endl;
	cout << "-------------------------" << endl;
	cout << "  0.-Salir del programa" << endl << endl;
	cout << "Selecciona la opcion" << endl;
	cin >> tipo;//introduciendo el tipo de juego 
	//si el tipo es igual a 0  finaliza todo el programa
	if (tipo == 0)
	{
		cout << "Programa finalizado" << endl;
		exit(9);

	}

	//matrix ya esta inicializada 
	matrix = crear(tipo);        //se crea la matriz con los parametros tipo
	while (posible)
	{	//llamamos a la funcion mostrar matrix 
		mostrar(matrix);
		while (mal)
		{
			cout << endl;
			cout << " Ingrese coordenada de origen(fila, columna): " << endl;
			cin >> y1 >> x1;
			cout << " Ingrese coordenada de destino (fila columna) : " << endl;
			cin >> y2 >> x2;
			//se disminuyen uno a todos las entradas ya que las posiciones de matrix empeizan desde 0 
			x1--;
			y1--;
			x2--;
			y2--;
			//variable entera caso será el retorno de la funcion validar movimiento
			caso = validar_mov(x1, x2, y1, y2, tipo, matrix);
			//priemro se ve si el movimiento es valido
			//el caso toma el valor de la funcion validar movimiento y luego evalua en el siguiente if para 
			//ver si pide nuevamente las cordenadas o si hará una edición de la matrix
			if (caso == 0)
			{
				mal = 1;
			}
			else
			{
				mal = 0;
			}
		}
		//si la jugada es válida se editará la matrix
		//la matrix de editárá con los datos de filas ,columnas , la propia matrix creada y el valor del caso
		matrix = editar(x1, x2, y1, y2, matrix, caso);  //se edita
		//luego se realizar la jugada verificaremos si hay otre jugada disponible
		//la variable posible tomará  el valor de la función esperanza , ya que"posible" es la se encuentra en el while principl
		posible = esperanza(matrix);        //se serciora que hay algun movimiento posible
		mal = 1;
	}
	auto win = ganaste(matrix);
	if (win)
	{
		cout << "GANASTE!!!"<<endl;
		system("PAUSE");
		exit(9);
	}
	
	else
	{
		cout << "PERDISTE!" << endl;
		system("PAUSE");
		exit(0);
	}
	
}



/*

*/