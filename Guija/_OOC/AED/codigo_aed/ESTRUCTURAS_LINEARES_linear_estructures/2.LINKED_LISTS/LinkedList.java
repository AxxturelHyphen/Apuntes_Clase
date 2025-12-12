/**
 * Linked list:
 * Nodos con data + punteros.
 * No hay memoria contigua, tamaño dinámico.
 * Insertar/eliminar en posiciones conocidas → O(1).
 * Acceder al elemento  → O(n).
 */

import java.util.LinkedList;
/// EJEMPLO DE USO DE LINKED LIST DE JAVA
static void main(){
    LinkedList<String> listaDeEjemplo = new LinkedList<>();

    listaDeEjemplo.add("A");      // inserta al final
    listaDeEjemplo.addFirst("B");    // inserta al inicio
    listaDeEjemplo.addLast("C");     // inserta al final

    System.out.println(listaDeEjemplo);  // [B, A, C]

    listaDeEjemplo.remove("A");       // elimina la aparicion de "A"

    System.out.println(listaDeEjemplo);  // [B, C]
 }

