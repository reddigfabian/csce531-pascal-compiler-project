 #    2
 #    3
 #    4
 #    5
 #    6
 #    7
 #    8
				# b_global_decl (B, alignment = 4, size = 4)
.globl B
	.data
	.align	4
	.type	B, @object
	.size	B, 4
B:
	.zero	4
				# b_global_decl (A, alignment = 4, size = 4)
.globl A
	.align	4
	.type	A, @object
	.size	A, 4
A:
	.zero	4
 #    9
				# b_global_decl (C, alignment = 1, size = 1)
.globl C
	.align	1
	.type	C, @object
	.size	C, 1
C:
	.zero	1
 #   10
 #   11
 #   12
 #   13
 #   14
 #   15
 #   16
 #   17
 #   18
 #   19
 #   20
 #   21
 #   22
 #   23
 #   24
 #   25
 #   26
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   27
 #   28
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (9)
	movl	$9, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   29
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   30
 #   31
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   32
				# b_dispatch (  == ,signed long int, 1, .LC2, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC3
	addl	$8, %esp
				# b_jump ( destination = .LC2 )
	jmp	.LC2
.LC3:
				# b_jump ( destination = .LC1 )
	jmp	.LC1
.LC2:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_one, void)
	call	Print_one
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC0 )
	jmp	.LC0
.LC1:
 #   33
				# b_dispatch (  == ,signed long int, 2, .LC5, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC6
	addl	$8, %esp
				# b_jump ( destination = .LC5 )
	jmp	.LC5
.LC6:
				# b_jump ( destination = .LC4 )
	jmp	.LC4
.LC5:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_two, void)
	call	Print_two
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC0 )
	jmp	.LC0
.LC4:
 #   34
				# b_dispatch (  == ,signed long int, 3, .LC8, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC9
	addl	$8, %esp
				# b_jump ( destination = .LC8 )
	jmp	.LC8
.LC9:
				# b_jump ( destination = .LC7 )
	jmp	.LC7
.LC8:
 #   35
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_three, void)
	call	Print_three
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC0 )
	jmp	.LC0
.LC7:
				# b_pop ()
	addl	$8, %esp
.LC0:
 #   36
 #   37
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   38
				# b_dispatch (  == ,signed long int, 1, .LC12, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC13
	addl	$8, %esp
				# b_jump ( destination = .LC12 )
	jmp	.LC12
.LC13:
				# b_jump ( destination = .LC11 )
	jmp	.LC11
.LC12:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_one, void)
	call	Print_one
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC11:
 #   39
				# b_dispatch (  == ,signed long int, 2, .LC15, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC16
	addl	$8, %esp
				# b_jump ( destination = .LC15 )
	jmp	.LC15
.LC16:
				# b_jump ( destination = .LC14 )
	jmp	.LC14
.LC15:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_two, void)
	call	Print_two
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC14:
 #   40
				# b_dispatch (  == ,signed long int, 3, .LC18, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC19
	addl	$8, %esp
				# b_jump ( destination = .LC18 )
	jmp	.LC18
.LC19:
				# b_jump ( destination = .LC17 )
	jmp	.LC17
.LC18:
 #   41
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_three, void)
	call	Print_three
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC17:
				# b_pop ()
	addl	$8, %esp
 #   42
 #   43
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_dunno, void)
	call	Print_dunno
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
.LC10:
 #   44
 #   45
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   46
 #   47
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   48
				# b_dispatch (  == ,signed long int, 1, .LC22, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC23
	addl	$8, %esp
				# b_jump ( destination = .LC22 )
	jmp	.LC22
.LC23:
				# b_jump ( destination = .LC21 )
	jmp	.LC21
.LC22:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_one, void)
	call	Print_one
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC20 )
	jmp	.LC20
.LC21:
 #   49
				# b_dispatch (  == ,signed long int, 2, .LC25, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC26
	addl	$8, %esp
				# b_jump ( destination = .LC25 )
	jmp	.LC25
.LC26:
				# b_jump ( destination = .LC24 )
	jmp	.LC24
.LC25:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_two, void)
	call	Print_two
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC20 )
	jmp	.LC20
.LC24:
 #   50
				# b_dispatch (  == ,signed long int, 3, .LC28, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC29
	addl	$8, %esp
				# b_jump ( destination = .LC28 )
	jmp	.LC28
.LC29:
				# b_jump ( destination = .LC27 )
	jmp	.LC27
.LC28:
 #   51
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_three, void)
	call	Print_three
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC20 )
	jmp	.LC20
.LC27:
				# b_pop ()
	addl	$8, %esp
 #   52
 #   53
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_dunno, void)
	call	Print_dunno
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
.LC20:
 #   54
 #   55
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   56
 #   57
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   58
				# b_dispatch (  == ,signed long int, 2, .LC32, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC33
	addl	$8, %esp
				# b_jump ( destination = .LC32 )
	jmp	.LC32
.LC33:
				# b_dispatch (  == ,signed long int, 1, .LC32, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC34
	addl	$8, %esp
				# b_jump ( destination = .LC32 )
	jmp	.LC32
.LC34:
				# b_jump ( destination = .LC31 )
	jmp	.LC31
.LC32:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_one, void)
	call	Print_one
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC30 )
	jmp	.LC30
.LC31:
 #   59
				# b_dispatch (  == ,signed long int, 3, .LC36, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC37
	addl	$8, %esp
				# b_jump ( destination = .LC36 )
	jmp	.LC36
.LC37:
				# b_jump ( destination = .LC35 )
	jmp	.LC35
.LC36:
 #   60
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_three, void)
	call	Print_three
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC30 )
	jmp	.LC30
