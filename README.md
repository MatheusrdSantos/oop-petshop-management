# PetFera

Este repositório consiste na implementação de um sistema de gerenciamento de PetShop em C++.
O PetFera é um petshop que comercializa animais silvestres e domésticos, portanto, necessita de uma equipe de tratadores e veterinários para garantir o bem estar dos animais. Toda a parte de gerenciamento dos animais e funcionários é feita através deste sistema.

## Instalação

Basta clonar o repositório e executar os comandos listados na seção seguinte.

## Como usar?

Na pasta raiz execute os seguintes comandos:

Compilar o PetFera
```
make

```
Compilar a biblioteca de exportação de dados
```
make linux
```
Executar
```
make run
```

## Funcionalidades

* Adicionar funcionário 
* Adicionar animal 
* Remover animal 
* Remover funcionário 
* Atualizar dados de um animal 
* Listar animais por funcionario 
* Listar animais por classe 
* Listar todos funcionarios 
* Listar todos animais

## Exportação dos dados
Para exportar os dados dos animais basta executar o arquivo `exportar` localizado em `build/lib`.
Os comandos de exportação seguem o seguinte padrão:
```
./build/lib/exportar -c <classe> -v <nome_do_veterinario> -t <nome_do_tratador> nomedoarquivo.csv
```
Os filtros -c, -v e -t são opcionais. Caso não especificados, todos os animais serão exportados.

## Bibliotecas de terceiros
* [CSVparser](https://github.com/rsylvian/CSVparser)

## License
[MIT](https://choosealicense.com/licenses/mit/)
