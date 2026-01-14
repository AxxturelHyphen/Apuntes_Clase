 Es un mecanismo de sincronización que **controla el acceso a recursos** de memoria compartidos.

Se compone de:
- Una **variable entera** (`S.valor`) que representa el **número de instancias libres del recurso**. Si tengo 3 impresoras, la variable será 3 y cada vez que use una disminuirá, así como si dejo una libre aumentará.
- Una **cola de procesos** `S.cola`, que están bloqueados esperando poder usar el recurso. Si no hay recursos libres, se pondrán a la espera los procesos y cuando se liberen los recursos se irán despertando por orden para usarlos.

Se accede al semáforo con **dos operaciones atómicas**:
- **wait()** -> **Añade el proceso a la cola** y lo bloquea para esperar a que haya recursos.

```java
wait(S) {
    S.valor--;                // Reducir recursos disponibles
    if (S.valor < 0) {        // Si no hay recursos
        añadir_proceso_a(S.cola); // Se bloquea el proceso
        bloquear_proceso();
    }
}
```

- **signal()** -> **Libera un recurso** y hace que el siguiente proceso de la cola despierte para usarlo.

```java
signal(S) {
    S.valor++;                // Incrementar recursos disponibles
    if (S.valor <= 0) {       // Si hay procesos esperando
        P = sacar_de(S.cola);   // Sacar un proceso de la cola
        despertar_proceso(P);    // Permitirle ejecutar
    }
}
```