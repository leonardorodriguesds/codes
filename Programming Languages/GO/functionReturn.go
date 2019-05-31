package main

import (
	"fmt" 
)

type error interface {
	Error() string
}
type RandomException struct {
	msg string
}
func (error *RandomException) Error() string {
	return error.msg
}
func randomFuncThrowError() (int, error) {
	var x int = 10
	return x, &RandomException{"custom error"}
}
func randomFunc() (int, error) {
	var x int = 10
	return x, nil
}
func catch(err error) {
	switch err.(type) {
	case error:
		fmt.Println("A RandomException captured...")
		fmt.Println(err.Error())
	default:
		fmt.Println("Everything is alright...")
	}
}
func main() {
	var _, catchError1 = randomFuncThrowError()
	var _, catchError2 = randomFunc()
	catch(catchError1)
	catch(catchError2)
}