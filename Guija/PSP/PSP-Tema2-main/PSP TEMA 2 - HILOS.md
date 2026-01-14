## **CREACION DE HILOS (java)*

Existen dos clases para manejar [[Hilo]]s:
#### Thread

Crear una clase que extiende de Thread y sobreescribir su método run()
```java
public class MiHilo extends Thread {
    @Override
    public void run() {
        System.out.println("Hilo corriendo...");
    }
}
// Para lanzarlo:
new MiHilo().start();
```
#### Runnable

Implementar la interfaz Runnable en una clase, que después pasas como argumento a un objeto Thread como tal:
```java
public class MiTarea implements Runnable {
    @Override
    public void run() {
        System.out.println("Tarea en ejecución...");
    }
}
// Para lanzarlo:
Thread hilo = new Thread(new MiTarea());
hilo.start();
```
!! Es mucho más recomendable implementar runnable porque separas la función (lo que hace el codigo) del mecanismo (el funcionamiento del hilo) y no te limitas a solamente poder heredar de la clase Thread.

## **ESTADOS DEL HILO**
Un [[Hilo]] puede estar:
- **Nuevo**: Preparado para su ejecución esperando la llamada de la misma.
- **Listo**: Ha recibido la llamada de ejecución y está arrancado en la cola de procesos, esperando tener recursos. 
- **Runnable**: Puede estar ejecutándose. Engloba tanto al hilo que **está esperando** su turno (Listo) como al hilo que **ya está ocupando** el procesador en este preciso instante (En ejecución).
- **Bloqueado**: El hilo está parado, esperando poder volver a estar runnable y reanudarse.
- **Terminado**: Hilo cuya ejecución ha finalizado.

![[Pasted image 20260108174910.png]]

## **GESTION DE HILOS**
**Creación y arranque**: Al iniciar un proceso, este tendrá un **[[Hilo]] de ejecución principal**. Este podrá **crear hilos hijo** para ejecutar tareas.

**Espera de hilos**: Se usa cuando los **hilos están inactivos** por no tener tarea, ya que al compartir procesador estarían **gastando recursos**
- **Join**: El hilo se pausa hasta que termine otro hilo determinado (al que nos hemos "unido").
- **Sleep**: El hilo se pausa por un tiempo determinado. Se hace con el método `sleep(ms)`.

**Interrupción de hilos**: Indicación de que debería parar sus tareas para hacer otras. Se envían interrupciones a un hilo con su método `interrupt()`.

Con `isAlive()` se comprueba si el hilo finalizó su ejecución.

## **HILO**
Secuencia de código en ejecución dentro del contexto de un proceso. Unidad **básica** de utilización de un core del procesador.

- **Dependen de un proceso**, que es el nodo raíz de un árbol de hilos, el **hilo primario**
- Dentro de un proceso, pueden **coexistir** varios hilos que **comparten la memoria del proceso**.
![[{893C7DA6-4CC4-4AB1-9B7D-27E7E9367BE8}.png]]

## **HILOS COOPERANTES**
[[Hilo]]s ejecutados **simultáneamente** pero que **acceden a los mismos recursos** (ficheros, datos en memoria...). Aquí las políticas de [[Planificación de hilos]] del sistema no son suficientes, el **programador debe tomar el control** para acceder de **manera síncrona**, para que la ejecución sea segura y no cause problemas interfiriendo en el resultado.

## **HILOS DEMONIO**
Se ejecutan siempre en **segundo plano** para **prestar servicios** a otros [[hilo]]s. Cuando **solamente queden hilos demonio** en ejecución colgando del hilo principal (proceso), se **detendrá su ejecución** para no quedarse en un bucle infinito. 

Para crear un hilo demonio:
```java
hilo.setDaemon(true);
Boolean b=hilo.isDaemon(); // ver si es demonio
```

Todos los **hilos creados por un hilo demonio** serán **hilos demonio también**.

