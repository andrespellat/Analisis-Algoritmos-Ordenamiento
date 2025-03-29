#include <iostream>
#include <random>   
#include <chrono>   
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
using namespace chrono;

#define NUM_PRUEBAS 1000
#define MIN_TAMANIO 10
#define MAX_TAMANIO 1000
#define INCREMENTO 10
#define NUM_TAMANIOS (MAX_TAMANIO-MIN_TAMANIO)/INCREMENTO+1
#define NUM_ALGORITMOS 7

void probarAlgoritmos(string[]);
void generarArregloTamanios(int[]);
void generarArregloAleatorio(int[], int);
void copiarArregloAleatorio(int[], int[], int);
void imprimirArreglo(int[], int);
void ordenarArreglo(int[], int, int);
void INSERTION_SORT(int[], int);
void BUBBLE_SORT(int[], int);
void SELECTION_SORT(int[], int);
void SHELL_SORT(int[], int);
void MERGE_SORT(int[], int, int);
void MERGE(int[], int, int, int);
void QUICK_SORT(int[], int, int);
int  PARTITION(int[], int, int);
void HEAP_SORT(int[], int);
void BUILD_MAX_HEAP(int[], int);
void MAX_HEAPIFY(int[], int, int);
void calcularTiemposPromedio(double[][NUM_TAMANIOS][NUM_ALGORITMOS], double[][NUM_ALGORITMOS]);
void exportarResultados(double[][NUM_TAMANIOS][NUM_ALGORITMOS], double[][NUM_ALGORITMOS], int[], string[]);

int main(){
    int arregloTamanios[NUM_TAMANIOS];
    string arregloNombres[NUM_ALGORITMOS]={"Insercion","Burbuja","Seleccion","Shell","Mezcla","Rapido","Monticulos"};
    double arregloTiemposDeEjecucion[NUM_PRUEBAS][NUM_TAMANIOS][NUM_ALGORITMOS]; 
    double arregloTiemposPromedio[NUM_TAMANIOS][NUM_ALGORITMOS];
    int* arregloAleatorio;
    int* arregloCopia;
    
    //Se imprime en pantalla un arreglo aleatorio de prueba y el resultado de ordenar dicho arreglo con todos los
    //algoritmos para verificar que ordenan correctamente.
    
    probarAlgoritmos(arregloNombres);
    
    //Se genera un arreglo con los tamaños de arreglo a probar, i.e., [10,20,30,....,1000]
    
    generarArregloTamanios(arregloTamanios);
    
    //Se calculan los tiempos de ejecución.
    //Para ello, se usan 3 ciclos anidados. El índice j indica el número de tamaño de arreglo que se ordena, el índice i
    //indica el número de prueba que se realiza y el índice k indica el algoritmo que se utiliza para ordenar.
    
    for(int j=0; j<NUM_TAMANIOS; j++){
        
        //Para cada tamaño de arreglo se reserva el espacio en memoria necesario para dos arreglos de enteros del j-ésimo tamaño.
        //arregloAleatorio es el arreglo de enteros aleatorios que se va a generar y arregloCopia es una copia de arregloAleatorio.
        //arregloCopia es el arreglo que se va a ordenar con los algoritmos, el cual se utiliza para garantizar que todos los algoritmos 
        //se prueban con los mismos arreglos.
        
        arregloAleatorio=new int[arregloTamanios[j]];
        arregloCopia=new int[arregloTamanios[j]];
        
        for(int i=0; i<NUM_PRUEBAS; i++){
            
            //Para cada prueba se genera un nuevo arreglo aleatorio del j-ésimo tamaño.
            
            generarArregloAleatorio(arregloAleatorio, arregloTamanios[j]);
            
            for(int k=0; k<NUM_ALGORITMOS; k++){
                
                //Para cada algoritmo se obtiene una copia nueva del arreglo aleatorio generado, se toma el tiempo inicial,
                //se ordena la copia del arreglo aleatorio, se toma el tiempo final y se calcula el tiempo de ejecución 
                //del algoritmo en nanosegundos. Este tiempo de ejecución se convierte a microsegundos y se guarda en el 
                //arreglo tridimensional de tiempos de ejecución en la posición (i,j,k).
                
                copiarArregloAleatorio(arregloAleatorio, arregloCopia, arregloTamanios[j]);
                steady_clock::time_point tiempoInicial = steady_clock::now();
                ordenarArreglo(arregloCopia, arregloTamanios[j], k);
                steady_clock::time_point tiempoFinal = steady_clock::now();
                nanoseconds tiempoDeEjecucion = duration_cast<nanoseconds>(tiempoFinal-tiempoInicial);
                arregloTiemposDeEjecucion[i][j][k]=tiempoDeEjecucion.count()*pow(10,-3);
            }
        }
        
        //Una vez completadas todas las pruebas con todos los algoritmos para el j-ésimo tamaño de arreglo, se imprime en pantalla
        //un mensaje de confirmación para poder visualizar el progreso del programa durante su ejecución. Además, se libera el 
        //espacio de memoria reservado para el arreglo aleatorio y su copia para que pueda ser utilizado para las pruebas con
        //los tamaños de arreglo que restan.
        
        cout<<"Pruebas completadas con todos los algoritmos para los arreglos de tamanio "<<setw(4)<<arregloTamanios[j]<<endl;
        delete[] arregloAleatorio;
        delete[] arregloCopia;
    }
    
    //Una vez completadas todas las pruebas con todos los algoritmos para todos los tamaños de arreglo, se calculan los tiempos 
    //promedio de ejecución para cada algoritmo con cada tamaño de arreglo. Por último, se exportan los resultados a 8 archivos
    //distintos: 7 de ellos son para los tiempos de ejecución para cada algoritmo y el 8vo es para los tiempos promedio de todos
    //los algoritmos.
    
    cout<<endl;
    calcularTiemposPromedio(arregloTiemposDeEjecucion, arregloTiemposPromedio);
    exportarResultados(arregloTiemposDeEjecucion, arregloTiemposPromedio, arregloTamanios, arregloNombres);
    return 0;
}

