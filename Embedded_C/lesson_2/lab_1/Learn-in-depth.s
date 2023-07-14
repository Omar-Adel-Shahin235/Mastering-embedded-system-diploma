
Learn-in-depth.elf:     file format elf32-littlearm


Disassembly of section .startup:

00010000 <reset>:
   10000:	e3a0da11 	mov	sp, #69632	; 0x11000
   10004:	eb000000 	bl	1000c <main>

00010008 <stop>:
   10008:	eafffffe 	b	10008 <stop>

Disassembly of section .text:

0001000c <main>:
   1000c:	e92d4800 	push	{fp, lr}
   10010:	e28db004 	add	fp, sp, #4
   10014:	e59f0004 	ldr	r0, [pc, #4]	; 10020 <main+0x14>
   10018:	eb000001 	bl	10024 <Uart_send_string>
   1001c:	e8bd8800 	pop	{fp, pc}
   10020:	000100d8 	ldrdeq	r0, [r1], -r8

00010024 <Uart_send_string>:
   10024:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   10028:	e28db000 	add	fp, sp, #0
   1002c:	e24dd00c 	sub	sp, sp, #12
   10030:	e50b0008 	str	r0, [fp, #-8]
   10034:	ea000006 	b	10054 <Uart_send_string+0x30>
   10038:	e59f3030 	ldr	r3, [pc, #48]	; 10070 <Uart_send_string+0x4c>
   1003c:	e51b2008 	ldr	r2, [fp, #-8]
   10040:	e5d22000 	ldrb	r2, [r2]
   10044:	e5832000 	str	r2, [r3]
   10048:	e51b3008 	ldr	r3, [fp, #-8]
   1004c:	e2833001 	add	r3, r3, #1
   10050:	e50b3008 	str	r3, [fp, #-8]
   10054:	e51b3008 	ldr	r3, [fp, #-8]
   10058:	e5d33000 	ldrb	r3, [r3]
   1005c:	e3530000 	cmp	r3, #0
   10060:	1afffff4 	bne	10038 <Uart_send_string+0x14>
   10064:	e28bd000 	add	sp, fp, #0
   10068:	e8bd0800 	ldmfd	sp!, {fp}
   1006c:	e12fff1e 	bx	lr
   10070:	101f1000 	andsne	r1, pc, r0

00010074 <str2>:
   10074:	6e20796d 	cdpvs	9, 2, cr7, cr0, cr13, {3}
   10078:	20656d61 	rsbcs	r6, r5, r1, ror #26
   1007c:	6f207369 	svcvs	0x00207369
   10080:	0072616d 	rsbseq	r6, r2, sp, ror #2
	...

Disassembly of section .data:

000100d8 <str>:
   100d8:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xd45
   100dc:	64656464 	strbtvs	r6, [r5], #-1124	; 0x464
   100e0:	73797320 	cmnvc	r9, #32, 6	; 0x80000000
   100e4:	3a6d6574 	bcc	1b696bc <stack_top+0x1b58580>
   100e8:	72616d6f 	rsbvc	r6, r1, #7104	; 0x1bc0
	...

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002d41 	andeq	r2, r0, r1, asr #26
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000023 	andeq	r0, r0, r3, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	Address 0x0000002c is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <stack_top+0x10bfbe8>
   4:	4e472820 	cdpmi	8, 4, cr2, cr7, cr0, {1}
   8:	34202955 	strtcc	r2, [r0], #-2389	; 0x955
   c:	322e372e 	eorcc	r3, lr, #12058624	; 0xb80000
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000058 	andeq	r0, r0, r8, asr r0
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000011 	andeq	r0, r0, r1, lsl r0
  10:	00002e01 	andeq	r2, r0, r1, lsl #28
  14:	00000000 	andeq	r0, r0, r0
  18:	01002400 	tsteq	r0, r0, lsl #8
  1c:	01007400 	tsteq	r0, r0, lsl #8
  20:	00000000 	andeq	r0, r0, r0
  24:	1d010200 	sfmne	f0, 4, [r1, #-0]
  28:	01000000 	mrseq	r0, (UNDEF: 0)
  2c:	00240104 	eoreq	r0, r4, r4, lsl #2
  30:	00740001 	rsbseq	r0, r4, r1
  34:	00000001 	andeq	r0, r0, r1
  38:	4e010000 	cdpmi	0, 0, cr0, cr1, cr0, {0}
  3c:	03000000 	movweq	r0, #0
  40:	00000043 	andeq	r0, r0, r3, asr #32
  44:	004e0401 	subeq	r0, lr, r1, lsl #8
  48:	91020000 	mrsls	r0, (UNDEF: 2)
  4c:	04040074 	streq	r0, [r4], #-116	; 0x74
  50:	00000054 	andeq	r0, r0, r4, asr r0
  54:	35080105 	strcc	r0, [r8, #-261]	; 0x105
  58:	00000000 	andeq	r0, r0, r0

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0c3f012e 	ldfeqs	f0, [pc], #-184	; ffffff64 <stack_top+0xfffeee28>
  18:	0b3a0e03 	bleq	e8382c <stack_top+0xe726f0>
  1c:	0c270b3b 	stceq	11, cr0, [r7], #-236	; 0xffffff14
  20:	01120111 	tsteq	r2, r1, lsl r1
  24:	42970640 	addsmi	r0, r7, #64, 12	; 0x4000000
  28:	0013010c 	andseq	r0, r3, ip, lsl #2
  2c:	00050300 	andeq	r0, r5, r0, lsl #6
  30:	0b3a0e03 	bleq	e83844 <stack_top+0xe72708>
  34:	13490b3b 	movtne	r0, #39739	; 0x9b3b
  38:	00000a02 	andeq	r0, r0, r2, lsl #20
  3c:	0b000f04 	bleq	3c54 <reset-0xc3ac>
  40:	0013490b 	andseq	r4, r3, fp, lsl #18
  44:	00240500 	eoreq	r0, r4, r0, lsl #10
  48:	0b3e0b0b 	bleq	f82c7c <stack_top+0xf71b40>
  4c:	00000e03 	andeq	r0, r0, r3, lsl #28
	...

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	047d0002 	ldrbteq	r0, [sp], #-2
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000050 	andeq	r0, r0, r0, asr r0
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
   c:	00000000 	andeq	r0, r0, r0
  10:	00010024 	andeq	r0, r1, r4, lsr #32
  14:	00000050 	andeq	r0, r0, r0, asr r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0000003b 	andeq	r0, r0, fp, lsr r0
   4:	001d0002 	andseq	r0, sp, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	54524155 	ldrbpl	r4, [r2], #-341	; 0x155
  20:	0000632e 	andeq	r6, r0, lr, lsr #6
  24:	00000000 	andeq	r0, r0, r0
  28:	00240205 	eoreq	r0, r4, r5, lsl #4
  2c:	84150001 	ldrhi	r0, [r5], #-1
  30:	02008431 	andeq	r8, r0, #822083584	; 0x31000000
  34:	03610104 	cmneq	r1, #4, 2
  38:	08028209 	stmdaeq	r2, {r0, r3, r9, pc}
  3c:	Address 0x0000003c is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6c5c3a45 	mrrcvs	10, 4, r3, ip, cr5
   4:	6f737365 	svcvs	0x00737365
   8:	6c5c326e 	lfmvs	f3, 2, [ip], {110}	; 0x6e
   c:	315f6261 	cmpcc	pc, r1, ror #4
  10:	554e4700 	strbpl	r4, [lr, #-1792]	; 0x700
  14:	34204320 	strtcc	r4, [r0], #-800	; 0x320
  18:	322e372e 	eorcc	r3, lr, #12058624	; 0xb80000
  1c:	72615500 	rsbvc	r5, r1, #0, 10
  20:	65735f74 	ldrbvs	r5, [r3, #-3956]!	; 0xf74
  24:	735f646e 	cmpvc	pc, #1845493760	; 0x6e000000
  28:	6e697274 	mcrvs	2, 3, r7, cr9, cr4, {3}
  2c:	41550067 	cmpmi	r5, r7, rrx
  30:	632e5452 	teqvs	lr, #1375731712	; 0x52000000
  34:	736e7500 	cmnvc	lr, #0, 10
  38:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0x769
  3c:	68632064 	stmdavs	r3!, {r2, r5, r6, sp}^
  40:	70007261 	andvc	r7, r0, r1, ror #4
  44:	5f78745f 	svcpl	0x0078745f
  48:	69727473 	ldmdbvs	r2!, {r0, r1, r4, r5, r6, sl, ip, sp, lr}^
  4c:	Address 0x0000004c is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000014 	andeq	r0, r0, r4, lsl r0
  14:	00000000 	andeq	r0, r0, r0
  18:	00010024 	andeq	r0, r1, r4, lsr #32
  1c:	00000050 	andeq	r0, r0, r0, asr r0
  20:	8b040e42 	blhi	103930 <stack_top+0xf27f4>
  24:	0b0d4201 	bleq	350830 <stack_top+0x33f6f4>
