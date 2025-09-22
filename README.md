# 🚨 Emulador de Erros de Sistema Operacional - projetoSO-

<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

**Simulador educacional interativo para demonstração prática de erros críticos em sistemas operacionais**

</div>

---

## 👥 Integrantes do Grupo

- **Bruno Almeida dos Santos** - Implementação de erros em C
- **Luiz Filipe Santos de Souza** - Estruturação do projeto e desenvolvimento
- **Caio Eduardo Ferreira dos Santos** - Implementação de erros em C

---

## 📋 Descrição do Projeto

O projeto foi desenvolvido para **simular e demonstrar diversos erros de programação e problemas comuns em sistemas operacionais**, permitindo que alunos, desenvolvedores e interessados observem, de forma prática e controlada, o comportamento de códigos que geram erros críticos como:

- 🧠 **Memory Leak** - Vazamento de memória
- 🏃‍♂️ **Race Condition** - Condições de corrida
- 🔒 **Deadlock** - Bloqueio mútuo
- 📊 **Stack Overflow** - Estouro de pilha
- 🔓 **Buffer Overflow** - Estouro de buffer
- 💥 **Segmentation Fault** - Violação de segmento

O projeto é desenvolvido em **C** com foco educacional.

---

## 🏗️ Estrutura do Projeto

```
projetoSO-/
├── 📁 include/                 # Arquivos de cabeçalho
│   └── erros.h                 # Declaração das funções de erro
├── 📁 src/                     # Código-fonte principal
│   ├── main.c                  # Menu interativo principal
│   └── erros.c                 # Implementação dos erros
├── 📄 README.md                # Documentação do projeto
```

---

## ✅ Status dos Erros

### 🟢 Implementados e Funcionais

| Erro                      | Descrição                                                       | Comportamento                              | Threads |
| ------------------------- | --------------------------------------------------------------- | ------------------------------------------ | ------- |
| 🧠 **Memory Leak**        | Demonstra alocação de memória que nunca é liberada              | Crescimento progressivo de memória         | ❌      |
| 🏃‍♂️ **Race Condition**     | Múltiplas threads acessam recurso compartilhado simultaneamente | Comportamento não-determinístico           | ✅      |
| 🔒 **Deadlock**           | Threads travadas esperando recursos umas das outras             | Bloqueio completo do programa              | ✅      |
| 🔓 **Buffer Overflow**    | Escrita de dados além do limite do buffer                       | Possível sobrescrição de memória adjacente | ❌      |
| 📊 **Stack Overflow**     | Excesso de chamadas recursivas ou alocação excessiva na stack   | Programa encerra abruptamente              | ❌      |
| 💥 **Segmentation Fault** | Acesso indevido à memória (endereços inválidos)                 | Falha de segmentação                       | ❌      |

> ⚠️ **Aviso de Segurança**: Os erros implementados podem afetar o desempenho do sistema. Execute com cautela e em ambiente controlado.

---

## 🚀 Como Usar

### 💻 Execução Local

#### Pré-requisitos

- GCC compiler
- Build tools (`build-essential` no Ubuntu/Debian)
- Sistema Linux ou WSL

#### Compilação e Execução

1. Clone o repositório:

   ```bash
   git clone https://github.com/seu-usuario/projetoSO-.git
   cd projetoSO-
   ```

2. Compile o projeto:

   ```bash
   gcc -o projetoSO src/main.c src/erros.c -Iinclude -lpthread
   ```

3. Execute o programa:

   ```bash
   ./projetoSO
   ```

4. Escolha uma das opções no menu interativo para simular o erro correspondente.

---

## 🎮 Interface do Menu

Após a execução, você verá:

```
====================================
      EMULADOR DE ERROS - RUNNER
====================================
1  - Memory Leak
2  - Race Condition
3  - Deadlock
4  - Segmentation Fault
5  - Stack Overflow
6  - Buffer Overflow
7  - Sair
Escolha uma opcao:
```

---

<div align="center">

</div>
