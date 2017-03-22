; Prototype : int ft_tolower(int c)
;

section .text
	global _ft_tolower

_ft_tolower:
	push rbp
	mov rbp, rsp

	mov rax, rdi	; Copie c dans le resultat

	cmp rax, 'A'
	jl fin			; Si c'est inferieur a 'A' -> fin
	cmp rax, 'Z'
	jg fin			; Si c'est superieur a 'Z' -> fin

	add rax, 0x20	; Pour tout le reste, addition de 0x20 au resultat

fin:

	leave
	ret
