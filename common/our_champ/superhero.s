.name "SuperHero"
.comment "just a corewar"
		
eldaroid:	sti	r1,%:eldaroid,%0
	and	r1,%0,r1
tanya:	live	%1
	zjmp	%:tanya

alive:
		live		%2863311530
		live		%637485
		fork		%:alive
		live		%62243211
		fork		%:clear
		zjmp		%:alive

circup:
		live		%756436893
		zjmp		%:circup

clear:
		live		%534675876
		add			r16, r1, r2
		ld			%8, r3
		fork		%:clear916

clear18:
		live		%64732221
		fork		%:clear58

clear14:
		ld			%0, r4
		ld			%150994945, r2
		st			r2, 110
		ld			%0, r16
		zjmp		%101

clear58:
		ld			%4, r4
		ld			%0, r16
		st			r2, 85
		ld			%0, r16
		zjmp		%72

clear916:
		live		%-3245
		fork		%:clear1316

clear912:
		ld			%8, r4
		ld			%190054915, r2
		st			r2, 52
		ld			%0, r16
		zjmp		%35

clear1316:
		ld			%12, r4
		ld			%67698694, r2
		st			r2, 27
		ld			%0, r16
		zjmp		%6

rush:
		live		%23145789
		ld			%190054917, r2
		ld			%67699190, r3
		ld			%507, r5
		ld			%16, r6
		st			r2, 511
		st			r3, 510
		fork		%:rush58

rush14:
		ld			%190055173, r2
		ld			%190056198, r3
		ld			%190056198, r7
		ld			%0, r4
		ld			%0, r16
		zjmp		%463

rush58:
		ld			%67699190, r2
		ld			%67698699, r3
		ld			%67698699, r7
		ld			%4, r4
		ld			%0, r16
		zjmp		%425

p0:
		live		%45678923
		fork		%:pp
		add			r8, r15, r8
		ld			%0, r15
		zjmp		%:p1

pp:
		add			r8, r3, r8
		ld			%0, r15
		zjmp		%:p1

p1:
		live		%5412876
		fork		%:p2
		live		%864259
		add			r8, r15, r8
		fork		%:p3
		add			r8, r15, r8
		ld			%0, r15
		zjmp		%134

p2:
		live		%987652
		add			r8, r4, r8
		fork		%:p3
		add			r8, r15, r8
		ld			%0, r15
		zjmp		%111

p3:
		add			r8, r5, r8
		ld			%0, r15
		zjmp		%96
