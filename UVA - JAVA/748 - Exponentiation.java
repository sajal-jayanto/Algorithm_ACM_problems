import java.util.Scanner;
import java.math.BigDecimal;

public class Main {

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		BigDecimal a;
		int p,i,j;
		String sum;
		while(input.hasNext())
		{
			a = input.nextBigDecimal();
			p = input.nextInt();
			sum = a.pow(p).toPlainString();
			i = 0;
			j = sum.length() - 1;
			while(sum.charAt(i) == '0') i++;
			while(sum.charAt(j) == '0') j--;
			for(p = i ; p <= j ; p++) System.out.printf("%c",sum.charAt(p));
			System.out.println();
		}
	}
}