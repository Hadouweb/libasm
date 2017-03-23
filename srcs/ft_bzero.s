section .text
	global _ft_bzero

_ft_bzero:
	push    rbp
	mov     rbp, rsp 		; Sauvegarde de la pile pour preserver la pile de la fonction appelante
	mov		rax, rsi		; rsi correspond au second parametre (size_t n) on le place dans le registre rax pour pouvoir le comparer
	cmp		rax, 0			; Si (n == 0) cmp remplit les bits du registre EFLAGS
	je		end				; Jumb par rapport a l'une des valeurs de EFLAGS (si n == 0)

loop:						; do
	mov		[rdi], byte 0	; *s = 0
	inc		rdi				; s++
	dec		rax				; n--
	cmp		rax, 0			; cmp n et 0
	jg		loop			; while (n > 0)

end:
	leave					; retour le contexte de la pile pour la fonctione appelante == (mov esp, ebp | pop ebp)
	ret						; return
