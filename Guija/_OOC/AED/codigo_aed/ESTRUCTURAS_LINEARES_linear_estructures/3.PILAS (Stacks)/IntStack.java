class IntStack {
    private int[] stackArr;
    private int topIndex;

    public IntStack(int capacity) {
        stackArr = new int[capacity];
        topIndex = -1;  // pila vacía
    }

    public void push(int value) throws Exception {
        if (topIndex == stackArr.length - 1) {
            throw new Exception("Stack overflow");
        }
        stackArr[++topIndex] = value;
    }

    public int pop() throws Exception {
        if (topIndex < 0) {
            throw new Exception("Stack underflow");
        }
        int val = stackArr[topIndex--];
        return val;
    }

    public int peek() throws Exception {
        if (topIndex < 0) {
            throw new Exception("Stack underflow");
        }
        return stackArr[topIndex];
    }

    public boolean isEmpty() {
        return topIndex == -1;
    }

    static void main() throws Exception {
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