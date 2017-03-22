; Prototype : int ft_isascii(int c)
; Notes :
; - Si le resultat d'une operation (ex : and) donne zero, le flag z est set
; - jz execute le saut si le flag z est set
;

section .text
	global _ft_isascii

_ft_isascii:
	push rbp
	mov rbp, rsp

	mov rax, 0					; Initialisation du resultat a 0

	and rdi, 0xffffffffffffff80	; z = ((c & 0xffffff80) == 0) ? 1 : 0;
	jnz	fin						; if ( ! z) goto fin; // c n'est pas ascii

	mov rax, 1					; met le resultat a 1

fin:

	leave
	ret