void probarAlgoritmos(string arregloNombres[]){
    int n=5;
    int arregloAleatorio[n], arregloCopia[n];
    
    generarArregloAleatorio(arregloAleatorio, n);
    
    cout<<endl;
    cout<<"Arreglo aleatorio de prueba:"<<endl;
    imprimirArreglo(arregloAleatorio, n);
    cout<<endl;
    
    for(int k=0; k<NUM_ALGORITMOS; k++){
        copiarArregloAleatorio(arregloAleatorio, arregloCopia, n);
        ordenarArreglo(arregloCopia, n, k);
        cout<<"Resultado del ordenamiento ";
        if(k%2==0) cout<<"por ";
        cout<<arregloNombres[k]<<":"<<endl;
        imprimirArreglo(arregloCopia, n);
        cout<<endl;
    }
}

void generarArregloTamanios(int arregloTamanios[]){
    arregloTamanios[0]=MIN_TAMANIO;
    
    for(int i=1; i<NUM_TAMANIOS; i++){
        arregloTamanios[i]=arregloTamanios[i-1]+INCREMENTO;
    }
}

void generarArregloAleatorio(int arregloAleatorio[], int tamanio){
    random_device aleatorio;
    uniform_int_distribution<int> rango(1,1000);
    
    for(int i=0; i<tamanio; i++){
        arregloAleatorio[i]=rango(aleatorio);
    }
}

void copiarArregloAleatorio(int arregloAleatorio[], int arregloCopia[], int tamanio){
    
    for(int i=0; i<tamanio; i++){
        arregloCopia[i]=arregloAleatorio[i];
    }
}

