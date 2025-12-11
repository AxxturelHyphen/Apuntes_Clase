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
    LinkedList<String> listaEnlazada = new LinkedList<>();

    listaEnlazada.add("A");      // inserta al final
    listaEnlazada.addFirst("B");    // inserta al inicio
    listaEnlazada.addLast("C");     // inserta al final

    System.out.println(listaEnlazada);  // [B, A, C]

    listaEnlazada.remove("A");       // elimina la aparicion de "A"

    System.out.println(listaEnlazada);  // [B, C]
 }

