#include <vector>
#include <iostream>
using namespace std;

bool ganaste(vector< vector<int>> matrix);
int validar_mov(int x1, int x2, int y1, int y2, int tipo, vector< vector<int>> matrix);
vector< vector<int>> crear(int tipo);
vector< vector<int>> editar(int x1, int x2, int y1, int y2, vector< vector<int>> matrix, int type);
bool esperanza(vector< vector<int>> matrix);
void mostrar(vector< vector<int>> matrix);