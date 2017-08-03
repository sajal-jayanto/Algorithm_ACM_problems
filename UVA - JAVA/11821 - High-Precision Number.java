import java.util.Scanner;
import java.math.BigDecimal;

public class Main
{
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		int t = input.nextInt();
		BigDecimal num, sum;
		String s;		
		while(t != 0)
		{
			t--;
			sum = BigDecimal.ZERO;
			while(input.hasNext())
			{
				num = input.nextBigDecimal();
				if(num.equals(BigDecimal.ZERO)) break; 
				sum = sum.add(num);
			}
			s = sum.toPlainString();
			int len = s.length() - 1;
			while(s.charAt(len) == '0') len--;
			if(s.charAt(len) == '.') len--;
			for(int i = 0 ; i <= len ; i++)
			{
				System.out.printf("%c",s.charAt(i));
			}
			System.out.println();
		}
	}
}