package main
import "fmt"

func swap(x, y int) (int, int){
	return y, x
}

func main(){
	var a, b int
	a, b = swap(4, 5)
	fmt.Printf("a: %d, b: %d\n",  a, b);
}