#ifndef CWINDOW_H
#define CWINDOW_H

#ifdef __cplusplus
extern "C" {
#endif
typedef void* cWindow;
void SetTitle(cWindow cwindow, const char* title);
void Clear(cWindow cwindow, float x, float y, float z);
#ifdef __cplusplus
}
#endif

#endif