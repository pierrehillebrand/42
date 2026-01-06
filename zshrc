unsetopt BEEP
alias l="ft_lock"
alias g="cd ~/goinfre; pwd"
alias gg="rm -rf ~/.config/google-chrome/Singleton*"

alias cca="cc -Wall -Werror -Wextra"
alias gca="c++ -Wall -Werror -Wextra -std=c++98"
alias ccc="cca -c"
alias vs="valgrind --leak-check=full -s --show-leak-kinds=all"
alias vsc="vs --trace-children=yes --track-fds=yes"
alias vmini="make && valgrind -s --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=/goinfre/phillebr/mini/readline.supp ./minishell"
alias vh="valgrind --tool=helgrind -s"

alias ga="git add . && gis"
alias gc="git commit -m"
alias gp="git push"
alias gis="git status"
alias gcm="git checkout main; git pull"
alias gcp="git checkout phillebr; git pull"
alias gmm="git merge main"
alias gmt="git merge thelee"
alias gmp="git merge phillebr"

gl ()
{
	git clone $1 $2
	cd $2
}
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

alias norm="clear && norminette"
export PATH=/home/phillebr/.local/funcheck/host:$PATH
