#include <RadioLib.h>

// Definição dos pinos SPI e LoRa
#define LORA_CLK SCK   // Pino de clock SPI
#define LORA_MISO MISO // Pino MISO SPI
#define LORA_MOSI MOSI // Pino MOSI SPI
#define LORA_NSS SS    // Pino de seleção do módulo LoRa (Chip Select)

// Configurações LoRa
#define SF 7        // Spreading Factor (7-12)
#define CR 5        // Coding Rate (4/5)
#define BAND 915.0  // Frequência LoRa (Brasil: 915 MHz)
#define TX_POWER 20 // Potência de Transmissão (máximo 22 dBm)

// Criação do objeto LoRa SX1262 - Ordem: NSS, DIO1, RESET, BUSY
SX1262 Lora = new Module(8, 14, 12, 13);

void setup()
{
  Serial.begin(115200);

  // Inicializa a interface SPI com pinos definidos
  SPI.begin(LORA_CLK, LORA_MISO, LORA_MOSI, LORA_NSS);

  // Inicializa o módulo LoRa
  Serial.print("Iniciando LoRa... ");
  int state = Lora.begin(BAND);

  if (state == RADIOLIB_ERR_NONE)
  {
    Serial.println("Sucesso!");
  }
  else
  {
    Serial.print("Erro de inicialização. Código: ");
    Serial.println(state);
    while (true)
      ; // Para aqui se falhar
  }

  // Configuração dos parâmetros LoRa
  Lora.setSpreadingFactor(SF);
  Lora.setCodingRate(CR);
  Lora.setOutputPower(TX_POWER);

  Serial.println("LoRa configurado e pronto para enviar!");
}

void loop()
{
  // Leitura simulada da temperatura
  float temperature = 25.0;

  // Monta mensagem como string
  String data = "Temperatura: " + String(temperature) + " C";
  Serial.println("\nEnviando via LoRa: " + data);

  // Transmite os dados (modo bloqueante)
  int state = Lora.startTransmit(data);

  if (state == RADIOLIB_ERR_NONE)
  {
    Serial.println("Mensagem enviada com sucesso!");
  }
  else
  {
    Serial.print("Falha no envio. Código: ");
    Serial.println(state);
  }

  // Espera 2 segundos antes de enviar novamente
  delay(2000);
}
