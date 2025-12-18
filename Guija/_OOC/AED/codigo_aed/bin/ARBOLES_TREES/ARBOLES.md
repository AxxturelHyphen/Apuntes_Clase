## 4.1 Terminología esencial (core terminology)

### Idea intuitiva (intuitive idea)

Un **árbol (tree)** representa jerarquías: carpetas, DOM de HTML, expresiones, menús, genealogías. La idea clave: no es “una línea” como una lista; es una estructura con ramificación.

### Definición formal (formal definition)

En estructuras de datos casi siempre usamos **árboles enraizados (rooted trees)**:

- **Nodo (node)**: elemento/objeto.

- **Arista (edge)**: conexión padre–hijo.

- **Raíz (root)**: nodo superior, sin padre.

- **Padre (parent)** y **hijo (child)**.

- **Hoja (leaf)**: nodo sin hijos.

- **Subárbol (subtree)**: un nodo con todos sus descendientes.

- **Camino (path)**: secuencia de aristas entre dos nodos.

- **Nivel (level)**: suele coincidir con la profundidad (ojo: depende de convención).

- **Profundidad (depth)** de un nodo: número de aristas desde la raíz hasta el nodo.

- **Altura (height)** de un nodo: número de aristas del camino más largo desde ese nodo hasta una hoja.

- **Altura del árbol**: altura de la raíz.

**Convención típica**:

- Raíz tiene depth = 0

- Hoja tiene height = 0

- Árbol vacío a veces se define con height = -1 (útil en AVL para fórmulas); si no te lo dicen, no inventes en examen: especifica la convención.

### Propiedad base que cae en exámenes

En un árbol con **n** nodos (conectado, sin ciclos) hay **n − 1** aristas.  
(Útil para sanity-check en dibujos.)

---

## 4.2 Árbol binario (binary tree)

### Qué es y para qué sirve

Un **árbol binario (binary tree)** es un árbol donde cada nodo tiene como máximo 2 hijos:

- **left child**

- **right child**

Sirve para:

- representar expresiones

- implementar BST y heaps

- decisiones binarias (sí/no)

- estructuras de indexación simples

### Tipos de árboles binarios (muy preguntables)

- **Full / proper binary tree**: cada nodo tiene 0 o 2 hijos.

- **Complete binary tree**: todos los niveles llenos excepto quizá el último, que se rellena de izquierda a derecha.

- **Perfect binary tree**: todos los niveles llenos (todas las hojas al mismo depth).

- **Degenerate tree**: parece una lista (cada nodo tiene 1 hijo). Altura ~ n.

---

## 4.3 Recorridos (traversals): DFS y BFS

### Idea intuitiva

Recorrer un árbol es “visitar” sus nodos en un orden fijo. Los más típicos:

- DFS (Depth-First Search):

  - **preorder**: Node → Left → Right

  - **inorder**: Left → Node → Right

  - **postorder**: Left → Right → Node

- BFS (Breadth-First Search):

  - **level-order**: por niveles (usa queue)

---

### 4.3.1 Ejemplo único para trazar (lo usaremos en todo el bloque)

Árbol:

```
        8
      /   \
     3     10
    / \      \
   1   6      14
      / \     /
     4   7   13

```

Órdenes correctos (para check rápido):

- preorder: 8, 3, 1, 6, 4, 7, 10, 14, 13

- inorder: 1, 3, 4, 6, 7, 8, 10, 13, 14

- postorder: 1, 4, 7, 6, 3, 13, 14, 10, 8

- level-order: 8, 3, 10, 1, 6, 14, 4, 7, 13

---

### 4.3.2 DFS recursivo (recursive DFS): lo más directo

**Complejidad** (igual para los 3):

- Tiempo: $O(n)$ (visitas cada nodo una vez)

- Espacio (stack recursivo): $O(h)$ donde h es la altura (worst-case $O(n)$, balanced $O(\log n)$)

---

### 4.3.3 DFS iterativo (iterative): usando stack (muy de examen práctico)

#### Preorder iterativo (stack)

Idea: simulas la recursión con una **pila (stack)**.

#### Inorder iterativo (stack)

Este es muy típico: “baja todo a la izquierda”, procesa, y ve a la derecha.

#### Postorder iterativo (dos stacks o “one stack trick”)

---

### 4.3.4 BFS / Level-order (queue)

Usa una **cola (queue)**: primero entra la raíz, sacas y metes sus hijos.
Complejidad:

- Tiempo: $O(n)$

- Espacio: $O(w)$ donde w es el ancho máximo (max width), worst-case puede ser $O(n)$

---

## 4.4 BST — Árbol de búsqueda binario (binary search tree)

### 4.4.1 Definición (definition) e invariante (invariant)

Un **BST (binary search tree)** cumple:

Para cualquier nodo con clave key:

- todo en el subárbol izquierdo (left subtree) es **< key**

- todo en el subárbol derecho (right subtree) es **> key**

Esto es el **invariante BST**: si se rompe, deja de ser BST.

