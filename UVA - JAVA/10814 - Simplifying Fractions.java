import java.util.Scanner;
import java.math.BigInteger;

public class Main 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		BigInteger a,b,c;
		String s ;
		int t = input.nextInt();
		while(t != 0)
		{
			t--;
			a = input.nextBigInteger();
			s = input.next();
			b = input.nextBigInteger();
			
			c = a.gcd(b);
			
			if(c.compareTo(BigInteger.ONE) == 0)
			{
				System.out.println(a + " / " + b);
			}
			else 
			{
				a = a.divide(c);
				b = b.divide(c);
				System.out.println(a + " / " + b);
			}
		}
	}
}