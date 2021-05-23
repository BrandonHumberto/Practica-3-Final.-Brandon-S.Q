#include <iostream>
#include <string.h>
/////////////////////////////////////////////////////////////
//Practica-3- Final. Realizada por Brandon Segnini Quesada.//
/////////////////////////////////////////////////////////////
using namespace std;
struct equipo{
  string cargaconectada ;
  string nombre_1;
  string descripcion;
  equipo *siguiente;
};
struct tiempo{
  float hours;
  tiempo *siga;
};
struct potencia{
  float consumo;
  potencia *adelante;
};
struct dispositivo{
  string carga;
  dispositivo *desplazar;
};
 void opciones(); 
 //Agregando todos los prototipos de funciones
 void insertarlista(equipo *&,string);   //ok
 void insertartipo(dispositivo *&,string);
 void insertarconsumo(potencia *&,int c); //ok
 void insertarhoras(tiempo *&,int);  //ok
 void mostrarhoras(tiempo *);  //ok
 void mostrarreporte(equipo *); //ok
 equipo *lista = NULL;
 tiempo *lista_horas =NULL;
 potencia *listado=NULL;
 dispositivo *lis=NULL;
int main() {
 opciones();
 return 0;
}
 //Creando un menú de opciones para la selección del usuario, ademas las variables. 
void opciones(){
  int opcion;
  string cargaconectada;
  string nombre_1;
  string descripcion;
  string carga;
  float hours;
  float consumo;
  bool escoja;
 do{
   cout<<" \n               Elija una opcion: \n";
   cout<<"\n 1. Insertar las cargas que se encuentran  conectadas en su hogar y sus horas de uso.\n";
   cout<<"\n 2. Mostrar las cargas y su tiempo de uso. \n";
   cout<<"\n 3. Mostrar reporte final.\n";
   cout<<"\n 4. Salir";
   cout<< "\n                         Opcion: ";
   cin>>opcion;
    
 switch  (opcion){
    case 1:
  
    cout<<"Digite 0 si desea agregar descripcion al dispositivo sino,presione 1,luego Enter.\n";
    cin>>escoja;
    cout<<"seleccionó la opción: "<<escoja;
    if(escoja==1){
    cout<<"\nNombre del dispositivo: ";
    cin>>nombre_1;
    carga=nombre_1;
    cargaconectada=nombre_1;
    cout<<"Tipo:"<< carga;
    cout<<"      consumo: ";
    cin>>consumo;
    cout<<"consumo:"<<consumo<<" watts";
    cout<<"\n                Digite las horas de uso: ";
    cin>> hours;
    insertarhoras(lista_horas,hours);
    insertarlista(lista,cargaconectada);
    insertartipo(lis,carga);
    insertarconsumo(listado,consumo);
    cout<<"\n";
    system("clear");
  
    }
    if(escoja==0){
    cout<<"\nNombre del dispositivo: ";
    cin>>nombre_1;
    cin>>descripcion;
    carga=nombre_1;
    cargaconectada=nombre_1 + " " + descripcion;
    cout<<"Tipo:"<< carga;
    cout<<"      consumo: ";
    cin>>consumo;
    cout<<"consumo:"<<consumo<<" watts";
    cout<<"\n               Digite las horas de uso: ";
    cin>> hours;
    insertarhoras(lista_horas,hours);
    insertarlista(lista,cargaconectada);
    insertarconsumo(listado,consumo);
    insertartipo(lis,carga);
    cout<<"\n";
    system("clear");
    }
    
    break;
 
   case 2: 
   mostrarhoras(lista_horas);
   cout<<"\n";
   break;
 
   case 3: 
   mostrarreporte(lista);
   cout<<"\n";
   break;
    
   case 4:
   system("clear");
   break;
 }
 }while(opcion != 4);
}
//Creando nodos para almacenar el consumo de cada carga.
void insertarconsumo(potencia *&listado,int c){
  
  potencia *nueva_potencia=new potencia(); //reservando espacio de memoria
  nueva_potencia -> consumo=c; //Se almacena el consumo agregado por el usuario en la variable c
  potencia *aux1=listado; // Guardando los datos en aux1
  potencia *aux2; //Su funcion:Ordenar los datos al final
  //El dato ingresado por el usuario es diferente a NULL entra al While y   los desplaza a la ultima posición.
  while ( aux1 != NULL) {
    aux2 =aux1;  //Referencia para desplazar el siguiente dato
    aux1 =aux1->adelante;//colocandolo al final
    }
    //Cumple cuando el dato vaya al inicio, sino, lo desplaza al final. 
  if(listado==aux1){
    listado=nueva_potencia;
   }
  
  else{
    aux2->adelante=nueva_potencia;
  }
    nueva_potencia->adelante=aux1;  
}
void insertarlista(equipo *&lista,string n){
 equipo *nuevo_equipo =new equipo();
 nuevo_equipo -> cargaconectada=n;
 //Agregando elementos a la lista y guardandolo en la variable cargaconectada
 equipo *aux1=lista;
 equipo *aux2;
 // insertando elementos en forma ordenada
 // && (aux1->cargaconectada != n))
 while ( aux1 != NULL) {
   aux2 =aux1;
   aux1 =aux1->siguiente;
 }
 if(lista==aux1){
   lista=nuevo_equipo;
 }
 else{ 
   aux2->siguiente=nuevo_equipo;
  } 
}

