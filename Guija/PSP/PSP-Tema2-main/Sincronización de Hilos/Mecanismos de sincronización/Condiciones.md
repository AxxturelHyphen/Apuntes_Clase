Existe un hilo que va a ejecutar una **sección crítica**, pero antes de entrar tiene que cumplir una **condición**, que es **cambiada por otro hilo al finalizar su sección crítica**.

Funciona con dos operaciones:
- ``wait()``: El hilo se pausa y libera el cerrojo, **quedando esperando a que se cambie la condición**.
- `notify()`: Avisa de que cambia la condición y **despierta a los hilos pausados**.

![[Pasted image 20260111183101.png]]