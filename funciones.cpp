#include "10.h"
using namespace std;


bool ganaste(vector< vector<int>> matrix)
{
	bool condicion = false;

	for (auto a : matrix)
	{
		for (auto b : a)
		{
			if (b == 1 && condicion)
			{
				return false;
			}
			else
			{
				condicion = true;
			}
		}
	}
	return condicion;
}

int validar_mov(int x1, int x2, int y1, int y2, int tipo, vector< vector<int>> matrix)
{                           //se serciora que el movimiento
							//es válido
	//creacion d euna variable caso
	int caso = 0;
	//viene un switch para el caso

	switch (tipo)
	{
		//en cualquiera de los 3 casos si alguna fila o columna ingresa esta fuera del rango , retornará caso=0 al main 
		//luego  en main se observa que si caso=0;seguirá pidiendo las coordenadas
	case 1:
	{
		//analizando si alguna coordenadas esta fuera del rango caso1
		if (x1 >= 9 || x2 >= 9 || y1 >= 9 || y2 >= 9)
		{
			return caso;
		}
	}
	case 2:
	{	//analizando si alguna coordenadas esta fuera del rango caso2

		if (x1 >= 7 || x2 >= 7 || y1 >= 7 || y2 >= 7)
		{
			cout << "?";
			return caso;
		}
	}
	case 3:
	{	//analizando si alguna coordenadas esta fuera del rango caso3

		if (x1 >= 9 || x2 >= 9 || y1 >= 9 || y2 >= 9)
		{
			return caso;
		}
	}
	}
	//aca se ve el caso de coordenada invalida si se quiere mover el centro que vale 0 o demas 9 creados
	//conforme se va elminando los "0" o tambien cuando se quiere mover a un O ( valen 1;coordenada de destino)
	if (matrix[y1][x1] == 0 || matrix[y2][x2] == 1)
	{
		cout << "Coordenada invalida.";
		return caso;
	}
	//si los datos ingresados estan fuera de la matrix , ya que los 9 representan los vacios
	if (matrix[y1][x1] == 9 || matrix[y2][x2] == 9)
	{
		cout << "Dato invalido";
		return caso;
	}
	//si pasa todas estas condiciones
	//recordar que en este programa ( y son filas , x columnas)

	//primer caso si el movimiento es en forma vertical 
	if (x1 == x2)
	{
		caso = 2;
	}
	//segundo  caso si el movimiento horizontal
	if (y1 == y2)
	{
		caso = 1;
	}
	//case switch de los casos anteriores
	switch (caso)
	{
	case 1: {
		//en el caso de que el movimiento sea horizontal(filas iguales), segun el juego debe haber una resta de 2 posiciones
		//que puede ser para el lado derecho o para e lado izquierdo(2 y -2), si esto no se cumple retorna 0 
		//el cual en el main el 0 vuelve a pedoir el bucle de pedir coordenadas
		if (x1 > x2)
		{
			if (matrix[y1][x1 - 1] == 0)
			{
				return 0;
			}
		}
		else
		{
			if (matrix[y1][x2 - 1] == 0)
			{
				return 0;
			}
		}
		if (((x1 - x2) != 2 && (x1 - x2) != -2))
		{

			return 0;
		}
		//si no cumple anterior condición significa que las posiciones de la columnas es la correcta y retorna el valor
		//del caso evaluado en el switch
		else
		{
			break;
		}}
			//la misma lógica se cumple para el movimiento vertical
				//caso 2 si son las columnas son iguales
	case 2: {
		if (y1 > y2)
		{
			if (matrix[y1 - 1][x1] == 0)
			{
				return 0;
			}
		}
		else
		{
			if (matrix[y2 - 1][x1] == 0)
			{
				return 0;
			}
		}
		if (((y1 - y2) != 2 && (y1 - y2) != -2))
		{
			return 0;
		}}


	}

	return caso;
}

vector< vector<int>> crear(int tipo) // 
{
	//creacion de una cualquiera variable auxiliar
	int aux = 0;
	//llama a la matrix para jodificarla 
	vector< vector<int>> matrix;
	//estilo diamante
	if (tipo == 3)

	{
		//como el estilo diamante tiene 9 filas y 9 cokumnas se le cambia el tamaño de la matrix a 9
		matrix.resize(9);
		//rrecoriendo toda la matrix
		for (int j = 0; j < 9; j++)
		{
			if (j > 4)
			{
				aux = aux + 2;
			}
			matrix[j].resize(9);
			matrix[j] = { 9,9,9,9,9,9,9,9,9 };
			//los 9 simbolizan el vacio y los 1 los espacios
			for (int k = (9 / 2) - j + aux; k <= (9 / 2) + j - aux; k++)
			{
				matrix[j][k] = 1;
			}
		}
		//elemento central sempre en 0
		matrix[9 / 2][9 / 2] = 0;
	}
	//estilo aleman
	if (tipo == 1)
	{	//tamaño de la matrizx aleman 9 filas por 9 columnas
		matrix.resize(9);
		//creando dos variables i y n
		int i, n;
		for (int k = 0; k < 9; k++)
		{	//los 9 son los espacios donde no aparecerá nada de la figura
			matrix[k].resize(9);
			matrix[k] = { 9,9,9,9,9,9,9,9,9 };

			if (k >= 3 && k <= 5)
			{
				i = 0;
				n = 9;
			}
			else
			{
				i = 3;
				n = 6;
			}
			while (i < n)
			{
				//los 1 son los espacios que dan forma a la figura del juego elegido
				matrix[k][i] = 1;
				i++;
			}
		}//elemento central siempre en 0
		matrix[9 / 2][9 / 2] = 0;
	}
	if (tipo == 2)
	{	//cambia el tamaño de la matriz 7x7
		matrix.resize(7);
		//crea dos variables 
		int i, n;
		for (int k = 0; k < 7; k++)
		{
			//los 9 son los espacios donde no aparecerá nada de la figura
			matrix[k].resize(7);
			matrix[k] = { 9,9,9,9,9,9,9 };
			if (k >= 2 && k <= 4)
			{
				i = 0;
				n = 7;
			}
			else
			{
				i = 2;
				n = 5;
			}
			while (i < n)
			{
				//los 1 son los espacios que dan forma a la figura del juego elegido
				matrix[k][i] = 1;
				i++;
			}
		}
		//element central siempre en 0 (vacio)
		matrix[7 / 2][7 / 2] = 0;
	}
	return matrix;
}


