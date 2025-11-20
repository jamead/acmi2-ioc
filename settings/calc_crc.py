import struct

def crc32_msb(data, poly=0x04C11DB7, init_val=0xFFFFFFFF, final_xor=0x00000000):
    crc = init_val
    for byte_index, byte in enumerate(data):
        crc ^= (byte << 24)

        # Print CRC after XORing in the byte
        # print(f"After byte {byte_index:03d} (0x{byte:02X}) XOR:  CRC = 0x{crc:08X}")

        # Bitwise processing
        for _ in range(8):
            if crc & 0x80000000:
                crc = ((crc << 1) ^ poly) & 0xFFFFFFFF
            else:
                crc = (crc << 1) & 0xFFFFFFFF

        # Print CRC after completing all 8 bit shifts
        print(f"After byte {byte_index:03d} (0x{byte:02X}) SHIFT: CRC = 0x{crc:08X}")

    return crc ^ final_xor


# ---- Load and parse settings.txt ----
vals = []
with open("settings.txt", "r") as f:
    for i, line in enumerate(f):
        if i >= 49:     # only the first 49 lines
            break
        num_str = line.split()[0]
        vals.append(int(num_str))

# ---- Pack as big-endian *signed* 32-bit integers ----
data = b''.join(struct.pack(">i", v) for v in vals)

# ---- Compute CRC ----
crc = crc32_msb(data)

print("\nFINAL CRC32 =", hex(crc))


