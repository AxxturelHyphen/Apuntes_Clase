/**
 * Recorridos iterativos (sin recursion) usando stack/queue:
 * - preorder, inorder, postorder (2 stacks), level-order.
 * @author AxxturelHyphen
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class TreeTraversalsIterative {
    static class TreeNode {
        int value;
        TreeNode left, right;
        TreeNode(int v) { value = v; }
    }

    // preorder iterativo: usar stack; push right primero para visitar left antes
    static List<Integer> preorder(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        if (root == null) return out;
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            out.add(node.value);
            if (node.right != null) stack.push(node.right);
            if (node.left != null) stack.push(node.left);
        }
        return out;
    }

    // inorder iterativo: bajar por la izquierda, procesar, ir derecha
    static List<Integer> inorder(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            TreeNode node = stack.pop();
            out.add(node.value);
            cur = node.right;
        }
        return out;
    }

    // postorder iterativo con 2 stacks (simple de seguir)
    static List<Integer> postorderTwoStacks(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        if (root == null) return out;
        Deque<TreeNode> s1 = new ArrayDeque<>();
        Deque<TreeNode> s2 = new ArrayDeque<>();
        s1.push(root);
        while (!s1.isEmpty()) {
            TreeNode node = s1.pop();
            s2.push(node);
            if (node.left != null) s1.push(node.left);
            if (node.right != null) s1.push(node.right);
        }
        while (!s2.isEmpty()) {
            out.add(s2.pop().value);
        }
        return out;
    }

    // level-order BFS iterativo con queue
    static List<Integer> levelOrder(TreeNode root) {
        List<Integer> out = new ArrayList<>();
        if (root == null) return out;
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove();
            out.add(node.value);
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return out;
    }

    // Construye el arbol de ejemplo del apunte
    static TreeNode buildSample() {
        TreeNode n8 = new TreeNode(8);
        TreeNode n3 = new TreeNode(3);
        TreeNode n10 = new TreeNode(10);
        TreeNode n1 = new TreeNode(1);
        TreeNode n6 = new TreeNode(6);
        TreeNode n14 = new TreeNode(14);
        TreeNode n4 = new TreeNode(4);
        TreeNode n7 = new TreeNode(7);
        TreeNode n13 = new TreeNode(13);

        n8.left = n3;
        n8.right = n10;
        n3.left = n1;
        n3.right = n6;
        n10.right = n14;
        n6.left = n4;
        n6.right = n7;
        n14.left = n13;
        return n8;
    }

    public static void main(String[] args) {
        TreeNode root = buildSample();
        System.out.println("preorder: " + preorder(root));
        System.out.println("inorder: " + inorder(root));
        System.out.println("postorder: " + postorderTwoStacks(root));
        System.out.println("level-order: " + levelOrder(root));
    }
}
