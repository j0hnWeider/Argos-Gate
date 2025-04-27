#pragma once

#ifdef PROCESSSCANNER_EXPORTS
#define PROCESSSCANNER_API __declspec(dllexport)
#else
#define PROCESSSCANNER_API __declspec(dllimport)
#endif

extern "C" {
    // Função para iniciar a listagem de processos (exemplo)
    PROCESSSCANNER_API void listar_processos();
}
