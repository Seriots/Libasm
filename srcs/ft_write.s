section .text
    global ft_write

ft_write:
    ; Appel système pour écrire sur la sortie standard (1)
    mov rax, 1
    syscall             ; Appel système

    ret