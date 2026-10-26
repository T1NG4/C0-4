# C0---4-

Dicionário de língua fictícia em C++ (Algoritmos III — INATEL).

O projeto armazena palavras em High Valyrian com significados em português e coordenadas no espaço 3D (100×100×100), utilizando um grafo para relacionar palavras e significados.

## Entregas implementadas

- **Parcial 1**: menu com opções a–g, cada uma em função dedicada
- **Parcial 2**: cadastro de palavras, grafo de adjacências, listagem de significados e sinônimos
- **Parcial 3**: listagem de palavras em ordem alfabética usando Árvore Binária de Busca (ABB)
- **Extra**: geração automática de coordenadas no cadastro

## Compilação (Windows / PowerShell)

Se o `dicionario.exe` estiver aberto, encerre o programa antes de compilar. Caso apareça `Permission denied`, use:

```powershell
Stop-Process -Name "dicionario" -Force
g++ -std=c++17 -Wall -Wextra -O0 -o dicionario.exe src/main.cpp src/palavra.cpp src/grafo.cpp src/dicionario.cpp src/menu.cpp
```

Comando completo recomendado (encerra o processo e recompila):

```powershell
Stop-Process -Name "dicionario" -ErrorAction SilentlyContinue; g++ -std=c++17 -Wall -Wextra -O0 -o dicionario.exe src/main.cpp src/palavra.cpp src/grafo.cpp src/dicionario.cpp src/menu.cpp
```

Com Make:

```bash
make
```

## Execução

```powershell
.\dicionario.exe
```

## Opções do menu

- **a)** Cadastrar palavra (fictícia + significado em português; coordenadas geradas automaticamente)
- **b)** Listar significados de uma palavra
- **c)** Listar sinônimos de uma palavra
- **d)** Listar palavras em ordem alfabética (usando Árvore Binária de Busca)
- **e–g)** Funcionalidades previstas para entregas futuras

### Exemplo de cadastro

```
a
Ambir
salmão
```

Saída esperada:

```
Coordenadas geradas automaticamente: (x, y, z)
Palavra cadastrada com sucesso.
```

## Vocabulário inicial

Palavras carregadas do [High Valyrian Dictionary](https://wiki.languageinvention.com/index.php?title=High_Valyrian_Dictionary), por exemplo:

- `Āegenka` / `Āegion` → ferro
- `Ajesurilaror` / `Ajesurilaros` → especiaria
- `Morghon` → morte

## Publicar no GitHub

Use o script `publicar.bat` na raiz do projeto:

```powershell
.\publicar.bat
```

Ou com mensagem de commit personalizada:

```powershell
.\publicar.bat "Implementa Parcial 2 do dicionario"
```

## Estrutura do projeto

```
src/
  main.cpp
  menu.cpp / menu.h
  grafo.cpp / grafo.h
  palavra.cpp / palavra.h
  dicionario.cpp / dicionario.h
template/
Makefile
publicar.bat
```
