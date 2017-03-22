; Prototype : void *ft_memcpy(void *dest, const void *src, size_t n);
;

section .text
	global _ft_memcpy
_ft_memcpy:
	push rbp
	mov rbp, rsp

						; rdi = dest
						; rsi = src

	mov rax, rdi		; Pour retourner la destination
	
	mov rcx, rdx		; rcx = n; // Initialisation du compteur
	rep movsb			; Copie rcx octets de rsi vers rdi


	leave
	ret
