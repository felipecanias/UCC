#include <iostream>

using namespace std;

class vehiculo{
  private:
    int potencia;
    int modelo;

  public:
    virtual void setpotencia();
    virtual void setmodelo();
    virtual int getpotencia();
    virtual int getmodelo();
};

class terrestre: public vehiculo(){
  private:
    int cantruedas;
    int cantpuertas;

  public:
    virtual void setcantruedas();
    virtual void setcantpuertas();
    virtual int getcantruedas();
    virtual int getcantpuertas();

  };

  class auto: public terrestre(){
    private:
      string baul;
      int capacidad;
    public:
      void setbaul();
      void setcapacidad();
      string getbaul();
      int getcapacidad();
  };

  class camion: public terrestre(){
    private:
      string tipocarga;
      int carga;
    public:
      void setcarga();
      void settipocarga();
      int getcarga();
      string tipocarga();
  };

  class tren: public terrestre(){
    private:
      int bagon;
      int pasajerosporbagon;
    public:
      void setbagon();
      void setpasajerosporbagon();
      int getbagon();
      int getpasajerosporbagon();
  };


int main(){

  return 0;
}
