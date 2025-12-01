# 🧠 Algoritmos en C++: Problema del Cambio y de la Mochila

Este repositorio contiene implementaciones en **C++** de dos problemas clásicos del análisis de algoritmos:

- **Problema del Cambio (Coin Change)**
- **Problema de la Mochila**

Cada problema está resuelto utilizando las **cuatro tácticas algorítmicas fundamentales**:

1. **Greedy (Algoritmos Voraces)**
2. **Divide & Conquer (Divir y Conquistar)**
3. **Programación Dinámica (Memoización y Tabulación)**
4. **Backtracking**

El objetivo es comparar enfoques, entender diferencias de complejidad y ver cómo cambia la implementación según la táctica utilizada.

---

## 📂 Estructura del Repositorio

```
/
├── Cambio/
│ ├── cambio_greedy.cpp
│ ├── cambio_DAC.cpp
│ ├── cambio_PD.cpp
│ ├── cambio_backtracking.cpp
│
├── Mochila/
│ ├── mochila_greedy.cpp
│ ├── mochila_DAC.cpp
│ ├── mochila_PD.cpp
│ ├── mochila_backtracking.cpp
│
├── LICENSE
└── README.md
```


---

## 🪙 Problema del Cambio (Coin Change)

Dado un conjunto de monedas y un valor objetivo, el problema consiste en determinar **la cantidad mínima de monedas** necesarias para llegar exactamente al total solicitado.

### Métodos implementados

### ✔ Greedy  
- Selecciona siempre la moneda de mayor valor posible.  
- Es muy rápido (**O(n)**), pero **no siempre da solución óptima** (depende del sistema de monedas).

### ✔ Divide & Conquer  
- Explora todas las combinaciones posibles.
- Complejidad exponencial.

### ✔ Programación Dinámica (Tabulación)  
- Construye una tabla de soluciones óptimas para todos los subproblemas (Bottom-Up).
- Complejidad **O(n × m)** (n = monto, m = número de monedas).
- **Siempre óptimo**.

### ✔ Programación Dinámica (Memoización)  
- Recursión + cacheo de subproblemas ya resueltos (Top-Down).
- Menos código que tabulación y muy eficiente.

### Backtracking
- Prueba todas las combinaciones de monedas hasta encontrar la que nos de la menor cantidad.

---

## 🎒 Problema de la Mochila

Dados objetos con peso y valor, y una capacidad máxima, el objetivo es maximizar el valor total sin exceder la capacidad.

### Métodos implementados

### ✔ Greedy  
- Para 0/1 no garantiza solución óptima.

### ✔ Divide & Conquer  
- Evalúa ambas decisiones: tomar o no tomar cada objeto.
- Complejidad exponencial.

### ✔ Programación Dinámica (Tabulación)  
- Usa una matriz de `n × W`.
- Solución óptima para **0/1**.

### ✔ Programación Dinámica (Memoización)  
- Implementación recursiva optimizada.
- Reduce drásticamente el tiempo respecto a Divide & Conquer.


### Backtracking
- No nos da la solución óptima, ya que el problema de la mochila es un problema de optimización "para arriba", o sea que queremos maximizar, por lo tanto no es sencillo calcular cuando podemos **podar**. No es imposible pero es mucho más complejo.

---

## 🚀 Objetivo del Proyecto

- Comparar distintos **paradigmas algorítmicos** aplicados a problemas clásicos.
- Analizar rendimiento y complejidad.
- Proveer implementaciones claras, probadas y organizadas.

---

## 🛠️ Tecnologías Utilizadas

- **C++17 o superior**
- Librerías estándar (`iostream` y `climits`.)
- Compilador sugerido: `g++`, `clang++`, MinGW o similar.

---

## ▶️ Cómo Compilar y Ejecutar

### Linux / MacOS / Windows con git Bash

```bash
g++ ./nombreDelArchivo.cpp -o nombreDelEjecutable
./nombreDelEjecutable
```

### Windows

```
g++ ./nombreDelArchivo.cpp -o nombreDelEjecutable.exe
nombreDelEjecutable.exe
```

## 📄 Licencia

Este proyecto se distribuye bajo la MIT License.
Podés usar, modificar y distribuir el código libremente.