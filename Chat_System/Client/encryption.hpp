/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2018  pawn <email>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cryptopp/osrng.h>
#include <cryptopp/rsa.h>
#include <cryptopp/files.h>
#include <cryptopp/cryptlib.h>
#include <boost/filesystem.hpp>

/**
 * @todo write docs
 */
class Encryption {
  public:
    //When we initialize an Encryption object it will look
    //for existing keys or generate new keys
    //if existing keys are found they will be loaded in
    Encryption();

    //will encrypt an item using the existing keys
    std::string encrypt(const std::string & item);

    //decryption of an item using the private key
     std::string decrypt(const std::string & item);

  private:

    //function that does the key generation
    //and saves the keys into the file structure
    void generateKeys();

    //function that checks if the keys and folder are there
    bool keysPresent();

    //function to load the keys into the system
    void loadFromFolder(const std::string & fileName,
			CryptoPP::RSA::PublicKey & publicKey);

    //function to load the keys into the system
    void loadFromFolder(const std::string & fileName,
			CryptoPP::RSA::PrivateKey & privateKey);

    //function to handle loading the data into a secure location
    void load(const std::string & fileName,
	      CryptoPP::BufferedTransformation & buffTrans);

    //verify the keys
    bool validateKey(CryptoPP::RSA::PublicKey & publicKey);
    bool validateKey(CryptoPP::RSA::PrivateKey & privateKey);

    //create the key folder to store the keys inside
    void createKeyFolder();

    //prep the keys for saving by loading them into a secure location
    void SaveKey(const CryptoPP::RSA::PublicKey & key);
    void SaveKey(const CryptoPP::RSA::PrivateKey & key);

    //actually do the saving into a filename
    void save(const std::string & fileName,
	      const CryptoPP::BufferedTransformation & bt);


     CryptoPP::AutoSeededRandomPool rng;
     CryptoPP::RSA::PublicKey serverPublicKey;
     CryptoPP::RSA::PrivateKey privateKey;
     CryptoPP::RSA::PublicKey publicKey;
};

#endif				// ENCRYPTION_H
