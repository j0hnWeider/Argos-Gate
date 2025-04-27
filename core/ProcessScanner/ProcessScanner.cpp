#include "ProcessScanner.h"
#include <tlhelp32.h>
#include <psapi.h>
#include <iostream>

namespace ArgosGate
{
    ProcessScanner::ProcessScanner()
    {
        // Construtor - pode inicializar recursos se necessário
    }

    ProcessScanner::~ProcessScanner()
    {
        // Destrutor - liberar recursos se necessário
    }

    std::vector<ProcessoInfo> ProcessScanner::listarProcessos()
    {
        std::vector<ProcessoInfo> processos;

        // Criar snapshot dos processos ativos
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hSnapshot == INVALID_HANDLE_VALUE)
        {
            // Falha ao criar snapshot, retornar lista vazia
            return processos;
        }

        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);

        // Obter o primeiro processo
        if (!Process32First(hSnapshot, &pe32))
        {
            CloseHandle(hSnapshot);
            return processos;
        }

        do
        {
            ProcessoInfo info;
            info.pid = pe32.th32ProcessID;
            info.nome = pe32.szExeFile;
            info.caminho = obterCaminhoProcesso(info.pid);

            processos.push_back(info);

        } while (Process32Next(hSnapshot, &pe32));

        CloseHandle(hSnapshot);
        return processos;
    }

    std::wstring ProcessScanner::obterCaminhoProcesso(DWORD pid)
    {
        std::wstring caminho = L"";

        // Abrir processo para consulta
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION | PROCESS_VM_READ, FALSE, pid);
        if (hProcess)
        {
            WCHAR buffer[MAX_PATH];
            DWORD tamanho = MAX_PATH;

            // Tentar obter o caminho do módulo principal
            if (QueryFullProcessImageNameW(hProcess, 0, buffer, &tamanho))
            {
                caminho.assign(buffer, tamanho);
            }
            CloseHandle(hProcess);
        }

        return caminho;
    }
}
