import java.io.IOException;
import java.util.Scanner;
public class Main { 
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner(System.in);
		int n, t, i, num;
		n = scan.nextInt();
		t = scan.nextInt();
		scan.nextLine();
		String[] players = new String[n];
		String[][] times = new String[t][];
		String[] player;
		for (i = 0; i < n; i++) {
			players[i] = scan.nextLine();
		}
		for (i = 0; i < n; i++) {
			player = players[i].split(" ");
			num = Integer.parseInt(player[1]);
			System.out.printf("Nome: %s%nNum: %d%n", player[0], num);
		}
		scan.close();
	}
}
