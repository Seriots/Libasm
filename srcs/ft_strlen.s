section .text
    global ft_strlen

ft_strlen:
    ; Prototype int (char *str)

	mov rcx, 0 ; initialisation du compteur

.loop:
    cmp byte [rdi + rcx], 0 ; regarde si le caractere a la position rdi (addr de str) + rcx == 0
    je   .end ; si oui, on sort de la boucle

	add rcx, 1 ; si non on incremente le compteur
	jmp  .loop ; again

.end:
	mov rax, rcx ; on met le compteur dans rax
    ret