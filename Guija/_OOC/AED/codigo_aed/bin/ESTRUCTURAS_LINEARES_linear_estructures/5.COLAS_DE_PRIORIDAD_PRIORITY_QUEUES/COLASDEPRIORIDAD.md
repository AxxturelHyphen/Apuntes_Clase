## 5. Colas de prioridad (priority queues)

### 5.1 Idea intuitiva

Una **cola de prioridad (priority queue)** es una cola donde cada elemento lleva una **prioridad**, y:

> Siempre sale primero el elemento con **mayor prioridad**,  
> no necesariamente el que llegó antes.

Ejemplos:

- Urgencias en un hospital: el caso más grave se atiende antes.

- Planificación de tareas: jobs más importantes o con deadline cercano se ejecutan antes.

- Algoritmo de Dijkstra: siempre procesas el vértice con menor distancia provisional (cola de prioridad de mínimos).

Si dos elementos tienen la misma prioridad, normalmente se respeta el orden de llegada (FIFO entre iguales), aunque en implementaciones típicas con _heap_ esto no siempre está garantizado automáticamente.

---

### 5.2 Definición formal

TAD **PriorityQueue**:

- `insert(x, p)` o simplemente `insert(x)` donde `x` tiene prioridad `p`.

- `extractMax()` / `extractMin()`:

  - Devuelve y elimina el elemento con **máxima** (o mínima) prioridad.

- `peekMax()` / `peekMin()`:

  - Devuelve el elemento de máxima prioridad sin eliminarlo.

- `isEmpty()`, `size()`, etc.

Implementaciones posibles:

- **Array desordenado**:

  - `insert`: $O(1)$.

  - `extractMax`: buscar máximo → $O(n)$.

- **Lista ordenada**:

  - `insert`: encontrar hueco → $O(n)$.

  - `extractMax`: sacar primero → $O(1)$.

- **Árbol balanceado (BST)**:

  - `insert`, `extractMax`: $O(log n)$.

- **Heap binario (binary heap)**:

  - `insert`, `extractMax`: $O(log n)$.

  - `peekMax`: $O(1)$.  
        → Es la implementación más común.

Por defecto, en muchas librerías estándar se usa un **min-heap** (sale el mínimo primero). Para un max-heap se invierte el comparador.

---

### 5.3 Heap binario (visión rápida)

Un **binary heap (max-heap)** es:

- Un árbol binario **completo** (se rellena por niveles de izquierda a derecha).

- Con la **propiedad de heap**:

  - Cada nodo es **mayor o igual** que sus hijos.

El máximo está **siempre en la raíz**.

Se representa muy fácil en un **array**:

- Raíz en índice `0`.

- Hijos de índice $i$: índices $2 * i + 1$ y $2 * i + 2$.

- Padre de índice $i$ (para $i > 0$): índice `floor((i - 1) / 2)`.

Operaciones típicas:

- `insert(x)`:

    1. Insertas `x` al final del array (como nueva hoja).

    2. Haces _bubble-up_ (subir) mientras `x` sea mayor que su padre.

    3. Coste peor caso: $O(log n)$.

- `extractMax()`:

    1. Guardas la raíz (máximo).

    2. Mueves el último elemento del array a la raíz.

    3. Haces _bubble-down_ (bajar) comparando con hijos y bajando hasta restaurar la propiedad de heap.

    4. Coste peor caso: $O(log n)$.

- `peekMax()`:

  - Devuelves `heap[0]` → coste $O(1)$.

### 5.6 Complejidad

Con implementación por **binary heap**:

- `insert`: $O(log n)$.

- `extractMax` / `extractMin`: $O(log n)$.

- `peek`: $O(1)$.

- `build-heap` desde un array de $n$ elementos: $O(n)$.

Otras opciones:

- Array desordenado:

  - `insert`: $O(1)$.

  - `extractMax`: $O(n)$.

- Lista ordenada:

  - `insert`: $O(n)$.

  - `extractMax`: $O(1)$.

El heap es un buen equilibrio: $O(log n)$ en inserción y extracción.

**Orden interno vs orden de salida:**

- La cola de prioridad no mantiene los elementos completamente ordenados en memoria.

- Solo garantiza que el próximo `extractMax`/`poll` devuelve el de **mayor prioridad**.

- Si extraes todos los elementos uno a uno, obtienes la secuencia ordenada por prioridad.

**Prioridades iguales:**

- El TAD conceptual suele asumir que a igual prioridad se podría respetar el orden de llegada.

- Un heap binario típico **no es estable**: el orden de elementos con prioridad igual puede depender de la estructura interna.

- Si quieres estabilidad, puedes usar un par `(priority, timestamp)` y definir el comparador como:

  - Primero por prioridad.

  - Luego por `timestamp` (menor timestamp = llegó antes).

---

### 5.7 Mini resumen (chuleta mental)

- **Cola de prioridad (priority queue)**:

  - Siempre sale primero el elemento con prioridad más alta (o más baja, según definición).

  - No respeta estrictamente FIFO, solo respeta las prioridades.

- **Operaciones**:

  - `insert(x, p)`, `extractMax()` / `extractMin()`, `peek()`, `isEmpty()`.

  - En heap: `insert` y `extract` en $O(log n)$, `peek` en $O(1)$.

- **Implementación típica**:

  - **Binary heap (montículo binario)**:

    - Árbol binario completo con propiedad de heap.

    - Representado por array.

    - `insert`: $O(log n)$ (bubble-up).

    - `extractMax`: $O(log n)$ (bubble-down).

    - `peekMax`: $O(1)$.

- **Ventajas**:

  - Mucho más eficiente que lista ordenada o desordenada cuando hay muchas operaciones mixtas de inserción y extracción.

  - Fundamental en algoritmos de grafos (Dijkstra, Prim), planificación de tareas, simulaciones de eventos, etc.

- **Desventajas**:

  - No es fácil eliminar un elemento arbitrario que no sea el tope (normalmente $O(n)$ si lo buscas).

  - No es estable si no se controla el desempate.

- **Errores típicos**:

  - Pensar que `PriorityQueue` de Java devuelve el **máximo** por defecto (devuelve el mínimo).

  - Esperar que iterar por la `PriorityQueue` devuelva elementos en orden de prioridad (no es así; hay que ir sacándolos con `poll()`).

  - No manejar el caso de heap vacío (hacer `poll`/`peek` sin comprobar).
