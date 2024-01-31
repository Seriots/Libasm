section .text
    global test

test:
    ; recupere la valeur d'entrée et la mettre dans eax
    xor rax, rax
    mov rax, [rdi + 12]

    ret