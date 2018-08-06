import java.io.IOException;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws IOException {
 		int count_leds[] = new int[] {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
 		int n, num, count;
 		Scanner scan = new Scanner(System.in);
 		n = scan.nextInt();
 		while(n > 0){
 			count = 0;
	 		num = scan.nextInt();
	 		while(num > 0){
	 			count += count_leds[num % 10];
	 			num /= 10;
	 		}
	 		System.out.printf("%d leds%n", count);
	 		n--;
	 	}
	}
}
