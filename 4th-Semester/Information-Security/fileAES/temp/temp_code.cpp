void take_input(){
  byte byte_input[16], byte_key[16];
  printf("Enter Input: ");
  for(int i=0 ;i<16; i++) scanf("%c",&byte_input[i]);
  printf("Enter key: ");
  for(int i=0 ;i<16; i++) scanf("%c",&byte_key[i]);
}

void take_hex_input(){ //convert input into matrix and store it in global variables.
  byte byte_input[16], byte_key[16];
  printf("Enter Input: ");
  for(int i=0 ;i<16; i++) scanf("%x ",&byte_input[i]);
  printf("Enter key: ");
  for(int i=0 ;i<16; i++) scanf("%x ",&byte_key[i]);
}


void test_round(){
  printf("Testing round module: -------------");
  take_input();
  printf("Plaintext: \n");
  plaintext.print();
  printf("Key: \n");
  key.print();

  int r=1;

  round(r);
  printf("Ciphertext after round %d: \n",r);
  ciphertext.print();

  // inverse_round(10-r);
  // inverse_round(r);
  printf("Reverse Ciphertext after round %d: \n",10-r);
  ciphertext.print();
}

void test_aes(){
  take_hex_input();
  printf("Plaintext:\n");
  plaintext.print();
  encryption_algorithm();
  printf("Ciphertext:\n");
  ciphertext.print();
  decryption_algorithm();
  printf("Reverse Ciphertext:\n");
  ciphertext.print();
}
