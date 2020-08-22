#pragma once
#include <vector>
#include <Windows.h>

struct  Monitor {

	//��Ļ��С
	int left;
	int top;
	int width;
	int height;

	//¼������ 
	int capture_x;
	int capture_y;
	int capture_w;
	int capture_h;

	wchar_t name[256];
};


std::vector<Monitor> GetMonitors();



