import java.util.Scanner;
import java.math.BigInteger;

public class Main{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		BigInteger sum;
		String n;
		int d;
		while(input.hasNext())
		{
			n = input.next();
			sum = new BigInteger(n);
			sum = sum.multiply(sum);
			if(sum.toString().endsWith(n))
			{
				d = n.toString().length();
				System.out.printf("Automorphic number of %d-digit.\n",d);
			}
			else 
			{
				System.out.printf("Not an Automorphic number.\n");
			}
		}
	}
}