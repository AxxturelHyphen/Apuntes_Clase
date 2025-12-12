import java.util.ArrayDeque;
import java.util.Deque;

Deque<String> stack = new ArrayDeque<>();

stack.push("uno");
stack.push("dos");

System.out.println(stack.peek());  // "dos"
System.out.println(stack.pop());   // "dos"
System.out.println(stack.pop());   // "uno"
System.out.println(stack.isEmpty()); // true