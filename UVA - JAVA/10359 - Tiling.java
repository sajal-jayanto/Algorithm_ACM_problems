import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int MAX = 260;
		BigInteger two = BigInteger.valueOf(2);
		BigInteger[] num = new BigInteger[MAX];
		num[0] = BigInteger.ONE;
		num[1] = BigInteger.ONE;
		for(int i = 2 ; i < MAX ; i++) num[i] = num[i - 1].add(two.multiply(num[i - 2]));
		while(input.hasNext())
		{
			int n = input.nextInt();
			System.out.println(num[n]);
		}
	}
}