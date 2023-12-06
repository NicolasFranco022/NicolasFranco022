FUNÇÃO EXCLUIR POSIÇÃO JOGADOR

void excluirPosicaoJogador()
{
    int i, k;
    enum_posicao posicao;

    printf("\nLista de jogadores e suas posições:\n");
    for (i = 0; i < num_times; i++)
    {
        for (k = 0; k < pTime[i].posicao_jogador; k++)
        {
            printf("- Jogador: %s, Posição: %d\n", pTime[i].jogadores[k].nome, pTime[i].jogadores[k].posicao);
        }
    }

    printf("\nDigite a posição do jogador a ser excluída (1 - Goleiro, 2 - AlaD, 3 - AlaE, 4 - Fixo, 5 - Pivo): ");
    scanf("%d", (int *)&posicao);
    fflush(stdin);

    if ((posicao < Goleiro) || (posicao > Pivo))
    {
        printf("\nPosição inválida!\n");
        return;
    }

    int posicaoEscolhida;
    printf("\nDigite a posição já definida que deseja excluir: ");
    scanf("%d", &posicaoEscolhida);

    // Itera sobre os times
    for (i = 0; i < num_times; i++)
    {
        // Itera sobre os jogadores do time
        for (k = 0; k < pTime[i].posicao_jogador; k++)
        {
            // Verifica se o jogador tem a posição escolhida
            if (pTime[i].jogadores[k].posicao == posicao && pTime[i].jogadores[k].posicao == posicaoEscolhida)
            {
                // Remove o jogador da posição escolhida
                for (int j = k; j < pTime[i].posicao_jogador - 1; j++)
                {
                    pTime[i].jogadores[j] = pTime[i].jogadores[j + 1];
                }

                pTime[i].posicao_jogador--;
                k--;  // Decrementa k para verificar novamente na mesma posição, pois os jogadores foram deslocados
            }
        }
    }

    printf("\nPosição de jogador excluída com sucesso!\n");
}
