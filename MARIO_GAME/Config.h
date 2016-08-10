#pragma once
#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <sstream>

#define SAFE_RELEASE(obj) {if (obj != NULL) {obj->Release(); obj = NULL;}}
#define SAFE_DELETE(ins) if (ins != NULL){	delete ins;	ins = NULL;}
#define SAFE_DELETE_ARRAY(arr) {if (arr != NULL){delete arr;arr = NULL;	}}
#define SAFE_DELETE_PTRARR(arr,n) {for (int i = 0; i < n; i++){	SAFE_DELETE(arr[i]);}SAFE_DELETE_ARRAY(arr);}

#define DEBUG_MODE 1
#if DEBUG_MODE == 1
#define LOG(info) ;
#endif
#endif