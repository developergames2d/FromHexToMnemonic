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

#include "Crypto.hpp"
#pragma warning(push)
#pragma warning(disable:4005)
#include <MyLib\BigInteger.hpp>
#pragma warning(pop)

using namespace std;

namespace crypto
{
	extern const size_t PRIVATE_KEY_BYTES = 32;

	const char BASE58[BASE58_SIZE + 1] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

	MyString GetBitsFromBytes(std::vector<unsigned __int8> bytes)
	{
		MyString res;

		for (size_t i = 0; i < bytes.size(); ++i)
		{
			unsigned __int8 c = bytes[i];
			char str[9];
			for (int j = 0; j < 8; ++j)
			{
				str[7 - j] = c % 2 + '0';
				c >>= 1;
			}
			str[8] = '\0';
			res += str;
		}
		return res;
	}

	MyString GetHexFromBytes(std::vector<unsigned __int8> bytes)
	{
		MyString res;
		const char * HEX = "0123456789abcdef";

		for (size_t i = 0; i < bytes.size(); ++i)
		{
			unsigned __int8 c = bytes[i];
			res += HEX[c >> 4];
			res += HEX[c % 0x10];
		}
		return res;
	}
	std::vector<unsigned __int8> GetBytesFromHex(const MyString & hex)
	{
		std::vector<unsigned __int8> result;

		if(hex.getLength() % 2 != 0)
			throw MyException() << __FILE__ << ":" << __LINE__;

		for (size_t i = 0; i + 1 < hex.getLength(); )
		{
			unsigned __int8 byte = 0;

			if (hex[i] >= '0' && hex[i] <= '9')
				byte += hex[i] - '0';
			else if (hex[i] >= 'a' && hex[i] <= 'f')
				byte += hex[i] - 'a' + 10;
			else if (hex[i] >= 'A' && hex[i] <= 'F')
				byte += hex[i] - 'A' + 10;
			else
				throw MyException() << __FILE__ << ":" << __LINE__;

			byte *= 0x10;
			++i;
			if (hex[i] >= '0' && hex[i] <= '9')
				byte += hex[i] - '0';
			else if (hex[i] >= 'a' && hex[i] <= 'f')
				byte += hex[i] - 'a' + 10;
			else if (hex[i] >= 'A' && hex[i] <= 'F')
				byte += hex[i] - 'A' + 10;
			else
				throw MyException() << __FILE__ << ":" << __LINE__;
			++i;
			result.push_back(byte);
		}

		return result;
	}
}