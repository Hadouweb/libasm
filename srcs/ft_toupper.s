section .text
	global _ft_toupper

_ft_toupper:
	push    rbp
	mov		rbp, rsp        ; Sauvegarde de la pile
	mov		rax, rdi        ; valeur de retour == param c (rdi)
	cmp		rax, 'a'        ; Si < 'a'
	jl		end             ; return c
	cmp		rax, 'z'        ; Si > 'z'
	jg		end             ; return c
	sub		rax, 32         ; c = c - 32

end:
	leave
	ret
