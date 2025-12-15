import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Uso rapido de ArrayDeque como pila LIFO en Java.
 * push/peek/pop operan sobre la misma interfaz Deque sin sincronizacion extra.
 * @author AxxturelHyphen
 */

Deque<String> stack = new ArrayDeque<>();

stack.push("uno");
stack.push("dos");

System.out.println(stack.peek());   // "dos"
System.out.println(stack.pop());    // "dos"
System.out.println(stack.pop());    // "uno"
System.out.println(stack.isEmpty()); // true
