import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;
public class Main { 
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner(System.in);
		float num = Float.parseFloat(scan.nextLine()), percentual = 15;
		if(num >= 400.01 && num <= 800.00)
			percentual = 12;
		else if(num >= 800.01 && num <= 1200.0)
			percentual = 10;
		else if(num >= 1200.01 && num <= 2000.0)
			percentual = 7;
		else if(num > 2000.00)
			percentual = 4;
		String novosalario = String.format(Locale.US, "%.2f", num + num * (percentual / 100));
		String aumento = String.format(Locale.US, "%.2f", num * (percentual / 100));
		System.out.printf("Novo salario: %s%nReajuste ganho: %s%nEm percentual: %.0f %%%n", novosalario, aumento, percentual);
		scan.close();
	}
}
