#include <stdio.h>

// Cálculo dos dados para Densidade Populacional e PIB per Capita
void calcular_dados(unsigned long int populacao, float area, float pib, float *densidade, float *pib_per_capita) {
    *densidade = populacao / area;
    *pib_per_capita = (pib * 1000000000.0f) / populacao;
}

// Função para o Super Poder da carta
float superPoder(unsigned long int populacao, float area, float pib, int pontos_turisticos, float densidade, float pib_per_capita) {
    float inverso_densidade = 1 / densidade;
    return populacao + area + pib + pontos_turisticos + pib_per_capita + inverso_densidade;
}

// Função para comparar apenas o atributo População
void comparar_atributo_populacao(unsigned long int populacao1, unsigned long int populacao2, char cidade1[], char cidade2[]) {
    printf("\n--- Comparação de Cartas (Atributo: População) ---\n");
    printf("Carta 1 - %s: %lu habitantes\n", cidade1, populacao1);
    printf("Carta 2 - %s: %lu habitantes\n", cidade2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }
}


// função principal 
int main() {
    // Declaração de variavéis
    char estado1[50], estado2[50];
    char codigo1[50], codigo2[50];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;
    float super1, super2;

    // Primeira carta
    printf("\n=== Cadastro da Primeira Carta ===\n");
    printf("Estado: "); fgets(estado1, 50, stdin);
    printf("Código da carta: "); scanf("%s", codigo1); getchar();
    printf("Cidade: "); fgets(cidade1, 50, stdin);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área: "); scanf("%f", &area1);
    printf("PIB (em bilhões): "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_turisticos1);
    getchar();

    // Definição de dados da Carta 1 para Calculo de Dados e Super Poder 
    calcular_dados(populacao1, area1, pib1, &densidade1, &pib_per_capita1);
    super1 = superPoder(populacao1, area1, pib1, pontos_turisticos1, densidade1, pib_per_capita1);

    // Segunda carta
    printf("\n=== Cadastro da Segunda Carta ===\n");
    printf("Estado: "); fgets(estado2, 50, stdin);
    printf("Código da carta: "); scanf("%s", codigo2); getchar();
    printf("Cidade: "); fgets(cidade2, 50, stdin);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área: "); scanf("%f", &area2);
    printf("PIB (em bilhões): "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_turisticos2);
    getchar();

    // Definição de dados da Carta 2 para Calculo de Dados e Super Poder 
    calcular_dados(populacao2, area2, pib2, &densidade2, &pib_per_capita2);
    super2 = superPoder(populacao2, area2, pib2, pontos_turisticos2, densidade2, pib_per_capita2);

    // Parte na qual é comparado o atributo de duas cartas (nesse caso vamos de população)
    comparar_atributo_populacao(populacao1, populacao2, cidade1, cidade2);

    return 0;
}