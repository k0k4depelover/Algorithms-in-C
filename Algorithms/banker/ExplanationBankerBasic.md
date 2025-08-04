# 🧠 Banker Algorithm (Algoritmo del Banquero)

## 📌 ¿Qué es?

El **Algoritmo del Banquero** es una técnica de asignación de recursos utilizada en sistemas operativos para evitar interbloqueos (*deadlocks*). Fue propuesto por **Edsger Dijkstra**, y su nombre proviene de una analogía con un banquero que asigna fondos a clientes, asegurándose de que siempre pueda satisfacer futuras solicitudes.

Este algoritmo evalúa si un sistema se encuentra en un **estado seguro**, es decir, si existe al menos una secuencia de ejecución en la que todos los procesos puedan completar su ejecución sin que ocurra un interbloqueo.

---

## 📊 Estructuras utilizadas

El algoritmo utiliza las siguientes matrices y vectores:

| Componente  | Descripción |
|-------------|-------------|
| `ALLOC`     | Matriz `n x m` que representa los recursos actualmente asignados a cada proceso. |
| `MAX`       | Matriz `n x m` que indica el máximo de recursos que cada proceso podría llegar a solicitar. |
| `NEED`      | Matriz `n x m` calculada como `MAX - ALLOC`; representa los recursos que aún podría necesitar cada proceso. |
| `AVAILABLE` | Vector de tamaño `m` que representa la cantidad de recursos disponibles en el sistema para cada tipo de recurso. |

Donde:
- `n` es el número de procesos.
- `m` es el número de tipos de recursos.

---

## 🛡️ Objetivo

El **objetivo** del algoritmo es asegurar que, tras una solicitud de recursos, el sistema **permanezca en un estado seguro**, es decir, que **siempre haya una forma de ejecutar todos los procesos hasta su finalización**, liberando los recursos necesarios paso a paso.

---

## 🧮 Ejemplo de matrices

```text
ALLOC = [
  [0, 1, 0],
  [2, 0, 0],
  [3, 0, 2],
  [2, 1, 1],
  [0, 0, 2]
]

MAX = [
  [7, 5, 3],
  [3, 2, 2],
  [9, 0, 2],
  [2, 2, 2],
  [4, 3, 3]
]

AVAILABLE = [3, 3, 2]

NEED = MAX - ALLOC

```
### Funciones Auxiliares
Puedes omitir esta parte.
#### mostrarVector
Aca muestro soluciones para mostrar un vector junto con una etiqueta, esto es util si queremos visualizar el estado de un proceso:
```
void mostrarVector(const Vec& v, const string& nombre){
  std:: cout<< nombre<< ": ";
  for(int x in v){
  std::cout<< x << " ";
}
  cout<< " \n"
}
```
Donde *Vec&* es un vector, *string&* es el nombre del proceso.



