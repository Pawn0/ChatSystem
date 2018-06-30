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

#include "encryption.hpp"

Encryption::Encryption()
{
    if (keysPresent()) {	//if the keys are present, load them in
	std::cout << "Keys are present, loading them in.." << std::endl;
	loadFromFolder("../keyFolder/publicKey", publicKey);
	loadFromFolder("../keyFolder/privateKey", privateKey);

    } else {			//otherwise generate,create folder ,save and load keys,
	std::cout << "Generating, saving keys, and loading them in.." <<
	    std::endl;
	generateKeys();
	loadFromFolder("../keyFolder/publicKey", publicKey);
	loadFromFolder("../keyFolder/privateKey", privateKey);
    }
}

void Encryption::generateKeys()
{
    CryptoPP::InvertibleRSAFunction params;
    params.GenerateRandomWithKeySize(rng, 3072);

    //generate the keys
    publicKey = params;
    privateKey = params;

    std::cout << "Folders created!" << std::endl;
    SaveKey(publicKey);
    SaveKey(privateKey);
}

std::string Encryption::encrypt(const std::string & item)
{
    //create an encryptor object
    CryptoPP::RSAES_OAEP_SHA_Encryptor e(publicKey);

    std::string cipher;

    //use a string source, with the string, told to encrypt it all, and a new encryptor filter
    //filterinto a string sink
    CryptoPP::StringSource stringSource(item, true,
					new
					CryptoPP::PK_EncryptorFilter(rng,
								     e,
								     new
								     CryptoPP::StringSink
								     (cipher)));

    return cipher;
}

std::string Encryption::decrypt(const std::string & item)
{
    //decryptor object to decrypt the cipher with our private key
    CryptoPP::RSAES_OAEP_SHA_Decryptor d(privateKey);

    std::string recovered;

    //use a string source, with the string, told to decrypt it all, using a decryption filter
    //filter into a string sink
    CryptoPP::StringSource stringSource(item, true,
					new
					CryptoPP::PK_DecryptorFilter(rng,
								     d,
								     new
								     CryptoPP::StringSink
								     (recovered)
					)
	);
    return recovered;
}

bool Encryption::keysPresent()
{
    //if the folder exists, and if they keys exist, then we return true
    if (boost::filesystem::exists("../keyFolder")
	&& boost::filesystem::is_regular_file("../keyFolder/privateKey")
	&& boost::filesystem::is_regular_file("../keyFolder/publicKey")) {
	std::cout << "Folder exists." << std::endl;
    } else {			//otherwise we display the keys do not exist
	std::cout << "Folder with Keys does not exist!" << std::endl;
	return false;
    }

}

void Encryption::loadFromFolder(const std::string & fileName,
				CryptoPP::RSA::PublicKey & publicKey)
{
    try {			//load the data from the folder
	CryptoPP::ByteQueue queue;
	load(fileName, queue);

	//then load it into the system
	publicKey.Load(queue);

	//then validate the key
	validateKey(publicKey);

    } catch(std::exception & ex) {
	std::cout << ex.what() << std::endl;
	std::exit(1);
    }
}

void Encryption::loadFromFolder(const std::string & fileName,
				CryptoPP::RSA::PrivateKey & privateKey)
{
    try {			//load the data from the folder
	CryptoPP::ByteQueue queue;
	load(fileName, queue);

	//then load it into the system
	privateKey.Load(queue);

	//then validate the key
	validateKey(privateKey);
    } catch(std::exception & ex) {
	std::cout << ex.what() << std::endl;
	std::exit(1);
    }
}

void Encryption::load(const std::string & fileName,
		      CryptoPP::BufferedTransformation & buffTrans)
{
    //get the file source, and tell it to pump in all the contents
    CryptoPP::FileSource file(fileName.c_str(), true);
    file.TransferAllTo(buffTrans);
    buffTrans.MessageEnd();
}

bool Encryption::validateKey(CryptoPP::RSA::PublicKey & publicKey)
{
    if (!publicKey.Validate(rng, 2)) {
	throw std::runtime_error("RSA public key validation failed!");
	return false;
    }
    return true;
}

bool Encryption::validateKey(CryptoPP::RSA::PrivateKey & privateKey)
{
    if (!privateKey.Validate(rng, 2)) {
	throw std::runtime_error("RSA private key validation failed!");
	return false;
    }
    return true;
}

void Encryption::SaveKey(const CryptoPP::RSA::PublicKey & key)
{
    CryptoPP::ByteQueue queue;
    key.Save(queue);

    save("../keyFolder/publicKey", queue);
}

void Encryption::SaveKey(const CryptoPP::RSA::PrivateKey & key)
{
    CryptoPP::ByteQueue queue;
    key.Save(queue);

    save("../keyFolder/privateKey", queue);
}

void Encryption::save(const std::string & fileName,
		      const CryptoPP::BufferedTransformation & bt)
{
    CryptoPP::FileSink file(fileName.c_str());
    bt.CopyTo(file);
    file.MessageEnd();
}
