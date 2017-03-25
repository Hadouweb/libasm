struc Mylink
	.prev: resb 8
	.next: resb 8
endstruc

struc Mylist
	.link: resb 16
	.head: resb 8
	.tail: resb 8
	.size: resb 8
endstruc

section .text
	global _ft_list_push_front

_ft_list_push_front:
	push	rbp
	mov		rbp, rsp
	mov		r9, rdi							; r9 = list
	mov		r10, rsi						; r10 = link
	cmp		r9, 0							; if list == NULL
	je		end								; return
	cmp		r10, 0							; if link == NULL
	je		end								; return ;
	cmp		qword [r9 + Mylist.tail], 0x0	; if list->tail == null
	je		no_tail					
	jmp		have_tail

no_tail:
	mov		[r9 + Mylist.head], r10			; list->head = link
	mov		[r9 + Mylist.tail], r10			; list->tail = link
	add		[r9 + Mylist.size], byte 1		; list->size++
	jmp 	end								; return ;

have_tail:
	mov		r11, [r9 + Mylist.head]			; r11 = list->head
	mov		[r11], r10,						; list->head->prev = link
	mov		[r10 + Mylink.next], r11		; link->next = list->head
	mov		[r9 + Mylist.head], r10			; list->head = link
	add		[r9 + Mylist.size], byte 1		; list->size++
	jmp		end

end:
	leave
	ret
