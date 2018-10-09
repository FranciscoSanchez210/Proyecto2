#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include<stdlib.h> 
#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#define PRS(x) printf ("%s\n",x)
#include <limits>
#include <stdexcept>
#include <windows.h>
using namespace std;
string usuario;
string psswd;

void passw(string contra){
	char caracter;
	caracter=getch();
	contra="-";
	while(caracter!= 13){
	contra.push_back(caracter);
	cout<<"*";
	caracter=getch();
	}
	fflush(stdin);
}

struct console
  {
  console( unsigned width, unsigned height )
    {
    SMALL_RECT r;
    COORD      c;
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (!GetConsoleScreenBufferInfo( hConOut, &csbi ))
      throw runtime_error( "You must be attached to a human." );

    r.Left   =
    r.Top    = 0;
    r.Right  = width;
    r.Bottom = height ;
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }
    

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  };
  
  console con( 60, 20 );


struct administrador{
	
	long int cedula;
	int edad;
	string nombre;
	string sexo;
	
}admin;

struct jugador{
	
	string nombre;
	int edad;
	long int cedula;
	char sexo;
	
}jugadores[20];


void inicio()
{	
	string psswdv;
	cout<<"\t\t\t=========================="<<endl;
	cout<<"\t\t\t\t BIENVENIDO"<<endl;
	cout<<"\t\t\t=========================="<<endl;
	cout<<"\nA continuacion se registrara un Administrador\nLlene los campos solicitados a continuacion\n\n"<<endl;
	cout<<"Ingrese un nombre de usuario:";
	cin>>usuario;
	cout<<"Escriba una contrasenia:";
	cin>>psswd;
	cout<<endl;
	cout<<"Escriba nuevamente su contrasenia:";
	cin>>psswdv;
	cout<<endl;
	if (psswdv != psswd){
		do{
		cout<<"Las contrasenias no coinciden"<<endl;
		cout<<"Vuelva a escribir la contrasenia:";
		cin>>psswdv;
		}
		while (psswdv != psswd);
	}
	else;
	cout<<"Ingrese su nombre:";
	cin>>admin.nombre;
	cout<<"Ingrese su edad:";
	cin>>admin.edad;
	cout<<"Ingrese sexo(M/F):";
	cin>>admin.sexo;
}

