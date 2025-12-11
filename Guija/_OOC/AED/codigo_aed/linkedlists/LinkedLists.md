## 2. Listas enlazadas (singly / doubly / circular linked lists)

### 2.1 Idea intuitiva

Una **lista enlazada (linked list)** es una estructura **dinámica** en la que cada elemento se guarda en un **nodo** que contiene:

- Un **valor** (`data`).

- Uno o más **punteros/enlaces** (`links`) a otros nodos.


No están en memoria contigua. Cada nodo “sabe” quién viene después (y en las dobles, quién viene antes).

Analogías:

- Una cadena de eslabones: cada eslabón apunta al siguiente.

- Una gymkhana con pistas: cada pista te dice dónde está la siguiente.


Ventajas:

- Insertar/eliminar elementos en medio es **muy barato** si ya estás en el sitio correcto: solo re-enlazar punteros.

- El tamaño es dinámico: crece/disminuye sin tener que copiar todo.


Desventajas:

- No hay **acceso aleatorio**: para llegar al elemento número $i$ hay que caminar desde el principio → $O(n)$.

- Peor localidad de caché: cada nodo puede estar en otra zona de memoria.


Variantes típicas:

- **Singly linked list** (simplemente enlazada): cada nodo tiene `next`.

- **Doubly linked list** (doblemente enlazada): cada nodo tiene `prev` y `next`.

- **Circular linked list**: el último nodo apunta al primero (y a veces el primero al último), formando un ciclo.


---

### 2.2 Definición formal y variantes

**Lista simplemente enlazada (singly linked list):**

- Conjunto de nodos $n_1, n_2, ..., n_k$.

- Cada nodo tiene:

    - `data`.

    - `next` apuntando al siguiente nodo (excepto el último, que apunta a `null`).

- Puntero externo `head` apunta al primer nodo $n_1$.

- Lista vacía: `head == null`.


Operaciones típicas:

- Insertar al inicio (`push_front`):  
  Nuevo nodo apunta a `head` y actualizamos `head`.  
  Coste: $O(1)$.

- Eliminar al inicio (`pop_front`):  
  `head = head.next`.  
  Coste: $O(1)$.

- Buscar por valor:  
  Recorrer hasta encontrarlo.  
  Peor caso: $O(n)$.

- Insertar después de un nodo conocido:

    - Coste $O(1)$ si ya tienes la referencia al nodo.

- Eliminar después de un nodo conocido:

    - Coste $O(1)$ si tienes la referencia al nodo anterior.


**Lista doblemente enlazada (doubly linked list):**

- Cada nodo tiene:

    - `data`.

    - `next` (siguiente).

    - `prev` (anterior).

- Sueles mantener punteros `head` y `tail`.

- Ventaja: si tienes referencia al nodo a eliminar, puedes quitarlo en $O(1)$ sin buscar el anterior:

    - Ajustas `prev.next` y `next.prev`.


Formalmente, si la lista tiene nodos $n_1, ..., n_k$:

- $n_1.prev = null$

- $n_k.next = null$

- Para $1 < i < k$:

    - $n_i.prev = n_{i-1}$

    - $n_i.next = n_{i+1}$

---

**Casos borde / errores típicos:**

- Perder nodos al re-enlazar mal:

    - Por ejemplo, al eliminar un nodo intermedio, no relinkear correctamente y “cortar” el resto de la lista.

- No actualizar `prev` en listas dobles → estructura inconsistente.

- Olvidar actualizar `head`/`tail` al insertar/eliminar en extremos.

- En listas circulares, escribir bucles sin condición de parada adecuada → bucles infinitos.


---

### 2.4 Complejidad

Para una lista enlazada (singly o doubly):

- Insertar al inicio: $O(1)$.

- Eliminar al inicio: $O(1)$.

- Insertar al final:

    - Sin puntero `tail`: necesitas recorrer hasta el final → $O(n)$.

    - Con `tail`: $O(1)$.

- Eliminar al final:

    - Lista simple: si no tienes el anterior, hay que recorrer → $O(n)$.

    - Lista doble con `tail`: puedes eliminar `tail` en $O(1)$.

- Insertar/eliminar **después de un nodo conocido**: $O(1)$.

- Búsqueda por valor / acceso al nodo $i$:

    - Hay que recorrer desde `head` → $O(n)$.

- Espacio:

    - $O(n)$, pero con overhead de 1 o 2 punteros por nodo.

    - Menor localidad de caché que arrays.


Clave mental: listas enlazadas optimizan **inserciones/eliminaciones locales** y penalizan **acceso por índice**.

---

### 2.5 Mini resumen (chuleta mental)

- **Linked list**:

    - Nodos con `data` + punteros.

    - No hay memoria contigua, tamaño dinámico.

    - Insertar/eliminar en posiciones conocidas → $O(1)$.

    - Acceder al elemento $i$ → $O(n)$.

- **Singly linked list**:

    - Solo `next`.

    - Menos memoria, más sencilla.

    - Para eliminar un nodo necesitas referencia al anterior (o buscarlo).

- **Doubly linked list**:

    - `prev` y `next`.

    - Más memoria, pero eliminar un nodo dado es $O(1)$ sin buscar el anterior.

    - Más fácil recorrer hacia atrás.

- **Circular linked list**:

    - Último nodo apunta al primero.

    - Útil en rondas cíclicas, buffers circulares.

    - Cuidado con bucles infinitos.

- **Comparación rápida array vs lista enlazada**:

    - Array: acceso por índice $O(1)$, inserciones en medio $O(n)$.

    - Lista enlazada: acceso por índice $O(n)$, inserciones locales $O(1)$.

- **Errores de examen típicos**:

    - Dibujar mal la lista después de una inserción/eliminación.

    - Olvidar actualizar `head`/`tail`.

    - Olvidar alguno de los punteros en listas dobles (`prev` o `next`).