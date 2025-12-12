import java.util.ArrayList;

class Arrays_ArrayLists {
    /**
     * Mini demo: array fijo vs ArrayList dinamica.
     * array => size fijo, acceso O(1) via index, sin resize.
     * ArrayList => dynamic resize interno, add/remove desplaza elementos.
     */
    public static void main(String[] args) {
        // Array basico en Java (fixed-size, valores int)
        int[] numeros = new int[5]; // array de 5 enteros (inicializados a 0)
        numeros[0] = 42;
        numeros[1] = 13;

        System.out.println(numeros[0]); // acceso directo por index: imprime 42

        int idx = 1;
        System.out.println(numeros[idx]); // imprime 13 (acceso con variable indice)

        // Lista dinamica con ArrayList (crece/shrink con resize interno)
        ArrayList<String> listaNombres = new ArrayList<>();
        listaNombres.add("Ana");
        listaNombres.add("Juan");
        listaNombres.add("Luis");

        System.out.println(listaNombres.get(1)); // imprime "Juan" via get(index)

        listaNombres.remove(0); // remove reacomoda, ahora quedan [Juan, Luis]

        System.out.println(listaNombres); // imprime [Juan, Luis]
    }
}
