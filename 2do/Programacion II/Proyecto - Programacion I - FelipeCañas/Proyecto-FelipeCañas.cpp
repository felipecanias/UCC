//Proyecto Felipe Cañas

//Librerias
#include <iostream>
#include <fstream>

using namespace std;

// Struct Datos Pacientes
struct paciente{
    int filacama;
    int columnacama;
    string nombre;
    int edad;
    int dni;
    int dias;
}paciente[100];

string s;
// Funciones
int promedioedad(int k){
  int sumatoria=0;
    for(int i=0;i<k;i++){
      sumatoria+=paciente[i].edad;
    }

  sumatoria/=k;

  return sumatoria;
}

void internados(int k){
  ofstream file;
  file.open("Internados5dias.txt",ios::out);
  if(file.fail()){
    cout<<"No se pudo abrir el archivo 'Internados5dias.txt'";
    exit(1);
  }

  for(int i=0;i<k;i++){
    if(paciente[i].dias>5){
      file<<paciente[i].nombre<<endl;
    }
  }
  file.close();

}

void edadmayorpromedio(int k){
  ofstream file;
  file.open("Edadmayorpromedio.txt",ios::out);
  if(file.fail()){
    cout<<"No se pudo abrir el archivo 'Edadmayorpromedio.txt'";
    exit(1);
  }

  for(int i=0;i<k;i++){
    if(paciente[i].edad>promedioedad(k)){
      file<<paciente[i].nombre<<'\t';
      file<<paciente[i].dni<<endl;
    }
  }
  file.close();

}

void datos(int o,int p,int k){
  for(int i=0;i<k;i++){
      if(o==paciente[i].filacama && p==paciente[i].columnacama){
          cout<<"----------------------"<<endl;
          cout<<"Nombre del paciente: "<<paciente[i].nombre<<endl;
          cout<<"Edad del paciente: "<<paciente[i].edad<<endl;
          cout<<"Dni del paciente: "<<paciente[i].dni<<endl;
          cout<<"Dias internados del paciente: "<<paciente[i].dias<<endl;
          cout<<"----------------------"<<endl;
    }
  }
}

void pacientesadyacentes(int f, int c, int k){

string top,down,left,right,topleft,topright,downleft,downright;

  ofstream file;
  file.open("PacientesAdyacentes.txt",ios::out);
  if(file.fail()){
    cout<<"No se pudo abrir el archivo 'PacientesAdyacentes.txt'";
    exit(1);
  }

  for(int i=0;i<k;i++){
      if(paciente[i].filacama==f-1 && paciente[i].columnacama==c){
        top=paciente[i].nombre;
      }
      if(paciente[i].filacama==f+1 && paciente[i].columnacama==c){
        down=paciente[i].nombre;
      }
      if(paciente[i].filacama==f && paciente[i].columnacama==c-1){
        left=paciente[i].nombre;
      }
      if(paciente[i].filacama==f && paciente[i].columnacama==c+1){
        right=paciente[i].nombre;
      }
      if(paciente[i].filacama==f-1 && paciente[i].columnacama==c-1){
        topleft=paciente[i].nombre;
      }
      if(paciente[i].filacama==f-1 && paciente[i].columnacama==c+1){
        topright=paciente[i].nombre;
      }
      if(paciente[i].filacama==f+1 && paciente[i].columnacama==c-1){
        downleft=paciente[i].nombre;
      }
      if(paciente[i].filacama==f+1 && paciente[i].columnacama==c+1){
        downright=paciente[i].nombre;
      }
  }

    file<<top<<endl;
    file<<down<<endl;
    file<<left<<endl;
    file<<right<<endl;
    file<<topleft<<endl;
    file<<topright<<endl;
    file<<downleft<<endl;
    file<<downright<<endl;
}

