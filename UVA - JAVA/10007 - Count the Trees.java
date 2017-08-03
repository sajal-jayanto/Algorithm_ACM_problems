import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		BigInteger DP[] = new BigInteger[610];
		DP[0] = BigInteger.ONE;
		for(int i = 1 ; i < 610 ;i++) DP[i] = DP[i - 1].multiply(BigInteger.valueOf(i));
		while(input.hasNext())
		{
			int num = input.nextInt();
			if(num == 0) break;
			System.out.println(DP[2 * num].divide(DP[num + 1]));
		}
	}
}
