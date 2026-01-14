Se encargan de **manejar la exclusión mutua** (que un código sea ejecutado por solo un hilo a la vez) de forma **automática**, sin depender del programador, a través de un conjunto de métodos atómicos de los propios lenguajes de programación.

En java se usa `syncronized` para indicar una sección crítica en el código.

Existen dos formas de hacerlo:

### Métodos sincronizados

```java
class RecursoCompartido {
    private int valor;

    public synchronized void incrementar() {
        valor++;
    }

    public synchronized int leer() {
        return valor;
    }
}
```

**Solo un hilo puede ejecutar** cualquiera de los métodos sincronizados de esta clase **a la vez**.

### Sentencias sincronizadas

```java
public void incrementar() {
    synchronized(this) { 
        valor++;
    }
}
```

El monitor protege solamente **una parte del código**, que es la sección crítica, para garantizar mejor eficiencia.


---
### Sincronización reentrante

```java
class Recurso {
    public synchronized void a() {
        b();  // llama a otro método sincronizado del mismo objeto
    }

    public synchronized void b() {
        // hace algo
    }
}
```

El hilo que ejecuta el ``b()`` dentro de ``a()``, al terminar de ejecutar ``b()``, no tiene que esperar por que se libere `a()` puesto que ya lo estaba ejecutando él mismo.