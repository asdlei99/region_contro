#pragma once

#include  <stdint.h>
#include <winsock2.h>

//�̶���ʼ����
#define PACKET_START_SING  (0xffffffff)


//��Ļ����
#define PACKET_TYPE_SCREEN  0x001

//���
#define PACKET_TYPE_MOUSE_EVENT  0x02

//����
#define PACKET_TYPE_KEY_EVENT  0x03

//READY �ź�
#define PACKET_TYPE_READY  0x100

//READY �ź� �ظ�
#define PACKET_TYPE_READY_PEPLY  0x101


#pragma pack(push, 4)

//��ʼ��־+������+����+���ĳ�������  ����
struct PacketHead
{
	//0xffffffff  uint32 max
	uint32_t start_sign;

	//����
	uint32_t type;

	//���ĳ���
	uint32_t len;
};


//�����¼�������
struct KeybdEventData
{
	int VK;
	bool down;
};

//��������
struct MouseEventData
{
	 int dx;
	 int dy;

	unsigned int action;
	//����
	int wheel;
};

//Ready ���ģ��ɱ����ƶ˷������ƶˣ������� ��Ƶ�߿�
struct ReadyData
{
	unsigned int video_w;
	unsigned int video_h;
};


#pragma pack(pop)

//
int SendN(SOCKET s, const char *buf, int len, int flags);
int RecvN(SOCKET s, char *buf, int len, int flags);

//����һ����Ļ���ݰ�
bool Packet_SendScreenPacket(SOCKET con, uint8_t* data, uint32_t size);

//����һ�����λ�ð�
bool Packet_SendCursorPos(SOCKET con, int x, int y);

//����һ������¼���
bool Packet_SendMouseEvent(SOCKET con, unsigned int action, int wheel);

//����һ�������¼���
bool Packet_SendKeyEvent(SOCKET con, int VK, bool down);

void DebugWSAError();