void imprimirArreglo(int arreglo[], int tamanio){
    cout<<'[';
    for(int i=0; i<tamanio; i++){
        cout<<arreglo[i];
        if(i<tamanio-1) cout<<',';
    }
    cout<<']'<<endl;
}

void ordenarArreglo(int arregloCopia[], int tamanio, int k){
    int inicio=0, fin=tamanio-1;
    
    switch(k){
        case 0:
            INSERTION_SORT(arregloCopia, tamanio);
            break;
        case 1:
            BUBBLE_SORT(arregloCopia, tamanio);
            break;
        case 2:
            SELECTION_SORT(arregloCopia, tamanio);
            break;
        case 3:
            SHELL_SORT(arregloCopia, tamanio);
            break;
        case 4:
            MERGE_SORT(arregloCopia, inicio, fin);
            break;
        case 5:
            QUICK_SORT(arregloCopia, inicio, fin);
            break;
        case 6:
            HEAP_SORT(arregloCopia, tamanio);
            break;
    }
}

void INSERTION_SORT(int s[], int n){
    int val, j;
    
    for(int i=1; i<n; i++){
        val=s[i];                      
        j=i-1;
        while(j>=0 && val<s[j]){        
            s[j+1]=s[j];
            j=j-1;
        }
        s[j+1]=val;                     
    }
}

