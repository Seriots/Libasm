section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	; Protoype char * (const char *);

	; mov rsi, rdi; save rdi
 	push rdi; save rdi
	call ft_strlen; rax = strlen(rdi)
	add rax, 1
	mov rdi, rax; malloc's first (and only) parameter: number of bytes to allocate
	call malloc

	mov rdi, rax
	pop rsi; restore rdi
	; mov rsi, rsi; save rdi
	call ft_strcpy; strcpy(rdi, rsi)

	ret
