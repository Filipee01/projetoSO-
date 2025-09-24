# Emulador de Erros de Sistema Operacional - projetoSO-

<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

</div>

---

## Integrantes do Grupo

- **Bruno Almeida dos Santos**
- **Luiz Filipe Santos de Souza**
- **Caio Eduardo Ferreira dos Santos**

---

## 📋 Divisão de Tarefas

| Atividade                                                | Responsável                              |
| -------------------------------------------------------- | ---------------------------------------- |
| Implementação do erro de Stack Overflow                  | Luiz Filipe                              |
| Implementação do erro de Memory Leak                     | Luiz Filipe                              |
| Implementação do erro de Segmentation Fault              | Bruno Almeida                            |
| Implementação do erro de Buffer Overflow                 | Bruno Almeida                            |
| Implementação do erro de Condição de Corrida             | Caio Eduardo                             |
| Implementação do erro de Deadlock                        | Caio Eduardo                             |
| Criação de estrutura de pastas do projeto                | Luiz Filipe                              |
| Desenvolvimento dos arquivos .c e .h                     | Luiz Filipe, Caio Eduardo, Bruno Almeida |
| Documentação do projeto (README e comentários no código) | Luiz Filipe, Bruno Almeida, Caio Eduardo |

---

## Descrição do Projeto

Este projeto foi desenvolvido como uma **ferramenta educacional interativa** para demonstrar e simular diversos tipos de erros críticos que podem ocorrer em sistemas operacionais e programação de baixo nível.

### Objetivo Educacional

O emulador permite que estudantes, desenvolvedores e profissionais da área observem, de forma **prática e controlada**, o comportamento de códigos que geram erros críticos, incluindo:

- **Stack Overflow** - Esgotamento da pilha de execução
- **Segmentation Fault** - Violação de acesso à memória
- **Buffer Overflow** - Estouro de buffer
- **Memory Leak** - Vazamento de memória
- **Race Condition** - Condições de corrida entre threads
- **Deadlock** - Bloqueio mútuo entre processos

### Características Técnicas

- **Linguagem**: C (ANSI C99)
- **Threading**: POSIX Threads (pthread)
- **Plataforma**: Multiplataforma (Windows, Linux, macOS)
- **Propósito**: Educacional e demonstrativo

> **⚠️ Aviso de Segurança**: Este projeto simula erros que podem afetar o desempenho do sistema e causar travamentos. Execute sempre em ambiente controlado e salve seu trabalho antes dos testes.

---

## Detalhamento Técnico dos Erros

### 1. Stack Overflow

- **Implementação**: Recursão infinita que esgota a pilha de execução
- **Demonstração**: Função que chama a si mesma continuamente
- **Resultado**: Programa termina com erro de segmentação

### 2. Segmentation Fault

- **Implementação**: Tentativa de acesso a ponteiro NULL
- **Demonstração**: Desreferenciamento de ponteiro não inicializado
- **Resultado**: Violação de acesso à memória

### 3. Buffer Overflow

- **Implementação**: Escrita além dos limites de um array
- **Demonstração**: Loop que escreve 10 elementos em buffer de 5
- **Resultado**: Corrupção de memória adjacente

### 4. Memory Leak

- **Implementação**: Alocação contínua sem liberação de memória
- **Demonstração**: Alocação de 1 milhão de inteiros sem `free()`
- **Resultado**: Crescimento contínuo do uso de memória

### 5. Race Condition (Condição de Corrida)

- **Implementação**: Duas threads incrementando variável compartilhada
- **Demonstração**: Acesso simultâneo sem sincronização
- **Resultado**: Valor final incorreto devido à concorrência

### 6. Deadlock

- **Implementação**: Duas threads travando mutexes em ordem diferente
- **Demonstração**: Thread 1 trava M1→M2, Thread 2 trava M2→M1
- **Resultado**: Bloqueio mútuo permanente

---

## Estrutura do Projeto

```
projetoSO-/
├── 📁 include/                 # Arquivos de cabeçalho
│   └── erros.h                 # Declaração das funções de erro
├── 📁 src/                     # Código-fonte principal
│   ├── main.c                  # Menu interativo principal
│   ├── erros.c                 # Implementação dos erros
│   └── Emulador_erros          # Executável compilado
├── 📄 README.md                # Documentação do projeto
└── 📁 .git/                    # Controle de versão Git
```

---

## Status dos Erros

### Implementados e Funcionais

