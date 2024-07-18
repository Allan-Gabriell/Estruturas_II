# Como saber o número de vezes que passamos por um dado breakpoint

        allan@allan-Nitro-AN515-58:~/Estruturas_II/exercicios$ gdb ex_1_quest_1
        GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
        Copyright (C) 2022 Free Software Foundation, Inc.
        License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
        This is free software: you are free to change and redistribute it.
        There is NO WARRANTY, to the extent permitted by law.
        Type "show copying" and "show warranty" for details.
        This GDB was configured as "x86_64-linux-gnu".
        Type "show configuration" for configuration details.
        For bug reporting instructions, please see:
        <https://www.gnu.org/software/gdb/bugs/>.
        Find the GDB manual and other documentation resources online at:
        <http://www.gnu.org/software/gdb/documentation/>.

        For help, type "help".
        Type "apropos word" to search for commands related to "word"...
        Reading symbols from ex_1_quest_1...
        (gdb) b main
        Ponto de parada 1 at 0x1170: file ex_1_quest_1.c, line 13.
        (gdb) b fibonacci 
        Ponto de parada 2 at 0x1139: file ex_1_quest_1.c, line 5.
        (gdb) d
        Apagar todos os pontos de parada? (y or n) y
        (gdb) b fibonacci
        Ponto de parada 3 at 0x1139: file ex_1_quest_1.c, line 5.
        (gdb) d
        Apagar todos os pontos de parada? (y or n) y
        (gdb) b fibonacci if n == 5
        Ponto de parada 4 at 0x1139: file ex_1_quest_1.c, line 5.
        (gdb) info breakpoints 
        Num     Type           Disp Enb Address            What
        4       breakpoint     keep y   0x0000000000001139 in fibonacci at ex_1_quest_1.c:5
        stop only if n == 5
        (gdb) ignore 4 1000
        Will ignore next 1000 crossings of breakpoint 4.
        (gdb) run
        Starting program: /home/allan/Estruturas_II/exercicios/ex_1_quest_1 
        [Thread debugging using libthread_db enabled]
        Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
        [Inferior 1 (process 10102) exited normally]
        (gdb) info breakpoints 
        Num     Type           Disp Enb Address            What
        4       breakpoint     keep y   0x0000555555555139 in fibonacci at ex_1_quest_1.c:5
        stop only if n == 5
        breakpoint already hit 89 times
        ignore next 911 hits
        (gdb) quit