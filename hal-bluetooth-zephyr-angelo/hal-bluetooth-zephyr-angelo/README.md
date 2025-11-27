# HAL Bluetooth + Zephyr (SAMD21 Xplained Pro)

Projeto individual desenvolvido por **Angelo Luigi Bocchi Lovatto** para a disciplina de Sistemas Embarcados.

O objetivo deste repositório é documentar, em forma de código, a trajetória de desenvolvimento de um **HAL (Hardware Abstraction Layer)** para a placa **SAMD21 Xplained Pro**, incluindo:

- Organização de um HAL simples para GPIO (LED on-board).
- Estrutura de aplicação usando Zephyr RTOS.
- Esqueleto de integração com Bluetooth Low Energy (BLE) via Zephyr, pensado para uso com um módulo externo (por exemplo, BTLC1000).
- Código e estrutura prontos para serem avaliados via GitHub, com licença open-source **MIT**.

> Observação importante: o suporte BLE aqui foi organizado como **esqueleto de HAL**, isto é, focado na organização do código e na forma correta de inicializar e anunciar o dispositivo com a *stack* Bluetooth do Zephyr. A integração física completa com o módulo BTLC1000 ainda exige ajustes de *device tree* e *drivers* específicos, como descrito no relatório teórico.

## Estrutura do projeto

```text
.
├── CMakeLists.txt        # Arquivo padrão de aplicação Zephyr
├── prj.conf              # Configurações do Zephyr (GPIO + Bluetooth)
├── src
│   ├── main.c            # Laço principal usando o HAL
│   ├── hal_gpio.c        # Implementação da camada de GPIO
│   └── hal_bt.c          # Implementação da camada Bluetooth (esqueleto)
├── include
│   ├── hal_gpio.h        # Interface da camada de GPIO
│   └── hal_bt.h          # Interface da camada Bluetooth
├── README.md             # Este arquivo
├── LICENSE               # Licença MIT
└── docs
    └── README_docs.md    # Notas sobre o relatório teórico
```

## Como compilar (exemplo)

Este projeto segue o padrão de aplicações do Zephyr. Assumindo que você já tem o ambiente configurado (`west`, Zephyr SDK, etc.) e que o diretório deste projeto se chama `hal-bluetooth-zephyr-angelo/`, um exemplo de compilação é:

```bash
# Entrar na pasta raiz do Zephyr
cd C:/Users/angel/zephyrproject/zephyr

# Compilar a aplicação apontando para este diretório
py -m west build -b samd21_xpro C:/Users/angel/caminho/para/hal-bluetooth-zephyr-angelo -p
```

- Para a **SAMD21 Xplained Pro**, o LED on-board deve piscar utilizando apenas a camada de GPIO (Bluetooth pode não estar disponível nativamente).
- Para uma *board* com Bluetooth integrado (por exemplo, uma placa da família nRF52), o mesmo código pode ser reaproveitado, habilitando a parte BLE descrita em `hal_bt.c` (desde que `CONFIG_BT` esteja devidamente configurado no `prj.conf`).

## Arquivos principais

### `src/main.c`

- Faz a inicialização do HAL de GPIO.
- Tenta inicializar o HAL de Bluetooth (quando `CONFIG_BT=y`).
- Entra em um laço infinito alternando o LED on-board, servindo como teste simples de funcionamento.

### `src/hal_gpio.c` / `include/hal_gpio.h`

- Encapsula o acesso ao LED usando o *alias* `led0` do *device tree* do Zephyr.
- Oferece funções simples:
  - `hal_gpio_init()`
  - `hal_gpio_led_on()`
  - `hal_gpio_led_off()`
  - `hal_gpio_led_toggle()`

### `src/hal_bt.c` / `include/hal_bt.h`

- Organiza a inicialização da *stack* Bluetooth e o início de *advertising* BLE.
- Usa as APIs padrão do Zephyr para BLE (`bt_enable`, `bt_le_adv_start`).
- Se `CONFIG_BT` estiver desabilitado, as funções retornam `-ENOTSUP` e apenas registram mensagens via `printk`, permitindo compilar o projeto mesmo em placas sem Bluetooth.

## Relacionamento com o relatório teórico

No diretório `docs/` há um arquivo `README_docs.md` explicando a relação deste projeto de código com o relatório teórico em LaTeX (Overleaf). O relatório descreve:

- A trajetória de configuração do ambiente Zephyr.
- Os testes com exemplos básicos (`hello_world`, `blinky`).
- A migração para a placa SAMD21 Xplained Pro.
- Os erros encontrados ao tentar integrar Bluetooth e como eles foram estudados.
- Os aprendizados e conclusões sobre o uso de HAL + Zephyr + BLE.

## Licença

Este projeto está licenciado sob os termos da licença **MIT**. Consulte o arquivo [`LICENSE`](LICENSE) para mais detalhes.
