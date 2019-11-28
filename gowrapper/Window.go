package gowrapper

// #cgo LDFLAGS: ./../cmake-build-debug/libGoAtlasEngine.dll.a -lstdc++
// #include <stdlib.h>
// #include "../cwrapper/cWindow.h"
import "C"
import "unsafe"

type GoWindow struct {
	Window C.cWindow
}

func main() {}

func (w GoWindow) SetTitle(title string) {
	var cstr = C.CString(title)
	defer C.free(unsafe.Pointer(cstr))
	C.SetTitle(w.Window, cstr)
}
