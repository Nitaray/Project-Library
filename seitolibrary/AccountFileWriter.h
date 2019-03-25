#ifndef ACCOUNTFILEWRITER_H
#define ACCOUNTFILEWRITER_H

namespace MyLibrary
{

class AccountFileWriter:Writer<Account>
{
public:
	AccountFileWriter();
	~AccountFileWriter();

	void write(Account account) override;
};

}

#endif // ACCOUNTFILEWRITER_H
