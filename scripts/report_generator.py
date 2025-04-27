"""
Gerador de Relatórios Automáticos do Argos Gate

Este script em Python gera relatórios a partir dos dados analisados dos logs,
facilitando a visualização e interpretação dos resultados.

Autor: John Weider (Zeus)
Discord: dev.zeus
LinkedIn: https://www.linkedin.com/in/john-weider-98bb041b2/
"""

def gerar_relatorio(dados_analise):
    """
    Função para gerar um relatório simples a partir dos dados de análise.
    """
    relatorio = "Relatório de Análise do Argos Gate\n"
    relatorio += "===============================\n"
    for chave, valor in dados_analise.items():
        relatorio += f"{chave}: {valor}\n"
    return relatorio

if __name__ == "__main__":
    # Exemplo de uso com dados fictícios
    dados_exemplo = {
        "Eventos suspeitos": 5,
        "Eventos normais": 95,
        "Total de eventos": 100
    }
    print(gerar_relatorio(dados_exemplo))
