#include <iostream>

using namespace std;

class alumno{
  private:
    char nombre[100];
    int claveucc;
    int nota1;
    int nota2;
    int nota3;
    float promedio;

  public:
    void setnombre( char *a, int l);
    void setclaveucc( int b);
    void setnota1( int c);
    void setnota2 (int v);
    void setnota3( int z);
    void getnombre();
    int getclaveucc();
    int getnota1();
    int getnota2();
    int getnota3();
    int getpromedio();
    bool getaprobar();

};

void alumno::setnombre( char *nombre, int l){
  for( int i=0; i<l; i++){
    this->nombre[i]=nombre[i];
  }
}
void alumno::setclaveucc( int claveucc){
  this->claveucc=claveucc;
}
void alumno::setnota1( int nota1){
  this->nota1=nota1;
}
void alumno::setnota2( int nota2){
  this->nota2=nota2;
}
void alumno::setnota3( int nota3){
  this->nota3=nota3;
}


void alumno::getnombre(){
  cout<<"El nombre del alumno es: ";
  for( int i=0; i<6; i++){
    cout<<nombre[i];
  }
  cout<<endl;

}
int alumno::getclaveucc(){
  return claveucc;
}
int alumno::getnota1(){
  return nota1;
}
int alumno::getnota2(){
  return nota2;
}
int alumno::getnota3(){
  return nota3;
}

int alumno::getpromedio(){
  promedio=(nota1+nota2+nota3)/3;
  return promedio;
}

bool alumno::getaprobar(){
  return promedio>=4;
}

int main(){

  alumno A;
  int nota1,nota2,nota3,claveucc;
  string x;
  char *k;

  cout<<"Ingrese nombre del alumno: "; cin>>x;
  int largo= x.length();
  char *p, nombre[largo];

  p=nombre;

  for( int i=0; i<largo; i++){
    p[i]=x[i];
  }
  A.setnombre(p,largo);

  cout<<"Ingrese clave UCC: "; cin>>claveucc;
  A.setclaveucc(claveucc);
  cout<<"Ingrese primera nota: "; cin>>nota1;
  A.setnota1(nota1);
  cout<<"Ingrese segunda nota: "; cin>>nota2;
  A.setnota2(nota2);
  cout<<"Ingrese tercera nota: "; cin>>nota3;
  A.setnota3(nota3);


  A.getnombre();
  cout<<"La clave UCC del alumno es: "<<A.getclaveucc()<<endl;
  cout<<"El promedio del alumno es: "<<A.getpromedio()<<endl;

  if(A.getaprobar()==1){
    cout<<"El alumno aprobo la asignatura";
  }
  else{
    cout<<"El alumno reprobo la asignatura";
  }



  return 0;
}
