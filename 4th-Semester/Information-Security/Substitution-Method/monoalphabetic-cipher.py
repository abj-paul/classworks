DIVISION_FACTOR = 128 # We wish to cover all 128 ascii character so we must keep the sum=plaintext[i]+key within [0,127] so we divide the sum by DIVISION_FACTOR


def encrypt_text_with_key(plainText, key):
    encryptedText = ""
    for character in plainText:
        encryptedText = encryptedText + str(chr((ord(character)+key)%DIVISION_FACTOR))

    return encryptedText

def decrypt_text_with_key(encryptedText, key):
    plainText = ""
    for character in encryptedText:
        intValue = ord(character) - key;
        if key<0: intValue = DIVISION_FACTOR + intValue
        plainText = plainText + chr(intValue)
    return plainText

def main():
    plainText = input("Enter your message to encrypt: ")
    key = int(input("Enter key: "))
    encryptedText = encrypt_text_with_key(plainText, key)
    decryptedText = decrypt_text_with_key(encryptedText, key)

    print("Cipher Text: " + encryptedText)
    print("Plain Text: " + decryptedText)

if __name__ == '__main__':
    main()
