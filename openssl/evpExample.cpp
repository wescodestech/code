#include <iostream> 
#include <stdio.h> 
#include <string.h>
#include <openssl/aes.h> 
#include <openssl/evp.h> 
#include <openssl/rand.h> 

// EVP AES Example
// Another example of writing some code to get a hang
// of the OpenSSL implementation
// Compile:
// g++ -o aes evpExample.cpp -lcrypto


/**
Encrypt funciton
*/
int AesEncrypt(const std::string &sAesKey, 
                                        const std::string &ToEncrypt, 
                                        std::string &Encrypted) { 
        const int AesBlockSize=16; 
        unsigned char cInitVector[AesBlockSize]; 
        EVP_CIPHER_CTX oEncCtx; 
        const EVP_CIPHER *oChiper=0; 
        int retval=0; 
        unsigned char *cOutBuffer=0; 
        
        // Set aes key: 
        if (sAesKey.length()==16) { 
                oChiper = EVP_aes_128_cbc(); 
        } else { 
                oChiper = EVP_aes_256_cbc(); 
        }  

        // Create init vector and add him infront of encrypted output data: 
        RAND_pseudo_bytes(cInitVector, AesBlockSize); 
        Encrypted.assign((char *)cInitVector, ((char *)cInitVector)+AesBlockSize); 

        // Create encryption context.	
        EVP_CIPHER_CTX_init(&oEncCtx); 
        EVP_EncryptInit_ex(&oEncCtx, oChiper, 0, (unsigned char *)sAesKey.c_str(), cInitVector); 

        // Encrypt most of the data: 
        int OutBufferByteLen = ToEncrypt.length()+2*AesBlockSize; 
        cOutBuffer = new unsigned char[OutBufferByteLen]; 
        retval = EVP_EncryptUpdate( 
                &oEncCtx, 
                cOutBuffer, 
                &OutBufferByteLen, 
                (unsigned char *)ToEncrypt.c_str(), 
                ToEncrypt.length()); 

        // Doese encryption fail? 
        if (retval<0) { 
                delete[] cOutBuffer; 
                return retval; // Encryption error. 
        } 

        // Add encrypted data to output: 
        Encrypted.append((char *)cOutBuffer, ((char *)cOutBuffer)+OutBufferByteLen); 
        delete[] cOutBuffer; 
        
        //Add last block+padding: 
        OutBufferByteLen = 2*AesBlockSize; 
        cOutBuffer = new unsigned char[OutBufferByteLen]; // To be sure add two blocks. 
        retval = EVP_EncryptFinal_ex( 
                &oEncCtx, 
                cOutBuffer, 
                &OutBufferByteLen); 

        // Doese encryption fail? 
        if (retval<0) { 
                delete[] cOutBuffer; 
                return retval; // Encryption error. 
        } 

        // Add encrypted data to output: 
        Encrypted.append((char *)cOutBuffer, ((char *)cOutBuffer)+OutBufferByteLen); 
        delete[] cOutBuffer; 

        EVP_CIPHER_CTX_cleanup(&oEncCtx); 
        return 0; // Success 
} 

/**
Decrypt Function
*/
int AesDecrypt(const std::string &sAesKey, 
                                        const std::string &ToDecrypt, 
                                        std::string &Decrypted) { 
        const int AesBlockSize=16; 
        unsigned char cInitVector[AesBlockSize]; 
        EVP_CIPHER_CTX oEncCtx; 
        const EVP_CIPHER *oChiper=0; 
        int retval=0; 
        unsigned char *cOutBuffer=0; 
        
        // Set aes key:
        oChiper = EVP_aes_256_cbc();

        // Get init vector: 
        const char *constInitVectorPtr = ToDecrypt.c_str(); 
        for (int i=0; i<AesBlockSize; i++) { 
                cInitVector[i] = *constInitVectorPtr; 
                constInitVectorPtr++; 
        } 

        // Create decryption context.	
        EVP_CIPHER_CTX_init(&oEncCtx); 
        EVP_DecryptInit_ex(&oEncCtx, oChiper, 0, (unsigned char *)sAesKey.c_str(), cInitVector); 

        // Decrypt most of the data: 
        int OutBufferByteLen = ToDecrypt.length() - AesBlockSize; // Subtract the InitVec. 
        cOutBuffer = new unsigned char[OutBufferByteLen]; 
        retval = EVP_DecryptUpdate( 
                &oEncCtx, 
                cOutBuffer, 
                &OutBufferByteLen, 
                ((unsigned char *)ToDecrypt.c_str()) + AesBlockSize, // Remove the InitVector. 
                OutBufferByteLen); 

        // Doese encryption fail? 
        if (retval<0) { 
                delete[] cOutBuffer; 
                return retval; // Encryption error. 
        } 

        // Add encrypted data to output: 
        Decrypted.append((char *)cOutBuffer, ((char *)cOutBuffer)+OutBufferByteLen); 
        delete[] cOutBuffer; 
        
        //Add last block+padding: 
        OutBufferByteLen = 2*AesBlockSize; 
        cOutBuffer = new unsigned char[OutBufferByteLen]; // To be sure add two blocks. 
        retval = EVP_DecryptFinal_ex( 
                &oEncCtx, 
                cOutBuffer, 
                &OutBufferByteLen); 

        // Doese encryption fail? 
        if (retval<0) { 
                delete[] cOutBuffer; 
                return retval; // Encryption error. 
        } 

        // Add encrypted data to output: 
        Decrypted.append((char *)cOutBuffer, ((char *)cOutBuffer)+OutBufferByteLen); 
        delete[] cOutBuffer; 

        EVP_CIPHER_CTX_cleanup(&oEncCtx); 
        return 0; // Success 
} 

int main() { 
        std::string ToEncrypt, Encrypted, Decrypted, AesKey1, AesKey2; 
        int retval=0; 

        AesKey1 = "111112222233333444445555566666664444888885554444888548136241859641"; // 32 Byte = 256 Bit key. 
	AesKey2 = "111112222233333444445555566666664444888885554444888548136241859641"; // 32 Byte = 256 Bit key.
        ToEncrypt = "aaaaaaaaaaaaaabbbbbbbbbbbbbcccccccccccccccddddddddddddddddeeeeeeeeeeeeee"; 

	// Not sure why this is here?
        //OpenSSL_add_all_algorithms(); 
        //OpenSSL_add_all_ciphers(); 
        //OpenSSL_add_all_digests(); 

        retval = AesEncrypt(AesKey1, ToEncrypt, Encrypted); 
        retval = AesDecrypt(AesKey2, Encrypted, Decrypted); 

        printf( "Original: %s\nDecrypted: %s\n", ToEncrypt.c_str(), Decrypted.c_str() );
        return 0; 
} 
