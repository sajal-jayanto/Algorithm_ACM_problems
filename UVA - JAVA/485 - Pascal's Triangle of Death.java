import java.util.Scanner;
import java.math.BigInteger;

public class Main {

	public static void main(String[] args)
	{
		//Scanner input = new Scanner(System.in);
		for (int i = 0; i < 205 ; i++) 
		{
			BigInteger num = BigInteger.ONE;
			for (int j = 0 ; j <= i ; j++) 
			{
				if(j == 0)System.out.print(num);
				else System.out.print(" " + num );
				num = num.multiply(BigInteger.valueOf(i-j)).divide(BigInteger.valueOf(j + 1));
			}
			System.out.println();
		}
	}
}