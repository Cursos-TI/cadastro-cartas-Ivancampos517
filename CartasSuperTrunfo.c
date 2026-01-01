#include <stdio.h>

// Estrutura para representar uma carta do Super Trunfo
struct Carta {
    char estado[3];      // Exemplo: "SP"
    char codigo[10];     // Exemplo: "SP001"
    char cidade[50];     // Nome da cidade
    int populacao;       // População em habitantes
    float area;          // Área em km²
    float pib;           // PIB em bilhões
    int pontos_turisticos; // Número de pontos turísticos
    float densidade;     // Calculada: pop / area
    float pib_per_capita; // Calculada: pib / pop * 
};

int main() {
    // Carta 1: São Paulo
    struct Carta carta1;
    snprintf(carta1.estado, sizeof(carta1.estado), "SP");
    snprintf(carta1.codigo, sizeof(carta1.codigo), "SP001");
    snprintf(carta1.cidade, sizeof(carta1.cidade), "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 699.0;
    carta1.pontos_turisticos = 15;
    
    // Carta 2: Rio de Janeiro
    struct Carta carta2;
    snprintf(carta2.estado, sizeof(carta2.estado), "RJ");
    snprintf(carta2.codigo, sizeof(carta2.codigo), "RJ001");
    snprintf(carta2.cidade, sizeof(carta2.cidade), "Rio de Janeiro");
    carta2.populacao = 6748000;
    carta2.area = 1267.0;
    carta2.pib = 137.0;
    carta2.pontos_turisticos = 20;
    
    // Cálculos para Carta 1
    carta1.densidade = (float)carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1e9) / carta1.populacao;  // PIB em R$ por habitante
    
    // Cálculos para Carta 2
    carta2.densidade = (float)carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1e9) / carta2.populacao;
    
    // Exibe dados das cartas
    printf("=== DADOS DAS CARTAS ===\n");
    printf("Carta 1 - %s (%s): Pop: %d, Area: %.2f km², PIB: R$%.1f bi, Turísticos: %d\n", 
           carta1.cidade, carta1.estado, carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos);
    printf("Densidade: %.0f hab/km², PIB per capita: R$%.0f\n\n", carta1.densidade, carta1.pib_per_capita);
    
    printf("Carta 2 - %s (%s): Pop: %d, Area: %.2f km², PIB: R$%.1f bi, Turísticos: %d\n", 
           carta2.cidade, carta2.estado, carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos);
    printf("Densidade: %.0f hab/km², PIB per capita: R$%.0f\n\n", carta2.densidade, carta2.pib_per_capita);
    
    // Comparação: População (maior vence) - Escolha fixa no código
    printf("=== COMPARAÇÃO DE CARTAS (Atributo: População) ===\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
    
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
    
    return 0;
}
// Programa simples para representar cartas do Super Trunfo com dados de cidades brasileiras
// e comparar dois atributos (população neste caso).