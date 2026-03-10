# 🧮 Algorithms in C++

Colección de algoritmos clásicos de Sistemas Operativos y Ciencias de la Computación implementados en C++, con explicaciones técnicas que van desde los conceptos matemáticos hasta el código. Cada algoritmo incluye su propio documento de explicación en Markdown.

> El objetivo no es solo tener el código — es que entiendas **exactamente** qué está haciendo cada línea, sin importar tu nivel.

---

## 📁 Algoritmos Incluidos

### 🏦 Banker's Algorithm (Algoritmo del Banquero)
**Categoría:** Evitación de Deadlocks | Sistemas Operativos

Implementación del Algoritmo del Banquero de Dijkstra para determinar si un sistema está en un **estado seguro** — si existe al menos una secuencia de ejecución donde todos los procesos terminan sin deadlock.

```
Algorithms/banker/
├── bankerBasic.cpp            # Implementación del algoritmo
└── ExplanationBankerBasic.md  # Explicación teórica detallada
```

### 🌳 Trees (Árboles)
**Categoría:** Estructuras de Datos

```
Algorithms/trees/
└── [Implementaciones de árboles]
```

---

## 💻 El Algoritmo del Banquero en Detalle

La función `esSeguro()` simula la ejecución de procesos para verificar si el estado del sistema es seguro:

```cpp
bool esSeguro(const Mat& alloc, const Mat& need, const Vec& work) {
    int n = alloc.size();
    std::vector<bool> finish(n, false);
    Vec workCopy = work;  // Copia de recursos disponibles

    while (true) {
        bool progreso = false;
        for (int i = 0; i < n; i++) {
            if (finish[i]) continue;

            // ¿El proceso i puede ejecutarse con los recursos actuales?
            bool puede = true;
            for (int j = 0; j < m; j++) {
                if (need[i][j] > workCopy[j]) {  // necesita más de lo disponible
                    puede = false;
                    break;
                }
            }

            if (puede) {
                // Simular que termina y libera sus recursos
                for (int j = 0; j < m; j++) {
                    workCopy[j] += alloc[i][j];
                }
                finish[i] = true;
                progreso = true;
            }
        }
        if (!progreso) break;  // Nadie puede avanzar → posible deadlock
    }

    // Estado seguro = todos los procesos pudieron terminar
    return std::all_of(finish.begin(), finish.end(), [](bool f) { return f; });
}
```

**Lógica del algoritmo:**
1. Simula que el sistema tiene `work` recursos disponibles.
2. Busca cualquier proceso cuya `need ≤ work` (puede ejecutarse).
3. Al "terminar" ese proceso, sus recursos `alloc` se devuelven a `work`.
4. Repite hasta que todos terminan (estado seguro) o no hay progreso (estado inseguro).

### Tipos Personalizados

```cpp
using Mat = std::vector<std::vector<int>>;  // Matriz: need, alloc, max
using Vec = std::vector<int>;               // Vector: available, work
```

---

## 📦 Compilación

```bash
# Compilar el algoritmo del banquero
g++ -std=c++17 -O2 -o banker Algorithms/banker/bankerBasic.cpp
./banker
```

---

## 🗺️ Roadmap

- [x] Banker's Algorithm
- [x] Trees
- [ ] Scheduling (FCFS, SJF, Round Robin)
- [ ] Page Replacement (LRU, FIFO, Optimal)
- [ ] Sorting con análisis de complejidad

---

## 🤝 Contribución

Cada nuevo algoritmo debe incluir:
1. El `.cpp` con implementación comentada
2. Un `.md` con la teoría detrás del algoritmo

---

## 📄 Licencia

MIT