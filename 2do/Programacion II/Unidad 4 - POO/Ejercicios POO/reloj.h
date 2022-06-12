#include <iostream>

using namespace std;

class tiempo{
  private:
    int hora;
    int min;
    int seg;
    int horaalarma;
    int minalarma;
    int segalarma;
    int talarma;

  public:
    void operator++();
    void sethora (int h);
    void setmin (int m);
    void setseg (int s);
    int gethora ();
    int getmin();
    int getseg();
    void sethoraalarma(int x);
    void setminalarma(int y);
    void setsegalarma(int z);
    int gethoraalarma();
    int getminalarma();
    int getsegalarma();
    void settiempoalarma(int t);
    int gettiempoalarma();
    //void acumulador ();
    bool alarma ();
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

    void tiempo:: sethoraalarma (int x){
      horaalarma=x;
    }
    void tiempo:: setminalarma (int y){
      minalarma=y;
    }
    void tiempo:: setsegalarma (int z){
      segalarma=z;
    }

    int tiempo:: gethoraalarma (){
      return horaalarma;
    }
    int tiempo:: getminalarma (){
      return minalarma;
    }
    int tiempo:: getsegalarma (){
      return segalarma;
    }

    void tiempo:: settiempoalarma(int a){
      talarma=a;
    }
    int tiempo:: gettiempoalarma(){
      return talarma;
    }

/*    void tiempo:: acumulador(){
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

        for( int i=0; i<10000000; i++){
        }
      }
*/
      bool tiempo:: alarma (){
        int o= (horaalarma*3600)+(minalarma*60)+segalarma;
        int p= (hora*3600)+(min*60)+seg;

        if(p==o+1){
          for(int i=1; i<=talarma; i++){

          cout<<"*SUENA LA ALARMA*"<<endl;

        cout<<hora<<":";
        cout<<min<<":";
        cout<<seg<<endl;
        operator++();

      }

    }
      return p==o;
  }

  void tiempo::operator++(){
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

    for( int i=0; i<10000000; i++){
    }
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
