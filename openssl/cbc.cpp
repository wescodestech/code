#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

//-----------------------------------------------------
// Example code I wrote in an attempt to get the hang
// of the OpenSSL library
// To compile:
// g++ -o cbc cbc.cpp -lcrypto
//-----------------------------------------------------



int main( int argc, char** argv )
{
    int keylength = 256;

    /* generate a key with a given length */
    // Note: Try to see if this works with QStrings.
    // It looks like we will need to have a set global variable
    // modify accordingly...
    // Note: Only seems to work with std strings
    std::string aes_str1 = "9876543210";
    const char* aes_key = aes_str1.c_str();
    //std::string aes_str2 = "9876543210";
    //const char* aes_key2 = aes_str2.c_str();

    /* generate input with a given length */
    std::string input_str = "Hello World!! This is a very long string.";
    const char* aes_input = input_str.c_str();
    size_t inputslength = 0;
    inputslength = strlen(aes_input);

    /* init vector */
    unsigned char iv_enc[AES_BLOCK_SIZE];
    unsigned char iv_dec[AES_BLOCK_SIZE];
    memset( iv_enc, 0, AES_BLOCK_SIZE );
    memcpy(iv_dec, iv_enc, AES_BLOCK_SIZE);

    // buffers for encryption and decryption
    const size_t encslength = ((inputslength + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char enc_out[encslength];
    unsigned char dec_out[inputslength];
    memset(enc_out, 0, sizeof(enc_out));
    memset(dec_out, 0, sizeof(dec_out));

    // so i can do with this aes-cbc-128 aes-cbc-192 aes-cbc-256
    AES_KEY enc_key;
    AES_KEY dec_key;
    unsigned char testKey1[strlen(aes_str1.c_str())];
    unsigned char testKey2[strlen(aes_str1.c_str())];
    memcpy( testKey1, aes_key, strlen(aes_str1.c_str()) );
    memcpy( testKey2, aes_key, strlen(aes_str1.c_str()) );
    AES_set_encrypt_key(testKey1, keylength, &enc_key);
    AES_cbc_encrypt((unsigned char*)aes_input, 
                    enc_out, 
                    inputslength, 
                    &enc_key, 
                    iv_enc, 
                    AES_ENCRYPT);

    aes_str1 = "9876543210";

    AES_set_decrypt_key(testKey2, keylength, &dec_key);
    AES_cbc_encrypt(enc_out, dec_out, encslength, &dec_key, iv_dec, AES_DECRYPT);

    printf("original:\t%s\n", (char*)aes_input );
    printf("decrypt:\t%s\n", (char*)dec_out );
    return 0;
}
