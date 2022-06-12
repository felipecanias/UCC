#include <iostream>

using namespace std;

class tiempo{
  private:
    int hora;
    int min;
    int seg;
    int f;

  public:
    void sethora (int h);
    void setmin (int m);
    void setseg (int s);
    int gethora ();
    int getmin();
    int getseg();
    void setfrenar ( int a);
    void acumulador ( int &h, int &m, int &s);
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
    void tiempo:: setfrenar(int a){
      f=a;
    }

    void tiempo:: acumulador( int &hora, int &min, int &seg){
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

      }while();

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

    class alarma{
      private:
        int horaalarma;
        int minalarma;
        int segalarma;

      public:
        void sethoraalarma (int h);
        void setminalarma (int m);
        void setsegalarma (int s);
        bool comparador (int h, int m, int s, int x, int y, int z);
      };

      void alarma:: sethoraalarma (int h){
        horaalarma=h;
      }
      void alarma:: setminalarma (int m){
        minalarma=m;
      }
      void alarma:: setsegalarma (int s){
        segalarma=s;
      }

      bool alarma:: comparador (int h, int m, int s, int x, int y, int z){
        return h==x && m==y && s==z;
      }



int main(){
  tiempo H;
  temperatura T;
  alarma A;
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
  A.sethoraalarma(xx);
  cout<<"Ingrese minutos de la alarma: "; cin>>yy;
  A.setminalarma(yy);
  cout<<"Ingrese segundos de la alarma: "; cin>>zz;
  A.setsegalarma(zz);

  cout<<"------------------"<<endl;
  cout<<"La hora es: ";
  cout<<H.gethora()<<":";
  cout<<H.getmin()<<":";
  cout<<H.getseg()<<endl;
  cout<<"La temperatura es: "<<T.gettemp()<<" grados C"<<endl;

  H.acumulador(x,y,z);
  // p=A.comparador(xx,yy,zz,x,y,z);
  // cout<<p;
  // H.setfrenar(p);



  return 0;
}
