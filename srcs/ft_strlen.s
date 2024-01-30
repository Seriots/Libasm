section .text
    global ft_strlen

ft_strlen:
    ; Argument de la fonction
    ; rdi: pointeur vers une chaîne de caractères (char *)
    ; Retourne la première lettre de la chaîne en sortie (dans al)

    ; Vérifier si le pointeur est nul
	mov rcx, 0

.loop:
    cmp byte [rdi + rcx], 0
    je   .end

	add rcx, 1
	jmp  .loop

.end:
	mov rax, rcx
    ret