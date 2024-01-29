section .text
    global test

test:
    mov eax, 42 ; Placer la valeur 42 dans le registre eax (convention de retour)

    ; Terminer la fonction et retourner à l'appelant
    ret