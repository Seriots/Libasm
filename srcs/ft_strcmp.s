section .text
	global ft_strcmp

ft_strcmp:
	; Prototype (const char *s1, const char *s2)

	mov rcx, 0 ; initialisation du compteur

.loop:
	movzx r10, byte [rsi + rcx]
	movzx r11, byte [rdi + rcx]

	cmp r11, 0 ; regarde si le caractere a la position rdi (addr de str) + rcx == 0
	je    .end ; si oui, on sort de la boucle

	cmp r10, 0 ; regarde si le caractere a la position rsi (addr de str) + rcx == 0
	je    .end ; si oui, on sort de la boucle


    cmp r11, r10 ; regarde si le caractere a la position rdi (addr de str) + rcx == 0
    jne   .end ; si oui, on sort de la boucle

	add rcx, 1 ; si non on incremente le compteur
	jmp  .loop ; again

.end:

	mov rax, r11 ; on met le caractere dans rax
	sub rax, r10 ; on soustrait le caractere de rdi a celui de rsi
    ret