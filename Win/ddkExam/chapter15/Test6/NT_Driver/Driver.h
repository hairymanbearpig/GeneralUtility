/************************************************************************
* �ļ�����:Driver.h                                                 
* ��    ��:�ŷ�
* �������:2007-11-1
*************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include <NTDDK.h>

void Ke386SetIoAccessMap(int, UCHAR *);
void Ke386QueryIoAccessMap(int, UCHAR *);
void Ke386IoSetAccessProcess(PEPROCESS, int);

#ifdef __cplusplus
}
#endif 

#define IOPM_SIZE 0x2000
UCHAR *pIOPM = NULL;

#include "ioctls.h"

#define PAGEDCODE code_seg("PAGE")
#define LOCKEDCODE code_seg()
#define INITCODE code_seg("INIT")

#define PAGEDDATA data_seg("PAGE")
#define LOCKEDDATA data_seg()
#define INITDATA data_seg("INIT")

#define arraysize(p) (sizeof(p)/sizeof((p)[0]))

#define MAX_FILE_LENGTH 1024

typedef struct _DEVICE_EXTENSION {
	PDEVICE_OBJECT pDevice;
	UNICODE_STRING ustrDeviceName;	//�豸����
	UNICODE_STRING ustrSymLinkName;	//����������

	PUCHAR buffer;//������
	ULONG file_length;//ģ����ļ����ȣ�����С��MAX_FILE_LENGTH
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;

// ��������

NTSTATUS CreateDevice (IN PDRIVER_OBJECT pDriverObject);
VOID HelloDDKUnload (IN PDRIVER_OBJECT pDriverObject);
NTSTATUS HelloDDKDispatchRoutin(IN PDEVICE_OBJECT pDevObj,
								 IN PIRP pIrp);
NTSTATUS HelloDDKDeviceIOControl(IN PDEVICE_OBJECT pDevObj,
								 IN PIRP pIrp);
