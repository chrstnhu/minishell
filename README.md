# Minishell

Group project 42 school

Write a program that does the same as the shell (based on bash)

## Collaborators
* github : [chrstnhu](https://github.com/chrstnhu)
* github : [haiyingluo](https://github.com/haiyingluo)

## Run

Git clone and go to project directory :

```bash
git clone git@github.com:chrstnhu/minishell.git && cd minishell
```

Download minilibx :
```bash
git clone https://github.com/42Paris/minilibx-linux
```

Make :
```bash
make
```

Run minishell :
```bash
./minishell
```

Run valgrind (ignore readline leak):
```bash
valgrind --suppressions=ignore_readline.supp ./minishell
```

## Rules
* Display a prompt when waiting for a new command
* Have a working history
* Not interpret unclosed quotes, backslash ( \ ) or semicolon ( ; )
### Handle
* Handle single quote ( ' ), double quote ( " )
* Handle environment variables ( $ ) and exit status ( $? )
* Handle ctrl-C, ctrl-D, ctrl-\

### Implement
* Implement redirection input ( < ), delimiter ( << ), output ( > ), output in append mode ( >> )
* Implement pipes ( | )
* Implement builtins : echo, cd, pwd, export, unset, env, exit

### Bonus
* Implement wildcards ( * )
