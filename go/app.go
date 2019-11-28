package main

import "C"

import (
	"fmt"

	gowrapper "../gowrapper"
)

func main() {}

//export LoadContent
func LoadContent(window gowrapper.Window) {
	window.SetTitle("Blub")
	fmt.Println("Hello from go. Loading Content")
}

//export UnloadContent
func UnloadContent() {
	fmt.Println("Hello from go. UnloadContent")
}

//export Render
func Render(deltaTime float32) {
	fmt.Println("Hello from go. Render")
}

//export Update
func Update(delteTime float32) {
	fmt.Println("Hello from go. Update")
}
