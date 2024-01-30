section .text
    global string_test

string_test:
    ; recupere la valeur d'entrée et la mettre dans eax


    movzx rax, byte [rdi + 4]

    ; Copier la valeur (rdi + 1) à l'adresse (rdi + 0)
    mov [rdi + 1], rax

    movzx rax, byte [rdi + 9]

    ; Copier la valeur (rdi + 1) à l'adresse (rdi + 0)
    mov [rdi + 2], rax

    mov rax, rdi

    ; Terminer la fonction et retourner à l'appelant
    ret