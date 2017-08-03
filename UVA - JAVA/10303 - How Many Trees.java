import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	
	public static BigInteger DP[] = new BigInteger[1010];
	
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		
		for(int i = 0 ; i < 1010 ;i++) DP[i] = BigInteger.valueOf(-1);
		Catalan_num(1008);
		while(input.hasNext())
		{
			int num = input.nextInt();
			System.out.println(DP[num]);
		}
	}
	public static BigInteger Catalan_num(int n)
	{
		if(n == 0) return BigInteger.valueOf(1);
		if(DP[n] != BigInteger.valueOf(-1) ) return DP[n];
		BigInteger ans = BigInteger.ZERO;
		for(int i = 1 ; i <= n ; i++) ans = ans.add(Catalan_num(i - 1).multiply(Catalan_num(n - i)));
		DP[n] = ans;
		return DP[n];
	}
}
