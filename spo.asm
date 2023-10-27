[section data_ram]
test: times 16 db 0xff

[section code_ram]
start:
    push r0
    hlt
