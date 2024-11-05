import java.io.*;
import java.util.*;
import java.util.Scanner;

class PriorityQueue {

   private static int valuesize = 0 ;
   static class Priority{
        int size;
        int[] value;

        public Priority(int size){
            this.size = size ;
            this.value = new int[size];
        }
    }
    static void remove(int index,Priority prioritystack) {
        int i;
        for ( i = 0; i < prioritystack.size; i++)
        {
            if (prioritystack.value[i] == prioritystack.value[index]) {
                break;
            }
        }
        if (i<prioritystack.size)
        {
            prioritystack.size = prioritystack.size - 1;
            for (int x = i; x < prioritystack.size; x++)
            {
                prioritystack.value[x] = prioritystack.value[x + 1];

            }
        }
    }
    static void add(Stack<Integer> stack, int priority,Priority prioritystack)
    {
            int i = (int) (Math.random()*(20)+1);

            stack.add(i);
            System.out.println("element added to queue: "+i);
            prioritystack.value[valuesize] = priority;
            System.out.println("priority of added element: "+priority + "\n");
            valuesize++;

    }
    static int get(Stack<Integer> stack,Priority prioritystack) {
        int x = stack.size()-1;

        Integer element = (Integer) stack.peek();
        System.out.println("Element on stack top : " + element);


        outerLoop:
        for (; x >= 0; x-- ) {

            if (prioritystack.value[x] == 3) {
                Integer y = (Integer) stack.remove(x);
                remove(x,prioritystack);
                System.out.println("Element poped from the stack : " + y);
                break;
            }
            if (prioritystack.value[x] != 3 && x == 0 ) {
                outerLoop2:
                for (x = stack.size() - 1; x >= 0; x--) {
                    if (prioritystack.value[x] == 2) {
                        Integer y = (Integer) stack.remove(x);
                        remove(x, prioritystack);
                        System.out.println("Element poped from the stack : " + y);
                        break outerLoop;
                    }
                    if (x == 0) break outerLoop2;
                }
            }
            if (prioritystack.value[x] != 3 && x == 0 && prioritystack.value[x] != 2) {

                for (x = stack.size() - 1; x >= 0; x--) {
                    if (prioritystack.value[x]==1){
                        Integer y = (Integer) stack.remove(x);
                        remove(x,prioritystack);
                        System.out.println("Element poped from the stack : " + y);
                        return y;
                        }
                }
            }

        }
        return stack.get(x);
    }
    public static void main(String[] args)
    {

        Stack<Integer> stack = new Stack<Integer>();

        Priority prioritystack = new Priority(5);

        add(stack,1,prioritystack);
        add(stack,2,prioritystack);
        add(stack,3,prioritystack);
        add(stack,3,prioritystack);
        add(stack,1,prioritystack);
        get(stack,prioritystack);
        get(stack,prioritystack);
        get(stack,prioritystack);
        get(stack,prioritystack);
        get(stack,prioritystack);

    }
}

