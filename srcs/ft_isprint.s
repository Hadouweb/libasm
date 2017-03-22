; Prototype : int ft_isprint(int c)
;

section .text
	global _ft_isprint

_ft_isprint:
	push rbp
	mov rbp, rsp

	mov rax, 0

	cmp rdi, 0x20
	jl pas_print
	cmp rdi, 0x7e
	jg pas_print

	mov rax, 1

pas_print:

	leave
	ret
