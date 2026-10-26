@echo off
setlocal

cd /d "%~dp0"

set "MENSAGEM=%~1"
if "%MENSAGEM%"=="" set "MENSAGEM=Implementa Parcial 3: ABB para ordenacao alfabetica"

echo.
echo === Publicando no GitHub ===
echo Repositorio: https://github.com/T1NG4/C0---4-.git
echo Mensagem: %MENSAGEM%
echo.

git status
if errorlevel 1 (
    echo Erro ao verificar status do git.
    pause
    exit /b 1
)

git add .
if errorlevel 1 (
    echo Erro ao adicionar arquivos.
    pause
    exit /b 1
)

git commit -m "%MENSAGEM%"
if errorlevel 1 (
    echo Nenhuma alteracao para commitar ou commit falhou.
    pause
    exit /b 1
)

git push -u origin main
if errorlevel 1 (
    echo Erro ao publicar no GitHub.
    pause
    exit /b 1
)

echo.
echo Publicacao concluida com sucesso.
echo.

pause
endlocal
