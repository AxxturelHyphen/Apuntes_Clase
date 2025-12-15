/**
 * Pila (stack) basada en array con tope creciente.
 * Demuestra las operaciones basicas LIFO: push, pop, peek e isEmpty.
 * No se expande dinamicamente: al llegar a la capacidad lanza overflow.
 * @author AxxturelHyphen
 */
class IntStack {
    private int[] stackArr;
    private int topIndex;

    /**
     * Crea una pila con capacidad fija.
     * @param capacity cuantos elementos puede almacenar la pila
     */
    public IntStack(int capacity) {
        stackArr = new int[capacity];
        topIndex = -1;  // pila vacia (sin elementos cargados)
    }

    /**
     * Inserta un valor en el tope de la pila.
     * @param value valor a apilar
     * @throws Exception si la pila esta llena (overflow)
     */
    public void push(int value) throws Exception {
        if (topIndex == stackArr.length - 1) {
            throw new Exception("Stack overflow");
        }
        stackArr[++topIndex] = value;
    }

    /**
     * Saca y devuelve el valor del tope.
     * @return ultimo valor insertado
     * @throws Exception si la pila esta vacia (underflow)
     */
    public int pop() throws Exception {
        if (topIndex < 0) {
            throw new Exception("Stack underflow");
        }
        int val = stackArr[topIndex--];
        return val;
    }

    /**
     * Mira el valor del tope sin retirarlo.
     * @return valor actualmente en el tope
     * @throws Exception si la pila esta vacia
     */
    public int peek() throws Exception {
        if (topIndex < 0) {
            throw new Exception("Stack underflow");
        }
        return stackArr[topIndex];
    }

    /**
     * Indica si la pila no tiene elementos.
     */
    public boolean isEmpty() {
        return topIndex == -1;
    }

    public static void main(String[] args) throws Exception {
        IntStack stack = new IntStack(5);

        stack.push(10);
        stack.push(20);

        System.out.println(stack.peek());  // 20

        int x = stack.pop();
        System.out.println(x);            // 20

        System.out.println(stack.pop());  // 10
        System.out.println(stack.isEmpty()); // true
    }
}
