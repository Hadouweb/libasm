; Prototype : int ft_isdigit(int c)
;

section .text
	global _ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp, rsp

	mov rax, 0		; Initialisation du resultat

	cmp rdi, '0'
	jl pas_digit
	cmp rdi, '9'
	jg pas_digit

	mov rax, 1		; C'est un digit, rectification du resultat

pas_digit:

	leave
	ret

