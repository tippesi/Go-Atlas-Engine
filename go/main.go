package main

import "C"

import (
	"fmt"
)

func main() { fmt.Println("Hello from go. Loading Content") }

//export Add
func Add(a, b int) int { return a + b }

//export GoLoadContent
func GoLoadContent() {
	fmt.Println("Hello from go. Loading Content")
}

//export GoUnloadContent
func GoUnloadContent() {
	fmt.Println("Hello from go. UnloadContent")
}

//export GoRender
func GoRender(deltaTime float32) {
	fmt.Println("Hello from go. Render")
}

//export GoUpdate
func GoUpdate(delteTime float32) {
	fmt.Println("Hello from go. Update")
}