.LC35:
				# b_pop ()
	addl	$8, %esp
 #   61
 #   62
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_dunno, void)
	call	Print_dunno
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
.LC30:
 #   63
 #   64
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   65
 #   66
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   67
				# b_dispatch (  == ,signed long int, 2, .LC40, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC41
	addl	$8, %esp
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC41:
				# b_dispatch (  == ,signed long int, 1, .LC40, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC42
	addl	$8, %esp
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC42:
				# b_jump ( destination = .LC39 )
	jmp	.LC39
.LC40:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_one, void)
	call	Print_one
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC38 )
	jmp	.LC38
.LC39:
 #   68
				# b_dispatch (  == ,signed long int, 3, .LC44, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC45
	addl	$8, %esp
				# b_jump ( destination = .LC44 )
	jmp	.LC44
.LC45:
				# b_jump ( destination = .LC43 )
	jmp	.LC43
.LC44:
 #   69
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_three, void)
	call	Print_three
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC38 )
	jmp	.LC38
.LC43:
				# b_pop ()
	addl	$8, %esp
 #   70
 #   71
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_dunno, void)
	call	Print_dunno
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
.LC38:
 #   72
 #   73
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   74
 #   75
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   76
				# b_dispatch (  == ,signed long int, 2, .LC48, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC49
	addl	$8, %esp
				# b_jump ( destination = .LC48 )
	jmp	.LC48
.LC49:
				# b_dispatch (  == ,signed long int, 1, .LC48, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC50
	addl	$8, %esp
				# b_jump ( destination = .LC48 )
	jmp	.LC48
.LC50:
				# b_jump ( destination = .LC47 )
	jmp	.LC47
.LC48:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_one, void)
	call	Print_one
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC46 )
	jmp	.LC46
.LC47:
 #   77
				# b_dispatch (  == ,signed long int, 3, .LC52, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC53
	addl	$8, %esp
				# b_jump ( destination = .LC52 )
	jmp	.LC52
.LC53:
				# b_jump ( destination = .LC51 )
	jmp	.LC51
.LC52:
 #   78
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_three, void)
	call	Print_three
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC46 )
	jmp	.LC46
.LC51:
				# b_pop ()
	addl	$8, %esp
 #   79
 #   80
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_dunno, void)
	call	Print_dunno
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
.LC46:
 #   81
 #   82
 #   83
 #   84
 #   85
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> unsigned char)
				# b_assign (unsigned char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   86
 #   87
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
 #   88
				# b_dispatch (  == ,signed long int, 3, .LC56, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC57
	addl	$8, %esp
				# b_jump ( destination = .LC56 )
	jmp	.LC56
.LC57:
				# b_jump ( destination = .LC55 )
	jmp	.LC55
.LC56:
 #   89
 #   90
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
 #   91
				# b_dispatch (  == ,signed long int, 4, .LC60, pop on jump )
	movl	(%esp), %edx
	movl	$4, %eax
	cmpl	%eax, %edx
	jne	.LC61
	addl	$8, %esp
				# b_jump ( destination = .LC60 )
	jmp	.LC60
.LC61:
				# b_dispatch (  == ,signed long int, 2, .LC60, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC62
	addl	$8, %esp
				# b_jump ( destination = .LC60 )
	jmp	.LC60
.LC62:
				# b_dispatch (  == ,signed long int, 1, .LC60, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC63
	addl	$8, %esp
				# b_jump ( destination = .LC60 )
	jmp	.LC60
.LC63:
				# b_jump ( destination = .LC59 )
	jmp	.LC59
.LC60:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_oops, void)
	call	Print_oops
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC58 )
	jmp	.LC58
.LC59:
 #   92
				# b_dispatch (  == ,signed long int, 3, .LC65, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC66
	addl	$8, %esp
				# b_jump ( destination = .LC65 )
	jmp	.LC65
.LC66:
				# b_jump ( destination = .LC64 )
	jmp	.LC64
.LC65:
 #   93
 #   94
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_712, void)
	call	Print_712
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   95
 #   96
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_is_the, void)
	call	Print_is_the
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC58 )
	jmp	.LC58
.LC64:
 #   97
				# b_pop ()
	addl	$8, %esp
.LC58:
 #   98
 #   99
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_grooviest, void)
	call	Print_grooviest
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC54 )
	jmp	.LC54
.LC55:
 #  100
				# b_pop ()
	addl	$8, %esp
 #  101
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_oops, void)
	call	Print_oops
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #  102
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (unsigned char)
	movl	(%esp), %eax
	movzbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
 #  103
				# b_dispatch (  == ,signed long int, 4, .LC69, pop on jump )
	movl	(%esp), %edx
	movl	$4, %eax
	cmpl	%eax, %edx
	jne	.LC70
	addl	$8, %esp
				# b_jump ( destination = .LC69 )
	jmp	.LC69
.LC70:
				# b_dispatch (  == ,signed long int, 3, .LC69, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC71
	addl	$8, %esp
				# b_jump ( destination = .LC69 )
	jmp	.LC69
.LC71:
				# b_dispatch (  == ,signed long int, 2, .LC69, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC72
	addl	$8, %esp
				# b_jump ( destination = .LC69 )
	jmp	.LC69
.LC72:
				# b_dispatch (  == ,signed long int, 1, .LC69, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC73
	addl	$8, %esp
				# b_jump ( destination = .LC69 )
	jmp	.LC69
.LC73:
				# b_jump ( destination = .LC68 )
	jmp	.LC68
.LC69:
 #  104
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_oops, void)
	call	Print_oops
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC67 )
	jmp	.LC67
.LC68:
				# b_pop ()
	addl	$8, %esp
 #  105
 #  106
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_oops, void)
	call	Print_oops
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
.LC67:
 #  107
.LC54:
 #  108
 #  109
 #  110
 #  111
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_newline, void)
	call	Print_newline
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #  112
