I have been trying to fix the memory leaks in this program constantly. The memory leaks all originate from my node_init and
insert_node functions. I cant figure out what is being allocated and lost at the end of the program, but valgrind
shows that the memory leaks only come from those functions. The two functions are only called in the main.c file in the evil_hangman
function. 