**Importante (duplicates)**: si hay claves repetidas, hay que decidir una política:

- o no permites duplicados

- o “igual va a la derecha” / “igual va a la izquierda”  
    En examen: si no lo indican, di tu convención.

### 4.4.2 Consecuencia clave

El recorrido **inorder** de un BST devuelve las claves en **orden ascendente** (sorted order).  
Esto es súper preguntable.

### 4.4.3 Operaciones típicas

- search (buscar)

- insert (insertar)

- delete (borrar)

**Complejidad depende de altura h**:

- Tiempo (search/insert/delete): $O(h)$

  - BST “balanceado”: h ~ $O(\log n)$

  - BST degenerado: h ~ $O(n)$

- Espacio adicional: depende de implementación (recursivo añade stack)

---

### 4.4.4 Inserción paso a paso (BST insertion tracing) — ejercicio clásico

Inserta secuencia: 8, 3, 10, 1, 6, 14, 4, 7, 13

Regla: “menor a la izquierda, mayor a la derecha”.

Proceso resumido:

1. 8 → raíz

2. 3 < 8 → left de 8

3. 10 > 8 → right de 8

4. 1 < 8 → vas a 3, 1 < 3 → left de 3

5. 6 < 8 → vas a 3, 6 > 3 → right de 3

6. 14 > 8 → vas a 10, 14 > 10 → right de 10

7. 4 < 8 → 3 → 6, 4 < 6 → left de 6

8. 7 < 8 → 3 → 6, 7 > 6 → right de 6

9. 13 > 8 → 10 → 14, 13 < 14 → left de 14

Árbol final (es el ejemplo del bloque de recorridos):

```
        8
      /   \
     3     10
    / \      \
   1   6      14
      / \     /
     4   7   13

```

---

**Complejidad (BST)**:

- Mejor caso: $O(1)$ (si buscas la raíz)

- Promedio (si inserciones “aleatorias”): ~ $O(\log n)$

- Peor caso: $O(n)$ (degenerado)

**Error típico examen**: asumir que BST “siempre” es $O(\log n)$. No: solo si está balanceado o si el input no lo degenera.

---

## 4.5 “Balanceado” (balanced) y AVL trees

### 4.5.1 Qué significa “balanceado”

En AED, “balanceado” suele significar que la altura del árbol crece como $O(\log n)$, evitando el caso degenerado tipo lista.

No es un único concepto: hay varias familias de árboles balanceados (AVL, Red-Black, 2-3, B-trees…). Aquí: **AVL**.

---

### 4.5.2 AVL tree: definición y factor de balance

Un **AVL tree** es un BST que mantiene:

Para cada nodo:

- **balance factor (BF)** = height(left) − height(right)

- Debe cumplir: BF ∈ { -1, 0, +1 }

Si BF se sale de ese rango tras insert/delete, se aplican **rotaciones (rotations)** para restaurar el balance.

**Consecuencia**: search/insert/delete en AVL garantizan $O(\log n)$.

---

### 4.5.3 Rotaciones (rotations): las 4 situaciones

Cuando un nodo se desbalancea, miras:

- si el “peso” está a la izquierda o derecha

- y si el hijo pesado tiene peso alineado o cruzado

Casos clásicos:

1. **LL (Left-Left)** → rotación derecha (right rotation)

2. **RR (Right-Right)** → rotación izquierda (left rotation)

3. **LR (Left-Right)** → rotación izquierda en hijo + derecha en nodo

4. **RL (Right-Left)** → rotación derecha en hijo + izquierda en nodo

---

### 4.5.4 Ejemplos mínimos (para entender “alguna” rotación)

#### Caso LL (Right rotation)

Inserta: 30, 20, 10

Antes de balancear:

```
    30
   /
  20
 /
10

```

BF en 30 = 2 (demasiado a la izquierda) y el hijo (20) también está cargado a la izquierda → **LL**.

Rotación derecha en 30:

```
   20
  /  \
 10  30

```

#### Caso LR (Double rotation)

Inserta: 30, 10, 20

Antes:

```
   30
  /
 10
   \
   20

```

En 30 está cargado a la izquierda, pero su hijo (10) está cargado a la derecha → **LR**.

Paso 1: rotación izquierda en 10:

```
   30
  /
 20
 /
10

```

Paso 2: rotación derecha en 30:

```
   20
  /  \
 10  30

```

---

### 4.5.5 Complejidad (AVL)

- search: $O(\log n)$

- insert: $O(\log n)$ (rebalance cuesta constante por nivel, y el número de niveles es log)

- delete: $O(\log n)$ (puede rebalancear hacia arriba)

**Trade-off**: AVL mantiene balance más estricto que otros (ej. Red-Black), por eso puede hacer más rotaciones, pero búsquedas suelen ser muy rápidas.

---

## 4.6 Heaps / Binary heaps y Priority Queue

### 4.6.1 Qué es un heap binario (binary heap)

