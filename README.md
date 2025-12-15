# 🧪 Tutorial de Testes Unitários em C com μTest (uTest)

Este repositório contém um **tutorial prático e completo** para configuração e uso de **testes unitários em C no Windows**, utilizando:

- **μTest (uTest / utest.h)** — framework de testes unitários em C
- **MSYS2 (MINGW64 ou UCRT64)** — ambiente de compilação
- **GCC** — compilador C
- **Visual Studio Code** — editor de código

O projeto é indicado para **estudantes, iniciantes e desenvolvedores** que desejam aplicar testes unitários em projetos C, incluindo firmware, bibliotecas e aplicações simples.

---

## 🎯 Objetivo

- Configurar um ambiente de testes unitários em C no Windows
- Estruturar um projeto C de forma organizada
- Implementar uma biblioteca simples (calculadora)
- Criar e executar testes unitários com **μTest**
- Compilar e executar os testes usando **GCC no MSYS2**

---

## 🧰 Tecnologias Utilizadas

- **Linguagem:** C (C99 ou superior)
- **Framework de testes:** μTest (`utest.h`)
- **Compilador:** GCC (MSYS2)
- **Editor:** Visual Studio Code
- **Sistema Operacional:** Windows

---

## 📂 Estrutura do Projeto

```text
PROJETO_AUTO_TEST/
|-- inc/
|   |-- calc.h
|   |-- utest.h
|-- src/
|   |-- calc.c
|-- tests/
|   |-- test_calc.c
|-- Makefile
