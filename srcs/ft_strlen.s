section .text
	global _ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp, rsp	; Suavegarde de la pile

end:
	leave
	ret
