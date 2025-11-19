- **[[1.Fundamentos de algoritmos y complejidad]]**
    
    - Qué es un algoritmo (algorithm), modelo de coste.
        
    - Medir tiempo y espacio (time & space complexity).
        
    - Notación Big-O, Big-Ω, Big-Θ (asymptotic notation).[Wikipedia+2GeeksforGeeks+2](https://en.wikipedia.org/wiki/Big_O_notation?utm_source=chatgpt.com)
        
    - Casos: peor (worst case), promedio (average case), mejor (best case).
        
- **[[2.Recurrencias (recurrences) y recursión (recursion)]]**
    
    - Relación de recurrencia (recurrence relation) básica.
        
    - Ejemplos: factorial, Fibonacci, búsqueda binaria recursiva (recursive binary search).
        
    - Método de sustitución / expansión (substitution method).
        
- **[[3.Estructuras lineales (linear data structures)]]**
    
    - Arrays y listas (arrays & lists).
        
    - Listas enlazadas simples, dobles y circulares (singly / doubly / circular linked lists).
        
    - Pilas (stacks) y colas (queues).
        
    - Colas de prioridad (priority queues) básicas.
        
- **Árboles (trees)**
    
    - Árboles binarios (binary trees) y recorridos (traversals): preorder, inorder, postorder.
        
    - Árboles de búsqueda binarios (binary search trees, BST).
        
    - Árboles balanceados (balanced trees) tipo AVL.
        
    - Heaps / binary heaps (y priority queue eficiente).
        
- **Tablas hash (hash tables / hash maps)**
    
    - Funciones hash (hash functions).
        
    - Colisiones (collisions) y resolución: chaining, open addressing.
        
    - Complejidad promedio y peor caso.
        
- **Grafos (graphs)**
    
    - Conceptos básicos: nodos (nodes), aristas (edges), grados (degree).
        
    - Representaciones: adjacency list vs adjacency matrix.
        
    - Recorridos BFS (breadth-first search) y DFS (depth-first search).
        
    - Caminos mínimos (shortest paths: Dijkstra).
        
    - Árboles de expansión mínima (minimum spanning trees: Kruskal, Prim).
        
- **Algoritmos de ordenación (sorting algorithms)**
    
    - Bubble, insertion, selection (O(n²) family).
        
    - Merge sort, quicksort, heapsort (O(n log n)).
        
    - Estabilidad (stability), in-place vs out-of-place.
        
- **Técnicas de diseño de algoritmos (algorithm design techniques)**
    
    - Divide and conquer (divide y vencerás).
        
    - Greedy algorithms (voraces).
        
    - Dynamic programming (programación dinámica) introductorio.[docs.ie.edu](https://docs.ie.edu/university/Grados/BCSAI/ALGORITHMS__DATA_STRUCTURES.pdf?utm_source=chatgpt.com)


## **[BLOQUE 1 – Fundamentos de algoritmos y complejidad]**

> Qué es un algoritmo, modelo de coste, tiempo/espacio, notación Big-O / Big-Ω / Big-Θ, casos peor/promedio/mejor.

### Aquí qué hacer

- **Leer / entender muy bien (teoría):**
    
    - Definición de algoritmo (algorithm).
        
    - Qué significa modelo de coste (cost model).
        
    - Intuición de complejidad temporal (time complexity) y espacial (space complexity).
        
    - Significado formal de notación:
        
        - $O(f(n))$
            
        - $\Omega(f(n))$
            
        - $\Theta(f(n))$
            
    - Diferencia entre:
        
        - peor caso (worst case),
            
        - promedio (average case),
            
        - mejor caso (best case).
            
- **Practicar (pero ejercicios cortos):**
    
    - Dado un fragmento de código → decir si es:
        
        - $O(1)$, $O(\log n)$, $O(n)$, $O(n^2)$, $O(2^n)$, etc.
            
    - Ordenar funciones por crecimiento:
        
        - tipo: $\log n < n < n \log n < n^2 < 2^n$.
            
    - Interpretar algún gráfico simple de “input size vs tiempo”.
        

**Resumen:**  
Este bloque es **50% leer / 50% ejercicios cortos de reconocimiento de complejidad**. No hace falta hacer listas infinitas de ejercicios, pero sí que todo ejemplo que veas lo sepas justificar con palabras.

---

## **[BLOQUE 2 – Recurrencias (recurrences) y recursión (recursion)]**

> Recurrencias básicas, factorial, Fibonacci, búsqueda binaria recursiva, método de sustitución / expansión.

### Aquí qué hacer

- **Leer / entender:**
    
    - Idea de recursión (recursion): función que se llama a sí misma.
        
    - Condición base (base case) vs caso recursivo (recursive case).
        
    - Qué es una relación de recurrencia (recurrence relation):
        
        - Ej: $T(n) = T(n-1) + c$, $T(n) = 2T(n/2) + cn$.
            
- **Practicar sí o sí (importante):**
    
    - Trazar recursión:
        
        - factorial: cuántas llamadas se hacen, qué devuelve cada una.
            
        - Fibonacci recursivo: ver el árbol de llamadas.
            
        - binary search recursivo: ver cómo parte el array.
            
    - Sacar complejidad a partir de la recurrencia:
        
        - Ejercicios típicos:
            
            - $T(n) = T(n-1) + c$ → $O(n)$.
                
            - $T(n) = T(n-2) + c$ → $O(n)$.
                
            - $T(n) = 2T(n/2) + c$ → $O(n)$.
                
            - $T(n) = 2T(n/2) + cn$ → $O(n \log n)$.
                
        - Usando método de expansión (substitution / unfolding), no hace falta ponerse muy hardcore con el Master Theorem si el profe no lo usa.
            

**Resumen:**  
Este bloque es **muy de examen**: traza de recursión + plantear y resolver $T(n)$. Aquí sí te conviene hacer **bastantes ejercicios**.

---

## **[BLOQUE 3 – Estructuras lineales (linear data structures)]**

> Arrays, listas, linked lists (simple/doble/circular), pilas (stacks), colas (queues), colas de prioridad básicas.

### Aquí qué hacer

- **Leer / entender:**
    
    - Diferencia conceptual:
        
        - array vs lista enlazada (linked list),
            
        - pila (stack) = LIFO,
            
        - cola (queue) = FIFO.
            
    - Operaciones típicas:
        
        - stack: `push`, `pop`, `peek`.
            
        - queue: `enqueue`, `dequeue`, `front`.
            
        - listas enlazadas: insertar/borrar al principio, al final, en medio.
            
- **Practicar fuerte:**
    
    - Trazas de operaciones:
        
        - Dada una secuencia de `push`/`pop` → ¿qué queda en la pila?
            
        - Dada una secuencia de `enqueue`/`dequeue` → ¿qué sale y qué queda en la cola?
            
        - Dado código que maneja `next`/`prev` → dibujar la lista.
            
    - Complejidad de operaciones:
        
        - Saber decir y justificar:
            
            - insertar al principio / final / posición `i` en array vs linked list.
                
            - coste de `push`/`pop`, `enqueue`/`dequeue`.
                
    - Implementación en papel:
        
        - Métodos simples de listas enlazadas: insertar en cabeza, buscar elemento.
            
        - Implementar stack con array y con linked list.
            
        - Implementar queue con array circular.
            

**Resumen:**  
Bloque **muy práctico**: mucha traza y pseudo-código / Java en papel.

---

## **[BLOQUE 4 – Árboles (trees)]**

> Árboles binarios, recorridos (preorder, inorder, postorder), BST, AVL, heaps.

### Aquí qué hacer

- **Leer / entender:**
    
    - Terminología: root, child, leaf, height, depth, subtree.
        
    - Definición de BST (binary search tree).
        
    - Qué significa “balanceado” (balanced): altura $O(\log n)$.
        
    - Qué es un heap binario (binary heap) y cómo soporta una priority queue eficiente.
        
- **Practicar sí o sí:**
    
    - Construcción paso a paso:
        
        - Insertar una secuencia de claves en un BST → dibujar el árbol final.
            
        - Insertar en un AVL → aunque no te pidan todas las rotaciones de memoria, al menos entender alguna.
            
    - Recorridos:
        
        - Dado un árbol, sacar:
            
            - preorder, inorder, postorder, level-order.
                
        - Muy típico de examen.
            
    - Complejidad:
        
        - Coste de búsqueda/inserción/borrado en:
            
            - BST balanceado vs BST degenerado.
                
            - heap (insert, extract-min / extract-max).
                

**Resumen:**  
Bloque **mezcla de teoría (definiciones)** y **ejercicios gráficos y de traza**. Vale MUCHO la pena practicar.

---

## **[BLOQUE 5 – Tablas hash (hash tables / hash maps)]**

> Funciones hash, colisiones, chaining, open addressing, complejidad promedio / peor.

### Aquí qué hacer

- **Leer / entender bien:**
    
    - Idea de función hash (hash function).
        
    - Qué es una colisión (collision).
        
    - Diferencias entre:
        
        - chaining (listas enlazadas por bucket),
            
        - open addressing (linear probing, quadratic probing, double hashing).
            
    - Carga (load factor) y cómo afecta a rendimiento.
        
- **Practicar (no tanto como árboles/grafos, pero importante):**
    
    - Dada una tabla hash y una función hash simple, simular:
        
        - inserciones con colisiones,
            
        - búsquedas,
            
        - borrados (si entran).
            
    - Saber estimar:
        
        - coste promedio (average case) ≈ $O(1)$,
            
        - peor caso (worst case) ≈ $O(n)$.
            

**Resumen:**  
Bloque de **entender muy bien la teoría + hacer algunas trazas** de inserciones/búsquedas para no liarte con las colisiones.

---

## **[BLOQUE 6 – Grafos (graphs)]**

> Nodos, aristas, representaciones, BFS, DFS, Dijkstra, Kruskal, Prim.

### Aquí qué hacer

- **Leer / entender:**
    
    - Qué es un grafo (graph), dirigido / no dirigido.
        
    - Diferencia entre adjacency matrix y adjacency list.
        
    - Intuición de BFS vs DFS:
        
        - BFS: por niveles usando queue.
            
        - DFS: profundidad usando stack (o recursión).
            
- **Practicar bastante:**
    
    - Trazas de BFS / DFS:
        
        - Dado un grafo y un nodo inicial:
            
            - orden de visita,
                
            - contenido de la cola (BFS) o pila / call stack (DFS) en cada paso.
                
    - Dijkstra:
        
        - Sobre un grafo con pesos positivos, ir actualizando distancias mínimas.
            
        - Tabla de distancias + conjunto de nodos ya fijos.
            
    - MST (Kruskal, Prim):
        
        - Kruskal: ordenar aristas por peso y añadir sin crear ciclos (usar unión-find o, en examen, “visual”).
            
        - Prim: ir creciendo un árbol añadiendo la arista de menor peso conectando a un nuevo nodo.
            

**Resumen:**  
Bloque **muy de ejercicios de traza sobre grafos dibujados**. Aquí conviene hacer varios ejemplos, no solo leer.

---

## **[BLOQUE 7 – Algoritmos de ordenación (sorting algorithms)]**

> Bubble, insertion, selection, merge sort, quicksort, heapsort, estabilidad, in-place.

### Aquí qué hacer

- **Leer / entender:**
    
    - Idea intuitiva de cada algoritmo:
        
        - bubble, insertion, selection: familia $O(n^2)$.
            
        - merge sort, quicksort, heapsort: familia $O(n \log n)$.
            
    - Conceptos:
        
        - algoritmo estable (stable),
            
        - in-place vs out-of-place.
            
- **Practicar bastante:**
    
    - Trazar a mano:
        
        - un bubble sort sobre una lista pequeña.
            
        - un insertion sort y ver cómo se va construyendo la parte ordenada.
            
        - un merge sort: ver cómo divide y luego mergea.
            
        - un quicksort: elegir pivote, particiones, recursión.
            
    - Complejidad:
        
        - saber justificar por qué:
            
            - bubble / insertion / selection → $O(n^2)$,
                
            - merge / heap / quick (caso promedio) → $O(n \log n)$,
                
            - quick worst-case → $O(n^2)$.
                

**Resumen:**  
Bloque **muy probable en exámenes**. Trazas + justificar complejidad.

---

## **[BLOQUE 8 – Técnicas de diseño de algoritmos (algorithm design techniques)]**

> Divide and conquer, greedy, dynamic programming (intro).

### Aquí qué hacer

- **Leer / entender:**
    
    - Esquema general de:
        
        - divide and conquer: divide → resuelve recursivamente → combina.
            
        - greedy: decisiones locales óptimas esperando solución global buena.
            
        - dynamic programming: subproblemas, solapamiento (overlapping subproblems), optimal substructure, tabla.
            
- **Practicar pero con pocos buenos problemas:**
    
    - Divide and conquer:
        
        - identificar que merge sort y quicksort son ejemplos.
            
        - ver algún problema simple (búsqueda de máximo/mínimo, etc.).
            
    - Greedy:
        
        - problemas típicos sencillos:
            
            - actividad seleccionada (activity selection),
                
            - cambio de monedas en casos donde greedy funciona.
                
    - Dynamic programming:
        
        - un par de clásicos intro:
            
            - Fibonacci con DP (bottom-up).
                
            - mochila 0/1 simple o longest common subsequence pequeñita.
                
        - Montar tablita y rellenarla.
            

**Resumen:**  
Bloque **más conceptual / de esquemas** pero aun así merece **algunos ejercicios representativos**, no miles.

---

## En conclusión (para que te organices)

Si tu tiempo es limitado y tienes que priorizar dónde hacer MÁS ejercicios vs MÁS lectura:

- **Mucho ejercicio (prioridad alta):**
    
    - Bloque 2 – Recurrencias y recursión.
        
    - Bloque 3 – Estructuras lineales.
        
    - Bloque 4 – Árboles.
        
    - Bloque 6 – Grafos.
        
    - Bloque 7 – Ordenación.
        
- **Mixto, pero con menos carga de ejercicios:**
    
    - Bloque 1 – Fundamentos y notación.
        
    - Bloque 5 – Hash tables.
        
    - Bloque 8 – Técnicas de diseño.