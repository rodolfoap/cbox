#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <zmq.hpp>
#include <string>
#include <uuid/uuid.h>

// A couple of define macro functions
#define frandom(n1, n2) (((float)n2-(float)n1)*random()/(RAND_MAX+1.0)+n1)
#define log(text)(std::cerr<<text<<std::endl)

// Converts a text into a zmq::message_t
zmq::message_t getMessage(std::string s);

// Converts a zmq::message_t into a text
std::string getString(zmq::message_t* m);

// Generates a uuid string
std::string genuuid();

// Trivial encryption/decryption
void encryptDecrypt(std::string& s);

#endif
