#ifndef __TOOL_FORMATTING_HPP__
#define __TOOL_FORMATTING_HPP__

#include <string>
#include <regex>



class tool_Formatting {
public:
	static std::string query_regex (std::string desp) {
		static std::map<std::string, std::string> m_regex_items {
			{ "IPv4", "^(((25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d))))$" },
			{ "IPv6", "^((([0-9|A-F|a-f]{1,4}:){7}([0-9|A-F|a-f]{1,4}|:))|(([0-9|A-F|a-f]{1,4}:){6}(:[0-9|A-F|a-f]{1,4}|((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)(\\.(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)){3})|:))|(([0-9|A-F|a-f]{1,4}:){5}(((:[0-9|A-F|a-f]{1,4}){1,2})|:((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)(\\.(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)){3})|:))|(([0-9|A-F|a-f]{1,4}:){4}(((:[0-9|A-F|a-f]{1,4}){1,3})|((:[0-9|A-F|a-f]{1,4})?:((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)(\\.(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)){3}))|:))|(([0-9|A-F|a-f]{1,4}:){3}(((:[0-9|A-F|a-f]{1,4}){1,4})|((:[0-9|A-F|a-f]{1,4}){0,2}:((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)(\\.(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)){3}))|:))|(([0-9|A-F|a-f]{1,4}:){2}(((:[0-9|A-F|a-f]{1,4}){1,5})|((:[0-9|A-F|a-f]{1,4}){0,3}:((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)(\\.(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)){3}))|:))|(([0-9|A-F|a-f]{1,4}:){1}(((:[0-9|A-F|a-f]{1,4}){1,6})|((:[0-9|A-F|a-f]{1,4}){0,4}:((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)(\\.(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)){3}))|:))|(:(((:[0-9|A-F|a-f]{1,4}){1,7})|((:[0-9|A-F|a-f]{1,4}){0,5}:((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)(\\.(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)){3}))|:)))(%.+)?$" },
			{ "����", "^([a-zA-Z0-9]([a-zA-Z0-9\\-]{0,61}[a-zA-Z0-9])?\\.)+[a-zA-Z]{2,6}$" },
			{ "URL", "^(http|ftp|https):\\/\\/[\\w\\-_]+(\\.[\\w\\-_]+)+([\\w\\-\\.,@?^=%&:/~\\+#]*[\\w\\-\\@?^=%&/~\\+#])?$" },
			{ "��������", "^\\w+(\\.\\w+)*@(\\w)+((\\.\\w+)+)$" },
			{ "����֤��", "^(\\d{17}(\\d|x|X|))|(\\d{15})$" },
			{ "�ֻ�", "^\\d{11}$" },
			{ "����", "^\\d{4}-\\d{1,2}-\\d{1,2}$" },
			{ "ʱ��", "^\\d{1,2}:\\d{1,2}:\\d{1,2}$" },
			{ "���", "^([0-9]+|[0-9]{1,3}(,?[0-9]{3})*)(.[0-9]{1,5})?$" },
			{ "�ʱ�", "^\\d{6}$" },
			{ "����(GB18030)", "^((\\u8140-\\ufefe)|(\\u8130-\\ufe39){2})+$" },
		};
		return m_regex_items[desp];
	}

	static bool is_ipv4 (std::string s) {
		std::regex r (query_regex ("IPv4"));
		return std::regex_match (s, r);
	}

	static bool is_ipv6 (std::string s) {
		std::regex r (query_regex ("IPv6"));
		return std::regex_match (s, r);
	}

	static bool is_domain (std::string s) {
		std::regex r (query_regex ("����"));
		return std::regex_match (s, r);
	}

	static bool is_url (std::string s) {
		std::regex r (query_regex ("URL"));
		return std::regex_match (s, r);
	}
};

#endif //__TOOL_FORMATTING_HPP__