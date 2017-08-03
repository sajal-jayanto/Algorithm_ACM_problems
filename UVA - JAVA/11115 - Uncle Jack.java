import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		while(input.hasNext())
		{
			int a = input.nextInt();
			int b = input.nextInt();
			if(a == 0 && b == 0) break;
			BigInteger one = BigInteger.valueOf(a);
			System.out.println(one.pow(b));
		}
	}
}

