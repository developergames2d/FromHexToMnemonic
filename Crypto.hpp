#pragma once

//!     Official link:
//!     https://github.com/developergames2d/CryproWalletGenerator/
//!     DONATE:
//!     	XMR:
//!     		87MnyP3mpxQBmCoQHM4H64RuaBZtP5zW2hGWu18YPujA94a18ypzpYT6jnNq68Q24yXwXAFDG2Vi91AgLNC76uEcR5WMoRp
//!     	BTC:
//!     		bc1qrg8agge2gcy75kct9g3cxeyl26ecjsx5wf4r8a
//!     	DOGE:
//!     		D9UD5v6xDAQZkBpJz1eP3Q1byGBC9dx5rd
//!     	Litecoin:
//!     		Latr7n7ATGEC9AGXbJW2D9SWQdQUu3am1C
//!         Solana:
//!             ET1Zbdun77T64e5EPBkyj13DZyLMmkjiB7nkVHak2q87

#include <MyLib\MyString.hpp>
#include <vector>
#include <MyLib\MyException.hpp>

namespace crypto
{
	extern const char BASE58[];
	const size_t BASE58_SIZE = 58;

	namespace bitcoin
	{
		const char * BIP39_WORDS[];
		const size_t BIP39_SIZE = 2048;

		void AddSHA(std::vector<unsigned __int8> & bytes);
		std::vector<MyString> GetBIP39Mnemonic24(std::vector<unsigned __int8> bytes);
		std::vector<MyString> GetBIP39Mnemonic12(std::vector<unsigned __int8> bytes);
	}

	MyString GetBitsFromBytes(std::vector<unsigned __int8> bytes);
	MyString GetHexFromBytes(std::vector<unsigned __int8> bytes);
	std::vector<unsigned __int8> GetBytesFromHex(const MyString & hex);

	extern const size_t PRIVATE_KEY_BYTES;
}