## **HILOS INDEPENDIENTES**
Son aquellos [[hilo]]s que **se ejecutan simultáneamente** o concurrentemente pero **no comparten ni modifican recursos comunes**. Cada hilo tiene sus propios datos y tareas, y no interfieren con los otros hilos. La ejecución es **asíncrona**.

## **METODOS DE LA CLASE THREAD**
| Método                                         | Tipo de retorno | Descripción                                                                                                                                                                                                                   |
| ---------------------------------------------- | --------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `currentThread()`                              | `Thread`        | Devuelve una referencia del hilo que actualmente está en ejecución.                                                                                                                                                           |
| `destroy()`                                    | `void`          | Destruye este hilo sin realizar ninguna operación de limpieza. El hilo pasa a estado terminado.                                                                                                                               |
| `getName()`                                    | `String`        | Devuelve el nombre del hilo.                                                                                                                                                                                                  |
| `getPriority()`                                | `int`           | Devuelve la prioridad del hilo.                                                                                                                                                                                               |
| `interrupt()`                                  | `void`          | Envía este hilo al estado de preparado. Obliga al hilo a dejar de hacer lo que está haciendo. Se usa, por ejemplo, para “despertarlo”.                                                                                        |
| `isAlive()`                                    | `boolean`       | Verifica si este hilo está vivo (no ha terminado).                                                                                                                                                                            |
| `isDaemon()`                                   | `boolean`       | Verifica si este hilo es un hilo demonio.                                                                                                                                                                                     |
| `isInterrupted()`                              | `boolean`       | Verifica si este hilo ha sido interrumpido.                                                                                                                                                                                   |
| `join([miliseg][, nanoseg])`                   | `void`          | Bloquea indefinidamente o por el tiempo especificado al hilo. El hilo despierta cuando: a) finaliza el tiempo indicado, b) otro hilo ejecuta `interrupt()`, c) todos sus hilos hijos han finalizado.                          |
| `run()`                                        | `void`          | Contiene el código que se ejecutará cuando el hilo pase al estado de ejecución. Tarea del hilo.                                                                                                                               |
| `setDaemon(boolean)`                           | `void`          | Define este hilo como demonio (`true`) o como hilo de usuario (`false`).                                                                                                                                                      |
| `setName(String)`                              | `void`          | Cambia el nombre del hilo. Por defecto: `Thread1`, `Thread2`, etc.                                                                                                                                                            |
| `setPriority(int)`                             | `void`          | Cambia la prioridad del hilo. Por defecto hereda la del hilo padre. Valores entre `1` y `10` (`MIN_PRIORITY` y `MAX_PRIORITY`).                                                                                               |
| `sleep(long miliseg[, int nanoseg])`           | `void`          | Envía este hilo a dormir por el tiempo especificado. El hilo despierta cuando transcurre el tiempo o cuando se ejecuta `interrupt()`.                                                                                         |
| `start()`                                      | `void`          | Inicia la ejecución del hilo. Lo pone en estado listo y la JVM invoca el método `run()`.                                                                                                                                      |
| `yield()`                                      | `void`          | Detiene temporalmente la ejecución del hilo para permitir la ejecución de otros. Envía el hilo a la cola de preparados.                                                                                                       |
| `notify()`                                     | `void`          | Despierta un hilo que está esperando por el monitor de este objeto (`wait()`). Se invoca desde una sección crítica y cede el control del monitor.                                                                             |
| `notifyAll()`                                  | `void`          | Despierta todos los hilos que están esperando por el monitor de este objeto (`wait()`). Se invoca desde una sección crítica.                                                                                                  |
| `wait()` / `wait(long miliseg[, int nanoseg])` | `void`          | Envía el hilo al estado de espera por el monitor del objeto hasta que otro hilo invoque `notify()`/`notifyAll()` o transcurra el tiempo indicado. Cede el control del monitor. Debe ejecutarse dentro de código sincronizado. |

## **MULTITAREA**
Ejecución de **varios [[Hilo]]s a la vez**.

