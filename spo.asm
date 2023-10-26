[section data_ram]
test: times 16 db 0xff

[section code_ram]
start:
    add r1, r1, 4
    hlt
