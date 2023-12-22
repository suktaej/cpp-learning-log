call plug#begin('~/.vim/plugged')
Plug 'folke/tokyonight.nvim', { 'branch': 'main' }
Plug 'scrooloose/nerdtree'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'thaerkh/vim-indentguides'
Plug 'machakann/vim-highlightedyank'
Plug 'osyo-manga/vim-anzu'
Plug 'majutsushi/tagbar'
Plug 'blueyed/vim-diminactive' 
"Plug 'sunjon/shade.nvim'
Plug 'xolox/vim-misc'
Plug 'xolox/vim-easytags'  
Plug 'airblade/vim-gitgutter'
Plug 'tpope/vim-fugitive'
Plug 'frazrepo/vim-rainbow'
Plug 'Raimondi/delimitMate'  
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'majutsushi/tagbar'
Plug 'easymotion/vim-easymotion'
Plug 'terryma/vim-multiple-cursors'
Plug 'chrisbra/NrrwRgn'
Plug 'pangloss/vim-simplefold'
Plug 'morhetz/gruvbox'
"Plug 'OmniSharp/omnisharp-vim'
"Plug 'dense-analysis/ale'
"Plug 'ctrlpvim/ctrlp.vim'
"Plug 'preservim/vimux'
"Plug 'xuhdev/SingleCompile'

Plug 'vim-syntastic/syntastic' "syntax check plugin
Plug 'altercation/vim-colors-solarized'
Plug 'psliwka/vim-smoothie'
"Plug 'junegunn/goyo.vim'

"Plug 'mattn/emmet-vim' "html/css auto complete
"Plug 'pangloss/vim-javascript' "javascript higlight
"Plug 'neoclide/coc.nvim', {'tag': '*', 'do': { -> coc#util#install()}}
call plug#end()

"let g:coc_disable_startup_warning = 1

"let g:diminactive_use_syntax = 1

"let g:indent_guides_enable_on_vim_startup = 1
let g:indent_guides_start_level = 2
let g:indent_guides_guide_size = 1
"hi IndentGuidesOdd  ctermbg=black
"hi IndentGuidesEven ctermbg=darkgrey

let delimitMate_expand_cr=1

let g:coc_disable_startup_warning = 1

let g:airline_powerline_fonts = 1 
let g:airline#extensions#tabline#enabled = 1

let g:SimpylFold_docstring_preview=1
set foldenable          " enable folding
set foldlevelstart=10   " open most folds by default
set foldnestmax=10      " 10 nested fold max
set foldmethod=indent   " fold based on indent level

"nmap <F9> :SCCompile<cr>
"nmap <F10> :SCCompileRun<cr>

"Syntastic
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
let g:syntastic_loc_list_height = 6

let g:syntastic_cpp_compiler = "g++"
let g:syntastic_cpp_compiler_options = "-std=c++17"
let g:syntastic_c_compiler_options = "-std=c11"
"let g:syntastic_cpp_compiler_options = "-std=c++17 -Wall -g -Wextra -Wpendantic
"let g:syntastic_c_compiler_options = "-std=c11 -Wall -g -Wextra -Wpendantic

let g:easytags_syntax_keyword = 'always'

let g:solarized_termcolors=256
"let g:OmniSharp_server_stdio = 0

"Goyo
"nnoremap <F4> :Goyo <CR>
"function! s:goyo_enter()
"  set noshowmode
"  set noshowcmd
"  set scrolloff=999
"  set number
"  set rnu
"  " ...
"endfunction
"
"function! s:goyo_leave()
"  set showmode
"  set showcmd
"  set scrolloff=999
"  " ...
"endfunction
"
"autocmd! User GoyoEnter nested call <SID>goyo_enter()
"autocmd! User GoyoLeave nested call <SID>goyo_leave()

"Coc.nvim Tab key binding
inoremap <silent><script><expr> <Tab> pumvisible() ? "\<C-y>" : "\<Tab>"

set number
set relativenumber
set ruler
set title

set cindent
set autoindent
set smartindent

set tabstop=4
set shiftwidth=4
set softtabstop=4

set hlsearch
set ignorecase
set smartcase
set showmatch

"set cursorline

set laststatus=2
set statusline=%F\ %y%m%r\ %=Line:\ %l/%L\ [%p%%]\ Col:%c\ Buf:%n

set mouse=a

set clipboard+=unnamedplus

if has("syntax")
        syntax on
endif
set t_Co=256
set background=dark
"colorscheme jellybeans
"colorscheme tokyonight-storm
"colorscheme gruvbox
colorscheme solarized

filetype indent on

imap <A-h> <Left>
imap <A-j> <Down>
imap <A-k> <Up>
imap <A-l> <Right>
imap <A-u> <Home>
imap <A-o> <End>
imap <A-d> <BS>
imap <A-f> <Del>

if has('nvim')
    :tnoremap <A-h> <C-\><C-n><C-w>h
    :tnoremap <A-j> <C-\><C-n><C-w>j
    :tnoremap <A-k> <C-\><C-n><C-w>k
    :tnoremap <A-l> <C-\><C-n><C-w>l
	:tnoremap <C-w> <C-\><C-n><C-w>
endif
:nnoremap <A-h> <C-w>h
:nnoremap <A-j> <C-w>j
:nnoremap <A-k> <C-w>k
:nnoremap <A-l> <C-w>l

nnoremap <C-Left> :bprevious<CR>
nnoremap <C-Right> :bnext<CR>
nnoremap <C-Up> :bfirst<CR>
nnoremap <C-Down> :blast<CR>
