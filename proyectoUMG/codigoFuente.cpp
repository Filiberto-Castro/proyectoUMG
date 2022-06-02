#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>  

using namespace std;

void gotoxy(int x,int y)
{  
HANDLE hcon;  
hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
COORD dwPos;  
dwPos.X = x;  
dwPos.Y= y;  
SetConsoleCursorPosition(hcon,dwPos);  
}  



main()
{
	char nom[30][50], edad[5][50], tel[15][50];
	char d[15][50], m[15][50], a[15][50];
	char pago[20][50];
	int cla,opc;
	int n,n1;
	int cont=0;
	
	
	INICIO:
	system("cls");
	cout<<"***>>> GIMNASIO SUPER MAMADISIMOS <<<***"<<endl;
		//IGRESO DE CLAVE DE ACCESO
		cout<<"\n -----------------------"<<endl;
		cout<<"|**>> INGRESE CLAVE <<**|"<<endl;
		cout<<" -----------------------"<<endl;
		cout<<"      |            |    "<<endl;
		cout<<"       ------------     "<<endl;
gotoxy(10,5);cin>>cla;

if(cla==201302)
{// INICIO MENU
	MENU:
		system("cls");
		cout<<"**<< MENU DE REGISTRO >>**"<<endl;
		cout<<" -----------------------"<<endl;
		cout<<"| 1-> |NUEVO CLIENTE    |"<<endl;
		cout<<"| 2-> |VER CLIENTES     |"<<endl;
		cout<<"| 3-> |BUSCAR CLIENTE   |"<<endl;
		cout<<"| 4-> |MODIFICAR DATOS  |"<<endl;
		cout<<" -----------------------"<<endl;
		cout<<"<< SELECCIONE UNA OPCION >>"<<endl;
		cout<<" -------------------------"<<endl;
		cout<<"          |     |        "<<endl;
		cout<<"           -----"<<endl;
gotoxy(13,9);cin>>opc;

	switch(opc)
	{//INICIO DE SWITCH
	
		//INICIO CASO 1
		case 1:
		{
			INGRESO:
			system("cls");
			cont=cont+1;
      		cout<<"         ----------------> INGRESO DE CLIENTES <--------------- "<<endl;
      		cout<<"                                                              "<<endl;
      		cout<<" ----------------------------------------------------------------------"<<endl;
      		cout<<"| NO. |       Nombres       |  Telefonos | Edad |   Fecha   |    Pago  |"<<endl;
      		cout<<" ----------------------------------------------------------------------"<<endl;
      		cout<<"|     |                     |            |      |           |Q.        |"<<endl;
      		cout<<" ----------------------------------------------------------------------"<<endl;
      		cout<<"| Ingresar Otro: 1.SI - 2. No ------> |           |"<<endl;
      		cout<<" -------------------------------------------------"<<endl;
      		gotoxy(4,5);  cout<<cont;
      		fflush(stdin);
      		gotoxy(9,5); gets(nom[cont]);
      		gotoxy(31,5); cin>>tel[cont];
      		gotoxy(44,5); cin>>edad[cont];
      		gotoxy(51,5); cin>>d[cont];
      		gotoxy(53,5); cout<<"-";
      		gotoxy(54,5); cin>>m[cont];
      		gotoxy(56,5); cout<<"-";
      		gotoxy(57,5); cin>>a[cont];
      		gotoxy(65,5); cin>>pago[cont];
      		
     		gotoxy(43,7); cin>>opc;
     		if(opc==1)
     		{
            	goto INGRESO;
      		}
      		else
      		{
            	goto MENU;
      		}
      		system("pause");
      		
		}//FIN CASO 1
		
		//INICIO CASO 2
		case 2:
		{
			system("cls");
			
			cout<<"         ----------------> LISTADO DE CLIENTES <--------------- "<<endl;
      		cout<<"                                                              "<<endl;
      		cout<<"\n -----------------------------------------------------------------------";
      		cout<<"\n| NO. |       Nombre        |  Telefonos  | Edad |   Fecha   |   Pago   |";
      		cout<<"\n -----------------------------------------------------------------------";
      		for(int i=1; i<=cont; i++)
      		{
      		cout<<"\n|     |                     |             |      |           |Q.        |";
    
			gotoxy(3,5+i);  cout<<i;
      		gotoxy(9,5+i); cout<<nom[i];
      		gotoxy(32,5+i); cout<<tel[i];
      		gotoxy(45,5+i); cout<<edad[i];
      		gotoxy(51,5+i); cout<<d[i];
      		gotoxy(53,5+i); cout<<"-";
      		gotoxy(54,5+i); cout<<m[i];
      		gotoxy(56,5+i); cout<<"-";
      		gotoxy(57,5+i); cout<<a[i];
      		gotoxy(67,5+i); cout<<pago[i];
		
			}  		
      		cout<<"\n -----------------------------------------------------------------------";
			
			cout<<"\n PRESIONE ENTER PARA REGRESAR--------"<<endl;
			system("pause");
			goto MENU;	
		}//FIN CASO 2
		
		//INICIO CASO 3
		case 3:
		{
			BUSQUEDA:
			system("cls");
    		cout<<"         ----------------> BUSCAR CLIENTES <------------------ "<<endl;
      		cout<<"                                                              "<<endl;
      		cout<<"\n                           -------------------";
      		cout<<"\n                          |  Numero:   |      |";
      		cout<<"\n --------------------------------------------------------------"<<endl;
      		cout<<"|       Nombres       |  Telefonos | Edad |   Fecha   |  Pago  |"<<endl;
   			cout<<" --------------------------------------------------------------"<<endl;
   			cout<<"|                     |            |      |           |Q.      |"<<endl;
   			cout<<" --------------------------------------------------------------"<<endl;
    	 	cout<<"| Buscar Otro: 1.SI - 2. No -----> |      |"<<endl;
   			cout<<" -----------------------------------------"<<endl;
   		    
			gotoxy(42,4); cin>>n;
    		
			if(n>cont||n<1)
      		{
     	    	gotoxy(3,12); cout<<"\n OPCION NO VALIDA  ";
     		}
      		
			else
      		{
      		
      			gotoxy(3,8); cout<<nom[n];
      			gotoxy(25,8); cout<<tel[n];
      			gotoxy(38,8); cout<<edad[n];
      			gotoxy(45,8); cout<<d[n];
      			gotoxy(47,8); cout<<"-";
      			gotoxy(48,8); cout<<m[n];
      			gotoxy(50,8); cout<<"-";
      			gotoxy(51,8); cout<<a[n];
      			gotoxy(58,8); cout<<pago[n];
     		}
     		
      		gotoxy(38,10); cin>>opc;
      	
      		if(opc==1)
      		{
      			goto BUSQUEDA;
     		}
      		else
      		{
      			system("pause");
       			goto MENU;
      		}		
		}//FIN DEL CASO 3
		
		
		//INICIO CASO 4
		case 4:
		{
			MODIFICAR:
			system("cls");
			
			cout<<"         ----------------> MODIFICAR CLIENTES <------------------ "<<endl;
      		cout<<"                                                              "<<endl;
      		cout<<"\n                           -------------------";
      		cout<<"\n                          |  Numero:   |      |";
      		cout<<"\n --------------------------------------------------------------"<<endl;
      		cout<<"|       Nombres       |  Telefonos | Edad |   Fecha   |  Pago  |"<<endl;
   			cout<<" --------------------------------------------------------------"<<endl;
   			cout<<"|                     |            |      |           |Q.      |"<<endl;
   			cout<<" --------------------------------------------------------------"<<endl;
   			cout<<" --------------------------------------------------------------"<<endl;
   			cout<<"|                     |            |      |           |Q.      |"<<endl;
   			cout<<" --------------------------------------------------------------";
    	 	cout<<"\n| 1. MODIFICAR - 2. REGRESAR - 3 BUSCRA OTRO|      |";
      		cout<<"\n ---------------------------------------------------";
			
			gotoxy(42,4); cin>>n1;
      		if(n1>cont||n1<1)
      		{
      			gotoxy(3,8); cout<<"\n OPCION NO VALIDA  ";
      		}
      		else
      		{
      			gotoxy(3,8); cout<<nom[n1];
      			gotoxy(25,8); cout<<tel[n1];
      			gotoxy(38,8); cout<<edad[n1];
      			gotoxy(45,8); cout<<d[n1];
      			gotoxy(47,8); cout<<"-";
      			gotoxy(48,8); cout<<m[n1];
      			gotoxy(50,8); cout<<"-";
      			gotoxy(51,8); cout<<a[n1];
      			gotoxy(58,8); cout<<pago[n1];
      		}
      		
     		gotoxy(46,13); cin>>opc;
      		
			  if(opc==1)
      		{
      			fflush(stdin);
      			gotoxy(3,11); gets(nom[n1]);
      			gotoxy(25,11); cin>>tel[n1];
      			gotoxy(38,11); cin>>edad[n1];
      			gotoxy(45,11); cin>>d[n1];
      			gotoxy(47,11); cout<<"-";
      			gotoxy(48,11); cin>>m[n1];
      			gotoxy(50,11); cout<<"-";
      			gotoxy(51,11); cin>>a[n1];
      			gotoxy(58,11); cin>>pago[n1];
				goto MENU;
      		}
      		
      		else if(opc==2)
      		{
       			goto MENU;
      		}
      		
      		if(opc==3)
      		{
        		goto MODIFICAR;
      		}		
      		system("pause");
		}//FIN DE CASO 4
		
		
	}//FIN DE SWITCH
			
}//FIN MENU

else
{
	system("cls");
	cout<<"*** CLAVE INCORRECTA*** "<<endl;
	cout<<"*** INTENTE DE NUEVO POR FAVOR ***"<<endl;
	
	system ("pause");
	goto INICIO;
}
	
	
}//FIN DEL PROGRAMA
