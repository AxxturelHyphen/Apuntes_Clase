Significa **"Exclusión Mutua"** (Mutual Exclusion), y **solo registra si un recurso está disponible** o no, tomando los valores ``true`` o ``false`` (0 o 1).

Puede resolver el problema de la sesión crítica.

```java
Semáforo S; 
wait(S); // comprueba que el semáforo le deje pasar

// SECCIÓN CRÍTICA 

signal(S); // libera el semáforo para que los otros procesos que hicieron wait puedan pasar
```