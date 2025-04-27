/*
 * Módulo SignatureVerifier - Validação de assinatura digital
 * Autor: John Weider (Zeus)
 * Descrição: Este módulo utiliza a WinAPI para verificar a assinatura digital de arquivos.
 */

#include <windows.h>
#include <wincrypt.h>
#include <wintrust.h>
#include <softpub.h>
#include <iostream>

#pragma comment(lib, "wintrust")

using namespace std;

static const GUID WINTRUST_ACTION_GENERIC_VERIFY_V2 = 
{ 0xaac56bca, 0xcd44, 0x11d0, { 0x8c, 0xc2, 0x00, 0xc0, 0x4f, 0xc2, 0x95, 0xee } };

/*
 * Função para verificar a assinatura digital de um arquivo.
 * Retorna true se o arquivo estiver assinado e a assinatura for válida.
 */
bool verificarAssinatura(const wchar_t* caminhoArquivo) {
    LONG status;
    WINTRUST_FILE_INFO fileInfo = {0};
    WINTRUST_DATA winTrustData = {0};

    fileInfo.cbStruct = sizeof(WINTRUST_FILE_INFO);
    fileInfo.pcwszFilePath = caminhoArquivo;
    fileInfo.hFile = NULL;
    fileInfo.pgKnownSubject = NULL;

    winTrustData.cbStruct = sizeof(WINTRUST_DATA);
    winTrustData.pPolicyCallbackData = NULL;
    winTrustData.pSIPClientData = NULL;
    winTrustData.dwUIChoice = WTD_UI_NONE;
    winTrustData.fdwRevocationChecks = WTD_REVOKE_NONE;
    winTrustData.dwUnionChoice = WTD_CHOICE_FILE;
    winTrustData.pFile = &fileInfo;
    winTrustData.dwStateAction = 0;
    winTrustData.hWVTStateData = NULL;
    winTrustData.pwszURLReference = NULL;
    winTrustData.dwProvFlags = WTD_SAFER_FLAG;
    winTrustData.dwUIContext = 0;

    status = WinVerifyTrust(NULL, &WINTRUST_ACTION_GENERIC_VERIFY_V2, &winTrustData);

    return (status == ERROR_SUCCESS);
}

int main() {
    wstring caminho;
    wcout << L"Digite o caminho do arquivo para verificar assinatura digital: ";
    getline(wcin, caminho);

    bool resultado = verificarAssinatura(caminho.c_str());
    if (resultado) {
        wcout << L"Arquivo assinado digitalmente e válido." << endl;
    } else {
        wcout << L"Arquivo não assinado ou assinatura inválida." << endl;
    }

    return 0;
}
