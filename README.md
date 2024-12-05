# Tabela Hash - Professor Lucas

# Exercício: Implementação de Lista Telefônica com Hash Table

## Descrição

Você deverá implementar uma aplicação em C ou C++ que funcione como uma lista telefônica. A aplicação deverá utilizar uma tabela hash para armazenar pares de dados (nome e número de telefone) em memória, possibilitando uma busca rápida pelo número de telefone associado a um nome específico.

## Objetivo

Praticar o uso de tabelas hash para resolver problemas de indexação e busca eficiente. O aluno deve compreender e implementar uma estratégia de hash, bem como lidar com colisões.

## Requisitos

1. **Estrutura de Dados (Tabela Hash)**

   - A lista telefônica deve ser implementada usando uma tabela hash. Utilize uma função hash para associar cada nome a um índice na tabela.
   - Lide com colisões de dados, utilizando a técnica de _encadeamento_ (listas ligadas) ou _endereçamento aberto_ (linear probing, quadratic probing, etc.), conforme sua escolha.

2. **Armazenamento em Memória**

   - O programa deve armazenar todos os dados em memória, sem uso de banco de dados ou arquivos externos.

3. **Funcionalidades da Lista Telefônica**

   - **Adicionar novo contato:** Permitir que o usuário insira um nome e um número de telefone para adicioná-los à tabela hash.
   - **Buscar contato:** Através de um nome fornecido pelo usuário, buscar o número de telefone correspondente e exibir na tela.
   - **Remover contato:** Permitir que o usuário remova um contato, se ele existir na lista.
   - **Mostrar todos os contatos:** Exibir todos os contatos armazenados na tabela hash (nome e número).

4. **Interface do Usuário**

   - O programa deve ter uma interface simples de console, onde o usuário pode escolher as opções:
     - `1` - Adicionar contato
     - `2` - Buscar contato por nome
     - `3` - Remover contato
     - `4` - Exibir todos os contatos
     - `0` - Sair

5. **Medição de Desempenho**

   - Calcule e exiba o tempo médio de busca e inserção de um contato (em milissegundos). Isso permitirá aos alunos compreenderem a eficiência da tabela hash em operações de busca e inserção.

6. **Tratamento de Erros**
   - Caso o usuário tente buscar ou remover um contato que não existe, exibir uma mensagem de erro apropriada.
   - Caso de duplicidade de nomes (se desejado, permita a inserção de múltiplos números para um mesmo nome ou apenas um).

## Exemplo de Execução

```plaintext
Escolha uma opção:
1 - Adicionar contato
2 - Buscar contato por nome
3 - Remover contato
4 - Exibir todos os contatos
0 - Sair

Digite uma opção: 1
Nome: Maria
Telefone: 12345
Contato adicionado com sucesso.

Digite uma opção: 2
Nome: Maria
Telefone de Maria: 12345 (tempo de busca: 0.02 ms)
```



## Funcionalidades

     1 - Adicionar contato
![image](https://github.com/user-attachments/assets/78f3d06e-ebd3-426f-8c7b-a9239a0de842)
     
     2 - Buscar contato por nome
![image](https://github.com/user-attachments/assets/c45b5cc1-8e7a-4a89-b427-8e4730346ada)
    
     2 - Buscar contato inexistente por nome
![image](https://github.com/user-attachments/assets/0f75d8b0-246b-4860-8ee4-62fe364c0130)
    
     3 - Remover contato inexistente
![image](https://github.com/user-attachments/assets/fc3a246f-810b-4201-b96d-5d250a4cde04)

     3 - Remover contato   
![image](https://github.com/user-attachments/assets/a52511d5-1434-4406-9556-3ed7b0c918fd)

     4 - Exibir todos os contatos (antes da remoção)
![image](https://github.com/user-attachments/assets/24275e9e-da4a-4b52-9895-352f498b3c1b)

     4- Exibir todos os contatos (depois da remoção)
![image](https://github.com/user-attachments/assets/2c4c5d01-bd8e-41ca-8d72-1a420d87c368)
     
     0 - Sair
![image](https://github.com/user-attachments/assets/7d07777e-9da2-42b6-bfee-6e93b83b526a)


