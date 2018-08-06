import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;
public class Main {
	public static void main(String[] args) throws IOException {
		double average = 0;
		int friends = 0;
		Scanner scan = new Scanner(System.in).useLocale(Locale.US);
		while(scan.hasNextLine() && !(scan.nextLine().equals(""))){
			average += scan.nextInt();
			friends++;
			scan.nextLine();
		}
		String average_distance = String.format(Locale.US, "%.1f", (average / friends));
		System.out.printf("%s\n", average_distance);
	}
}
