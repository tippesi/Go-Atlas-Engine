#ifndef CWINDOW_H
#define CWINDOW_H

#ifdef __cplusplus
extern "C" {
#endif
typedef void* cWindow;
void SetTitle(cWindow cwindow, const char* title);
#ifdef __cplusplus
}
#endif

#endif