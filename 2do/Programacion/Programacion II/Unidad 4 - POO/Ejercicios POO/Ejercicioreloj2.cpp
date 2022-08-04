#include <iostream>


using namespace std;

class tiempo{
  private:
    int hora;
    int min;
    int seg;

  public:
    void sethora (int h);
    void setmin (int m);
    void setseg (int s);
    int gethora ();
    int getmin();
    int getseg();
    void acumulador ( int &h, int &m, int &s, int x, int y, int z);
  };

    void tiempo:: sethora (int h){
      hora=h;
    }
    void tiempo:: setmin (int m){
      min=m;
    }
    void tiempo:: setseg (int s){
      seg=s;
    }

    int tiempo:: gethora (){
      return hora;
    }
    int tiempo:: getmin (){
      return min;
    }
    int tiempo:: getseg (){
      return seg;
    }


    void tiempo:: acumulador( int &hora, int &min, int &seg, int x, int y, int z){
      int p;
      int o= (x*3600)+(y*60)+z;
      do{
        if( hora==23 && min==59 && seg==59){
          hora=0;
          min=0;
          seg=0;
        }
        if(seg==59){
          seg=-1;
          min++;
        }
        if(min==60){
          min=0;
          hora++;
        }

        seg++;

        cout<<hora<<":";
        cout<<min<<":";
        cout<<seg<<endl;

        for( int i=0; i<10000000; i++){
        }

        p= (hora*3600)+(min*60)+seg;

      }while(p!=o);

      cout<<"*SUENA LA ALARMA*";
      }


class temperatura{
  private:
    int temp;

  public:
    void settemp( int t);
    int gettemp ();
  };

    void temperatura:: settemp (int t){
      temp=t;
    }
    int temperatura:: gettemp (){
      return temp;
    }

int main(){
  tiempo H;
  temperatura T;
  int x,y,z,c,xx,yy,zz,p=0;

  cout<<"Ingrese hora:"; cin>>x;
  H.sethora(x);
  cout<<"Ingrese minutos: "; cin>>y;
  H.setmin(y);
  cout<<"Ingrese segundos: "; cin>>z;
  H.setseg(z);
  cout<<"Ingrese temperatura en grados C: "; cin>>c;
  T.settemp(c);
  cout<<"Ingrese hora de la alarma:"; cin>>xx;
  cout<<"Ingrese minutos de la alarma: "; cin>>yy;
  cout<<"Ingrese segundos de la alarma: "; cin>>zz;

  cout<<"------------------"<<endl;
  cout<<"La hora es: ";
  cout<<H.gethora()<<":";
  cout<<H.getmin()<<":";
  cout<<H.getseg()<<endl;
  cout<<"La temperatura es: "<<T.gettemp()<<" grados C"<<endl;

  H.acumulador(x,y,z,xx,yy,zz);

  return 0;
}
