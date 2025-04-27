/*
 * Módulo DLLInspector - Inspeção de DLLs carregadas em processos
 * Autor: John Weider (Zeus)
 * Descrição: Este módulo lista as DLLs carregadas em um processo Windows,
 * permitindo identificar módulos suspeitos ou não confiáveis.
 */

#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

using namespace std;

/*
 * Função para listar as DLLs carregadas em um processo pelo PID.
 */
void listarDLLs(DWORD pid) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        cerr << "Erro ao criar snapshot dos módulos." << endl;
        return;
    }

    MODULEENTRY32 me32;
    me32.dwSize = sizeof(MODULEENTRY32);

    if (!Module32First(hSnapshot, &me32)) {
        cerr << "Erro ao obter o primeiro módulo." << endl;
        CloseHandle(hSnapshot);
        return;
    }

    cout << "DLLs carregadas no processo PID " << pid << ":" << endl;
    do {
        wcout << L" - " << me32.szModule << L" (Base: " << me32.modBaseAddr << L")" << endl;
    } while (Module32Next(hSnapshot, &me32));

    CloseHandle(hSnapshot);
}

int main() {
    DWORD pid;
    cout << "Digite o PID do processo para listar DLLs carregadas: ";
    cin >> pid;

    listarDLLs(pid);

    return 0;
}
