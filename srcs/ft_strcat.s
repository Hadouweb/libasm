section .text
	global _ft_strcat

_ft_strcat:
	push	rbp
	mov		rbp, rsp
	mov		rax, rdi		; rax = le premier param (char *dst)
	mov		rcx, rdi		; rcx = char *dst (pour ne pas toucher au debut du ptr de dst)
	mov		rdx, rsi		; rdx = le second param (char *src)

loop_end_dst:
	cmp		[rcx], byte 0	; compare *dst et 0
	je		loop_fill		; sortir et aller vers le label de remplissage de dst
	inc		rcx				; dst++
	jmp		loop_end_dst	; retour vers le debut de la boucle

loop_fill:
	mov		r8b, [rdx]		; registre de 8 octects = *src
	cmp		r8b, byte 0		; compare *src et 0
	je		end
	mov		[rcx], r8b		; *dst = *src
	inc		rcx				; dst++
	inc		rdx				; src++
	jmp		loop_fill		; retour vers le debut de la boucle

end:
	mov		[rcx], byte 0 	; *dst = '\0'.
	leave
	ret						; le registre rax est utilise comme valeur de retour
