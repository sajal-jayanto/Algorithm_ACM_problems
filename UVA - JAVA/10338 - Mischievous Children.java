import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main(String [] args)
	{
		Scanner input = new Scanner(System.in);
		BigInteger ar[] = new BigInteger[25];
		ar[0] = BigInteger.ONE;
		for(int i = 1 ; i < 25 ; i++) ar[i] = ar[i - 1].multiply(BigInteger.valueOf(i));
		int t,cnt = 0;
		String s;
		int abc[] = new int[26];
		t = input.nextInt();
		s = input.nextLine();
		while(t-->0)
		{
			s = input.next();
			int len = s.length();
			for(int i = 0 ; i < len ; i++) abc[s.charAt(i) - 'A']++;
			BigInteger ans = BigInteger.ONE;
			for(int i = 0 ; i < 26 ; i++)
			{
				if(abc[i] >= 2) ans = ans.multiply(ar[abc[i]]);
					abc[i] = 0;
			}
			System.out.println("Data set " +  ++cnt  + ": " + ar[len].divide(ans));
		}
	}
}