void eleccion()
{	int eleg,elec;
	int add=0;
	string usuario,pass,usv,passv;
	cout<<"==================================================="<<endl;
	cout<<"\t\t BIENVENIDO"<<endl;
	cout<<"==================================================="<<endl;
inicio:	
	system ("color F8" );
	cout<<"Selecciona como deseas ingresar"<<endl;
	cout<<"[1]Administrador\n[2]Usuario club \n[0]Salir"<<endl;
	cout<<"Responder:";
	cin>>eleg;
	system("CLS");
	if (eleg==1)
	{	string usv;
		cout<<"Usuario:";
		cin>>usuario;
		cout<<"Contrasenia:";
		cin>>pass;
		ifstream archivo("admin.txt");
        int contador = 0;
        int max=1;
        getline(archivo,usv);
        while(getline(archivo,passv));
        if(max==1);
        system ("CLS");
        if(usv==usuario && passv==pass){
        cout<<"Bienvenido "<<usv<<endl;
        do{
    	cout<<"\nSeleccione que desea hacer"<<endl;
opadmin:system ("color f8" ); 
		cout<<"1._Agregar clubs\n2._Imprimir datos\n3._Eliminar club\n0._Regresar al loggin"<<endl;cin>>elec;
    	switch(elec)
    	{	
    		case 0:
	    		system("CLS	");
	    		goto inicio;
	    		break;
    		case 1:
    			
    			do{
				string nclub,pclub;
				cout<<"Ingrese el nombre del club:";
				cin.ignore();
				getline(cin,nclub);	
				nclub+=".txt";			
			    ofstream club(nclub.c_str());
			    cout<<"Ingrese la contrasenia del club:";
				fflush(stdin);
				getline(cin,pclub);
				club<<pclub;
			    club.close();
			    cout<<"\nSe a creado el club"<<endl;
			    system("CLS");
			    cout<<"\nDesea agregar mas clubs?"<<endl;
			    cout<<"0._No\n1._Si"<<endl;
			    cin>>add;
			    system ("CLS");
				}
				while(add!=0);
			    break;
			case 2:
				system("CLS");
				cout<<"======================"<<endl;
				cout<<admin.nombre<<endl;
				cout<<admin.edad<<endl;
				cout<<admin.sexo<<endl;
				cout<<"======================";
				break;
			case 3:
					char *p;
					char elim[20];
					int elimres;
				cout<<"Ingrese el club que desea eliminar(Agregue.txt):";
				cin>>elim;
				system("CLS");
				system ("color 4F" );
				cout<<"Esta seguro de eliminar el club "<<elim<<"?"<<endl;
				cout<<"1._si\n0._no"<<endl;cin>>elimres;
				system ("color F8" );
				system("CLS");
				if(elimres==1){
				if (unlink (elim) == -1) {
					p = strerror (errno);
					PRS(p);
					getch();
				}
				else {
					system ("color 2F" );
					PRS("Archivo borrado del sistema");
					getch();
			
				}
				}
				else{
				system("CLS");
				goto opadmin;
				}
				
				
				break;
				
	    	}
			}while(elec!=0);
			} 
			
		
        else if(usv!=usuario || passv!=pass){
        system ("color 4F" );
        cout<<"Usuario o contrasenia incorrecto"<<endl;
        getch();
    	goto inicio;
		}
	}
	
	else if (eleg==2)
		{	
		string nclub,vclub,pv,clubg,clubsint;
		cout << "Ingresa el nombre del club: ";
        cin.ignore();
        getline(cin, nclub);
        clubsint=nclub;
        nclub += ".txt";
        clubg=nclub;
        ifstream fs(nclub.c_str(), ios:: in );
        if (fs.fail()){
          cout << "El club no existe" << endl;
          getch();
          system("CLS");
    	  goto inicio;
		  }
        else{
	        int resp;
	        getline(fs,vclub);
			cout<<"Ingrese la contrasenia:";
			fflush(stdin);
			cin>>pv;
		if(pv==vclub){
			
inicio2:
		system ("color F8" );
		cout<<"Que desea hacer?"<<endl;
		cout<<"1._Agregar jugadores\n2._Imprimir lista de jugadores\n3._Bsuqueda de jugadores\n0._Regresar al inicio"<<endl;
		cin>>resp;
		system("CLS");
		
		if(resp==1){
				
				int respuesta,cjug;
				int add=0;
				string jugador;
				char linea[20];
				getline(cin,nclub);
        		nclub += ".txt";
        		ofstream fs(clubg.c_str(),ios::app);
        		cout<<"Cuantos jugadores desea ingresar?:";
        		cin>>cjug;
        		for(int i=0;i<cjug;i++){
				cout<<"Ingrese el nombre del jugador:"<<"["<<i+1<<"]";
				fflush(stdin);
				cin>>jugadores[i].nombre;
				cout<<"Ingrese numero de cedula:"<<"["<<i+1<<"]";
				fflush(stdin);
				cin>>jugadores[i].cedula;
				cout<<"Ingrese la edad del jugador:";
				fflush(stdin);
				cin>>jugadores[i].edad;
				cout<<"Ingrese sexo del jugador "<<"["<<i+1<<"]";
				fflush(stdin);
				cin>>jugadores[i].sexo;
				fs<<"\n"<<jugadores[i].nombre<<" "<<jugadores[i].cedula<<" "<<jugadores[i].edad<<" "<<jugadores[i].sexo;
				
				}
				fs.close();
				cout<<"Se a aniadido a el/los jugador/es";
				system("CLS");
				goto inicio2;
			    }
			    
			if(resp==2){
				
				cout<<"La lista del club "<<clubsint<<" es:"<<endl;
				cout<<"=========================="<<endl;
				string lista;
				int contador=0;
				int max=1;
				ifstream fs(clubg.c_str(), ios:: in);
				while (getline(fs,lista)) {
				for(int i=1;i<20;i++)	
				if(contador == i )
	            cout<<lista<<endl;
        		contador++;
            	}
           		cout<<"=========================="<<endl;
           		cout<<"Pulse una tecla para continuar....";
				getch();
           		system("CLS");
        		goto inicio2;			
				}
				if(resp==3){
				int contador=0;
				int numc;
				char w[100],*str[120];
				string lista;
				ifstream fs(clubg.c_str(), ios:: in);
				cout<<"Ingrese el numero de cedula para la busqueda:";
				cin>>numc;
				while(getline(fs,lista)){
				//for(int i=0;i<10;i++)
				if(numc==jugadores[0].cedula)
				cout<<jugadores[0].cedula<<jugadores[0].nombre<<jugadores[0].edad<<jugadores[0].sexo<<endl;
				else
				cout<<"No se a encontrado al jugador";}
            	cout<<"\n\nPresione una tecla para regresar a las opciones.....";
            	getch();
				system("CLS");
				}//fin de opcion 3 
				if(resp==0){
					goto inicio;
				}
				else
				goto inicio2;
		}
		else{
		system("CLS");
		system("color 4F");
		cout<<"Clave erronea"<<endl;
		getch();
		goto inicio;
		}
	   
	}}
	else if (eleg==0)
	exit(1);
	else
	cout<<"error";

}

void archadmin()
{
	ofstream archivo;
    archivo.open("admin.txt",ios::out);
    archivo<<usuario<<endl;
    archivo<<psswd;
    archivo.close();
}



void primero ()
{	system ("color F8" );
	char u[20],v[20];
	inicio();
	system("CLS");
	archadmin();
    eleccion();

	
}

int main(){
		system ("color F8" );
		ifstream fs("admin.txt",ios::in);
        if( fs.is_open()){
			eleccion();
		}       
		else
		//cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
		primero();
		return 0;	
}
