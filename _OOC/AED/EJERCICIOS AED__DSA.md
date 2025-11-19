## COMPLEJIDAD
Dado este código, di la complejidad en función de $n$ (peor caso) y explica por qué:
```Java
void ejemplo(int n) {
    int suma = 0;                 // (1)
    for (int i = 0; i < n; i++) { // (2)
        for (int j = 0; j < n; j++) { // (3)
            suma++;               // (4)
        }
    }
    System.out.println(suma);     // (5)
}
```
1. ¿Qué complejidad tiene? (en notación: $O(\cdot)$)
    
2. ¿Cómo justificarías esa complejidad paso a paso como si fuera en un examen?
    

Respóndeme tú primero, aunque sea “a ojo”, y a partir de ahí te corrijo y vamos subiendo nivel, twin.

# BLOQUE 1 – FUNDAMENTOS DE ALGORITMOS Y COMPLEJIDAD

## A. Preguntas conceptuales cortas (theory / definitions)

**Ejercicio A1 – ¿Qué es un algoritmo? (definition)**  
Explica con tus palabras qué es un **algoritmo (algorithm)** y di **dos ejemplos**:

1. Un algoritmo de la vida real (ej. hacer una tortilla).
    
2. Un algoritmo típico en programación (ej. ordenar una lista).
    

> Pista/Idea de corrección: debe aparecer algo tipo _“secuencia finita de pasos bien definidos que, dados unos datos de entrada (input), producen una salida (output) y terminan”_.

---

**Ejercicio A2 – Modelo de coste (cost model)**  
Contesta:

1. ¿Qué es un **modelo de coste (cost model)** y para qué lo usamos en análisis de algoritmos?
    
2. ¿Por qué en AED solemos considerar que operaciones básicas como asignaciones, comparaciones y sumas tienen coste constante (O(1))?
    

---

**Ejercicio A3 – Time vs Space complexity**  
Explica la diferencia entre:

- **Time complexity** (complejidad temporal)
    
- **Space complexity** (complejidad espacial)
    

Y pon un ejemplo de algoritmo donde **ahorrar tiempo consume más memoria** y otro donde **ahorrar memoria hace el algoritmo más lento**.

---

**Ejercicio A4 – Casos best / average / worst**  
Para cada uno de estos términos, da una definición breve y un ejemplo:

- **Mejor caso (best case)**
    
- **Caso promedio (average case)**
    
- **Peor caso (worst case)**
    

Ejemplo sugerido: **búsqueda lineal (linear search)** sobre un array desordenado.

---

## B. Identificar notación asintótica (Big-O, Big-Ω, Big-Θ)

**Ejercicio B1 – Clasificar funciones**

Ordena de **menor a mayor crecimiento** (growth rate):

1. $f(n)=nlog⁡nf(n) = n \log nf(n)=nlogn$
    
2. g(n)=n2g(n) = n^2g(n)=n2
    
3. h(n)=2nh(n) = 2^nh(n)=2n
    
4. k(n)=log⁡nk(n) = \log nk(n)=logn
    
5. p(n)=n3p(n) = n^3p(n)=n3
    

> Solución (orden de menor a mayor):  
> log⁡n<nlog⁡n<n2<n3<2n\log n < n \log n < n^2 < n^3 < 2^nlogn<nlogn<n2<n3<2n

---

**Ejercicio B2 – Big-O vs Big-Ω vs Big-Θ**

Para la función T(n)=3n2+10n+5T(n) = 3n^2 + 10n + 5T(n)=3n2+10n+5:

1. Da una cota de tipo **Big-O (upper bound)**.
    
2. Da una cota de tipo **Big-Ω (lower bound)**.
    
3. Da una cota de tipo **Big-Θ (tight bound)**.
    

> Solución esperada (sin demostración formal):
> 
> - Big-O: T(n)=O(n2)T(n) = O(n^2)T(n)=O(n2)
>     
> - Big-Ω: T(n)=Ω(n2)T(n) = \Omega(n^2)T(n)=Ω(n2)
>     
> - Big-Θ: T(n)=Θ(n2)T(n) = \Theta(n^2)T(n)=Θ(n2)
>     

---

**Ejercicio B3 – Verdadero / Falso**

Indica si son verdaderas o falsas y **justifica brevemente**:

1. Si un algoritmo es O(n2)O(n^2)O(n2), entonces también es O(n3)O(n^3)O(n3).
    
2. Si un algoritmo es O(n)O(n)O(n), entonces también es Ω(n2)\Omega(n^2)Ω(n2).
    
3. Si un algoritmo es Θ(n)\Theta(n)Θ(n), entonces también es O(n)O(n)O(n) y Ω(n)\Omega(n)Ω(n).
    
4. La notación O(⋅)O(\cdot)O(⋅) describe siempre el tiempo exacto que tarda un algoritmo.
    

> Idea de solución:
> 
> 1. Verdadero (n² crece más lento que n³, así que n² está acotada por c·n³).
>     
> 2. Falso. n crece más lento que n², no puedes acotarlo por debajo con n².
>     
> 3. Verdadero. Por definición.
>     
> 4. Falso. Da una **cota asintótica superior**, no el tiempo exacto.
>     

---

## C. Cálculo de complejidad de fragmentos de código

Lenguaje base: **Java-like pseudocode** para no liarte.

---

### Ejercicio C1 – Bucle simple