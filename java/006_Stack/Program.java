import java.util.*;

public class Program
{
	public static void main(String[] args)
	{
		Stack<Integer> stk = new Stack<Integer>();
		//Deque<Integer> deq = new ArrayDeque<Integer>();

		stk.push(4);
		stk.push(3);
		stk.push(2);
		stk.push(1);

		System.out.println(stk.peek());
		System.out.println(stk);

		
		System.out.println(stk.pop());
		System.out.println(stk);
		
		System.out.println(stk.search(4));
		System.out.println(stk.search(3));
	}
}

