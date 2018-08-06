import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static class element{
	private int number;
	private element next;

	public element(int num){
	    this.number = num;
	}
    }
    public static class address_list{
	private element first;
	private element last;
	private int countelements = 0;
	
	public void add(int num){
	    element _new_ = new element(num);
	    if(this.countelements > 0)
		this.last.next = _new_;
	    else
		this.first = _new_;
	    this.last = _new_;
	    this.countelements++;
	}

	public void listelements(){
	    element pointer = this.first;
	    int index = 0;
	    while(index < this.countelements){
		System.out.printf("%d -> ", pointer.number);
		pointer = pointer.next;
		index++;
	    }
	    System.out.printf("\\");
	}
    }
    public static void main(String[] args) throws IOException{
	int cases, m, c, i, j, num, index;
	Scanner scan = new Scanner(System.in);
	cases = scan.nextInt();
	for(i = 0; i < cases; i++){
	    m = scan.nextInt();
	    c = scan.nextInt();
	    address_list[] hashtable = new address_list[m];
	    for(j = 0; j < m; j++)
	    	hashtable[j] = new address_list();
	    for(j = 0; j < c; j++){
		num = scan.nextInt();
		index = num % m;
		hashtable[index].add(num);
	    }
	    for(j = 0; j < m; j++){
		System.out.printf("%d -> ", j);
		hashtable[j].listelements();
		System.out.print("\n");
	    }
	}
    }
}