void insertartipo(dispositivo *&lis,string t){
 dispositivo *nuevo_dispositivo =new dispositivo();
 nuevo_dispositivo -> carga=t;
 //Agregando elementos a la lista y guardandolo en la variable cargaconectada
 dispositivo *aux1=lis;
 dispositivo *aux2;
 // insertando elementos en forma ordenada
 // && (aux1->cargaconectada != n))
 while ( aux1 != NULL) {
   aux2 =aux1;
   aux1 =aux1->desplazar;
 }
 if(lis==aux1){
   lis=nuevo_dispositivo;
 }
 else{ 
   aux2->desplazar=nuevo_dispositivo;
  } 
cout<< t <<" tipo insertado a la lista correctamente\n"; 
}
//Crear nodo para desplegar las horas y los equipos ingresadas por el usuario.
void mostrarhoras(tiempo *lista_horas){
  tiempo *nuevo= new tiempo();
  equipo *actual =new equipo();
  actual = lista;  //Asignar lista a actual.
  nuevo=lista_horas;//Asignar lista_horas a nuevo.
  //Cuando la lista sea igual a NULL quiere decir que ya a recorrido toda la lista.
  while (nuevo != NULL){
   cout<<actual->cargaconectada<<": "<<nuevo-> hours<<" horas"<<" \n";
   nuevo=nuevo->siga; //Muestra y lo desplaza hasta que sea igual a NULL
   actual=actual->siguiente;//Muestra y lo desplaza hasta que sea igual a NULL, de esta manera despliega todos los equipos con sus horas de uso.
 }
}
// Creando la funcion para el reporte final de usuario
void mostrarreporte(equipo *lista){
  float valor1; //variable creada para almacenar el consumo y las horas
  float valor2; //variable creada para almacenar las horas
  float total1;//Almacena la cantidad de watts-hora de cada equipo digitado
   string carga;
  potencia *nueva_potencia=new potencia();
  dispositivo *nuevo_dispositivo =new dispositivo();
  equipo *actual=new equipo();
  tiempo *nuevo_tiempo=new tiempo();
  actual =lista;
  nueva_potencia=listado;
  nuevo_dispositivo=lis;
  nuevo_tiempo=lista_horas;
  
  while ((actual != NULL) && (nueva_potencia !=NULL)&&(nuevo_tiempo!=NULL)) {
   valor1=((nueva_potencia -> consumo));
   valor2=((nuevo_tiempo -> hours));
   total1=valor1*valor2;
   cout<<nuevo_dispositivo -> carga<<": "<<(total1)<<" watts-hora"<<"\n";
   actual=actual->siguiente;
   nueva_potencia=nueva_potencia->adelante;
   nuevo_tiempo=nuevo_tiempo->siga;
   nuevo_dispositivo=nuevo_dispositivo->desplazar;
   }
  }
void insertarhoras(tiempo *&lista_horas,int h){
 tiempo *nuevo_tiempo=new tiempo();
 potencia *nueva_potencia=new potencia();
 equipo *actual=new equipo();
 nuevo_tiempo ->  hours=h;
 tiempo *aux1=lista_horas;
 tiempo *aux2;
 actual =lista;

 while (( aux1 != NULL) && (actual != NULL)){  
   aux2 =aux1;
   aux1 =aux1->siga;
   actual=actual->siguiente;
  }
 if(lista_horas==aux1){
   lista_horas=nuevo_tiempo;
  }
 else{
   aux2->siga=nuevo_tiempo;
 } 
}  