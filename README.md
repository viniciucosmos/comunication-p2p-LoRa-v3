# communication-p2p-LoRa-v3

Este repositório contém o código de exemplo para comunicação ponto a ponto (P2P) usando LoRa, com placas **Heltec ESP32 LoRa V3**. O foco é exclusivamente a troca de mensagens entre um dispositivo transmissor (TX) e um receptor (RX) via LoRa, sem coleta de dados de sensores.  

Este projeto serve como **base de comunicação** para sistemas mais complexos, como monitoramento ambiental ou agrícola.

---

## Visão Geral

- Comunicação via LoRa (SX1262) entre dois dispositivos.
- Configuração otimizada de parâmetros LoRa (SF, CR, potência).
- Exibição dos dados recebidos no Serial Monitor e no display OLED.
- Código modular e pronto para expansão futura com sensores.

---

## Hardware Utilizado

- 2x **Heltec ESP32 LoRa V3** (WiFi + Bluetooth + OLED + LoRa SX1262 integrados)

---

## Bibliotecas Utilizadas

### Transmissor (`sender_V3.ino`)
- [`jgromes/RadioLib`](https://github.com/jgromes/RadioLib)

### Receptor (`receiver_V3.ino`)
- [`jgromes/RadioLib`](https://github.com/jgromes/RadioLib)
- [`adafruit/Adafruit SSD1306`](https://github.com/adafruit/Adafruit_SSD1306)
- [`sandeepmistry/LoRa`](https://github.com/sandeepmistry/arduino-LoRa) *(para compatibilidade com OLED + inicialização)*

---

## Mapeamento de Pinos (Heltec LoRa V3)

| Função        | Pino GPIO |
|---------------|-----------|
| LoRa NSS      | GPIO8     |
| LoRa SCK      | GPIO9     |
| LoRa MOSI     | GPIO10    |
| LoRa MISO     | GPIO11    |
| LoRa RST      | GPIO12    |
| LoRa BUSY     | GPIO13    |
| LoRa DIO1     | GPIO14    |

> Esses pinos são utilizados pela biblioteca `RadioLib` para comunicação com o rádio SX1262.

---

## 📁 Estrutura do Projeto

```bash
communication-p2p-LoRa-v3/
├── sender_V3.ino       # Código do transmissor
├── receiver_V3.ino       # Código do receptor com display OLED
├── README.md    # Este arquivo
