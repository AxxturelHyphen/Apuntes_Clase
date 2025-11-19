

---

---

# [BLOQUE 1] Fundamentos de algoritmos y complejidad – EJERCICIOS COMPLETOS

## A. Preguntas conceptuales cortas (theory / definitions)

### Ejercicio A1 – ¿Qué es un algoritmo?

Explica con tus palabras qué es un **algoritmo (algorithm)** y da **dos ejemplos**:

1. Un algoritmo de la vida real (ej. hacer una tortilla).
    
2. Un algoritmo típico en programación (ej. ordenar una lista).
    

Pista mental: incluye idea de **entrada (input)**, **salida (output)**, **pasos finitos** y **bien definidos**.

---

### Ejercicio A2 – Modelo de coste (cost model)

1. ¿Qué es un **modelo de coste (cost model)** en análisis de algoritmos?
    
2. ¿Por qué en AED solemos considerar que operaciones básicas como:
    
    - asignaciones,
        
    - comparaciones,
        
    - sumas/restas,
        
    - accesos a arrays
        
    
    tienen coste constante, es decir, tiempo $O(1)$?
    
3. Da un ejemplo de situación real donde este modelo pueda no ser perfecto (caché, disco, red, etc.).
    

---

### Ejercicio A3 – Time vs Space complexity

Explica la diferencia entre:

- **Time complexity** (complejidad temporal)
    
- **Space complexity** (complejidad espacial)
    

y pon:

1. Un ejemplo donde **ahorrar tiempo** implica usar **más memoria**.
    
2. Un ejemplo donde **ahorrar memoria** hace que el algoritmo sea más **lento**.
    

---

### Ejercicio A4 – Casos best / average / worst

Para la **búsqueda lineal (linear search)** en un array desordenado:

1. Define **mejor caso (best case)** y su complejidad en notación: $O(\cdot)$.
    
2. Define **peor caso (worst case)** y su complejidad.
    
3. Explica intuitivamente el **caso promedio (average case)** y su complejidad esperada.
    
4. ¿Por qué solemos analizar sobre todo el **peor caso** en teoría de algoritmos?
    

---

## B. Notación asintótica (Big-O, Big-Ω, Big-Θ) y comparar funciones

### Ejercicio B1 – Clasificar funciones

Ordena estas funciones de **menor a mayor crecimiento**:

1. $f(n) = n \log n$
    
2. $g(n) = n^2$
    
3. $h(n) = 2^n$
    
4. $k(n) = \log n$
    
5. $p(n) = n^3$
    

Después de ordenarlas, anota el orden correcto en tus apuntes.

(Solución esperada del orden: $\log n < n \log n < n^2 < n^3 < 2^n$.)

---

### Ejercicio B2 – Big-O, Big-Ω, Big-Θ de un polinomio

Sea:

$T(n) = 3n^2 + 10n + 5$.

1. Da una cota de tipo **Big-O (upper bound)**: $T(n) = O(\dots)$.
    
2. Da una cota **Big-Ω (lower bound)**: $T(n) = \Omega(\dots)$.
    
3. Da la cota ajustada **Big-Θ (tight bound)**: $T(n) = \Theta(\dots)$.
    
4. Explica por qué, para $n$ grande, solo importa el término $3n^2$.
    

(Spoiler para corrección propia: O, Ω y Θ todo respecto a $n^2$.)

---

### Ejercicio B3 – Verdadero / Falso (con explicación)

Indica V/F y justifica en 1–3 líneas:

1. Si un algoritmo es $O(n^2)$, entonces también es $O(n^3)$.
    
2. Si un algoritmo es $O(n)$, entonces también es $\Omega(n^2)$.
    
3. Si un algoritmo es $\Theta(n)$, entonces también es $O(n)$ y $\Omega(n)$.
    
4. La notación $O(\cdot)$ describe el tiempo exacto que tarda un algoritmo en ejecutarse.
    

---

## C. Cálculo de complejidad de fragmentos de código

Lenguaje base: Java-like.

### Ejercicio C1 – Bucle simple
```Java
void f(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + i;
    }
    System.out.println(sum);
}
```
1. ¿Cuántas veces se ejecuta la línea `sum = sum + i;` en función de $n$?
    
2. Da la **complejidad temporal** en notación Big-O.
    
3. Da la **complejidad espacial adicional** (ignora el array de entrada si lo hubiera).
    

(Guía: línea del bucle se ejecuta $n$ veces → tiempo $O(n)$; espacio extra $O(1)$.)

Ejercicio C2 – Bucle anidado (cuadrado)
```Java
void g(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }
    System.out.println(count);
}

```

1. ¿Cuántas veces se ejecuta `count++;` en total?
    
2. Da la complejidad temporal en notación Big-O.
    
3. Si movemos el `System.out.println(count);` dentro del bucle interno, ¿cambia la clase de complejidad asintótica?
    

---

### Ejercicio C3 – Bucle triangular
```Java
void h(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            count++;
        }
    }
}
```

1. Escribe la suma que cuenta cuántas veces se ejecuta `count++;`:  
    por ejemplo, algo tipo  
    $\sum_{i=0}^{n-1} (\dots)$.
    
2. Usa la fórmula clásica de la suma  
    $1 + 2 + \dots + n = \dfrac{n(n+1)}{2}$.
    
3. Da la complejidad en notación Big-O.
    
