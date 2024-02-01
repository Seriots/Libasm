section .text
    global test

test:
    ; recupere la valeur d'entrée et la mettre dans eax
    mov rax, 10
    and rax, 0x80000000
    

    ret