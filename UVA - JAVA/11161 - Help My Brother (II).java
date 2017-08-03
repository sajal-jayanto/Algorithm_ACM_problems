import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		BigInteger num;
		
		while(input.hasNext())
		{
			num = input.nextBigInteger();
			num = num.sqrt(num);
			System.out.println(num);
		}
	}
}