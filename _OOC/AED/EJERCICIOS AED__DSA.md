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