## 3. Pilas (stacks)

### 3.1 Idea intuitiva

Una **pila (stack)** es una estructura con disciplina **LIFO (Last In, First Out)**:

> El último en entrar es el primero en salir.

Analogía: una pila de platos. Pones platos uno encima de otro:

- Para poner un plato: lo dejas encima → operación `push`.
    
- Para coger un plato: coges el de arriba → operación `pop`.
    

No puedes sacar directamente el plato del centro sin quitar los de arriba. Lo mismo con una pila de datos: solo accedes al **tope (top)**.

Usos clásicos:

- **Call stack** o pila de llamadas de un programa (funciones recursivas).
    
- **Deshacer (undo)**: cada operación se apila, deshaces sacando la última.
    
- **Evaluación de expresiones** (notación postfija, etc.).
    
- **Backtracking** y **DFS (depth-first search)**.
    

---

### 3.2 Definición formal

TAD **Stack** (pila):

- `push(x)`: mete `x` en la cima.
    
- `pop()`: saca y devuelve el elemento de la cima.
    
- `peek()` o `top()`: devuelve el elemento de la cima sin sacarlo.
    
- `isEmpty()`, `size()`, etc.
    

Propiedad central: **LIFO**.

Errores clásicos:

- **Underflow**: hacer `pop` en pila vacía.
    
- **Overflow**: intentar `push` en pila llena (si es de capacidad fija).
    

Implementaciones típicas:

- Con **array**:
    
    - Array + índice `topIndex`.
        
- Con **linked list**:
    
    - Usando la cabeza de la lista como tope.
        

En ambos casos las operaciones son tiempo $O(1)$.

### 3.4 Complejidad

Para una pila bien implementada:

- `push`: $O(1)$ (amortizado si array dinámico).
    
- `pop`: $O(1)$.
    
- `peek`: $O(1)$.
    
- `isEmpty`, `size`: $O(1)$.
    

No hay diferencia entre mejor/peor/promedio (salvo el caso puntual de `resize` en arrays dinámicos, que se considera amortizado).

Espacio:

- $O(n)$ para $n$ elementos.
    
- Muy poco overhead extra.
    

---

### 3.5 Mini resumen (chuleta mental)

- **Stack = LIFO**:
    
    - Último en entrar, primero en salir.
        
    - Solo el tope es visible.
        
- **Operaciones**:
    
    - `push`, `pop`, `peek`, `isEmpty`.
        
    - Todas $O(1)$.
        
- **Implementación**:
    
    - Array + índice `topIndex`.
        
    - Lista enlazada (insertar/eliminar en cabeza).
        
- **Errores típicos**:
    
    - `pop` o `peek` sobre pila vacía (underflow).
        
    - Pila recursiva infinita → `StackOverflowError`.
        
- **Usos típicos**:
    
    - Pila de llamadas.
        
    - DFS (recursivo/iterativo).
        
    - Evaluación de expresiones.
        
    - Sistemas de undo/redo.
        