#include <stdio.h>

// Cálculo dos dados para Densidade Populacional e PIB per Capita
void calcular_dados(unsigned long int populacao, float area, float pib, float *densidade, float *pib_per_capita) {
    *densidade = populacao / area;
    *pib_per_capita = (pib * 1000000000.0f) / populacao;
}

// Função para o Super Poder da carta (Não será mais útil agora)
/* float superPoder(unsigned long int populacao, float area, float pib, int pontos_turisticos, float densidade, float pib_per_capita) {
    float inverso_densidade = 1 / densidade;
    return populacao + area + pib + pontos_turisticos + pib_per_capita + inverso_densidade;
}

*/

// função principal 
int main() {
    // Declaração de variavéis
    char estado1[50], estado2[50];                      // Estado
    char codigo1[50], codigo2[50];                      // Código da Carta
    char cidade1[50], cidade2[50];                      // Nome da Cidade
    unsigned long int populacao1, populacao2;           // População
    float area1, area2;                                 // Área
    float pib1, pib2;                                   // PIB
    int pontos_turisticos1, pontos_turisticos2;         // Pontos Turísticos
    float densidade1, densidade2;                       // Densidade Populacional
    float pib_per_capita1, pib_per_capita2;             // PIB per Capita
    /* float super1, super2; */                         // Super Poder

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
    /*
    super1 = superPoder(populacao1, area1, pib1, pontos_turisticos1, densidade1, pib_per_capita1);
    */

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
    /*
    super2 = superPoder(populacao2, area2, pib2, pontos_turisticos2, densidade2, pib_per_capita2);
    */
    
    int atributo;
    
    // Menu de escolha do atributo
    printf("\n=== Escolha um atributo para comparar ===\n");
    printf("1 - Nome da Cidade\n");
    printf("2 - População\n");
    printf("3 - Área\n");
    printf("4 - PIB\n");
    printf("5 - Pontos Turísticos\n");
    printf("6 - Densidade Demográfica\n");
    printf("Escolha: ");
    scanf("%d", &atributo);

    
    printf("\n=== Comparação entre %s e %s ===\n", cidade1, cidade2);

    switch (atributo) {
        case 1:
            printf("\n=== Nome das Cartas ===\n");
            printf("Carta 1: (%s)", cidade1);
            printf("Carta 2: (%s)", cidade2);
            break;
            
        case 2:
            printf("\n=== Comparação de Cartas (Atributo: População) ===\n");
            printf("Carta 1 - %s: %lu habitantes\n", cidade1, populacao1);
            printf("Carta 2 - %s: %lu habitantes\n", cidade2, populacao2);
        
            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            };
            break;

        case 3:
                printf("\n=== Comparação de Cartas (Atributo: Área) ===\n");
                printf("Carta 1 - %s: %f Km²\n", cidade1, area1);
                printf("Carta 2 - %s: %f Km²\n", cidade2, area2);
            
                if (area1 > area2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if (area2 > area1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                };
                break;

        case 4:
                printf("\n=== Comparação de Cartas (Atributo: PIB) ===\n");
                printf("Carta 1 - %s: %2.f bilhões de Reais\n", cidade1, pib1);
                printf("Carta 2 - %s: %2.f bilhões de Reais\n", cidade2, pib2);
            
                if (pib1 > pib2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if (pib2 > pib1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                };
                break;

        case 5:
                printf("\n=== Comparação de Cartas (Atributo: Pontos Turísticos) ===\n");
                printf("Carta 1 - %s: %d pontos turísticos\n", cidade1, pontos_turisticos1);
                printf("Carta 2 - %s: %d pontos turísticos\n", cidade2, pontos_turisticos2);
            
                if (pontos_turisticos1 > pontos_turisticos2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if (pontos_turisticos2 > pontos_turisticos1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                };
                break;

        case 6:
                printf("\n=== Comparação de Cartas (Atributo: Densidade Populacional) ===\n");
                printf("Carta 1 - %s: %f \n", cidade1, densidade1);
                printf("Carta 2 - %s: %f \n", cidade2, densidade2);
            
                if (densidade1 < densidade2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if (densidade2 < densidade1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                };
                break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}