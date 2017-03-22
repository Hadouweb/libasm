; Prototype : int ft_toupper(int c)
;

section .text
	global _ft_toupper

_ft_toupper:
	push rbp
	mov rbp, rsp

	mov rax, rdi	; Copie c dans le resultat

	cmp rax, 'a'
	jl fin			; Si c'est inferieur a 'a' -> fin
	cmp rax, 'z'
	jg fin			; Si c'est superieur a 'z' -> fin

	sub rax, 0x20	; Pour tout le reste, soustraction de 0x20 au resultat

fin:

	leave
	ret