Un **binary heap** es un **árbol binario completo (complete binary tree)** que cumple la **heap property**:

- **Min-heap**: cada nodo ≤ sus hijos (root es el mínimo)

- **Max-heap**: cada nodo ≥ sus hijos (root es el máximo)

Esto NO es un BST. En heap:

- no hay orden total izquierda/derecha

- solo hay orden “vertical” padre-hijos

### 4.6.2 Por qué es perfecto para priority queue

Una **priority queue** necesita:

- insertar con prioridad

- extraer el máximo/mínimo rápido

Heap lo da con:

- peek min/max: $O(1)$

- insert: $O(\log n)$

- extract-min/max: $O(\log n)$

---

### 4.6.3 Representación con array (array representation)

Como es **complete**, lo guardas en array:

Para índice i:

- parent = (i - 1) / 2

- left = 2*i + 1

- right = 2*i + 2

Esto evita punteros y es cache-friendly.

---

### 4.6.4 Operaciones clave (min-heap)

#### Insert (sift-up / bubble-up)

1. Insertas al final (mantienes complete tree)

2. Subes mientras viola heap property

#### Extract-min (remove root + sift-down)

1. Guardas root (mínimo)

2. Mueves último elemento al root

3. Bajas (sift-down) intercambiando con el hijo menor hasta restaurar

---

**Complejidad (heap)**:

- peek: $O(1)$

- insert: $O(\log n)$

- extract-min / extract-max: $O(\log n)$

**Extra clave**: construir un heap desde un array (build-heap) puede ser $O(n)$ usando heapify bottom-up (esto sale mucho en teoría).

---

## 4.7 Comparativas de complejidad (lo que te piden tal cual)

### BST balanceado vs degenerado

- search/insert/delete en BST:

  - si balanceado: $O(\log n)$

  - si degenerado: $O(n)$

### AVL

- search/insert/delete garantizado: $O(\log n)$

### Heap

- insert: $O(\log n)$

- extract-min/max: $O(\log n)$

- peek: $O(1)$

**Trampa típica**: “heap sirve para buscar un elemento cualquiera rápido”. No. Buscar un valor arbitrario en heap es $O(n)$ (no hay orden global como BST).

---

## 4.8 Practicar sí o sí (lo que más renta)

### A) Construcción paso a paso (drawing / tracing)

1. Insertar secuencia en **BST** y dibujar árbol final.

2. Insertar secuencia en **AVL**:

    - identificar primer nodo desbalanceado

    - decidir caso LL/RR/LR/RL

    - aplicar rotación(es)

### B) Recorridos (traversals)

Dado un árbol, sacar:

- preorder

- inorder

- postorder

- level-order

Esto es examen total porque es mecánico pero fácil de fallar si no practicas.

### C) Complejidad comparada

Darte una situación y preguntarte:

- “¿cuánto cuesta buscar?” según forma del árbol

- “¿qué estructura usarías para priority queue?” (heap)

- “¿por qué AVL evita el worst-case?” (balance)

---

## 4.9 Ejercicios tipo examen para meter en la rutinaa papi

### Nivel básico (basic)

1. Define: root, leaf, depth, height, subtree. (con tu convención)

2. Dado un árbol dibujado, escribe preorder/inorder/postorder/level-order.

3. ¿Por qué inorder de un BST sale ordenado?

### Nivel medio (intermediate)

4. Inserta en BST: 50, 30, 70, 20, 40, 60, 80. Dibuja el árbol final.

5. Borra en BST la clave 30 del árbol anterior y dibuja el resultado (recuerda los 3 casos).

6. Inserta en min-heap (array): 5, 3, 8, 1, 6. Muestra el array final.

### Nivel coñazo (coñazous)

7. Inserta en AVL: 10, 20, 30, 40, 50. Marca rotaciones y árbol final.

8. Demuestra informalmente por qué search en BST depende de h (altura).

9. Explica por qué build-heap puede ser $O(n)$.

Si quieres, dime “resuélveme los ejercicios 4, 5 y 7” y los hacemos con trazas limpias y dibujos ASCII.

---

## 4.10 Resumen final corto (mental cheat-sheet)

- Árbol (tree): jerarquía. depth = distancia a root. height = distancia a hoja más lejana.

- Binary tree: max 2 hijos.

- Traversals:

  - preorder: N L R

  - inorder: L N R

  - postorder: L R N

  - level-order: BFS con queue

- BST: left < node < right. Operaciones cuestan $O(h)$.

- Balanceado: altura ~ $O(\log n)$.

- AVL: BST con BF ∈ {-1,0,1}, rotaciones LL/RR/LR/RL, garantiza $O(\log n)$.

- Heap: complete + heap property. Perfecto para priority queue: peek $O(1)$, insert/extract $O(\log n)$.

- Error típico: confundir heap con BST (heap NO ordena globalmente).

Siguiente paso recomendado: hacemos una tanda de **trazas** (BST + recorridos + 1 ejemplo AVL) con ejercicios reales de examen y corrección paso a paso.