4. Compárala con el doble bucle perfecto (C2): ¿crecen igual asintóticamente?
    

---

### Ejercicio C4 – Búsqueda lineal (linear search)
```Java
int linearSearch(int[] a, int x) {
    for (int i = 0; i < a.length; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}
```

Sea $n = a.length$.

1. Da el **mejor caso** en tiempo: qué pasa y qué complejidad tiene.
    
2. Da el **peor caso** y su complejidad.
    
3. Da el **caso promedio** (intuitivo) y su complejidad.
    
4. ¿Por qué decimos que es un algoritmo de complejidad lineal en tiempo $O(n)$?
    

---

## D. Comparar algoritmos y crecimiento

### Ejercicio D1 – Dos fragmentos distintos

**Algoritmo 1:**
```Java
void algo1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // O(1)
        }
    }
}
```


Algoritmo 2:

```Java
void algo2(int n) {
    for (int i = 0; i < n; i++) {
        // O(1)
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            // O(1)
        }
    }
}
```

1. Da la complejidad temporal de `algo1` en Big-O.
    
2. Da la de `algo2`.
    
3. ¿Cuál de los dos es asintóticamente más eficiente?
    
4. Si las constantes ocultas fueran muy distintas, ¿podría ocurrir que, para tamaños de entrada pequeños, uno que es peor asintóticamente vaya más rápido en la práctica?
    

---

### Ejercicio D2 – Dos complejidades: lineal vs cuadrática

Tienes:

- Algoritmo X con tiempo aproximado $T_X(n) = 1000 \cdot n$.
    
- Algoritmo Y con tiempo aproximado $T_Y(n) = n^2$.
    

1. Para $n = 10$, ¿cuál crees que es más rápido en la práctica?
    
2. Para $n = 10^6$, ¿cuál ganará?
    
3. Explica en una frase la idea de que “a largo plazo, manda el orden de crecimiento (growth rate) más que las constantes”.
    

---

## E. Preguntas tipo test (multiple choice)

### Ejercicio E1

La complejidad temporal de un algoritmo que ejecuta de forma secuencial dos operaciones, una de tiempo $O(n)$ y otra de tiempo $O(n^3)$, es:

a) $O(n)$  
b) $O(n^3)$  
c) $O(n^4)$  
d) $O(n \log n)$

---

### Ejercicio E2

¿Cuál de las siguientes complejidades crece más rápido cuando $n \to \infty$?

a) $O(n \log n)$  
b) $O(n^2)$  
c) $O(2^n)$  
d) $O(n^3)$

---

### Ejercicio E3

¿En cuál de los siguientes casos tiene más sentido analizar **average-case time complexity**?

a) Un algoritmo que siempre hace exactamente lo mismo, independientemente del input.  
b) Un algoritmo cuyo comportamiento depende fuertemente de la distribución de los datos de entrada (por ejemplo, quicksort).  
c) Un algoritmo que solo se ejecuta una vez en toda la vida.  
d) Un algoritmo que siempre termina en tiempo $O(1)$.

---

## F. Problemas “de pensar” (diseño + complejidad)

### Ejercicio F1 – Problema “todos distintos”

Tienes un array de enteros `a[0..n-1]`. Queremos saber si **todos los elementos son distintos**.

1. Propón un algoritmo sencillo (pista: doble bucle que compare todos los pares de posiciones).
    
2. Da su complejidad temporal en el peor caso, en función de $n$.
    
3. Propón una mejora usando una **tabla hash (hash table)** (solo la idea general, no hace falta código).
    
4. ¿Cuál es la complejidad promedio de esa solución con tabla hash?
    
5. ¿Qué podría pasar en el peor caso con la tabla hash?
    

---

### Ejercicio F2 – Tiempo lineal con constante grande vs cuadrático

Piensa en dos algoritmos para el mismo problema:

- Algoritmo A: tiene complejidad $O(n)$, pero la constante es muy grande (tarda mucho por cada elemento).
    
- Algoritmo B: tiene complejidad $O(n^2)$, pero la constante es muy pequeña (cada operación es rapidísima).
    

1. Explica por qué, para valores pequeños de $n$, puede ser que el algoritmo B (cuadrático) sea más rápido que el A (lineal).
    
2. Explica por qué, para $n$ muy grande, el algoritmo A terminará siendo mejor.
    
3. Relaciónalo con la idea de **complejidad asintótica**.
    

---

## G. Análisis detallado de casos concretos

### Ejercicio G1 – Función `allPositive`
```Java
boolean allPositive(int[] a) {
    for (int i = 0; i < a.length; i++) {
        if (a[i] <= 0) {
            return false;
        }
    }
    return true;
}
```
Sea $n = a.length$.

1. Si **todos los elementos son positivos**, ¿cuántas veces se evalúa la condición del `if`? ¿Cuál es la complejidad temporal en el peor caso?
    
2. Si el **primer elemento ya es menor o igual que 0**, ¿cuántas veces se evalúa el `if`? ¿Cuál es entonces el mejor caso?
    
3. ¿Por qué podemos decir que, en notación asintótica, la complejidad es $O(n)$?
    

---

### Ejercicio G2 – Tabla “n vs tiempo” para $O(n^2)$

Imagina un algoritmo con complejidad $O(n^2)$. Completa mentalmente:

|n|Tiempo relativo|
|---|---|
|1.000|t|
|2.000|?|
|10.000|?|