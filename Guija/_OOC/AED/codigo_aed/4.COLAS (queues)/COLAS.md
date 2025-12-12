. Colas (queues)

### 4.1 Idea intuitiva

Una **cola (queue)** sigue disciplina **FIFO (First In, First Out)**:

> El primero en entrar es el primero en salir.

Analogía: cola en el súper. La gente se pone al final, y se atiende primero a quien lleva más tiempo esperando.

Propiedades:

- **Enqueue**: insertas al **final** de la cola.
    
- **Dequeue**: sacas del **frente** de la cola.
    
- FIFO: se respeta el orden de llegada.
    

Usos típicos:

- Sistemas de colas de impresión.
    
- Planificación de procesos (ready queue).
    
- Algoritmo **BFS (breadth-first search)** en grafos.
    
- Problemas productor-consumidor (buffers).
    

---

### 4.2 Definición formal

TAD **Queue**:

- `enqueue(x)` / `offer(x)`: añade `x` al final.
    
- `dequeue()` / `remove()` / `poll()`: saca y devuelve el elemento del frente.
    
- `peek()` / `front()`: devuelve el elemento del frente sin sacarlo.
    
- `isEmpty()`, `size()`, etc.
    

Tiene dos extremos:

- **Front (head)**: de donde salen elementos.
    
- **Rear (tail)**: donde entran.
    

Implementaciones típicas:

- Con **lista enlazada**:
    
    - `head` (front) y `tail` (rear).
        
- Con **array circular**:
    
    - Array + índices `headIndex` y `tailIndex` + `size`.
        

---

### 4.5 Complejidad

Con **lista enlazada** (`head` + `tail`):

- `enqueue`: $O(1)$.
    
- `dequeue`: $O(1)$.
    
- `peek`: $O(1)$.
    

Con **array circular**:

- `enqueue`: $O(1)$.
    
- `dequeue`: $O(1)$.
    
- `peek`: $O(1)$.
    

Con una implementación ingenua de array **sin** circularidad y haciendo `shift` al hacer `dequeue`, cada `dequeue` sería $O(n)$ y es mala idea.

Espacio: $O(n)$.

---

### 4.6 Mini resumen (chuleta mental)

- **Queue = FIFO**:
    
    - Primero en entrar, primero en salir.
        
    - Entra por `rear`, sale por `front`.
        
- **Operaciones**:
    
    - `enqueue`, `dequeue`, `peek`, `isEmpty`.
        
    - Todo $O(1)$ con lista enlazada o array circular.
        
- **Implementaciones**:
    
    - Linked list con `head`/`tail`.
        
    - Array circular (`(index + 1) % capacity`).
        
    - En Java: `Queue<E>` con `LinkedList` o `ArrayDeque`.
        
- **Errores típicos**:
    
    - Implementar cola con `ArrayList.remove(0)` (cada remove es $O(n)$).
        
    - No distinguir bien vacío vs lleno en buffer circular.
        
    - Underflow: `dequeue` en cola vacía.
        
- **Usos**:
    
    - BFS.
        
    - Buffers de mensajes (productor-consumidor).
        
    - Colas de impresión / jobs.
        