# Análisis de algoritmos de ordenamiento
<p align="justify">
Este proyecto consiste en realizar una comparación del rendimiento de 7 distintos algoritmos de ordenamiento utilizando datos obtenidos experimentalmente. Para obtener dichos datos se desarrolló un programa en el lenguaje C++, el cual mide el tiempo que tarda cada algoritmo en ordenar arreglos de números enteros generados aleatoriamente. Las mediciones se realizan para arreglos de 100 tamaños distintos (10,20,30,...,1000) y se hacen 1000 pruebas para cada tamaño de arreglo. El código de este programa se encuentra en el archivo algoritmosOrdenamiento.cpp y los tiempos de ejecución medidos se encuentran en archivos .csv, uno para cada algoritmo, los cuales están en la carpeta Datos_Experimentales.
</p>

## Algoritmos de ordenamiento implementados
Los algoritmos de ordenamiento implementados son:
1. Inserción por Orden
2. Ordenamiento Burbuja
3. Ordenamiento por Selección
4. Ordenamiento por Mezcla
5. Ordenamiento Rápido
6. Ordenamiento por Montículos
7. Ordenamiento Shell
   
Todos tienen como entrada y salida:
- Entrada: Un arreglo de números enteros $s=[s_1,s_2,...,s_n]$ y, o bien el tamaño del arreglo $n$ o el índice de su primer elemento $inicio$ y el de su último elemento $fin$.
- Salida: El arreglo $s$ con sus elementos ordenados de manera no decreciente.

### 1. Inserción por Orden
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/b935590c-c24f-4b7a-9a94-8aa27c10658e" width=75%>
</p>

### 2. Ordenamiento Burbuja
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/6bc54a35-0c57-4336-bc1b-d4871403d072" width=75%>
</p>

### 3. Ordenamiento por Selección
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/39971c19-0f07-4bb4-9217-6fd741365de6" width=75%>
</p>

### 4. Ordenamiento por Mezcla
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/a669d363-4312-46aa-9b2b-543161b503ba" width=75%>
<img src="https://github.com/user-attachments/assets/77bd1424-091b-4cb5-b262-e2bcc144eb06" width=75%>
</p>

### 5. Ordenamiento Rápido
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/d5dda71b-eba8-4fb9-8e89-e6ca9e875b61" width=75%>
</p>

### 6. Ordenamiento por Montículos
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/06845440-5eab-4376-83bf-9813e4f7b006" width=75%>
</p>

### 7. Ordenamiento Shell
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/70e371d7-fba8-4eea-a956-f5152f90541a" width=75%>
</p>

## Requisitos del sistema
Las características del sistema en el que se compiló y ejecutó el código son las siguientes:
- Sistema Operativo: Fedora Linux 41 (Workstation Edition)
- Procesador: AMD Ryzen 5 5600H
- RAM: 16.0 GiB tipo DDR4
- Disco: SSD de 520 GB
- Compilador: g++ (GCC) 14.2.1 20250110 (Red Hat 14.2.1-7)
  
## Instrucciones de compilación y ejecución
Desde la terminal se accede a la carpeta en la que está almacenado el archivo algoritmosOrdenamiento.cpp y se usan los siguientes comandos:
1. Para compilar:
```
g++ algoritmosOrdenamiento.cpp -o algoritmosOrdenamiento.out
```
2. Para ejecutar:
```
./algoritmosOrdenamiento.out
```
## Análisis de resultados

## Conclusiones
