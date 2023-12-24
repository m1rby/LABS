#include <iostream>
#include <vector>
#include <Windows.h>

int main() {
    // ��������� ���� � �������������� Windows API
    HANDLE hFile = CreateFile(L"file.rar", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    // �������� ������ �����
    DWORD fileSize = GetFileSize(hFile, NULL);

    // �������� ������ ��� �����
    std::vector<char> buffer(fileSize);

    // ������ ���������� ����� � �����
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer.data(), fileSize, &bytesRead, NULL)) {
        std::cerr << "Failed to read file." << std::endl;
        CloseHandle(hFile);
        return 1;
    }

    // ��������� ����
    CloseHandle(hFile);

    return 0;
}
