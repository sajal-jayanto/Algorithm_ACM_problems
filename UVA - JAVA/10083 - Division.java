import java.util.Scanner;
import java.math.BigInteger;

public class Main{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		BigInteger n,p1,p2;
		int num,n1,n2;
		while(input.hasNextInt())
		{
			num = input.nextInt();
			n1 = input.nextInt();
			n2 = input.nextInt();
			
			System.out.printf("(%d^%d-1)/(%d^%d-1) ",num,n1,num,n2);
			if(num == 1) System.out.println("is not an integer with less than 100 digits.");
			else if(n1 % n2 != 0) System.out.println("is not an integer with less than 100 digits.");
			else if(n1 == n2) System.out.println("1");
			else if((n1 - n2) * Math.log10(num) > 99.00) System.out.println("is not an integer with less than 100 digits.");
			else
			{
				n  = BigInteger.valueOf(num); 
				p1 = n.pow(n1);
				p1 = p1.subtract(BigInteger.ONE);
				p2 = n.pow(n2);
				p2 = p2.subtract(BigInteger.ONE);
				n = p1.divide(p2);
				if(n.toString().length() >= 100) System.out.println("is not an integer with less than 100 digits.");
				else System.out.println(n);
			}
		}
	}
}