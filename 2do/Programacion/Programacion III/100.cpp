#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
struct datos {
  int num;
  string nombre;
  int categoria, subcategoria, tirosCentro, tirosNoCentro, resultado;
};
void mostrar(datos comp[20]);
void menu();
void sumaPuntos(datos comp[20]);
void crearResultados(datos comp[20]);
void calculoCompetidores(datos comp[20]);
void categorias(datos comp[20]);

int main() {
  int i = 0, j = 0, salir = 1, elec, puntos[20];

  datos competencia[20];

  ifstream file;
  file.open("inscriptos.txt");
  while (i < 20) {
    file >> competencia[i].num;
    file >> competencia[i].nombre;
    file >> competencia[i].categoria;
    file >> competencia[i].subcategoria;
    file >> competencia[i].tirosCentro;
    file >> competencia[i].tirosNoCentro;
    competencia[i].resultado = 0;
    i++;
  }
  file.close();

  do {
    system("cls");
    menu();
    cin >> elec;

    switch (elec) {
    case 1:
      mostrar(competencia);
      break;

    case 2:
      sumaPuntos(competencia);
      break;

    case 3:
      crearResultados(competencia);
      break;

    case 4:
      calculoCompetidores(competencia);
      break;

    case 5:
      categorias(competencia);
      break;

    case 6:
      salir = 0;
      break;

    default:
      system("cls");
      cout << "Numero Incorrecto, seleccione una opcion de nuestro menu ...."
           << endl;
      break;
    }
  } while (salir != 0);

  if (elec != 6) {

    cout << " " << endl;
    cout << "Ingrese 1 en caso de querer retornar al menu" << endl;
    cout << "Ingrese otro valor para salir del programa" << endl;
    cout << " " << endl;
    cout << "Opcion: ";
    cin >> salir;
  }
  return (0);
}
void menu() {

  cout << "1. Mostrar el listado de los participantes inscriptos." << endl;
  cout << "2. Calcular el total de puntos sumados por cada competidor." << endl;
  cout << "3. Crear un archivo con los puntajes de los competidores ordenados "
          "de mayor a menor."
       << endl;
  cout << "4. Calcular la cantidad de competidores que superan un determinado "
          "umbral de puntos."
       << endl;
  cout << "5. Competidores por Categoria y Sub-Categoria." << endl;
  cout << "6. Salir." << endl;
  cout << "Seleccione una opcion: ";
  return;
}
void mostrar(datos comp[20]) {

  int i = 0;

  system("cls");

  cout << "Competidores:" << endl;
  cout << "" << endl;
  cout << "Numero Inscripcion        Nombre     Categ    Sub Categ   Tiros al "
          "Centro  Tiros No Centro"
       << endl;

  while (i < 20) {
    std::cout << std::left << std::setw(25) << comp[i].num << std::left
              << std::setw(13) << comp[i].nombre << std::left << std::setw(13)
              << comp[i].categoria << std::left << std::setw(13)
              << comp[i].subcategoria << std::left << std::setw(20)
              << comp[i].tirosCentro << std::left << std::setw(20)
              << comp[i].tirosNoCentro << std::endl;
    i++;
  }
  system("pause");
  return;
}
void sumaPuntos(datos comp[20]) {
  int j = 0;
  system("cls");

  while (j < 20) {
    int tiroCentro = comp[j].tirosCentro;
    int tiroNoCentro = comp[j].tirosNoCentro;
    comp[j].resultado = (tiroCentro * 10) + (tiroNoCentro * 5);
    j++;
  }

  cout << endl
       << "Se han sumado los resultados de todos los competidores!!" << endl;
  system("pause");
}
void crearResultados(datos comp[20]) {

  system("cls");
  for (int i = 0; i < 20 - 1; ++i) {
    for (int j = 0; j < 20 - 1; ++j) {
      if (comp[j].resultado < comp[j + 1].resultado) {
        datos temp = comp[j];
        comp[j] = comp[j + 1];
        comp[j + 1] = temp;
      }
    }
  }

  ofstream archivoResultados;
  archivoResultados.open("resultados.txt");

  std::cout << std::left << std::setw(25) << "Numero Inscripcion" << std::left
            << std::setw(13) << "Nombre" << std::left << std::setw(13)
            << "Categ" << std::left << std::setw(13) << "Sub Categ" << std::left
            << std::setw(20) << "Tiros al Centro" << std::left << std::setw(20)
            << "Tiros No Centro" << std::setw(20) << "Resultado" << std::endl;
  std::cout << "                                                             "
            << std::endl;

  int i = 0;

  while (i < 20) {
    std::cout << std::left << std::setw(25) << comp[i].num << std::left
              << std::setw(13) << comp[i].nombre << std::left << std::setw(13)
              << comp[i].categoria << std::left << std::setw(13)
              << comp[i].subcategoria << std::left << std::setw(20)
              << comp[i].tirosCentro << std::left << std::setw(20)
              << comp[i].tirosNoCentro << std::setw(20) << comp[i].resultado
              << std::endl;
    i++;
  }
  archivoResultados.close();
  system("pause");
}
void calculoCompetidores(datos comp[20]) {

  int cantidad, i = 0;
  int total = 0;

  system("cls");

  cout << "Ingrese el umbral de puntos que desea controlar con los resultados "
          "de los competidores: ";
  cin >> cantidad;

  while (i < 20) {

    if (cantidad < comp[i].resultado) {

      total = total + 1;
    }

    i = i + 1;
  }

  cout << "" << endl;
  cout << "Los competidor/es poseen mas puntos de los ingresados es de:  "
       << total << "!!";
  cout << "" << endl;
  system("pause");
}
void categorias(datos comp[20]) {
  system("cls");

  int array[3][3];

  for (int i = 0; i <= 2; ++i) {
    for (int j = 0; j <= 2; ++j) {
      array[i][j] = 0;
    }
  }
  for (int i = 0; i < 20; ++i) {
    int a = comp[i].categoria;
    int b = comp[i].subcategoria;
    array[a][b] = array[a][b] + 1;
  }
  for (int i = 0; i <= 2; ++i) {
    for (int j = 0; j <= 2; ++j) {
      cout << array[i][j] << "    ";
    }
    cout << endl;
  }

  cout << "" << endl;
  system("pause");
}