| Erro                   | Descrição                                                       | Comportamento                              |
| ---------------------- | --------------------------------------------------------------- | ------------------------------------------ |
| **Stack Overflow**     | Excesso de chamadas recursivas que esgotam a pilha              | Programa encerra abruptamente              |
| **Segmentation Fault** | Acesso indevido à memória (endereços inválidos)                 | Falha de segmentação                       |
| **Buffer Overflow**    | Escrita de dados além do limite do buffer                       | Possível sobrescrição de memória adjacente |
| **Memory Leak**        | Demonstra alocação de memória que nunca é liberada              | Crescimento progressivo de memória         |
| **Race Condition**     | Múltiplas threads acessam recurso compartilhado simultaneamente | Comportamento não-determinístico           |
| **Deadlock**           | Threads travadas esperando recursos umas das outras             | Bloqueio completo do programa              |

> **Aviso de Segurança**: Os erros implementados podem afetar o desempenho do sistema. Execute com cautela e em ambiente controlado.

---

## Como Usar

### Execução Local

#### Pré-requisitos

- **GCC compiler** (MinGW-w64 no Windows, ou WSL)
- **Build tools** (Visual Studio Build Tools ou WSL)
- **Sistema Windows** com PowerShell ou WSL/Linux

#### Compilação e Execução

**Opção 1: Windows com MinGW-w64**

1. Clone o repositório:

   ```powershell
   git clone https://github.com/Filipee01/projetoSO-.git
   cd projetoSO-
   ```

2. Compile o projeto:

   ```powershell
   gcc -o Emulador_erros src/main.c src/erros.c -Iinclude -lpthread
   ```

3. Execute o programa:
   ```powershell
   .\Emulador_erros.exe
   ```

**Opção 2: WSL (Windows Subsystem for Linux)**

1. Clone e navegue para o diretório:

   ```bash
   git clone https://github.com/Filipee01/projetoSO-.git
   cd projetoSO-
   ```

2. Compile o projeto:

   ```bash
   gcc -o Emulador_erros src/main.c src/erros.c -Iinclude -lpthread
   ```

3. Execute o programa:

   ```bash
   ./Emulador_erros
   ```

4. Escolha uma das opções no menu interativo para simular o erro correspondente.

---

## Interface do Menu

Após a execução, você verá:

```
====================================

	  EMULADOR DE ERROS

====================================

Escolha o erro a executar:
1 - Stack Overflow
2 - Segmentation Fault
3 - Buffer Overflow
4 - Memory Leak
5 - Condição de Corrida
6 - Deadlock
escolha uma opcao :
```

4. Escolha uma das opções no menu interativo para simular o erro correspondente.

---

## Resultados Esperados da Execução

### Para Apresentação do Projeto

Quando executar cada erro, você poderá demonstrar:

**Stack Overflow (Opção 1)**

- Mensagens de contagem crescente até o programa travar
- Demonstra limitações da pilha de execução

**Segmentation Fault (Opção 2)**

- Mensagem de erro instantânea
- Programa termina abruptamente demonstrando proteção de memória

**Buffer Overflow (Opção 3)**

- Execução aparentemente normal
- Demonstra vulnerabilidade silenciosa de segurança

**Memory Leak (Opção 4)**

- Alocação progressiva com mensagens informativas
- Use o gerenciador de tarefas para mostrar crescimento de memória

**Race Condition (Opção 5)**

- Resultado final incorreto (menor que 200.000)
- Execute múltiplas vezes para mostrar variação

**Deadlock (Opção 6)**

- Programa "congela" sem resposta
- Demonstra bloqueio permanente entre threads

---

---

## Conclusão

Este emulador de erros de sistema operacional oferece uma experiência prática e educativa sobre os principais problemas que podem afetar aplicações de baixo nível. Cada erro foi implementado de forma didática para facilitar o entendimento dos conceitos fundamentais de sistemas operacionais.

### Contribuições Acadêmicas

- **Visualização prática** de conceitos teóricos
- **Ambiente controlado** para experimentação
- **Demonstração interativa** de vulnerabilidades
- **Ferramenta de ensino** para cursos de SO

### Tecnologias Utilizadas

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Threads](https://img.shields.io/badge/POSIX-Threads-orange?style=for-the-badge)
![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)

---

<div align="center">

**Desenvolvido para fins educacionais em Sistemas Operacionais**

_Universidade - Disciplina de Sistemas Operacionais_

</div>
