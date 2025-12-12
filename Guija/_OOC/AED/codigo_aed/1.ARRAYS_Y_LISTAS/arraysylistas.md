## 1. Arrays y listas (arrays & lists)

### 1.1 Idea intuitiva

Un **array** (arreglo o vector) es una colección de elementos almacenados en posiciones **contiguas** de memoria, accesibles mediante un **índice entero**. Piénsalo como una fila de casillas numeradas consecutivamente (como columnas en Excel): cada casilla tiene un número (índice) y un valor.

Sirve para almacenar conjuntos de datos **homogéneos** (mismo tipo) de **tamaño fijo**, permitiendo acceder muy rápido a cualquier elemento sabiendo su posición.

Ejemplo: un array de tamaño `N` con índices de `0` a `N-1`. El elemento de la posición `5` se obtiene directamente, sin recorrer nada: acceso en tiempo constante (time complexity $O(1)$).

Problema: en muchos lenguajes el tamaño es **fijo** una vez creado. Si te quedas corto, hay que crear un array nuevo más grande y copiar.

Para aliviar esto aparecen las **listas dinámicas** o **arrays dinámicos** (_dynamic arrays_), que son estructuras que por dentro usan un array, pero que se **redimensiona automáticamente** cuando hace falta (por ejemplo, `ArrayList` en Java, `list` en Python, `std::vector` en C++). Al llegar a la capacidad máxima:

1. Crean un array más grande (típicamente el doble).
    
2. Copian los elementos antiguos.
    
3. Siguen trabajando como si nada.
    

Tú ves algo “elástico”; por debajo es un array que de vez en cuando se “muda de casa”.

---

### 1.2 Definición formal y propiedades

Un **array** de tamaño $N$:

- Estructura lineal de longitud fija con elementos indexados $0, 1, ..., N-1$.
    
- Todos del mismo tipo y almacenados en memoria contigua.
    
- Se puede ver como una función:  
    $A : {0, 1, ..., N-1} -> D$,  
    donde $D$ es el dominio de los valores (enteros, chars, etc.).
    

Propiedades clave:

- **Acceso aleatorio directo (random access)**  
    Dado un índice $i$, acceder a $A[i]$ es tiempo $O(1)$ (constante), porque físicamente se calcula algo del estilo:  
    `addr(A[i]) = addr(A[0]) + i * sizeof(tipo)`.
    
- **Tamaño fijo**  
    En Java/C/C++ estáticos, el tamaño se fija al crear el array. Para crecer más allá: crear uno nuevo y copiar todos los elementos (coste $O(N)$).
    
- **Almacenamiento contiguo**  
    Los elementos están uno detrás de otro en memoria. Esto:
    
    - Favorece la **localidad de referencia** (cache friendly).
        
    - Obliga a copiar si necesitas más espacio contiguo.
        

Una **lista dinámica** (array dinámico tipo `ArrayList`) es un **TAD Lista** con tamaño lógico variable. Internamente mantiene:

- Un array `data` de longitud `capacity`.
    
- Un entero `size` con el número real de elementos.
    

Cuando `size == capacity` y haces `add`:

1. Se crea un array nuevo, por ejemplo de capacidad `2 * capacity`.
    
2. Se copian los `size` elementos.
    
3. Se sustituye el array viejo por el nuevo.
    

Gracias a esa expansión geométrica, las inserciones al final tienen coste **amortizado** $O(1)$:

- Muchas inserciones muy baratas.
    
- Pocas inserciones caras (cuando toca copiar).
    

Operaciones típicas y coste (arrays / listas secuenciales):

- Acceso por índice: `A[i]` → tiempo $O(1)$.
    
- Búsqueda por valor (búsqueda lineal / _linear search_):  
    Peor caso: recorrer todos los elementos → tiempo $O(N)$.
    
- Inserción/eliminación al final:
    
    - En array estático con hueco: $O(1)$.
        
    - En array dinámico: $O(1)$ amortizado (a veces un `resize` de coste $O(N)$).
        
- Inserción/eliminación en posición arbitraria (inicio/medio):  
    Hay que desplazar elementos → coste $O(N)$.
    
- Memoria:
    
    - Array fijo: justo espacio para $N$ elementos → $O(N)$.
        
    - Array dinámico: algo de espacio extra (capacidad > tamaño), pero sigue siendo $O(N)$.
        

Conclusión rápida:

- Array: brutal si conoces tamaño y necesitas **acceso indexado rápido**.
    
- Lista dinámica: sacrifica algo de control por **flexibilidad de tamaño** con coste amortizado muy bueno.

`ArrayList` se encarga de:

- Redimensionar cuando hace falta.
    
- Mover elementos al hacer `remove` en el medio.
    

**Casos borde / errores típicos:**

- Acceder a índice fuera de rango.
    
- Confundir longitud $N$ con último índice $N-1$.
    
- Pensar que `ArrayList.remove(0)` es barato siempre: en realidad es $O(N)$ por desplazamientos.
    

---

### 1.4 Complejidad

**Array fijo:**

- Acceso `A[i]`:
    
    - Mejor/promedio/peor: tiempo $O(1)$.
        
- Búsqueda lineal:
    
    - Peor caso (no está o está al final): tiempo $O(N)$.
        
- Insertar/eliminar al final:
    
    - Si hay espacio: $O(1)$.
        
    - Si no hay espacio y quieres crecer: crear otro array y copiar → $O(N)$.
        
- Insertar/eliminar en posición $k$:
    
    - Hay que desplazar hasta $N - k$ elementos → $O(N)$.
        
- Espacio: $O(N)$.
    

**Array dinámico (tipo `ArrayList`):**

- Acceso por índice: tiempo $O(1)$.
    
- `add` al final:
    
    - Casi siempre $O(1)$.
        
    - A veces $O(N)$ por `resize`, pero **amortizado** → $O(1)$.
        
- Insertar/eliminar en medio:
    
    - Desplazar elementos → $O(N)$.
        
- Espacio:
    
    - `capacity` un poco mayor que `size`, pero sigue $O(N)$.
        

**Localidad de caché:**

- Arrays y array-lists son mucho más **cache-friendly** que estructuras enlazadas, porque los datos están contiguos.
    

---

### 1.5 Mini resumen (chuleta mental)

- **Array**:
    
    - Índices $0..N-1$, memoria contigua, acceso $O(1)$.
        
    - Insertar/quitar en medio → $O(N)$.
        
    - Tamaño fijo.
        
- **Array dinámico / lista dinámica** (por ejemplo `ArrayList`):
    
    - Internamente: array con `capacity` y `size`.
        
    - Al llenarse, se redimensiona (duplicando, típicamente).
        
    - `add` al final: $O(1)$ amortizado.
        
    - Quitar/insertar en medio: $O(N)$.
        
- **Cuándo usar**:
    
    - Usa **array / ArrayList** cuando necesites **acceso por índice rápido** y no estés todo el rato insertando en el medio.
        
    - Si vas a meter/quitar en medio constantemente, mejor mirar **listas enlazadas**.
        
- **Errores típicos de examen**:
    
    - Confundir $N$ con el último índice ($N-1$).
        
    - No contar el coste de desplazar elementos (asumir que `ArrayList.remove(0)` es $O(1)$).
        
    - Olvidar que el `resize` tiene coste $O(N)$ aunque amortizado.
        