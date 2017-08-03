import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		BigInteger[] fib = new BigInteger[805];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ZERO;
		for(int i = 2 ; i < 805 ; i++)
		{
			fib[i] = fib[i - 1].multiply(BigInteger.valueOf(i));
			if(i % 2 == 0) fib[i] = fib[i].add(BigInteger.ONE);
			else fib[i] = fib[i].add(BigInteger.valueOf(-1));
		}
		int num;
		while(true)
		{
			num = input.nextInt();
			if(num < 0) break;
			System.out.println(fib[num]);
		}
	}
}