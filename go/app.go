package main

// #cgo LDFLAGS: ${SRCDIR}/../cmake-build-debug/cwrapper/libGoAtlasEngineLib.dll.a -lstdc++
// #include <stdlib.h>
// #include "../cwrapper/src/cWindow.h"
import "C"
import (
	"strconv"
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

var w GoWindow
var i int

//export LoadContent
func LoadContent(window C.cWindow) {
	w.Window = window
	i = 0
	w.SetTitle("Blub")
}

//export UnloadContent
func UnloadContent() {

}

//export Render
func Render(deltaTime float32) {

}

//export Update
func Update(delteTime float32) {
	i = i + 1
	var s = strconv.Itoa(i)
	w.SetTitle(s)
}
