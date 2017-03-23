section .text
	global _ft_isascii

_ft_isascii:
	push	rbp
	mov		rbp, rsp	; Sauvegarde de la pile
	mov		rax, 0		; int ret = 0
	and		rdi, ~0x7f	; & logique rdi & ...1111 1111 1000 0000
	jnz		end			; return 0 si l'operation logique and == 0 FLAGS ZF == 0
	mov		rax, 1		; return 1

end:
	leave
	ret
