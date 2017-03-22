; Prototype : void *ft_strdup(const char *s);
; Notes :
; - Les registres rdi et rdx font partit des registres qui peuvent etre modifie par un call
;

section .text
	global _ft_strdup
	extern _malloc

_ft_strdup:
	push rbp
	mov rbp, rsp

	mov rdx, rdi				; memorise le debut de la chaine dans rdx
	mov rcx, 0xffffffffffffffff	; Le plus grand uint64
	mov al, 0					; al = '\0';
	repne scasb					; while (*rdi != al && rcx != 0) {rdi++; rcx--;} rdi++;
	sub rdi, rdx				; length + 1 = fin + 1 - debut

	push rdi					; Sauvegarde de rdi susceptible d'etre modifie par malloc
	push rdx					; Sauvegarde de rdx susceptible d'etre modifie par malloc

	call _malloc				; rax = malloc (rdi); // rdi = length + 1

	pop rdx						; Recuperation de rdx sauvegarde avant malloc
	pop rdi						; Recuperation de rdi sauvegarde avant malloc

	mov rcx, rdi				; Initialisation du compteur rcx, avec rdi
	mov rsi, rdx				; rsi = s; // Source
	mov rdi, rax				; rdi = "adresse du malloc"; // Destination
	
	rep movsb					; Copie rcx octets de rsi vers rdi

								; rax contient l'adresse du malloc

	leave
	ret
