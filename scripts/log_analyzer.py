"""
Analisador de Logs do Argos Gate

Este script em Python realiza a análise dos logs gerados pelo Argos Gate,
permitindo identificar padrões suspeitos e gerar relatórios.

Autor: John Weider (Zeus)
Discord: dev.zeus
LinkedIn: https://www.linkedin.com/in/john-weider-98bb041b2/
"""

import json

def analisar_log(caminho_arquivo):
    """
    Função para analisar o arquivo de log JSON e identificar eventos suspeitos.
    """
    with open(caminho_arquivo, 'r', encoding='utf-8') as arquivo:
        dados = json.load(arquivo)
    
    # Exemplo simples: contar eventos por tipo
    contagem_eventos = {}
    for evento in dados.get('eventos', []):
        tipo = evento.get('tipo', 'desconhecido')
        contagem_eventos[tipo] = contagem_eventos.get(tipo, 0) + 1
    
    return contagem_eventos

if __name__ == "__main__":
    caminho = "logs/argos_gate_log.json"
    resultado = analisar_log(caminho)
    print("Resumo da análise de logs:")
    for tipo, quantidade in resultado.items():
        print(f"{tipo}: {quantidade}")
