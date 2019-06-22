/*
	0000000000400546 <ret_str>:
	  400546:	55                   	push   %rbp
	  400547:	48 89 e5             	mov    %rsp,%rbp
	  40054a:	48 c7 45 f8 54 06 40 	movq   $0x400654,-0x8(%rbp)
	  400551:	00 
	  400552:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
	  400556:	5d                   	pop    %rbp
	  400557:	c3                   	retq   

	0000000000400558 <ret_str2>:
	  400558:	55                   	push   %rbp
	  400559:	48 89 e5             	mov    %rsp,%rbp
	  40055c:	48 83 ec 20          	sub    $0x20,%rsp
	  400560:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
	  400567:	00 00 
	  400569:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
	  40056d:	31 c0                	xor    %eax,%eax
	  40056f:	48 b8 6e 6f 77 20 69 	movabs $0x206d276920776f6e,%rax
	  400576:	27 6d 20 
	  400579:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
	  40057d:	c7 45 e8 68 65 72 65 	movl   $0x65726568,-0x18(%rbp)
	  400584:	c6 45 ec 00          	movb   $0x0,-0x14(%rbp)
	  400588:	b8 00 00 00 00       	mov    $0x0,%eax
	  40058d:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
	  400591:	64 48 33 14 25 28 00 	xor    %fs:0x28,%rdx
	  400598:	00 00 
	  40059a:	74 05                	je     4005a1 <ret_str2+0x49>
	  40059c:	e8 7f fe ff ff       	callq  400420 <__stack_chk_fail@plt>
	  4005a1:	c9                   	leaveq 
	  4005a2:	c3                   	retq   

	  Print the reversed `I'm here now':

		  echo '65726568206d276920776f6e' | xxd -r -p

*/

/* static, i.e. in .rodata section */
char *ret_str() {
	char *p="where am I?";
	return p;
}

/* on stack, i.e. hardcoded in instructions and assigned at runtime*/
char *ret_str2() {
	char p[] = "now i'm here";
	return p;
}

int main() {
	/* okay */
	char *p = ret_str();

	/* problematic */
	char *p2 = ret_str2();
}
