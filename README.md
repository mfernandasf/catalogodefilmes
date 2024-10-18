# Sistema de Catálogo de Filmes 🎞️📽️

Este projeto implementa um sistema simples de catálogo de filmes em C. Ele permite ao usuário inserir, buscar, visualizar e excluir filmes de um catálogo usando uma lista duplamente encadeada. O código inclui um menu interativo que facilita a navegação pelas funcionalidades.

## Funcionalidades

- **Inserir Filme**: Permite adicionar novos filmes ao catálogo, com informações como título, categoria, duração e ano de lançamento.
- **Buscar Filme**: Permite buscar um filme específico pelo título.
- **Exibir Catálogo**: Exibe todos os filmes presentes no catálogo com suas informações detalhadas.
- **Excluir Filme**: Remove um filme do catálogo com base no título.
- **Menu Interativo**: Interface simples para interagir com as opções disponíveis.

## Estrutura do Projeto

O projeto é baseado em duas estruturas principais:

- **`filme`**: Estrutura que armazena as informações de um filme (título, categoria, duração e lançamento).
- **`No`**: Estrutura de nó da lista duplamente encadeada que armazena os filmes e seus ponteiros para o próximo e o anterior.

## Compilação e Execução

### Compilação

Para compilar o código, você pode usar um compilador de C como o `gcc`. Execute o seguinte comando no terminal:

```bash
gcc -o catalogo_filmes projeto_final.c
```

### Execução

Após a compilação, execute o programa com o comando:

```bash
./catalogo_filmes
```

## Uso do Programa

Ao executar o programa, o usuário verá um menu com as seguintes opções:

```bash
--------------MENU---------------------
1 - Inserir Filme
2 - Buscar Filme
3 - Exibir Catálogo
4 - Excluir Filme
0 - Sair
Escolha uma opção:
```

1. **Inserir Filme**: Digite as informações solicitadas (título, categoria, duração e ano de lançamento) para adicionar um novo filme ao catálogo.
2. **Buscar Filme**: Digite o título do filme que deseja buscar no catálogo.
3. **Exibir Catálogo**: Exibe todos os filmes disponíveis no catálogo.
4. **Excluir Filme**: Digite o título do filme que deseja excluir.
5. **Sair**: Encerra o programa.

## Exemplo de Uso

Ao iniciar o programa, alguns filmes já estão pré-carregados no catálogo. Aqui estão alguns exemplos de filmes incluídos:

- O Poderoso Chefão (1972)
- Forrest Gump (1994)
- A Origem (2010)
- Clube da Luta (1999)
- Matrix (1999)
- O Senhor dos Anéis: A Sociedade do Anel (2001)
- Vingadores: Ultimato (2019)
- Interestelar (2014)
- O Cavaleiro das Trevas (2008)
- Gladiador (2000)

O usuário pode adicionar novos filmes ou buscar/excluir os já existentes.

## Estrutura de Dados Utilizada

O sistema utiliza uma **lista duplamente encadeada** para armazenar os filmes. Isso facilita a inserção, remoção e busca de elementos, permitindo a navegação em ambas as direções da lista (do primeiro ao último filme e vice-versa).

## Funções Principais

- **`inserir_filme()`**: Insere um novo filme no catálogo.
- **`imprime_catalogo()`**: Exibe todos os filmes no catálogo.
- **`procura_filme()`**: Realiza a busca de um filme específico pelo título.
- **`excluir_filme()`**: Remove um filme do catálogo.
- **`menu_principal()`**: Controla a lógica do menu interativo, permitindo a escolha das opções disponíveis.

## Dependências

Este projeto não possui dependências externas. Apenas as bibliotecas padrão da linguagem C são utilizadas:

- `stdio.h`: Entrada e saída de dados.
- `stdlib.h`: Alocação de memória dinâmica.
- `string.h`: Manipulação de strings.

## Contribuição

Sinta-se à vontade para contribuir com este projeto, melhorando o código ou adicionando novas funcionalidades.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).

---

Com esse README, qualquer usuário que acesse seu projeto terá uma visão clara de como usá-lo, suas funcionalidades e como ele foi construído. Se precisar de mais ajustes ou informações, posso refinar o conteúdo!
