#pragma once

static const int MAX_PORT_VALUE = 65535;
static const int MIN_PORT_VALUE = 1;
static const std::string regexLine("(http|https|ftp)://([^/ :]+):?([^/ ]*)/([^ ]*)");

enum class Protocol
{
	HTTP = 80,
	HTTPS = 443,
	FTP = 21
};

class CHttpUrl
{
public:
	// ��������� ������� ���������� ������������� URL-�, � ������ ������ ��������
	// ���������� ���������� CUrlParsingError, ���������� ��������� �������� ������
	CHttpUrl(std::string const& url);

	/* �������������� URL �� ������ ���������� ����������.
	��� �������������� ������� ���������� ����������� ����������
	invalid_argument
	���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = Protocol::HTTP,
		unsigned short port = 80);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;
private:
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;

	std::string CHttpUrl::VerifiedDomain(std::string const & domain) const;
	std::string CHttpUrl::VerifiedDocument(std::string const & document) const;
	unsigned short VerifiedPort(int const port) const;
	unsigned short GetPortFromStr(std::string const &portStr) const;
	Protocol GetProtocolFromStr(std::string protocol) const;
	std::string ConvertProtocol(Protocol const protocol) const;
	std::string ToLower(std::string str) const;
};
