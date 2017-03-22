; Prototype : size_t ft_strlen(const char *s)
; Notes :
; - http://x86.renejeschke.de/html/file_module_x86_id_279.html
;

section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	mov rdx, rdi				; memorise le debut de la chaine dans rdx
	mov rcx, 0xffffffffffffffff	; Le plus grand uint64
	mov al, 0					; al = '\0';
	repne scasb					; while (*rdi != al && rcx != 0) {rdi++; rcx--;} rdi++;
	dec rdi						; rdi--;
	sub rdi, rdx				; length = fin - debut
	mov rax, rdi				; resultat

	leave
	ret

