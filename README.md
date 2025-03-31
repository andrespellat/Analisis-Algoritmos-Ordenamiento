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
<p align="justify">
El algoritmo de inserción por orden inicia comparando el segundo elemento del arreglo con el primero. Si el segundo elemento es menor que el primero, sus valores son intercambiados y como resultado los primeros dos elementos del arreglo están en orden no decreciente. La idea del algoritmo es ir aumentando gradualmente la sección del arreglo que va quedando en orden no decreciente, esto mediante la inserción de cada elemento en su posición correcta con respecto a los elementos previos. Cuando el último elemento ha sido insertado en su posición correcta, entonces el arreglo completo está en orden no decreciente. La complejidad temporal del caso promedio para este algoritmo es $O(n²)$.
</p>
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:

<p align="center">
<img src="https://github.com/user-attachments/assets/b935590c-c24f-4b7a-9a94-8aa27c10658e" width=75%>
</p>

### 2. Ordenamiento Burbuja
<p align="justify">
El algoritmo de ordenamiento burbuja es un método simple que recorre repetidamente un arreglo, compara elementos adyacentes y los intercambia si están en el orden incorrecto. La complejidad temporal del caso promedio para este algoritmo es $O(n²)$.
</p>
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/6bc54a35-0c57-4336-bc1b-d4871403d072" width=75%>
</p>

### 3. Ordenamiento por Selección
<p align="justify">
El algoritmo de ordenamiento por selección es un método que divide el arreglo de entrada en dos partes: un subarreglo ya ordenado y un subarreglo por ordenar. El algoritmo busca repetidamente el elemento mínimo de la parte no ordenada y lo coloca al final de la parte ordenada. La complejidad temporal del caso promedio para este algoritmo es $O(n²)$.
</p>
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/39971c19-0f07-4bb4-9217-6fd741365de6" width=75%>
</p>

### 4. Ordenamiento por Mezcla
<p align="justify">
El algoritmo de ordenamiento por mezcla divide el arreglo en mitades recursivamente hasta obtener subarreglos de tamaño 1, que son trivialmente ordenados. Luego combina estos subarreglos para producir nuevos subarreglos ordenados hasta que solo queda un arreglo completamente ordenado. La complejidad temporal del caso promedio para este algoritmo es $O(n\log n)$.
</p>
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/a669d363-4312-46aa-9b2b-543161b503ba" width=75%>
<img src="https://github.com/user-attachments/assets/77bd1424-091b-4cb5-b262-e2bcc144eb06" width=75%>
</p>

### 5. Ordenamiento Rápido
<p align="justify">
El algoritmo de ordenamiento rápido selecciona un elemento como pivote y particiona el arreglo alrededor del pivote, colocando todos los elementos menores al pivote a su
izquierda y todos los mayores a su derecha. Luego, recursivamente ordena los dos subarreglos resultantes. La complejidad temporal del caso promedio para este algoritmo es $O(n\log n)$.
</p>
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/d5dda71b-eba8-4fb9-8e89-e6ca9e875b61" width=75%>
</p>

### 6. Ordenamiento por Montículos
<p align="justify">
El algoritmo de ordenamiento por montículos utiliza una estructura de datos llamada montículo para ordenar los elementos. Un montículo es un árbol binario casi completo que satisface la propiedad de montículo: en un montículo máximo, para cualquier nodo, el valor del nodo es mayor o igual que los valores de sus hijos.
   
El algoritmo consta de dos fases principales:

1. Construcción del montículo máximo: reorganizar el arreglo para formar un montículo máximo.
2. Extracción repetida del máximo: extraer repetidamente el elemento máximo del montículo y reubicarlo al final del arreglo.

La complejidad temporal del caso promedio para este algoritmo es $O(n\log n)$.
</p>
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/06845440-5eab-4376-83bf-9813e4f7b006" width=75%>
</p>

### 7. Ordenamiento Shell
<p align="justify">
El algoritmo de ordenamiento Shell es una extensión del algoritmo de ordenamiento por inserción que supera algunas de sus limitaciones al permitir el intercambio de elementos distantes. El algoritmo mejora el rendimiento del ordenamiento por inserción al ordenar elementos separados por una cierta distancia (o gap), reduciendo progresivamente esta distancia hasta que el gap sea 1, mo-
mento en el cual el algoritmo se comporta como el ordenamiento por inserción estándar. La idea principal es permitir que los elementos “salten” varias posiciones, haciendo que la lista se vuelva “parcialmente ordenada”, lo que hace que el ordenamiento por inserción final sea más eficiente.
</p>
El pseudocódigo que se siguió para implementar este algoritmo es el siguiente:
<p align="center">
<img src="https://github.com/user-attachments/assets/70e371d7-fba8-4eea-a956-f5152f90541a" width=75%>
</p>

