package main

// #cgo LDFLAGS: ${SRCDIR}/../cmake-build-debug/cwrapper/libGoAtlasEngineLib.dll.a -lstdc++
// #include <stdlib.h>
// #include "../cwrapper/src/cWindow.h"
import "C"
import (
	"math"
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

func (w GoWindow) Clear(x, y, z float32) {
	C.Clear(w.Window, C.float(x), C.float(y), C.float(z))
}

func main() {}

var w GoWindow
var i int
var tm float64

//export LoadContent
func LoadContent(window C.cWindow) { // We're not allowed to use Go structs in exports
	w.Window = window
	i = 0
	tm = 0
}

//export UnloadContent
func UnloadContent() {

}

//export Render
func Render(deltaTime float32) {
	w.Clear(float32(math.Abs(math.Sin(tm))), 1.0, 1.0)
}

//export Update
func Update(deltaTime float32) {
	i = i + 1
	var s = strconv.Itoa(i)
	w.SetTitle(s)
	tm += float64(deltaTime)
}
