import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		int b;
		BigInteger num,mod,r,ans,sum,count;
		BigInteger[] n = new BigInteger[10];
		while(input.hasNext())
		{
			b = input.nextInt();
			if(b == 0) break;
			num = input.nextBigInteger();
			mod = input.nextBigInteger();
			
			if(b == 10)
			{
				System.out.println(num.mod(mod));
				continue;
			}
			sum = BigInteger.ZERO;
			count = BigInteger.ONE;
			while(num != BigInteger.ZERO)
			{
				r = num.mod(BigInteger.TEN);
				sum = sum.add(r.multiply(count));
				count = count.multiply(BigInteger.valueOf(b));
				num = num.divide(BigInteger.TEN);
			}
			num = sum;
			sum = BigInteger.ZERO;
			count = BigInteger.ONE;
			while(mod != BigInteger.ZERO)
			{
				r = mod.mod(BigInteger.TEN);
				sum = sum.add(r.multiply(count));
				count = count.multiply(BigInteger.valueOf(b));
				mod = mod.divide(BigInteger.TEN);
			}
			mod = sum;
			ans = num.mod(mod);
			if(ans.compareTo(BigInteger.ZERO) == 0)
			{
				System.out.println(ans);
				continue;
			}
			int k = 0;
			while(ans != BigInteger.ZERO)
			{
				n[k++] = ans.mod(BigInteger.valueOf(b));
				ans = ans.divide(BigInteger.valueOf(b));
			}
			for(int i = k - 1 ; i >= 0; i--) System.out.printf("%d",n[i]);
			System.out.println();
		}
	}
}