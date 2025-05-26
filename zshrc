unsetopt BEEP

alias cca="cc -Wall -Werror -Wextra"
alias ccc="cca -c"
alias vs="valgrind --leak-check=full -s --show-leak-kinds=all"
alias vsc="vs --trace-children=yes --track-fds=yes"
alias vmini="make && valgrind -s --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=/home/pierre/Documents/minishell/Moulinette/ignore_readline.supp ./minishell"
alias vh="valgrind --tool=helgrind -s"

alias gcl="git clone"
alias ga="git add . && gis"
alias gc="git commit -m"
alias gp="git push"
alias gis="git status"
alias gcm="git checkout master; git pull"
alias gcp="git checkout phillebr; git pull"
alias gmm="git merge master"
alias gmp="git merge phillebr"

gch ()
{
	git checkout "$1"
	git pull
}
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
alias rc="vim ~/.zshrc && zshs"
alias rmf="rm -rf"

alias re="make re"
alias clean="make clean"
alias f="make fclean"
alias m="make"
alias b="make bonus"

alias norm="norminette"
