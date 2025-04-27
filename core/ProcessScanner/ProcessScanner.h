#pragma once

#include <windows.h>
#include <vector>
#include <string>

namespace ArgosGate
{
    // Estrutura que representa informações básicas de um processo
    struct ProcessoInfo
    {
        DWORD pid;              // ID do processo
        std::wstring nome;      // Nome do processo
        std::wstring caminho;   // Caminho completo do executável
    };

    class ProcessScanner
    {
    public:
        // Construtor e destrutor
        ProcessScanner();
        ~ProcessScanner();

        // Função para listar todos os processos ativos no sistema
        std::vector<ProcessoInfo> listarProcessos();

    private:
        // Função auxiliar para obter o caminho completo do executável dado o PID
        std::wstring obterCaminhoProcesso(DWORD pid);
    };
}