<p align="justify">
El rendimiento de este algoritmo se ve afectado por la secuencia de gaps utilizada. En este proyecto la secuencia de gaps que se utiliza es la secuencia original de Shell: $\lfloor n/2 \rfloor, \lfloor n/4 \rfloor, \lfloor n/8 \rfloor,...,1$. La complejidad temporal del caso promedio para este algoritmo está generalmente entre $O(n\log² n)$ y $O(n^{5/4})$  dependiendo de la secuencia de gaps utilizada.
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
<p align="justify">
Para poder comparar el rendimiento de los 7 algoritmos se calcularon los tiempos de ejecución promedio de cada algoritmo para los 100 tamaños de arreglo distintos y se almacenaron todos en un solo archivo llamado Tiempos_Promedio.csv, el cual se encuentra en la carpeta Datos_Experimentales. A continuación se presentan algunas gráficas de dichos datos para diferentes rangos de tamaño de arreglo.
</p>

<p align="center">
<img src="https://github.com/user-attachments/assets/93035230-61ab-4231-a399-549db5fb87ec" width=70%>
</p>

<p align="justify">
En esta gráfica se puede observar que el algoritmo de ordenamiento burbuja tiene un tiempo de ejecución similar a los demás algoritmos para arreglos de tamaño menor o igual a 30, pero una vez que el tamaño del arreglo supera los 30 elementos su tiempo de ejecución se separa cada vez más del resto, lo cual indica que el ritmo al que su tiempo de ejecución incrementa es el mayor de todos los algoritmos puestos a prueba. Por otro lado, se puede observar que el algoritmo de inserción es el más rápido para arreglos de tamaño menor o igual a 100.
</p>

<p align="center">
<img src="https://github.com/user-attachments/assets/507509e9-2217-416d-9220-8e31464ca3dc" width=70%>
</p>

<p align="justify">
En esta gráfica se puede observar que una vez que el tamaño del arreglo supera los 110 elementos el tiempo de ejecución del algoritmo de ordenamiento por selección queda únicamente por debajo del de ordenamiento burbuja, teniendo ambas curvas una forma similar.
</p>

<p align="center">
<img src="https://github.com/user-attachments/assets/5f85f305-9c14-4f1b-8ba2-ba3911b5882b" width=70%>
</p>

<p align="justify">
En esta gráfica se puede observar que una vez que el tamaño del arreglo supera los 300 elementos el tiempo de ejecución del algoritmo de inserción es el tercero más alto, quedando por debajo del de ordenamiento por selección.
</p>

<p align="center">
<img src="https://github.com/user-attachments/assets/6b503342-8257-4c41-a777-44b5b2317643" width=70%>
</p>

<p align="justify">
En esta gráfica se puede observar que una vez que el tamaño del arreglo supera los 300 elementos el tiempo de ejecución de los algoritmos puestos a prueba sigue el siguiente orden de más rápido a más lento:
   
1. Ordenamiento Rápido
2. Ordenamiento Shell
3. Ordenamiento por Mezcla
4. Ordenamiento por Montículos
5. Inserción por Orden
6. Ordenamiento por Selección
7. Ordenamiento Burbuja

Además, la forma que tienen las curvas de tiempo de ejecución obtenidas para cada algoritmo coinciden con la complejidad temporal teórica de cada uno de ellos: Se obtuvo una curva de forma cuadrática para los algoritmos de complejidad temporal de $O(n²)$  (Inserción, Selección y Burbuja) y una curva de forma lineal-logarítmica para los de $O(n\log n)$  (Rápido, Shell, Mezcla y Montículos).
</p>

## Conclusiones
<p align="justify">
Los resultados obtenidos sirven como confirmación de que los algoritmos de complejidad temporal de $O(n²)$  (Inserción, Selección y Burbuja) son mucho menos eficientes para ordenar arreglos de grandes tamaños a comparación de los de $O(n\log n)$  (Rápido, Shell, Mezcla y Montículos). Sin embargo, esto no significa que siempre que se necesite ordenar un arreglo lo mejor sea utilizar un algoritmo de orden $O(n\log n)$, también es necesario tomar en cuenta la complejidad espacial de los algoritmos, la cual no se puso a prueba en este proyecto, y considerar que para arreglos de tamaño pequeño los algoritmos de orden $O(n²)$ también tienen buenos tiempos de ejecución.
</p>
