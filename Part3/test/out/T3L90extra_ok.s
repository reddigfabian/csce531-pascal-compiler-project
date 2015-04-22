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
 #   27
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   28
 #   29
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
				# b_dispatch (  < ,signed long int, 5, .LC3, no pop on jump )
	movl	(%esp), %edx
	movl	$5, %eax
	cmpl	%eax, %edx
	jge	.LC4
				# b_jump ( destination = .LC3 )
	jmp	.LC3
.LC4:
				# b_dispatch (  <= ,signed long int, 10, .LC2, pop on jump )
	movl	(%esp), %edx
	movl	$10, %eax
	cmpl	%eax, %edx
	jg	.LC5
	addl	$8, %esp
				# b_jump ( destination = .LC2 )
	jmp	.LC2
.LC5:
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
				# b_funcall_by_name (Print_oops, void)
	call	Print_oops
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC0 )
	jmp	.LC0
.LC1:
 #   33
				# b_dispatch (  < ,signed long int, 1, .LC8, no pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jge	.LC9
				# b_jump ( destination = .LC8 )
	jmp	.LC8
.LC9:
				# b_dispatch (  <= ,signed long int, 3, .LC7, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jg	.LC10
	addl	$8, %esp
				# b_jump ( destination = .LC7 )
	jmp	.LC7
.LC10:
.LC8:
				# b_jump ( destination = .LC6 )
	jmp	.LC6
.LC7:
 #   34
 #   35
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
 #   36
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
 #   37
 #   38
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
.LC6:
 #   39
				# b_pop ()
	addl	$8, %esp
 #   40
 #   41
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
.LC0:
 #   42
 #   43
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (4)
	movl	$4, %eax
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
 #   44
 #   45
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   46
				# b_dispatch (  < ,signed long int, 5, .LC14, no pop on jump )
	movl	(%esp), %edx
	movl	$5, %eax
	cmpl	%eax, %edx
	jge	.LC15
				# b_jump ( destination = .LC14 )
	jmp	.LC14
.LC15:
				# b_dispatch (  <= ,signed long int, 10, .LC13, pop on jump )
	movl	(%esp), %edx
	movl	$10, %eax
	cmpl	%eax, %edx
	jg	.LC16
	addl	$8, %esp
				# b_jump ( destination = .LC13 )
	jmp	.LC13
.LC16:
.LC14:
				# b_jump ( destination = .LC12 )
	jmp	.LC12
.LC13:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_big, void)
	call	Print_big
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC11 )
	jmp	.LC11
.LC12:
 #   47
				# b_dispatch (  < ,signed long int, 1, .LC19, no pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jge	.LC20
				# b_jump ( destination = .LC19 )
	jmp	.LC19
.LC20:
				# b_dispatch (  <= ,signed long int, 3, .LC18, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jg	.LC21
	addl	$8, %esp
				# b_jump ( destination = .LC18 )
	jmp	.LC18
.LC21:
.LC19:
				# b_jump ( destination = .LC17 )
	jmp	.LC17
.LC18:
 #   48
 #   49
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
 #   50
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
 #   51
 #   52
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
				# b_jump ( destination = .LC11 )
	jmp	.LC11
.LC17:
 #   53
				# b_pop ()
	addl	$8, %esp
 #   54
 #   55
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
.LC11:
 #   56
 #   57
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (7)
	movl	$7, %eax
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
 #   58
 #   59
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   60
				# b_dispatch (  < ,signed long int, 5, .LC25, no pop on jump )
	movl	(%esp), %edx
	movl	$5, %eax
	cmpl	%eax, %edx
	jge	.LC26
				# b_jump ( destination = .LC25 )
	jmp	.LC25
.LC26:
				# b_dispatch (  <= ,signed long int, 10, .LC24, pop on jump )
	movl	(%esp), %edx
	movl	$10, %eax
	cmpl	%eax, %edx
	jg	.LC27
	addl	$8, %esp
				# b_jump ( destination = .LC24 )
	jmp	.LC24
.LC27:
.LC25:
				# b_jump ( destination = .LC23 )
	jmp	.LC23
.LC24:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_big, void)
	call	Print_big
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC22 )
	jmp	.LC22
.LC23:
 #   61
				# b_dispatch (  < ,signed long int, 1, .LC30, no pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jge	.LC31
				# b_jump ( destination = .LC30 )
	jmp	.LC30
.LC31:
				# b_dispatch (  <= ,signed long int, 3, .LC29, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jg	.LC32
	addl	$8, %esp
				# b_jump ( destination = .LC29 )
	jmp	.LC29
.LC32:
.LC30:
				# b_jump ( destination = .LC28 )
	jmp	.LC28
.LC29:
 #   62
 #   63
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
 #   64
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
 #   65
 #   66
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
				# b_jump ( destination = .LC22 )
	jmp	.LC22
.LC28:
 #   67
				# b_pop ()
	addl	$8, %esp
 #   68
 #   69
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
.LC22:
 #   70
 #   71
 #   72
 #   73
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
 #   74
