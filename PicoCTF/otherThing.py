import hashlib

def xor_bytes(b1, b2):
    return bytes(a ^ b for a, b in zip(b1, b2))

def sha256_hash(data):
    return hashlib.sha256(data).digest()

# Known plaintext for the first block
plaintext_block1 = b"Great and Noble Leader of the Ta"

# First ciphertext block (hex to bytes)
ciphertext_block1 = bytes.fromhex("146ffa07f717a0a1cd51be5f725e14d2f7e2db4791541e53c5e5243294d17d93")

# Recover key1
key1 = xor_bytes(plaintext_block1, ciphertext_block1)

# Remaining ciphertext blocks (hex to bytes)
ciphertext_blocks = [
    bytes.fromhex("1506978bc85d22d0e0e77ea5a44f7da392404acb8dbfd58ea4652fb67a44b7b1"),
    bytes.fromhex("57d8a5d51e5044a9fe4254bb7fbb5aadc5e466fa1945f7bdf5687f58eaee70fc"),
    bytes.fromhex("1553250a46346116648a5d32e399c6722b5ff0d36592f9b23dafc7dca76d2d77"),
    bytes.fromhex("a7197febbf33cfd03d37e3fea9b4b63cf006d6e8cc5633b3627a0b00a522bc56"),
    bytes.fromhex("5dfef21580a2a5d6e4bb72741257af038cc77923670c47efa35476cc435fee41"),
    bytes.fromhex("9d510be571a300ef76f4e89ed1bc404a58de5c4f16421553d5682bce58f30bc6"),
]

# Decrypt the blocks
keys = [key1]
plaintext_blocks = [plaintext_block1]

for i in range(len(ciphertext_blocks)):
    key_next = sha256_hash(keys[-1])
    plaintext_block = xor_bytes(ciphertext_blocks[i], key_next)
    plaintext_blocks.append(plaintext_block)
    keys.append(key_next)

# Print decrypted plaintext
for i, block in enumerate(plaintext_blocks):
    print(f"Block {i+1}: {block.decode('utf-8', errors='replace')}")