void BUBBLE_SORT(int s[], int n){
    int temp;
    
    for(int i=0; i<n-1; i++){
        
        for(int j=0; j<n-i-1; j++){
            
            if(s[j]>s[j+1]){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}

void SELECTION_SORT(int s[], int n){
    int min_idx, temp;
    
    for(int i=0; i<n-1; i++){
        min_idx=i;
        
        for(int j=i+1; j<n; j++){
            
            if(s[j]<s[min_idx]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            temp=s[i];
            s[i]=s[min_idx];
            s[min_idx]=temp;
        }
    }
}

void SHELL_SORT(int s[], int n){
    int temp, j;
    
    for(int gap=n/2; gap>0; gap/=2){
        
        for(int i=gap; i<n; i++){
            temp=s[i];
            j=i;
            
            while(j>=gap && s[j-gap]>temp){
                s[j]=s[j-gap];
                j-=gap;
            }
            s[j]=temp;
        }
    }
}

void MERGE_SORT(int s[], int inicio, int fin){
    int medio;
    
    if(inicio<fin){
        medio=(inicio+fin)/2;
        MERGE_SORT(s, inicio, medio);
        MERGE_SORT(s, medio+1, fin);
        MERGE(s, inicio, medio, fin);
    }
}

void MERGE(int s[], int inicio, int medio, int fin){
    int n1=medio-inicio+1;
    int n2=fin-medio;
    int* L;
    int* R;
    
    L=new int[n1];
    R=new int[n2];
    
    for(int i=0; i<n1; i++){
        L[i]=s[inicio+i];
    }
    for(int j=0; j<n2; j++){
        R[j]=s[medio+j+1];
    }
    int i=0;
    int j=0;
    int k=inicio;
    
    while(i<n1 && j<n2){
        
        if(L[i]<=R[j]){
            s[k]=L[i];
            i++;
        }
        else{
            s[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        s[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        s[k]=R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void QUICK_SORT(int s[], int inicio, int fin){
    int pivote_idx;
    
    if(inicio<fin){
        pivote_idx=PARTITION(s, inicio, fin);
        QUICK_SORT(s, inicio, pivote_idx-1);
        QUICK_SORT(s, pivote_idx+1, fin);
    }
}

int PARTITION(int s[], int inicio, int fin){
    int pivote=s[fin];
    int i=inicio-1;
    
    for(int j=inicio; j<=fin-1; j++){
        
        if(s[j]<=pivote){
            i+=1;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[fin]);
    
    return i+1;
}

void HEAP_SORT(int s[], int n){
    BUILD_MAX_HEAP(s, n);
    
    for(int i=n-1; i>=1; i--){
        swap(s[0], s[i]);
        n-=1;
        MAX_HEAPIFY(s, 0, n);
    }
}

void BUILD_MAX_HEAP(int s[], int n){
    
    for(int i=(n-1)/2; i>=0; i--){
        MAX_HEAPIFY(s, i, n);
    }
}

void MAX_HEAPIFY(int s[], int i, int n){
    int izquierdo=2*i;
    int derecho=2*i+1;
    int mayor=i;
    
    if(izquierdo<n && s[izquierdo]>s[mayor]){
        mayor=izquierdo;
    }
    if(derecho<n && s[derecho]>s[mayor]){
        mayor=derecho;
    }
    if(mayor!=i){
        swap(s[i], s[mayor]);
        MAX_HEAPIFY(s, mayor, n);
    }
}

void calcularTiemposPromedio(double arregloTiemposDeEjecucion[][NUM_TAMANIOS][NUM_ALGORITMOS], double arregloTiemposPromedio[][NUM_ALGORITMOS]){
    double sumaTiempos;
    
    for(int k=0; k<NUM_ALGORITMOS; k++){
        
        for(int j=0; j<NUM_TAMANIOS; j++){
            sumaTiempos=0;
            
            for(int i=0; i<NUM_PRUEBAS; i++){
                sumaTiempos+=arregloTiemposDeEjecucion[i][j][k];
            }
            arregloTiemposPromedio[j][k]=sumaTiempos/NUM_PRUEBAS;
        }
    }
}

void exportarResultados(double arregloTiemposDeEjecucion[][NUM_TAMANIOS][NUM_ALGORITMOS], double arregloTiemposPromedio[][NUM_ALGORITMOS], int arregloTamanios[], string arregloNombres[]){
    
    for(int k=0; k<NUM_ALGORITMOS; k++){
        string nombreArchivo;
        
        nombreArchivo=to_string(k+1)+"_"+arregloNombres[k]+"_Ordenamiento.csv";
        
        ofstream archivoTiempos;
        archivoTiempos.open(nombreArchivo);
        
        if(archivoTiempos.is_open()){
            
            for(int j=0; j<NUM_TAMANIOS; j++){
                archivoTiempos<<arregloTamanios[j];
                if(j<NUM_TAMANIOS-1) archivoTiempos<<',';
            }
            archivoTiempos<<endl;
        
            for(int i=0; i<NUM_PRUEBAS; i++){
            
                for(int j=0; j<NUM_TAMANIOS; j++){
                    archivoTiempos<<arregloTiemposDeEjecucion[i][j][k];
                    if(j<NUM_TAMANIOS-1) archivoTiempos<<',';
                }
                archivoTiempos<<endl;
            }
            archivoTiempos.close();
            cout<<"Se ha generado el archivo "<<nombreArchivo<<endl;
        }
        else{
            cout<<"Error al generar el archivo "<<nombreArchivo<<endl;
        }
    }
    
    ofstream archivoPromedios;
    archivoPromedios.open("Tiempos_Promedio.csv");
    
    if(archivoPromedios.is_open()){
        archivoPromedios<<"Tamanio,";
        
        for(int k=0; k<NUM_ALGORITMOS; k++){
            archivoPromedios<<arregloNombres[k];
            if(k<NUM_ALGORITMOS-1) archivoPromedios<<',';
        }
        archivoPromedios<<endl;
        
        for(int j=0; j<NUM_TAMANIOS; j++){
            archivoPromedios<<arregloTamanios[j]<<',';
            
            for(int k=0; k<NUM_ALGORITMOS; k++){
                archivoPromedios<<arregloTiemposPromedio[j][k];
                if(k<NUM_ALGORITMOS-1) archivoPromedios<<',';
            }
            archivoPromedios<<endl;
        }
        archivoPromedios.close();
        cout<<"Se ha generado el archivo Tiempos_Promedio.csv"<<endl;
    }
    else{
        cout<<"Error al generar el archivo Tiempos_Promedio.csv"<<endl;
    }
    
}