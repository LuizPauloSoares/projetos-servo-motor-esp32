# Projetos Servo Motor - ESP32

Três projetos progressivos de controle de servo motor com ESP32, do movimento básico até um sistema automático de irrigação. Desenvolvidos como parte dos estudos de eletrônica embarcada e IoT.

## 📁 Estrutura do repositório

```
projetos-servo-motor-esp32/
├── servo-basico/
│   └── servo-basico.ino
├── servo-potenciometro/
│   └── servo-potenciometro.ino
└── irrigacao-automatica/
    └── irrigacao-automatica.ino
```

## 🔧 Hardware utilizado

- ESP32 (DevKit)
- Servo motor (ex: SG90)
- Potenciômetro (projeto 2)
- Sensor de umidade de solo (projeto 3)
- 2x LED (verde e vermelho) + resistores (projeto 3)

## 🛠️ Biblioteca necessária

Todos os projetos usam a biblioteca [ESP32Servo](https://github.com/madhephaestus/ESP32Servo), instalável direto pelo Gerenciador de Bibliotecas da Arduino IDE.

---

## 1️⃣ servo-basico

Movimento fixo do servo entre três posições (0°, 90°, 180°), com pausas entre elas. Primeiro contato com a biblioteca `ESP32Servo` e os comandos `attach()` e `write()`.

**Conexões:**
| Servo | ESP32 |
|---|---|
| Sinal | GPIO 5 |
| VCC | 5V |
| GND | GND |

---

## 2️⃣ servo-potenciometro

Controle do ângulo do servo em tempo real através da leitura analógica de um potenciômetro. Introduz `analogRead()`, `map()` e monitoramento via `Serial`.

**Conexões:**
| Componente | ESP32 |
|---|---|
| Servo (sinal) | GPIO 5 |
| Potenciômetro (wiper) | GPIO 35 |

**O que faz:** lê o valor do potenciômetro (0–1023) e converte proporcionalmente para o ângulo do servo (0°–180°), exibindo os valores no Monitor Serial (115200 baud).

---

## 3️⃣ irrigacao-automatica

Projeto mais completo: um sensor de umidade do solo decide se o servo deve simular a abertura de uma válvula de irrigação, com LEDs indicando o status.

**Conexões:**
| Componente | ESP32 |
|---|---|
| Servo (sinal) | GPIO 5 |
| Sensor de umidade (saída analógica) | GPIO 34 |
| LED verde | GPIO 19 |
| LED vermelho | GPIO 18 |

**Como funciona:**
- Lê a umidade do solo e converte para porcentagem (0–100%)
- **Umidade < 30%** → LED verde aceso, servo varre de 0° a 180° e volta (simulando irrigação)
- **Umidade ≥ 30%** → LED vermelho aceso, servo permanece em 0° (solo úmido, sem necessidade de irrigar)
- A varredura do servo é interrompida assim que a umidade atinge o nível ideal

---

## 📈 Evolução do projeto

Este repositório reflete uma progressão de aprendizado:

1. **Controle fixo** → entendimento básico de servo motor
2. **Controle por input externo** → leitura analógica e mapeamento de valores
3. **Controle automático por sensor** → lógica condicional aplicada a um cenário real (IoT/automação)

---

## 👤 Autor

**Luiz Paulo Soares**
[GitHub](https://github.com/LuizPauloSoares) · [LinkedIn](https://www.linkedin.com/in/luiz-paulo-soares/) · [Instagram](https://instagram.com/lu1z_st)
