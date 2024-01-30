section .text
    global test

test:
    ; recupere la valeur d'entrée et la mettre dans eax

    ; Convertir le flottant (xmm0) en entier et ajouter aux entiers
    cvttss2si rax, xmm0

    add rax, rdi
    add rax, rsi
    add rax, rdx

    ; Terminer la fonction et retourner à l'appelant
    ret