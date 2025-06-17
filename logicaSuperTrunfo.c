#include <stdio.h>

// Cálculo dos dados para Densidade Populacional e PIB per Capita
void calcular_dados(unsigned long int populacao, float area, float pib, float *densidade, float *pib_per_capita) {
    *densidade = populacao / area;
    *pib_per_capita = (pib * 1000000000.0f) / populacao;
}

// Função para exibir o menu e ler o atributo escolhido
int escolher_atributo(int bloqueado, int rodada_num) {
    int opcao = 0;

    if (rodada_num == 1) {
        printf("\n=== Escolha um atributo para comparar ===\n");
    } else {
        printf("\n=== Escolha outro atributo para comparar ===\n");
    }

    if (bloqueado != 1) printf("1 - População\n");
    if (bloqueado != 2) printf("2 - Área\n");
    if (bloqueado != 3) printf("3 - PIB\n");
    if (bloqueado != 4) printf("4 - Pontos Turísticos\n");
    if (bloqueado != 5) printf("5 - Densidade Demográfica\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    // Verifica se o atributo escolhido é válido e não bloqueado
    if (opcao == bloqueado || opcao < 1 || opcao > 5) {
        printf("Opção inválida ou repetida! Tente novamente.\n");
        return escolher_atributo(bloqueado, rodada_num);
    }

    return opcao;
}

// Função para retornar o valor do atributo escolhido
float obter_valor_atributo(int atributo, unsigned long int populacao, float area, float pib, int pontos_turisticos, float densidade) {
    switch (atributo) {
        case 1: return (float) populacao;
        case 2: return area;
        case 3: return pib;
        case 4: return (float) pontos_turisticos;
        case 5: return densidade;
        default: return 0.0f;
    }
}

// Função para comparar e retornar vencedor de um atributo
int comparar_atributo(float v1, float v2, int atributo) {
    if (atributo == 5) { // Densidade: vence o menor
        return (v1 < v2) ? 1 : (v2 < v1) ? 2 : 0;
    } else { // Demais: vence o maior
        return (v1 > v2) ? 1 : (v2 > v1) ? 2 : 0;
    }
}

int main() {
    char estado1[50], estado2[50];
    char codigo1[50], codigo2[50];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;

    // Cadastro carta 1
    printf("\n=== Cadastro da Primeira Carta ===\n");
    printf("Estado: "); fgets(estado1, 50, stdin);
    printf("Código da carta: "); scanf("%s", codigo1); getchar();
    printf("Cidade: "); fgets(cidade1, 50, stdin);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área: "); scanf("%f", &area1);
    printf("PIB (em bilhões): "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_turisticos1);
    getchar();

    calcular_dados(populacao1, area1, pib1, &densidade1, &pib_per_capita1);

    // Cadastro carta 2
    printf("\n=== Cadastro da Segunda Carta ===\n");
    printf("Estado: "); fgets(estado2, 50, stdin);
    printf("Código da carta: "); scanf("%s", codigo2); getchar();
    printf("Cidade: "); fgets(cidade2, 50, stdin);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área: "); scanf("%f", &area2);
    printf("PIB (em bilhões): "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos_turisticos2);
    getchar();

    calcular_dados(populacao2, area2, pib2, &densidade2, &pib_per_capita2);

    // Escolha dos atributos
    int atributo1 = escolher_atributo(0, 1);
    int atributo2 = escolher_atributo(atributo1, 2);

    // Obter valores
    float valor1_attr1 = obter_valor_atributo(atributo1, populacao1, area1, pib1, pontos_turisticos1, densidade1);
    float valor2_attr1 = obter_valor_atributo(atributo1, populacao2, area2, pib2, pontos_turisticos2, densidade2);
    float valor1_attr2 = obter_valor_atributo(atributo2, populacao1, area1, pib1, pontos_turisticos1, densidade1);
    float valor2_attr2 = obter_valor_atributo(atributo2, populacao2, area2, pib2, pontos_turisticos2, densidade2);

    // Comparação individual
    int vencedor1 = comparar_atributo(valor1_attr1, valor2_attr1, atributo1);
    int vencedor2 = comparar_atributo(valor1_attr2, valor2_attr2, atributo2);

    // Soma
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Vencedor final
    int vencedor_final = (soma1 > soma2) ? 1 : (soma2 > soma1) ? 2 : 0;

    // Exibir resultados
    printf("\n=== Resultado da Comparação ===\n");
    printf("Cidade 1: %s", cidade1);
    printf("Cidade 2: %s", cidade2);

    printf("\nAtributo 1 (%d): Cidade 1 = %.2f | Cidade 2 = %.2f | %s venceu\n", atributo1, valor1_attr1, valor2_attr1,
           (vencedor1 == 1) ? "Cidade 1" : (vencedor1 == 2) ? "Cidade 2" : "Empate");

    printf("Atributo 2 (%d): Cidade 1 = %.2f | Cidade 2 = %.2f | %s venceu\n", atributo2, valor1_attr2, valor2_attr2,
           (vencedor2 == 1) ? "Cidade 1" : (vencedor2 == 2) ? "Cidade 2" : "Empate");

    printf("\nSoma dos atributos:\n");
    printf("Cidade 1: %.2f\n", soma1);
    printf("Cidade 2: %.2f\n", soma2);

    printf("\nResultado final: %s\n",
           (vencedor_final == 1) ? "Cidade 1 venceu!" :
           (vencedor_final == 2) ? "Cidade 2 venceu!" : "Empate!");

    return 0;
}
