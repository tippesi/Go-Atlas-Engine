package main

// #cgo LDFLAGS: C:/Users/tippe/OneDrive/Dokumente/GitHub/Go-Atlas-Engine-Test/cmake-build-debug/libGoAtlasEngine.dll.a -lstdc++
// #include <stdlib.h>
// #include "../cwrapper/cWindow.h"
import "C"
import (
	"fmt"
	"unsafe"
)

type GoWindow struct {
	Window C.cWindow
}

func (w GoWindow) SetTitle(title string) {
	var cstr = C.CString(title)
	defer C.free(unsafe.Pointer(cstr))
	C.SetTitle(w.Window, cstr)
}

func main() {}

//export LoadContent
func LoadContent(window C.cWindow) {
	var w GoWindow
	w.Window = window
	w.SetTitle("Blub")
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
