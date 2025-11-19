

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