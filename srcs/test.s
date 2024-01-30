section .text
    global test

test:
    ; recupere la valeur d'entrée et la mettre dans eax


    movzx rax, byte [rsp + 8]
    add rax, rdi
    add rax, rsi
    add rax, rdx
    add rax, rcx
    add rax, r8
    add rax, r9
    movzx rbx, byte [rsp + 16]
    add rax, rbx


    ; Terminer la fonction et retourner à l'appelant
    ret