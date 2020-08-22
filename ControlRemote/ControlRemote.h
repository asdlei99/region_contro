#pragma once

#include <stdint.h>
#include <winsock2.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS


#define ERROR_CODE_RECV (0x0101)

#define ERROR_CODE_START_SING (0x0102)

//_READY�ظ�����
#define ERROR_CODE_READY_PEPLY (0x0103)

#define WARNING_CODE_TYPE_NOT_SCREEN (0x0104)

#define ERROR_CODE_DECODE (0x0201)
#define ERROR_CODE_DECODE_PACKET_ERROR (0x0202)


#define ERROR_CODE_CREATE_SDLWINDOW (0x0301)
#define ERROR_CODE_CREATE_SDLRENDERER (0x0302)




//��ʽ��ʼ���ƻص�������Ϊ��Ƶ��С
typedef  void(_stdcall *StartCall) (int, int);

//�Ͽ��ص�����
typedef  void(_stdcall *DisconnectCall) ();

//������
typedef  void (_stdcall *ErrorMessageCall) (int,const char*);

struct Context;

//������������
 int _stdcall DLLInit();
 
 /*����һ��������
 HWND hwnd, ���ھ��
 SOCKET socket_con, socket ���

 StartCall startCall, ��ʼ�ص���������Ƶ�߿�
 DisconnectCall disconnectCall, �Ͽ��ص�
 ErrorMessageCall errorMessageCall ������Ϣ�ص�
 */
 void*_stdcall NewContext(HWND hwnd,SOCKET socket_con, 
	 StartCall startCall, DisconnectCall disconnectCall, ErrorMessageCall errorMessageCall);

 //ɾ����ֹͣ����������߳�
 void _stdcall DeleteStopContext(Context* context);

 //��ʼ�߳�
 int _stdcall StartWork(Context* context);


 /*
 �ú��������ǣ��Ƿ�ֻ���� ������ʾͼ��

 ԭ�����£�winform������С����ʱ�򣬻��ƻ��������ڶ��λ�ԭ����ʱ��  ��������С��ʱ�̿�ʼ���ƣ�

 ���ԣ���С����ʱ������ishowΪ0����֤��С��ʱ�򣬻����̲߳�������������С����ԭ���ڣ����治���ӳ٣���

 endraw 0��ʶ�����ƣ� ����0 ����
 */
 void  _stdcall EnableDraw(Context* context, int endraw);

 //�������λ��
 int _stdcall SendCursorPos(Context* context, int x, int y);

 //����������¼�
 int _stdcall SendMouseEvent(Context* context, unsigned int action, int wheel);

 //���ͼ����¼�
 int _stdcall SendKeyEvent(Context* context, int VK, bool down);


