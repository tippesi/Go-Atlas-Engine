package gui

// #cgo LDFLAGS: ./cmake-build-debug/libGoAtlasEngine.a
// #include <stdlib.h>
// #include "../../cwrapper/cWindow.h"
import "C"
import "unsafe"

type Window struct {
	window C.cWindow
}

func (window Window) SetTitle(title string) {
	cstr := C.CString(title)
	defer C.free(unsafe.Pointer(cstr))
	C.SetTitle(unsafe.Pointer(window.window), cstr)
}
