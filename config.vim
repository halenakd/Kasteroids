" Insira as configurações abaixo em seu arquivo ~/.vimrc

au BufNewFile,BufRead {*.cpp,*.cc,*.h,*.hpp}
    \set autoindent |
    \set number |               " turn on line numbering
    \set enc=utf-8 |            " encoding with UTF-8
    \set fenc=utf-8 |
    \set termencoding=utf-8 |
    \set smartindent |          " intelligent indentation for C
    \set tabstop=4 |            " tab width is 4 spaces
    \set softtabstop=4 |        " tab width in insert mode is 4 spaces
    \set shiftwidth=4 |         " indent with 4 spaces
    \set expandtab |            " expand tab for spaces
    \set textwidth=79 |         " wrap lines at 80
    \set showmatch              " highlight matching braces 
    \set ruler 				    " show line and column