vector< vector<int>> editar(int x1, int x2, int y1, int y2, vector< vector<int>> matrix, int type)
{                               //aqui se cambian ya los valores
	//analizar que valor tiene type
	switch (type)
	{
		//en el caso que el movimiento sea horizontal el  valor de type es 1(es decir que la jugada es horizontal)
		//siempre se colocara el cero donde se encuentra la coordenada de origen y el otro cero de destino se analizará a 
		//continuación donde irá
	case 1:
	{	//esta condición es para colocar ceros si el movimiento es del lado derecho a izquierda
		if (x1 > x2)
		{

			matrix[y1][x1] = 0;
			matrix[y1][x1 - 1] = 0;
			matrix[y1][x1 - 2] = 1;
		}
		//esta condición es para colocar ceros si el movimiento es del lado izquierdo hacia el derechp
		else
		{

			matrix[y1][x1] = 0;
			matrix[y1][x1 + 1] = 0;
			matrix[y1][x1 + 2] = 1;

		}
		break;
	}
	//en el caso que el movimiento sea vertical el  valor de type es 1(es decir la jugada es horozontal)
	case 2:
	{
		//esta condición es para colocar ceros si el movimiento es de abajo hacia arriba
		if (y1 > y2)
		{
			matrix[y1][x1] = 0;
			matrix[y1 - 1][x1] = 0;
			matrix[y1 - 2][x1] = 1;

		}
		//esta condición es para colocar ceros si el movimiento es de arriba hacia abajo
		else
		{
			matrix[y1][x1] = 0;
			matrix[y1 + 1][x1] = 0;
			matrix[y1 + 2][x1] = 1;
		}
		break;
	}
	}
	//retornara la matrix editada
	return matrix;
}

bool esperanza(vector< vector<int>> matrix)
{
	//se serciora que exista
	//algún movimiento posible
	//bool posible=0;
	//variable toma el tamaño de la matrix
	auto e = matrix.size();
	for (auto i = 0; i < e; i++)
	{

		for (int j = 0; j < e - 2; j++)
		{
			if (matrix[i][j] == 1 && matrix[i][j + 1] == 1 && matrix[i][j + 2] == 0)
			{
				return true;
			}
		}
	}
	for (auto i = 0; i < e - 2; i++)
	{
		for (int j = 0; j < e; j++)
		{
			if (matrix[i][j] == 1 && matrix[i + 1][j] == 1 && matrix[i + 2][j] == 0)
			{
				return true;
			}
		}
	}
	for (int i = e - 1; i >= 0; i--)

		for (int j = e - 1; j - 2 >= 0; j--)
		{
			if (matrix[i][j] == 1 && matrix[i][j - 1] == 1 && matrix[i][j - 2] == 0)
			{
				return true;
			}
		}
	//al reves
	for (int i = e - 1; i - 2 >= 0; i--)
	{
		for (int j = e - 1; j > 0; j--)
		{
			if (matrix[i][j] == 1 && matrix[i - 1][j] == 1 && matrix[i - 2][j] == 0)
			{
				return true;
			}
		}
	}
	return false;
}
void mostrar(vector< vector<int>> matrix) //muestra la matriz "matrix"
{
	//mide el tamaño de la matrix
	auto e = matrix.size();
	//da  un tab de espacio para empezar a imprimir
	cout << "\t";
	//imprimimos las columnas del juego
	for (int o = 0; o < e; o++)
	{
		cout << o + 1 << "\t";
	}
	//enter
	cout << endl;
	//empieza a imprimir la posición  de filas (1---------9)
	//el e tiene contenido el tamaño de la matrix 
	for (int i = 0; i < e; i++)
	{	//imprimir  los numros de filas (empiezan de 1)
		cout << i + 1 << " ";
		for (int j = 0; j < e; j++)
		{
			cout << "\t";
			if (matrix[i][j] == 9)
			{
				//aqui programa no hara nada, no imprimira nada 
			}
			else
			{
				//pero si la "casilla" es igual a 1 imprimira un O
				if (matrix[i][j] == 1)
				{
					cout << "O";
				}
				//y si no se cumple lo anterior, en primer lugar como habiamos dejado a la casilla del centro como un valor de cero
				//imprimirá el + que simboliza el vacío
				else
				{
					cout << "+";
				}
			}
		}
		//enter y enter
		cout << endl << endl;
	}
}

