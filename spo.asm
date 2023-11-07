[section data_ram]
lab: dw
[section code_ram]
start:
	mov 268, r0
	store r0, lab
	mov 0, r0
	load lab, r0
hlt
