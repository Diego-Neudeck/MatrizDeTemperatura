#include <iostream>
using namespace std;

char menu();
void carga(float **ptTEM,int F,int C);
float *busqueda(float **ptTEM,int F,int C);
int comparar(float **ptTEM,int F,int C,float X);

int main(int argc, char *argv[]) {
	char selec;
	float **ptTEM,*ptMAX;
	int b=0,F,C,X,com;
	do{
		selec=menu();
		if(selec=='1'){
			cout<<"ingrese cantidad de filas"<<endl;
			cin>>F;
			cout<<"ingrese la cantidad de columnas"<<endl;
			cin>>C;
			ptTEM=new float*[F];
			for(int i=0;i<F;i++){
				*(ptTEM+i)=new float[C];
			}
			carga(ptTEM,F,C);
			b=1;
		}
		if(selec=='2' && b==1){
			ptMAX=busqueda(ptTEM,F,C);
			for(int i=0;i<F;i++){
				cout<<"el mayor valor de la fila "<<i<<" es: "<<*(ptMAX+i)<<endl;
			}
		}
		if(selec=='3' && b==1){
			cout<<"ingrese un numero a buscar"<<endl;
			cin>>X;
			com=comparar(ptTEM,F,C,X);
			if(com==0)
				cout<<endl<<"no se encontro el valor de temperatura ingresado"<<endl<<endl;
			else
				cout<<endl<<"el valor de temperatura ingresado se encuentra"<<endl<<endl;
		}
		
	}while(selec!='s');
	
	for(int i=0;i<F;i++)
		delete[] *(ptTEM+i);
	delete[] ptTEM;
	return 0;
}

char menu(){
	char selec;
	int b=0;
	do{
		cout<<"1-ingresa la direccion del arreglo ,N,M y cargar"<<endl;
		cout<<"2-Buscar y mostrar la mayor temperatura por fila"<<endl;
		cout<<"3-Comparar y mostrar"<<endl;
		cout<<"s-salir"<<endl;
		cin>>selec;
		switch(selec){
		case '1':
			b=1;
			break;
		case '2':
			b=1;
			break;
		case '3':
			b=1;
			break;
		case 's':
			b=1;
			break;
		default:{
			cout<<endl<<"error, reingrese"<<endl<<endl;
			b=0;
		}
		}
	}while(b!=1);
	return(selec);
}

void carga(float **ptTEM,int F,int C){
	cout<<"carga la matriz"<<endl;
	
	for(int a=0;a<F;a++){
		for(int b=0;b<C;b++){
			cout<<"ingrese la temperatura perteneciente a la fila "<<a<<" y a la columna "<<b<<endl;
			cin>>*(*(ptTEM+a)+b);
		}
	}

}

float *busqueda(float **ptTEM,int F,int C){
	float *ptMAX;
	ptMAX=*(ptTEM);
	
	for(int a=0;a<F;a++){
		for(int b=0;b<C;b++){
			if(*(*(ptTEM+a)+b)>*(ptMAX+a))
				*(ptMAX+a)=*(*(ptTEM+a)+b);
		}
	}

	return (ptMAX);
}

int comparar(float **ptTEM,int F,int C,float X){
	int ban=0;
	for(int a=0;a<F;a++){
		for(int b=0;b<C;b++){
			if(*(*(ptTEM+a)+b)==X)
				ban=1;
		}
	}
	return(ban); 
		
}
