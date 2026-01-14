Ocurre **completa y sin interrupciones**, sin que ningún otro **hilo pueda leer o modificar datos** relacionados a ella.

Por ejemplo:

```python
x = x + 1;
```
Aunque parece una sola línea, en realidad implica:
- Leer x
- Sumar 1
- Escribir x

Si dos hilos ejecutan esto al mismo tiempo, pueden perderse incrementos.