 #    2
 #    3
 #    4
 #    5
 #    6
 #    7
 #    8
				# b_global_decl (K, alignment = 4, size = 4)
.globl K
	.data
	.align	4
	.type	K, @object
	.size	K, 4
K:
	.zero	4
				# b_global_decl (J, alignment = 4, size = 4)
.globl J
	.align	4
	.type	J, @object
	.size	J, 4
J:
	.zero	4
				# b_global_decl (I, alignment = 4, size = 4)
.globl I
	.align	4
	.type	I, @object
	.size	I, 4
I:
	.zero	4
 #    9
				# b_global_decl (Z, alignment = 4, size = 4)
.globl Z
	.align	4
	.type	Z, @object
	.size	Z, 4
Z:
	.zero	4
				# b_global_decl (Y, alignment = 4, size = 4)
.globl Y
	.align	4
	.type	Y, @object
	.size	Y, 4
Y:
	.zero	4
				# b_global_decl (X, alignment = 4, size = 4)
.globl X
	.align	4
	.type	X, @object
	.size	X, 4
X:
	.zero	4
 #   10
				# b_global_decl (D, alignment = 8, size = 8)
.globl D
	.align	8
	.type	D, @object
	.size	D, 8
D:
	.zero	8
 #   11
				# b_global_decl (C, alignment = 1, size = 1)
.globl C
	.align	1
	.type	C, @object
	.size	C, 1
C:
	.zero	1
 #   12
				# b_global_decl (Ip, alignment = 4, size = 4)
.globl Ip
	.align	4
	.type	Ip, @object
	.size	Ip, 4
Ip:
	.zero	4
 #   13
				# b_global_decl (Rp, alignment = 4, size = 4)
.globl Rp
	.align	4
	.type	Rp, @object
	.size	Rp, 4
Rp:
	.zero	4
 #   14
 #   15
 #   16
 #   17
 #   18
 #   19
 #   20
 #   21
				# b_init_formal_param_offset ()
				# b_func_prologue (Rst)
	.text
.global Rst
	.type	Rst, @function
Rst:
	pushl	%ebp
	movl	%esp, %ebp
				# b_alloc_local_vars ( size = 0 )
 #   22
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_alloc_arglist (0 bytes)
	subl	$0, %esp
				# b_funcall_by_name (Abc, signed long int)
	call	Abc
	addl	$0, %esp
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
 #   23
				# b_func_epilogue (Rst)
	leave
	ret
	.size	Rst, .-Rst
 #   24
 #   25
 #   26
				# b_init_formal_param_offset ()
				# b_func_prologue (Xyz)
.global Xyz
	.type	Xyz, @function
Xyz:
	pushl	%ebp
	movl	%esp, %ebp
				# b_alloc_local_vars ( size = 0 )
 #   27
 #   28
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (1999)
	movl	$1999, %eax
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
				# b_func_epilogue (Xyz)
	leave
	ret
	.size	Xyz, .-Xyz
 #   29
 #   30
 #   31
				# b_init_formal_param_offset ()
				# b_func_prologue (Abc)
.global Abc
	.type	Abc, @function
Abc:
	pushl	%ebp
	movl	%esp, %ebp
				# b_alloc_return_value ( )
				# b_alloc_local_vars ( size = 8 )
	subl	$8, %esp
				# b_alloc_local_vars ( size = 0 )
 #   32
				# b_alloc_arglist (0 bytes)
	subl	$0, %esp
				# b_funcall_by_name (Xyz, void)
	call	Xyz
	addl	$0, %esp
 #   33
				# b_push_const_int (18)
	movl	$18, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_set_return (signed long int)
	movl	(%esp), %eax
	movl	%eax, -8(%ebp)
	addl	$8, %esp
 #   34
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_push_const_int (20)
	movl	$20, %eax
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
 #   35
 #   36
				# b_push_const_int (19)
	movl	$19, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_set_return (signed long int)
	movl	(%esp), %eax
	movl	%eax, -8(%ebp)
	addl	$8, %esp
				# b_prepare_return (signed long int)
	movl	-8(%ebp), %eax
				# b_func_epilogue (Abc)
	leave
	ret
	.size	Abc, .-Abc
 #   37
 #   38
 #   39
				# b_init_formal_param_offset ()
				# b_func_prologue (Get_integer)
.global Get_integer
	.type	Get_integer, @function
