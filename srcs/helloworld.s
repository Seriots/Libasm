
section .text
    global hello_world

hello_world:
    ; Appel système pour écrire sur la sortie standard (1)
    mov eax, 4            ; Numéro du système pour write
    mov ebx, 1            ; Descripteur de fichier (1 pour la sortie standard)
    mov ecx, [rdi]  ; Adresse du message (deuxième argument)
    mov edx, [rsi]   ; Longueur du message (troisième argument)
    int 0x80              ; Appel système

    ; Appel système pour terminer le programme
    mov eax, 1            ; Numéro du système pour exit
    xor ebx, ebx          ; Code de retour 0
    int 0x80              ; Appel système

