set nocompatible
filetype plugin indent on

call plug#begin('~/.local/share/nvim/plugged')

"Edit
Plug 'mg979/vim-visual-multi'  "Multicursor
Plug 'tpope/vim-surround'
Plug 'preservim/nerdcommenter'  "Annotation
Plug 'tommcdo/vim-lion'                 "Line Alignment
Plug 'chrisbra/NrrwRgn'                 "파일 일부를 별도의 buffer에 저장
Plug 'vim-scripts/VisIncr'              "Visual mode에서 숫자를 순차적으로 증가

"Navigation
Plug 'scrooloose/nerdtree'
Plug 'easymotion/vim-easymotion'
Plug 'osyo-manga/vim-anzu'
"Plug 'majutsushi/tagbar'

"UI
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'thaerkh/vim-indentguides' "Indent line
Plug 'frazrepo/vim-rainbow'
"Plug 'pangloss/vim-simplefold'
"Plug 'psliwka/vim-smoothie'
"Plug 'blueyed/vim-diminactive'

"Syntax
Plug 'mattn/emmet-vim'  "HTML/CSS 약어코드완성
Plug 'neoclide/coc.nvim', {'branch': 'release'}
"coc.nvim이 정상설치 후 언어팩, 자동괄호 완성기능 설치
":CocInstall coc-pairs coc-git coc-snippets coc-json coc-pyright coc-clangd coc-html coc-css coc-tags

"Github
Plug 'airblade/vim-gitgutter'
Plug 'tpope/vim-fugitive'

"Colorscheme
Plug 'morhetz/gruvbox'
Plug 'folke/tokyonight.nvim'
Plug 'altercation/vim-colors-solarized'
Plug 'Mofiqul/vscode.nvim'
Plug 'nanotech/jellybeans.vim'

"ETC
"Plug 'ctrlpvim/ctrlp.vim'
"Plug 'antoinemadec/vim-verilog-instance'
"Plug 'vim-scripts/Quich-Filter'
call plug#end()

filetype indent on

" coc.nvim
" 자동완성 시 enter로 선택
" inoremap <expr> <CR> pumvisible() ? coc#_select_confirm() : "\<CR>"

" 자동완성 시 tab 선택
function! CheckBackspace() abort
  let col = col('.') - 1
  if col <= 0
    return v:true
  endif

  let prev = getline('.')[col - 1]

  return prev =~# '\s\|[;:,)\]}]'
endfunction

inoremap <silent><expr> <Tab>
      \ pumvisible() ? coc#_select_confirm() :
      \ coc#expandableOrJumpable() ?
      \ "\<C-r>=coc#rpc#request('doKeymap', ['snippets-expand-jump',''])\<CR>" :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()

inoremap <silent><expr> <S-Tab>
      \ pumvisible() ? "\<C-p>" : "\<C-h>"

" emmet-vim
let g:user_emmet_install_global = 0
autocmd FileType html,css EmmetInstall
let g:user_emmet_leader_key='<C-T>'

" Rainbow
let g:rainbow_active = 1

set number
set relativenumber
set ruler
set title
set cindent
set autoindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set hlsearch
set ignorecase
set smartcase
set showmatch
set cursorline
set laststatus=2
set mouse=a
set clipboard+=unnamedplus
set fileformats=unix,dos

"Colorscheme
syntax on
set background=dark
let g:gruvbox_contrast_dark = 'medium'
let g:gruvbox_italic = 0
colorscheme gruvbox

"keyMapping
let mapleader = " "
inoremap <C-h> <Left>
inoremap <C-j> <Down>
inoremap <C-k> <Up>
inoremap <C-l> <Right>

nnoremap <leader>d "_d

vnoremap <leader>d "_d
vnoremap <leader>p "_dP

function! ToggleBoolUnderCursor()
    let word = expand('<cword>')

    if word ==# 'true'
        execute 'normal! "_ciwfalse'
    elseif word ==# 'false'
        execute 'normal! "_ciwtrue'
    endif
endfunction

nnoremap <leader>c :call ToggleBoolUnderCursor()<CR>

"highlight
augroup highlight_yank
        autocmd!
        autocmd TextYankPost * silent! lua vim.highlight.on_yank()
augroup END
