unsetopt BEEP

alias cca="cc -Wall -Werror -Wextra"
alias ccc="cca -c"
alias vs="valgrind --leak-check=full -s --show-leak-kinds=definite"
alias vsc="vs --trace-children=yes --track-fds=yes"
alias vmini="make && valgrind -s --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=/home/pierre/Documents/minishell/Moulinette/ignore_readline.supp ./minishell"
alias vh="valgrind --tool=helgrind -s"

alias gcl="git clone"
alias ga="git add . && gis"
alias gc="git commit -m"
alias gp="git push"
alias gis="git status"

mdir ()
{
	mkdir "$1"
	cd "$1"
}
cdl ()
{
	cd "$1"
	ls
}
alias c="cd .. && pwd && ls"
zsha ()
{
	echo "$1" >> ~/.zshrc
	source ~/.zshrc
}
alias bp="bash --posix"
alias zshs="source ~/.zshrc"
alias norminette="ls"

alias gcm="git checkout main"
alias gcp="git checkout phillebr"
alias gmm="git merge main"
alias gmp="git merge phillebr"
alias desmume="~/emul/desmume-0.9.13/desmume/src/frontend/posix/gtk2/desmume"

alias melonDS="flatpak run net.kuribo64.melonDS"
