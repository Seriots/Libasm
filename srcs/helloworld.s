
section .text
    global hello_world

hello_world:
    ; Appel système pour écrire sur la sortie standard (1)
    mov rax, 1
    syscall             ; Appel système

    ret


