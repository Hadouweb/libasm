section .text
	global _ft_tolower

_ft_tolower:
	push	rbp
	mov		rbp, rsp	; Sauvegarde de la pile
	mov		rax, rdi	; valeur de retour == param c (rdi)
	cmp		rax, 'A'	; Si < 'a'
	jl		end			; return c
	cmp		rax, 'Z'	; Si > 'z'
	jg		end			; return c
	add		rax, 32		; c = c - 32

end:
	leave
	ret
