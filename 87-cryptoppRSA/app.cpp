#include <iostream>
#include <fstream>
#define LOG std::cerr<<">>>"<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text) (std::cerr<<text<<std::endl)

#include <cryptopp/rsa.h>
#include <cryptopp/integer.h>
#include <cryptopp/osrng.h>

int main(){
	// Keys
	CryptoPP::Integer n("0xbeaadb3d839f3b5f"), e("0x11"), d("0x21a5ae37b9959db9");

	CryptoPP::RSA::PrivateKey privKey;
	privKey.Initialize(n, e, d);

	CryptoPP::RSA::PublicKey pubKey;
	pubKey.Initialize(n, e);

	// Encryption
	std::string message = "secretse";
	std::cout << "message: " << message << std::endl;
	CryptoPP::Integer m((const byte *)message.data(), message.size());
	std::cout << "m: " << m << std::endl;
	// m: 126879297332596.

	CryptoPP::Integer c = pubKey.ApplyFunction(m);
	std::cout << "c: " << std::hex << c << std::endl;
	// c: 3f47c32e8e17e291h

	// Decryption
	CryptoPP::AutoSeededRandomPool prng;
	CryptoPP::Integer r = privKey.CalculateInverse(prng, c);
	std::cout << "r: " << std::hex << r << std::endl;

	// r: 736563726574h
	std::string recovered;
	recovered.resize(r.MinEncodedSize());

	r.Encode((byte *)recovered.data(), recovered.size());
	std::cout << "recovered: " << recovered << std::endl;

	// recovered: secret
	return 0;
}
