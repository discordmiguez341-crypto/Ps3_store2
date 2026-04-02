#include <stdio.h>
#include <rsx/rsx.h>
#include <sysutil/video.h>
#include <io/pad.h>
#include <malloc.h>

#define HOST_SIZE (1024*1024)

int main(void)
{
    // === INICIALIZAÇÃO DO PS3 ===
    videoState state;
    videoConfiguration vconfig;
    videoGetState(0, 0, &state);
    videoGetResolution(state.displayMode.resolution, &vconfig);

    gcmContextData *context;
    void *host_addr = memalign(1024*1024, HOST_SIZE);
    rsxInit(&context, 0x10000, HOST_SIZE, host_addr);

    ioPadInit(7);

    printf("=== PS3 MiniStore - Esqueleto ===\n");
    printf("Pressione START para sair\n");

    padData paddata;
    int running = 1;

    while (running) {
        ioPadGetData(0, &paddata);

        // === DETECÇÃO DE BOTÕES (placeholder) ===
        if (paddata.BTN_START) running = 0;

        // Aqui no futuro vamos detectar clique nos botões com Tiny3D
        // Por enquanto só mostramos o menu

        // Limpa tela
        rsxSetClearColor(context, 0x00204060);  // fundo azul escuro bonito
        rsxClearSurface(context, GCM_CLEAR_R | GCM_CLEAR_G | GCM_CLEAR_B | GCM_CLEAR_A);

        // === MENU COM BOTÕES (texto placeholder) ===
        // No futuro usaremos Tiny3D para desenhar botões clicáveis
        printf("=== MINI LOJA PS3 ===\n");
        printf("1 - Instalar Lojas\n");
        printf("2 - Baixar Ferramentas\n");
        printf("3 - Excluir esta Loja\n\n");
        printf("Use o controle para navegar (futuro)\n");

        // Troca buffer (mostra na tela)
        flip(context);
    }

    ioPadEnd();
    return 0;
}
