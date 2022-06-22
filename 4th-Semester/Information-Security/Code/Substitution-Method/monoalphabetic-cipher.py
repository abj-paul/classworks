from pydoc import plain

encryptionTable = ['i','m','p','j','k','l','f','y','v','t','z','o','n','x','w','c','h','u','g','r','e','d','s','a','b','q']
DIVISION_FACTOR = 256

def encrypt(plainText, key):
    encryptedText = ""
    for character in plainText:
        encryptedText = encryptedText + str(chr((ord(character)+key)%DIVISION_FACTOR))

    return encryptedText

def decrypt(encryptedText, key):
    plainText = ""
    for character in encryptedText:
        intValue = ord(character) - key;
        if key<0: intValue = DIVISION_FACTOR + intValue
        plainText = plainText + chr(intValue)
    return plainText

def main():
    plainText = input("Enter your message to encrypt: ")
    key = int(input("Enter key: "))
    encryptedText = encrypt(plainText, key)
    decryptedText = decrypt(encryptedText, key)

    print("Cipher Text: " + encryptedText)
    print("Plain Text: " + decryptedText)

if __name__ == '__main__':
    main()