int main(){

  //Declaracion de variables
  int c,f,k=0,x,o,p,q,w,n=0;

  //Inicio del Programa
  cout<<"HOSPITAL PRIVADO"<<endl;
  cout<<"-----------------"<<endl;

  //Ingreso cantidad de filas de camas
    while(true){
      cout<<"Ingrese cantidad de filas de camas: ";
      string filas;
      int validacionf=0;
      cin.sync();getline(cin, filas);cin.sync();
      int cantfilas=filas.length();

      //Validacion de datos
      try{
        for(int i=0; i<cantfilas; i++){
          if(int(filas[i])>=48 && int(filas[i])<=57){
            validacionf++;
          }
        }
        if(validacionf==cantfilas){
          f=stoi(filas);
          if(f>0){
          break;
          }
          else{
            cout<<"Error! Ingrese una cantidad de filas valida"<<endl;
            cout<<"-----------------------------"<<endl;
          }
        }
        else{
          cout<<"Error! Ingrese un numero"<<endl;
          cout<<"-----------------------------"<<endl;
        }
      }
      catch(out_of_range){
        cout<<"Error! La cantidad de filas de camas excede el limite"<<endl;
        cout<<"----------------------"<<endl;
      }
      catch(invalid_argument){
        cout<<"Error! Ingrese una cantidad de filas valida"<<endl;
        cout<<"----------------------"<<endl;
      }
    }

  //Ingreso cantidad de columnas de camas
    while(true){
      cout<<"Ingrese cantidad de columnas de camas: ";
      string columnas;
      int validacionc=0;
      cin.sync();getline(cin, columnas);cin.sync();
      int cantcolumnas= columnas.length();

      //Validacion de datos
      try{
        for(int i=0; i<cantcolumnas; i++){
          if(int(columnas[i])>=48 && int(columnas[i])<=57){
            validacionc++;
          }
        }
        if(validacionc==cantcolumnas){
          c=stoi(columnas);
          if(c>0){
          break;
          }
          else{
            cout<<"Error! Ingrese una cantidad de columnas valida"<<endl;
            cout<<"----------------------"<<endl;
          }
        }
        else{
          cout<<"Error! Ingrese un numero"<<endl;
          cout<<"----------------------"<<endl;
        }
      }
      catch(out_of_range){
        cout<<"Error! La cantidad de columnas de camas excede el limite"<<endl;
        cout<<"----------------------"<<endl;
      }
      catch(invalid_argument){
        cout<<"Error! Ingrese una cantidad de columnas valida"<<endl;
        cout<<"----------------------"<<endl;
      }
  }

  //Bucle "for" para ingreso de datos de los pacientes
  for(int i=0;i<f;i++){
    for(int j=0;j<c;j++){
      paciente[k].filacama=i;
      paciente[k].columnacama=j;

      //Ingreso de nombre del paciente
      while(true){
        cout<<"----------------------"<<endl;
        cout<<"Ingrese nombre del paciente de la cama, fila: "<<i+1<<", columna: "<<j+1<<" : ";
        string nombre;
        int validacion=0;
        cin.sync();getline(cin,nombre);
        int largonombre= nombre.length();

        //Validacion de datos
        if(nombre!=""){
          for(int i=0; i<largonombre; i++){
              if(int(toupper(nombre[i]))>=65 && int(toupper(nombre[i]))<=90 || int(nombre[i]==32)){
              validacion++;
            }
          }
          if(validacion==largonombre){
            paciente[k].nombre=nombre;
            break;
          }
          else{
            cout<<"Error! No ingrese caracateres incorrectos"<<endl;
          }
        }
        else{
          cout<<"Error! El campo no puede quedar vacio"<<endl;
        }
        }


      //Ingreso del dni del paciente
      while(true){
        cout<<"----------------------"<<endl;
        cout<<"Ingrese dni del paciente de la cama , fila: "<<i+1<<", columna: "<<j+1<<" : ";
        string dni;
        int validaciondni=0;
        cin.sync();getline(cin,dni);
        int largodni= dni.length();

        //Validacion de datos
        try{
          for(int i=0; i<largodni; i++){
            if(int(dni[i])>=48 && int(dni[i])<=57){
              validaciondni++;
            }
          }
          if(validaciondni==largodni){
            paciente[k].dni=stoi(dni);
            if(paciente[k].dni>100000 && paciente[k].dni<100000000){
              break;
            }
            else{
              cout<<"Error! Ingrese un dni valido"<<endl;
            }
          }
          else{
            cout<<"Error! Ingrese caracteres de tipo numerico"<<endl;
          }
        }
        catch(out_of_range){
          cout<<"Error! Ingrese un dni valido"<<endl;
        }
        catch(invalid_argument){
          cout<<"Error! Ingrese un dni valido"<<endl;
        }
      }

      //Ingreso de la edad del paciente
      while(true){
        cout<<"----------------------"<<endl;
        cout<<"Ingrese edad del paciente de la cama , fila: "<<i+1<<", columna: "<<j+1<<" : ";
        string edad;
        int validacionedad=0;
        cin.sync();getline(cin,edad);
        int largoedad= edad.length();

        //Validacion de datos
        try{
          for(int i=0; i<largoedad; i++){
            if(int(edad[i])>=48 && int(edad[i])<=57){
              validacionedad++;
            }
          }
          if(validacionedad==largoedad){
            paciente[k].edad=stoi(edad);
            if(paciente[k].edad>0 && paciente[k].edad<110){
              break;
            }
            else{
              cout<<"Error! Ingrese una edad valida"<<endl;
            }
          }
          else{
            cout<<"Error! Ingrese caracteres de tipo numerico"<<endl;
          }
        }
        catch(out_of_range){
          cout<<"Error! Ingrese una edad valida"<<endl;
        }
        catch(invalid_argument){
          cout<<"Error! Ingrese una edad valida"<<endl;
        }
      }

      //Ingreso de cantidad de dias internados del paciente
      while(true){
        cout<<"----------------------"<<endl;
        cout<<"Ingrese dias en el hospital del paciente de la cama , fila: "<<i+1<<", columna: "<<j+1<<" : ";
        string dias;
        int validaciondias=0;
        cin.sync();getline(cin,dias);
        int largodias= dias.length();

        //Validacion de datos
        try{
          for(int i=0; i<largodias; i++){
            if(int(dias[i])>=48 && int(dias[i])<=57){
              validaciondias++;
            }
          }
          if(validaciondias==largodias){
            paciente[k].dias=stoi(dias);
            if(paciente[k].dias>0 && paciente[k].dias<(paciente[k].edad*365)){
              break;
            }
            else{
              cout<<"Error! Ingrese una cantidad de dias valida"<<endl;
            }
          }
          else{
            cout<<"Error! Ingrese caracteres de tipo numerico"<<endl;
          }
        }
        catch(out_of_range){
          cout<<"Error! Ingrese una cantidad de dias valida"<<endl;
        }
        catch(invalid_argument){
          cout<<"Error! Ingrese una cantidad de dias valida"<<endl;

        }
      }

      k++;
    }
  }

  cout<<"----------------------"<<endl;

  //Habitacion, carga de datos a la matriz
  string habitacion[f][c];
  for(int i=0;i<f;i++){
    for(int j=0;j<c;j++){
      habitacion[i][j]=paciente[n].nombre;
      n++;
    }
  }
  system("CLS||clear");

  //Menu de operaciones
  do{

    while(true){
      //Habitacion, impresion de la matriz
      cout<<"Distribucion de camas de la habitacion"<<endl;
      cout<<"----------------------"<<endl;

      for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
          cout<<habitacion[i][j]<<'\t';
        }
        cout<<'\t'<<endl;
      }
      cout<<"----------------------"<<endl;
      cout<<"1) Promedio de edad de la habitacion"<<endl;
      cout<<"2) Pacientes con mas de 5 dias internados"<<endl;
      cout<<"3) Pacientes con edades mayores al promedio"<<endl;
      cout<<"4) Datos de un paciente"<<endl;
      cout<<"5) Pacientes adyacentes a un paciente"<<endl;
      cout<<"6) Exit"<<endl;
      cout<<"----------------------"<<endl;
      cout<<"Que accion desea realizar?"<<" ";
      string xx;
      int validacionx=0;
      cin.clear();cin.sync();getline(cin,xx);
      int largox= xx.length();
      cout<<"----------------------"<<endl;

      //Validacion de datos ingresados en el menu
      try{
        for(int i=0; i<largox; i++){
          if(int(xx[i])>=48 && int(xx[i])<=57){
            validacionx++;
          }
        }
        if(validacionx==largox){
          x=stoi(xx);
          if(x>=1 && x<=6){
            break;
          }
          else{
            cout<<"Error! Ingrese un numero valido"<<endl;
            cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
            system("CLS||clear");
          }
        }
        else{
          cout<<"Error! Ingrese caracteres de tipo numerico"<<endl;
          cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
          system("CLS||clear");
        }
      }
      catch(out_of_range){
        cout<<"Error! Ingrese un numero valido"<<endl;
        cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
        system("CLS||clear");
      }
      catch(invalid_argument){
        cout<<"Error! Ingrese un numero valido"<<endl;
        cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
        system("CLS||clear");
      }
    }


    switch(x){
        //Promedio de edad
        case 1: cout<<"El promedio de edad de la habitacion es: "<<promedioedad(k)<<endl;

                cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                system("CLS||clear");
                break;

        //Pacientes con mas de 5 dias internados
        case 2: internados(k);
                #ifdef _WIN32
                system("Internados5dias.txt");
                #elif __linux__
                system("head Internados5dias.txt");
                #endif
                cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                system("CLS||clear");
                break;

        //Pacientes con edades mayores a la promedio
        case 3: edadmayorpromedio(k);
                #ifdef _WIN32
                system("Edadmayorpromedio.txt");
                #elif __linux__
                system("head Edadmayorpromedio.txt");
                #endif
                cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                system("CLS||clear");
                break;

        //Datos de un paciente
        case 4: while(true){
                cout<<"Ingrese fila de la cama del paciente: ";
                string oo;
                int validaciono=0;
                cin.sync();getline(cin,oo);
                int largoo= oo.length();

                //Validacion de datos
                try{
                  for(int i=0; i<largoo; i++){
                    if(int(oo[i])>=48 && int(oo[i])<=57){
                      validaciono++;
                    }
                  }
                  if(validaciono==largoo){
                    o=stoi(oo);
                    o-=1;
                    if(o>=0 && o<f){
                      break;
                    }
                    else{
                      cout<<"Error! Ingrese una fila valida"<<endl;
                      cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                      system("CLS||clear");
                    }
                  }
                  else{
                    cout<<"Error! Ingrese caracteres de tipo numerico"<<endl;
                    cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                    system("CLS||clear");
                  }
                }
                catch(out_of_range){
                  cout<<"Error! Ingrese una fila valida"<<endl;
                  cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                  system("CLS||clear");
                }
                catch(invalid_argument){
                  cout<<"Error! Ingrese una fila valida"<<endl;
                  cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                  system("CLS||clear");
                }
              }

              while(true){
                      cout<<"Ingrese columna de la cama del paciente: ";
                      string pp;
                      int validacionp=0;
                      cin.sync();getline(cin,pp);
                      int largop= pp.length();

                      //Validacion de datos
                      try{
                        for(int i=0; i<largop; i++){
                          if(int(pp[i])>=48 && int(pp[i])<=57){
                            validacionp++;
                          }
                        }
                        if(validacionp==largop){
                          p=stoi(pp);
                          p-=1;
                          if(p>=0 && p<c){
                            break;
                          }
                          else{
                            cout<<"Error! Ingrese una columna valida"<<endl;
                            cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                            system("CLS||clear");
                          }
                        }
                        else{
                          cout<<"Error! Ingrese caracteres de tipo numerico"<<endl;
                          cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                          system("CLS||clear");
                        }
                      }
                      catch(out_of_range){
                        cout<<"Error! Ingrese una columna valida"<<endl;
                        cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                        system("CLS||clear");
                      }
                      catch(invalid_argument){
                        cout<<"Error! Ingrese una columna valida"<<endl;
                        cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                        system("CLS||clear");
                      }
                    }

                    datos(o,p,k);
                    cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                    system("CLS||clear");
                    break;

        //Pacientes adyacentes a un paciente
        case 5:while(true){
                cout<<"Ingrese fila de la cama del paciente: ";
                string qq;
                int validacionq=0;
                cin.sync();getline(cin,qq);
                int largoq= qq.length();

                //Validacion de datos
                try{
                  for(int i=0; i<largoq; i++){
                    if(int(qq[i])>=48 && int(qq[i])<=57){
                      validacionq++;
                    }
                  }
                  if(validacionq==largoq){
                    q=stoi(qq);
                    q-=1;
                    if(q>=0 && q<f){
                      break;
                    }
                    else{
                      cout<<"Error! Ingrese una fila valida"<<endl;
                      cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                      system("CLS||clear");
                    }
                  }
                  else{
                    cout<<"Error! Ingrese caracteres de tipo numerico"<<endl;
                    cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                    system("CLS||clear");
                  }
                }
                catch(out_of_range){
                  cout<<"Error! Ingrese una fila valida"<<endl;
                  cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                  system("CLS||clear");
                }
                catch(invalid_argument){
                  cout<<"Error! Ingrese una columna valida"<<endl;
                  cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                  system("CLS||clear");
                }
              }

              while(true){
                      cout<<"Ingrese columna de la cama del paciente: ";
                      string ww;
                      int validacionw=0;
                      cin.sync();getline(cin,ww);
                      int largow= ww.length();

                      //Validacion de datos
                      try{
                        for(int i=0; i<largow; i++){
                          if(int(ww[i])>=48 && int(ww[i])<=57){
                            validacionw++;
                          }
                        }
                        if(validacionw==largow){
                          w=stoi(ww);
                          w-=1;
                          if(w>=0 && w<c){
                            break;
                          }
                          else{
                            cout<<"Error! Ingrese una columna valida"<<endl;
                            cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                            system("CLS||clear");
                          }
                        }
                        else{
                          cout<<"Error! Ingrese caracteres de tipo numerico"<<endl;
                          cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                          system("CLS||clear");
                        }
                      }
                      catch(out_of_range){
                        cout<<"Error! Ingrese una columna valida"<<endl;
                        cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                        system("CLS||clear");
                      }
                      catch(invalid_argument){
                        cout<<"Error! Ingrese una columna valida"<<endl;
                        cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                        system("CLS||clear");
                      }
                    }

                pacientesadyacentes(q,w,k);
                #ifdef _WIN32
                system("PacientesAdyacentes.txt");
                #elif __linux__
                system("head PacientesAdyacentes.txt");
                #endif
                cout<<"Presione enter para continuar..."<<endl;getline(cin,s);
                system("CLS||clear");
                break;
    }

  } while(x!=6); //Exit

  return 0;
}
