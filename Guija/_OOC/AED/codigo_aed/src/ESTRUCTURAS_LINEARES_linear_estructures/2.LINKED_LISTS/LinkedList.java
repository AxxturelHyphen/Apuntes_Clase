/**
 * Linked list:
 * Nodos con data + punteros.
 * No hay memoria contigua, tamano dinamico.
 * Insertar/eliminar en posiciones conocidas -> O(1).
 * Acceder al elemento  -> O(n).
 */

/// Ejemplo minimo usando java.util.LinkedList
public class LinkedList {
    public static void main(String[] args) {
        java.util.LinkedList<String> listaDeEjemplo = new java.util.LinkedList<>();

        listaDeEjemplo.add("A");      // inserta al final
        listaDeEjemplo.addFirst("B");    // inserta al inicio
        listaDeEjemplo.addLast("C");     // inserta al final

        System.out.println(listaDeEjemplo);  // [B, A, C]

        listaDeEjemplo.remove("A");       // elimina la aparicion de "A"

        System.out.println(listaDeEjemplo);  // [B, C]
     }
}