- El programa podrá **responder** mientras sus hilos hacen otras tareas.
- Crear nuevos hilos no supone reservar más memoria (ya está reservada al proceso).
- Ejecutar varios hilos permite aprovechar los cores del procesador (**paralelismo**).

## **PLANIFICACION DE HILOS** 
Consiste en la ejecución de múltiples [[Hilo]]s en cierto orden.

Todas las rutinas del planificador de hilos que decide ese orden es llamado **algoritmo de planificación**.

---

Existen varios tipos de planificación:
#### Determinista

Funciona por **prioridades** ([[Prioridades de los hilos]]). Cada hilo tiene una prioridad asignada, normalmente del 1 al 10, y el que tenga **más prioridad será el siguiente en ser ejecutado**. Solamente **cuando deje de ejecutarse, será posible ejecutar otro que tenga menos prioridad**. Si está en **estado preparado otro hilo de mayor prioridad, se parará el hilo ejecutado** (de menor prioridad) para ejecutar el de más prioridad. Esto no funciona con hilos de **menor prioridad**.

#### No determinista

Sucede cuando **los hilos tienen la misma prioridad**. Entonces serán tratados como una **cola FIFO**, usando tiempos compartidos. Cada hilo tiene un tiempo asignado (**cuanto de ejecución**) y después cambia a otro, **turnándose entre todos para usar la CPU**. 


## **PRIORIDADES DE LOS HILOS**
Cuando se crea un [[hilo]], **nace con la misma prioridad que su padre**. 

Para modificar esta prioridad se usa el método `setPriority()`.

Por defecto, el `NORM_PRIORITY` de cualquier hilo será 5. Como es la prioridad por defecto del hilo padre, los hilos hijos también la tendrán por defecto.

Para obtener la prioridad, se usa `getPriority()`, que devuelve un ``int``. 

## **PROGRAMACION MULTIHILO**
Permite que **varios [[hilo]]s se ejecuten al mismo tiempo**, tantos como núcleos tenga el procesador.

Es necesario:
- **Descomposición funcional**: Identificando las tareas que debe realizar la aplicación, que recursos usan y que relación existe entre ellas
- **Partición**: Asignar las funciones entre los hilos, teniendo en cuenta los **problemas de sincronización**.
- **Implementación**: Usando la clase `Thread` o la interfaz `Runnable`, junto a los mecanismos de sincronización.
## **RECURSOS COMPARTIDOS POR HILOS**
Mientras los procesos tienen su propio espacio de direcciones y recursos, los [[Hilo]]s se limitan a **depender** de estos mismos **recursos del proceso**, tales como datos o código. Cada hilo puede tener también sus propios registros.

![[{FFC7CC38-D9E1-429D-AE4C-C5AD64392728}.png]]

## **SINCRONIZACION DE HILOS**
Los [[Hilo]]s se comunican a través de la memoria, ya que al pertenecer a un proceso, pueden compartir información eficientemente a través de ella. 

El problema surge cuando varios hilos manipulan a la vez objetos compartidos. Algunos de esos problemas se llaman:
- **Condiciones de carrera**: El resultado de la ejecución depende del orden en el que se realizan los accesos.
- **Inconsistencia de memoria**: Los hilos tienen una versión diferente de lo que debería ser el mismo dato.
- **Inanición**: Un proceso no toma el control de un recurso debido a que otros siempre lo toman antes que él.
- **Interbloqueo**: Hilos se quedan esperando indefinidamente por un evento que solo puede generar un proceso o hilo bloqueado.
- **Bloqueo activo**: Similar al interbloqueo pero cambiando de estado, como quedándose en bucle.

---
Cuando los hilos vayan a acceder a datos compartidos, deben hacerlo de manera **síncrona** (ordenada). Cuando las operaciones no afecten a ningún dato compartido, se podrán ejecutar **asíncronamente** (en paralelo). Para esto el código debe cumplir las [[Condiciones de Bernstein]].