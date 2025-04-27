using System;
using System.Runtime.InteropServices;

namespace ArgosGateUI
{
    public static class ProcessScannerInterop
    {
        // Importa a função listar_processos da DLL do ProcessScanner
        [DllImport("ProcessScanner.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void listar_processos();
    }
}
