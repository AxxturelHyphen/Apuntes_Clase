Dos segmentos de código son independientes (``i`` y ``j``) (se pueden ejecutar de forma asíncrona) si:
- No tienen **dependencia de flujo**: se da cuando acceden a la misma variable a la vez, por ejemplo si `i` escriba una variable y `j` la lea.
- No tienen **antidependencia**: que es al revés, es decir, `i` lee una variable que `j` va a escribir.
- No tienen **dependencia de salida**: ocurre cuando `i` y `j` van a escribir en la misma variable.

Hacer un programa que no cumpla estas condiciones haría que, al **compartir espacios de memoria**, el resultado de las operaciones cambie por modificar el orden de ejecución.