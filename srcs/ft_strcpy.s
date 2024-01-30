section .text
	global ft_strcpy

ft_strcpy:
	; Prototype (char *dest, char *src)
	
	mov rcx, 0 ; initialisation du compteur

.loop:
    cmp byte [rsi + rcx], 0 ; regarde si le caractere a la position rdi (addr de str) + rcx == 0
    je   .end ; si oui, on sort de la boucle

	movzx rax, byte [rsi + rcx]
	mov [rdi + rcx], rax ; on copie le caractere de str dans str2
	add rcx, 1 ; si non on incremente le compteur
	jmp  .loop ; again

.end:
	movzx rax, byte [rsi + rcx]
	mov [rdi + rcx], rax ; on copie le caractere de str dans str2
	mov rax, rdi ; on met le compteur dans rax
    ret