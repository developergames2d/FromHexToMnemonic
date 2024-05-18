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

#include <iostream>
#include <chrono>
#include <ctime>
#include "SHA256.hpp"
#include "Crypto.hpp"
#include <MyLib\MyException.hpp>

using namespace std;

enum class Coin { Bitcoin, Monero, Dogecoin, Litecoin, Solana, PKOIN, Incorrect };
enum class Mode { Standart, FromHexAndPassphrase, GetSeed, Incorrect };

int main()
{

	try
	{
		cout << "Type to hex.txt (64 symbols) your hex and run. The mnemonic will be in mnemonic.txt." << endl << endl;

		MyString hex;
		FILE * input;
		fopen_s(&input, "hex.txt", "r");
		if (!input)
			throw MyException() << __FILE__ << ":" << __LINE__;
		hex.fscan(input);
		fclose(input);

		auto bytes = crypto::GetBytesFromHex(hex);
		crypto::bitcoin::AddSHA(bytes);
		auto mnemonic = crypto::bitcoin::GetBIP39Mnemonic24(bytes);

		FILE * out_mnm;


		fopen_s(&out_mnm, "mnemonic.txt", "w");
		for (size_t i = 0; i < mnemonic.size(); ++i)
			fprintf_s(out_mnm, "%12s", mnemonic[i].operator const char *());
		fprintf_s(out_mnm, "\n");

		fclose(out_mnm);
	}
	catch (const MyException & e)
	{
		cout << "Exception:" << e << endl;
	}
	catch (...)
	{
		cout << "Fatal error: unknown exception." << endl;
	}

	system("pause");
	return 0;
}