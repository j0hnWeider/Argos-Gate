/*
 * Módulo ProcessScanner - Scanner principal de processos ativos
 * Autor: John Weider (Zeus)
 * Descrição: Este módulo utiliza a WinAPI para listar os processos ativos no sistema Windows.
 */

#include "ProcessScanner.h"
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

using namespace std;

/*
 * Função para listar os processos ativos no sistema.
 */
void listarProcessos() {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        cerr << "Erro ao criar snapshot dos processos." << endl;
        return;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &pe32)) {
        cerr << "Erro ao obter o primeiro processo." << endl;
        CloseHandle(hSnapshot);
        return;
    }

    cout << "Lista de processos ativos:" << endl;
    do {
        wcout << L"PID: " << pe32.th32ProcessID << L" - Nome: " << pe32.szExeFile << endl;
    } while (Process32Next(hSnapshot, &pe32));

    CloseHandle(hSnapshot);
}

// Função exportada para listar processos
extern "C" __declspec(dllexport) void listar_processos() {
    listarProcessos();
}

int main() {
    listarProcessos();
    return 0;
}
