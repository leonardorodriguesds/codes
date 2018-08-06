import java.io.IOException;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws IOException {
 		Scanner scan = new Scanner(System.in);
 		int x, y, i, z = 0;
 		x = scan.nextInt();
		y = scan.nextInt();
		for(i = 1; i <= y; i++){
			z++;
			if(z < x)
				System.out.printf("%d ", i);
			else{
				System.out.printf("%d%n", i);
				z = 0;
			}
		}
	}
}
