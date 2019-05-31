package main

import (
    "fmt"
    "time"
)

func sleepMessage(message string) {
	time.Sleep(5 * time.Second)
	fmt.Println(message)
}

func main() {
	sleepMessage("Mensagem printada...")
}