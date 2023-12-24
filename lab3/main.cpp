#include <iostream>
#include <locale>
#include <codecvt>
#include <vector>
#include <windows.h>

using namespace std;

#pragma pack(push, 1)

const BYTE RarSignature[] = {0x52, 0x61, 0x72, 0x21, 0x1A, 0x07, 0x00};

typedef struct
{
    WORD header_crc;
    BYTE header_type;
    WORD header_flags;
    WORD header_size;

}RarVolumeHeaderFormat, *PRarVolumeHeaderFormat;

typedef struct
{
    DWORD PackSize;
    DWORD UnpSize;
    BYTE HostOS;
    DWORD FileCRC;
    DWORD FileTime;
    BYTE UnpVer;
    BYTE Method;
    WORD NameSize;
    DWORD FileAttr;

}FILE_HEAD, *PFILE_HEAD;

#pragma pack(pop)

int ListRarContent (const BYTE *dataBuffer, unsigned int bufferSize)
{
    int numberOfFiles = 0;

    // ��������� ��������� ����� (�����������)
    if(memcmp(dataBuffer, RarSignature, sizeof(RarSignature)) != 0)
    {
        // ������
        return -1;
    }

    // ��������� �� ������ ����� �� ����� ��������� (7 ����)
    unsigned int fileOffset = sizeof(RarSignature);

    // ���� �� ������
    while(fileOffset < bufferSize)
    {
        // �������� ��������� �� ��������� ������� ������
        RarVolumeHeaderFormat *currentVolumeHeader = (RarVolumeHeaderFormat*)&dataBuffer[fileOffset];

        wcout<< L"��� ������: " << hex << uppercase << currentVolumeHeader->header_type << endl;

        // ��������� ��� ������. ��� ������ ���������� ������� ������� ���������� ������������ ������ ��� ���� ����������...
        if(currentVolumeHeader->header_type == 0x73)// 115
        {
            // MAIN_HEAD, ����������
            fileOffset += currentVolumeHeader->header_size;
        }
        else if(currentVolumeHeader->header_type == 0x74) // 116
		{
            // FILE_HEAD, ������� ��� �����

			const FILE_HEAD *fileHeader = (FILE_HEAD*)&dataBuffer[fileOffset + sizeof(RarVolumeHeaderFormat)];

			// ��� ����� ������� ����� ����� ��������� FILE_HEAD
			string fileName((char*)&dataBuffer[fileOffset + sizeof(RarVolumeHeaderFormat) + sizeof(FILE_HEAD)], fileHeader->NameSize);

			// ������� ��� �����
			cout << fileName << endl;
			numberOfFiles++;

            // ������ ������� �� ��������� � ����������� ������
            fileOffset += currentVolumeHeader->header_size;
            fileOffset += fileHeader->PackSize;
        }
        else if(currentVolumeHeader->header_type == 0x7B)
       	// ����� 123
        {
            // ������� ���������� ������
            break;
        }
		else
		{
			// ������ ���� ���������� �� �������������� � ���������� ���������� ���������
			break;
		}
    }

    return numberOfFiles;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // ������� ����
    HANDLE fileHandle = CreateFile("C:\\Users\\m1rby\\Downloads\\Example.rar",GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE)
    {
        DWORD errorCode = GetLastError();
        wcout<< L"������ �������� �����: " << errorCode <<endl;
        return 1;
    }

    // ���������� ��� ������
    DWORD fileSize = GetFileSize(fileHandle, NULL);
    if (fileSize == INVALID_FILE_SIZE)
    {
        wcout<< L"������ ����������� ������� �����"  <<endl;
        CloseHandle(fileHandle);
        return 1;
    }

    vector<BYTE> dataBuffer(fileSize);
    DWORD bytesRead;
    bool readOk = ReadFile(fileHandle, dataBuffer.data(), fileSize, &bytesRead, NULL);

    if(readOk && bytesRead == fileSize)
    {
        // ���� ������� ������
        int numberOfFiles = ListRarContent(dataBuffer.data(), dataBuffer.size());
        wcout << L"����� ������ � ������: " << numberOfFiles << endl;
    }

    CloseHandle(fileHandle);
    cin.get();
    return 0;
}