Get_integer:
	pushl	%ebp
	movl	%esp, %ebp
				# b_alloc_return_value ( )
				# b_alloc_local_vars ( size = 8 )
	subl	$8, %esp
				# b_alloc_local_vars ( size = 0 )
 #   40
				# b_push_ext_addr (Ip)
	subl	$8, %esp
	movl	$Ip, (%esp)
				# b_alloc_arglist (4 bytes)
	subl	$8, %esp
				# b_push_const_int (4)
	movl	$4, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (unsigned int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (malloc, pointer)
	call	malloc
	addl	$8, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (pointer)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   41
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_const_string ("Enter an integer:   ")
	.section	.rodata
.LC0:
.string	"Enter an integer:   "
	.text
				# b_push_ext_addr (.LC0)
	subl	$8, %esp
	movl	$.LC0, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$16, %esp
 #   42
				# b_alloc_arglist (8 bytes)
	subl	$16, %esp
				# b_push_const_string ("%ld")
	.section	.rodata
.LC1:
.string	"%ld"
	.text
				# b_push_ext_addr (.LC1)
	subl	$8, %esp
	movl	$.LC1, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (Ip)
	subl	$8, %esp
	movl	$Ip, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_funcall_by_name (Scanf, void)
	call	Scanf
	addl	$16, %esp
 #   43
				# b_push_ext_addr (Ip)
	subl	$8, %esp
	movl	$Ip, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_set_return (signed long int)
	movl	(%esp), %eax
	movl	%eax, -8(%ebp)
	addl	$8, %esp
 #   44
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_ext_addr (Ip)
	subl	$8, %esp
	movl	$Ip, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (free, void)
	call	free
	addl	$16, %esp
 #   45
				# b_prepare_return (signed long int)
	movl	-8(%ebp), %eax
				# b_func_epilogue (Get_integer)
	leave
	ret
	.size	Get_integer, .-Get_integer
 #   46
 #   47
 #   48
				# b_init_formal_param_offset ()
				# b_func_prologue (Get_real)
.global Get_real
	.type	Get_real, @function
Get_real:
	pushl	%ebp
	movl	%esp, %ebp
				# b_alloc_return_value ( )
				# b_alloc_local_vars ( size = 8 )
	subl	$8, %esp
				# b_alloc_local_vars ( size = 0 )
 #   49
				# b_push_ext_addr (Rp)
	subl	$8, %esp
	movl	$Rp, (%esp)
				# b_alloc_arglist (4 bytes)
	subl	$8, %esp
				# b_push_const_int (8)
	movl	$8, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_load_arg (unsigned int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (malloc, pointer)
	call	malloc
	addl	$8, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (pointer)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   50
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_const_string ("Enter a real:   ")
	.section	.rodata
.LC2:
.string	"Enter a real:   "
	.text
				# b_push_ext_addr (.LC2)
	subl	$8, %esp
	movl	$.LC2, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$16, %esp
 #   51
				# b_alloc_arglist (8 bytes)
	subl	$16, %esp
				# b_push_const_string ("%lf")
	.section	.rodata
.LC3:
.string	"%lf"
	.text
				# b_push_ext_addr (.LC3)
	subl	$8, %esp
	movl	$.LC3, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (Rp)
	subl	$8, %esp
	movl	$Rp, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_funcall_by_name (Scanf, void)
	call	Scanf
	addl	$16, %esp
 #   52
				# b_push_ext_addr (Rp)
	subl	$8, %esp
	movl	$Rp, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_set_return (double)
	movl	(%esp), %eax
	movl	%eax, -8(%ebp)
	movl	4(%esp), %edx
	movl	%edx, -4(%ebp)
	addl	$8, %esp
 #   53
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_ext_addr (Rp)
	subl	$8, %esp
	movl	$Rp, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (free, void)
	call	free
	addl	$16, %esp
 #   54
				# b_prepare_return (double)
	fldl	-8(%ebp)
				# b_func_epilogue (Get_real)
	leave
	ret
	.size	Get_real, .-Get_real
 #   55
 #   56
 #   57
				# b_init_formal_param_offset ()
				# b_func_prologue (Get_character)
.global Get_character
	.type	Get_character, @function
Get_character:
	pushl	%ebp
	movl	%esp, %ebp
				# b_alloc_return_value ( )
				# b_alloc_local_vars ( size = 8 )
	subl	$8, %esp
				# b_alloc_local_vars ( size = 0 )
 #   58
				# b_alloc_arglist (4 bytes)
	subl	$16, %esp
				# b_push_const_string ("Enter a character:   ")
	.section	.rodata
.LC4:
.string	"Enter a character:   "
	.text
				# b_push_ext_addr (.LC4)
	subl	$8, %esp
	movl	$.LC4, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$16, %esp
 #   59
				# b_alloc_arglist (0 bytes)
	subl	$0, %esp
				# b_funcall_by_name (Getchar, unsigned char)
	call	Getchar
	addl	$0, %esp
	subl	$8, %esp
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_set_return (unsigned char)
	movl	(%esp), %eax
	movl	%eax, -8(%ebp)
	addl	$8, %esp
 #   60
				# b_alloc_arglist (0 bytes)
	subl	$0, %esp
				# b_funcall_by_name (Getchar, unsigned char)
	call	Getchar
	addl	$0, %esp
	subl	$8, %esp
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_set_return (unsigned char)
	movl	(%esp), %eax
	movl	%eax, -8(%ebp)
	addl	$8, %esp
 #   61
				# b_prepare_return (unsigned char)
	movzbl	-8(%ebp), %eax
				# b_func_epilogue (Get_character)
	leave
	ret
	.size	Get_character, .-Get_character
 #   62
 #   63
 #   64
				# b_init_formal_param_offset ()
				# b_func_prologue (Print_globals)
.global Print_globals
	.type	Print_globals, @function
Print_globals:
	pushl	%ebp
	movl	%esp, %ebp
				# b_alloc_local_vars ( size = 0 )
 #   65
				# b_alloc_arglist (16 bytes)
	subl	$24, %esp
				# b_push_const_string ("i = %ld; j = %ld; k = %ld\n")
	.section	.rodata
.LC5:
.string	"i = %ld; j = %ld; k = %ld\n"
	.text
				# b_push_ext_addr (.LC5)
	subl	$8, %esp
	movl	$.LC5, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 4(%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 8(%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 12(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$24, %esp
 #   66
				# b_alloc_arglist (28 bytes)
	subl	$40, %esp
				# b_push_const_string ("x = %f; y = %f; z = %f\n")
	.section	.rodata
.LC6:
.string	"x = %f; y = %f; z = %f\n"
	.text
				# b_push_ext_addr (.LC6)
	subl	$8, %esp
	movl	$.LC6, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
				# b_push_ext_addr (Y)
	subl	$8, %esp
	movl	$Y, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
				# b_push_ext_addr (Z)
	subl	$8, %esp
	movl	$Z, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$40, %esp
 #   67
				# b_alloc_arglist (16 bytes)
	subl	$24, %esp
				# b_push_const_string ("d = %lf\nc = %u\n")
	.section	.rodata
.LC7:
.string	"d = %lf\nc = %u\n"
	.text
				# b_push_ext_addr (.LC7)
	subl	$8, %esp
	movl	$.LC7, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
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
				# b_load_arg (signed long int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 12(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$24, %esp
 #   68
				# b_func_epilogue (Print_globals)
	leave
	ret
	.size	Print_globals, .-Print_globals
 #   69
 #   70
 #   71
				# b_func_prologue (main)
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   72
 #   73
				# b_alloc_arglist (4 bytes)
	subl	$8, %esp
				# b_push_const_string ("this is a debugging message\n")
	.section	.rodata
.LC8:
.string	"this is a debugging message\n"
	.text
				# b_push_ext_addr (.LC8)
	subl	$8, %esp
	movl	$.LC8, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (Printf, void)
	call	Printf
	addl	$8, %esp
 #   74
 #   75
				# b_alloc_arglist (0 bytes)
	subl	$8, %esp
				# b_funcall_by_name (Rst, void)
	call	Rst
	addl	$8, %esp
 #   76
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_alloc_arglist (0 bytes)
	subl	$0, %esp
				# b_funcall_by_name (Get_real, double)
	call	Get_real
	addl	$0, %esp
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   77
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_alloc_arglist (0 bytes)
	subl	$0, %esp
				# b_funcall_by_name (Get_character, unsigned char)
	call	Get_character
	addl	$0, %esp
	subl	$8, %esp
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_assign (unsigned char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   78
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   79
				# b_push_ext_addr (Y)
	subl	$8, %esp
	movl	$Y, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( / , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	%ecx
	movl	%eax, (%esp)
				# b_convert (signed long int -> float)
	fildl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   80
				# b_push_ext_addr (Z)
	subl	$8, %esp
	movl	$Z, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( % , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	%ecx
	movl	%edx, (%esp)
				# b_convert (signed long int -> float)
	fildl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   81
 #   82
				# b_alloc_arglist (0 bytes)
	subl	$8, %esp
				# b_funcall_by_name (Print_globals, void)
	call	Print_globals
	addl	$8, %esp
 #   83
 #   84
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_alloc_arglist (0 bytes)
	subl	$0, %esp
				# b_funcall_by_name (Get_integer, signed long int)
	call	Get_integer
	addl	$0, %esp
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
 #   85
				# b_push_ext_addr (D)
	subl	$8, %esp
	movl	$D, (%esp)
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_const_double (2.0000000000000000e+00)
	.section	.rodata
	.align	8
.LC9:
	.long	0
	.long	1073741824
	.text
	fldl	.LC9
	subl	$8, %esp
	fstpl	(%esp)
				# b_arith_rel_op ( * , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fmulp	%st, %st(1)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   86
 #   87
 #   88
 #   89
				# b_alloc_arglist (0 bytes)
	subl	$8, %esp
				# b_funcall_by_name (Print_globals, void)
	call	Print_globals
	addl	$8, %esp
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #   90
